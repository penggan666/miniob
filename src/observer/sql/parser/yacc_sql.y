
%{

#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
  char id[MAX_NUM];
  //TODO: add subquery
  size_t now_select_dep;//当前查询的深度
  size_t path_to_sub[MAX_NUM];//从第一层定位到当前查询的路径 例如第一个子查询 [0 X X X ...] 基于now_select_dep判断需要徐遍历的位置
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = (ParserContext *)(yyget_extra(scanner));
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)

%}

%define api.pure full
%lex-param { yyscan_t scanner }
%parse-param { void *scanner }

//标识tokens
%token  SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
        INDEX
        SELECT
		MAX
		MIN
		COUNT
		AVG
        DESC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
		DATE_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
        AND
        SET
        ON
        LOAD
        DATA
        INFILE
        UNIQUE
        EQ
        LT
        GT
        LE
        GE
        NE
		ORDER
		GROUP
		BY
		ASC
		INNER
		JOIN
		NOT
		IN_T
		ISNULL
		IS
		NULLABLE
%union {
  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  char *string;
  int number;
  float floats;
	char *position;
}

%token <number> NUMBER
%token <floats> FLOAT 
%token <string> ID
%token <string> PATH
%token <string> SSS
%token <string> STAR
%token <string> STRING_V
//非终结符

%type <number> type;
%type <condition1> condition;
%type <value1> value;
%type <number> number;

%%

commands:		//commands or sqls. parser starts here.
    /* empty */
    | commands command
    ;

command:
	  select  
	| insert
	| update
	| delete
	| create_table
	| drop_table
	| show_tables
	| desc_table
	| create_index	
	| drop_index
	| sync
	| begin
	| commit
	| rollback
	| load_data
	| help
	| exit
    ;

exit:			
    EXIT SEMICOLON {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    };

help:
    HELP SEMICOLON {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    };

sync:
    SYNC SEMICOLON {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
    ;

begin:
    TRX_BEGIN SEMICOLON {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
    ;

commit:
    TRX_COMMIT SEMICOLON {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
    ;

rollback:
    TRX_ROLLBACK SEMICOLON {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
    ;

drop_table:		/*drop table 语句的语法解析树*/
    DROP TABLE ID SEMICOLON {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, $3);
    };

show_tables:
    SHOW TABLES SEMICOLON {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
    ;

desc_table:
    DESC ID SEMICOLON {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, $2);
    }
    ;

create_index:		/*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE index_attr RBRACE SEMICOLON
		{
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, $3, $5, 0);
		}
	| CREATE UNIQUE INDEX ID ON ID LBRACE index_attr RBRACE SEMICOLON
	    {
	        CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_unique_index";
	        create_index_init(&CONTEXT->ssql->sstr.create_index, $4, $6, 1);
	    }
    ;

index_attr:
    ID index_attr_list{
        IndexColumn iColumn;
        IndexColumn_attr_init(&iColumn,$1);
        create_index_append_attribute(&CONTEXT->ssql->sstr.create_index,&iColumn);
    }

index_attr_list:
    /* empty */
    | COMMA ID index_attr_list{
        IndexColumn iColumn;
        IndexColumn_attr_init(&iColumn,$2);
        create_index_append_attribute(&CONTEXT->ssql->sstr.create_index,&iColumn);
    }
    ;



drop_index:			/*drop index 语句的语法解析树*/
    DROP INDEX ID  SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, $3);
		}
    ;
create_table:		/*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, $3);
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
    ;
attr_def_list:
    /* empty */
    | COMMA attr_def attr_def_list {    }
    ;
    
attr_def:
    ID_get type LBRACE number RBRACE 
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, $4, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
    |ID_get type
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, 8, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
	//TODO: 添加字段是否为NULL
	| ID_get type NOT ISNULL
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, 8, 0);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
	| ID_get type NULLABLE
		{
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, $2, 8, 1);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}	
    ;
number:
		NUMBER {$$ = $1;}
		;
type:
	INT_T { $$=INTS; }
       | STRING_T { $$=CHARS; }
       | FLOAT_T { $$=FLOATS; }
	   //TODO: add date
	   | DATE_T{$$=DATES;}
       ;
ID_get:
	ID 
	{
		char *temp=$1; 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
	;

	
insert:				/*insert   语句的语法解析树*/
    INSERT INTO ID VALUES LBRACE value value_list RBRACE tuple_list SEMICOLON
		{
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, $3, CONTEXT->values, CONTEXT->value_length);

      //临时变量清零
      CONTEXT->value_length=0;
    }

value_list:
    /* empty */
    | COMMA value value_list  { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
    ;

tuple_list:
    /* empty */
    | COMMA LBRACE value value_list RBRACE tuple_list  {
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
    ;

value:
    NUMBER{	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
    |FLOAT{
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
    |SSS {
			$1 = substr($1,1,strlen($1)-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], $1);
		}
	|ISNULL{
	    value_init_nullvalue(&CONTEXT->values[CONTEXT->value_length++]);
	    }
    ;
    
delete:		/*  delete 语句的语法解析树*/
    DELETE FROM ID where SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, $3);
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
    ;
update:			/*  update 语句的语法解析树*/
    UPDATE ID SET ID EQ value where SEMICOLON
		{
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, $2, $4, value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
    ;
select:				/*  select 语句的语法解析树*/
    SELECT select_attr FROM ID rel_list where group order SEMICOLON
		{
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, $4);
			
			// selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length); 

			CONTEXT->ssql->flag=SCF_SELECT;//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;
			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;

	}
	;
group:
    /* empty */
    | GROUP BY group_attr{
    //TODO: add group
    }
    ;
group_attr:
    ID group_list{
        GroupAttr attr;
        group_attr_init(&attr,NULL,$1);
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
    | ID DOT ID group_list{
        GroupAttr attr;
        group_attr_init(&attr,$1,$3);
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
    ;

group_list:
    /* empty */
    | COMMA ID group_list{
        GroupAttr attr;
        group_attr_init(&attr,NULL,$2);
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }
    | COMMA ID DOT ID group_list{
        GroupAttr attr;
        group_attr_init(&attr,$2,$4);
        selects_append_group(&CONTEXT->ssql->sstr.selection,&attr);
    }


head_sub_select:
	LBRACE SELECT{
	Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
	//TODO: add sub query
	//判断一下是否有空间存放新遇到的子查询, 如果没有空间
	if(0==st->sub_num){//分配初始空间
		st->sub_select=(Selects *)(malloc(sizeof(Selects)*MAX_NUM));
		st->sub_num=1;
		// path_to_sub[now_select_dep-1]=0;//需要处理的子查询位于index 0
	}else{
		st->sub_num++;//增加一个子查询
	}
	CONTEXT->now_select_dep++;//遇到子查询, 跳入子查询, 深度+1
	CONTEXT->path_to_sub[CONTEXT->now_select_dep-1]=st->sub_num-1;//新增子查询位于index sub_num-1
	};
sub_select:
	head_sub_select select_attr FROM ID rel_list where RBRACE{
		//找到子查询, 并做一些收尾工作
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, $4);
		//处理完一个子查询
		CONTEXT->now_select_dep--;//跳回上一级查询
	}
order:
	/* empty */
	| ORDER BY order_attr{
	//TODO: add order 
	}
	;
order_attr:
	ID order_list{
		OrderAttr attr;
		order_attr_init(&attr,NULL,$1,OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	| ID DOT ID order_list{
		OrderAttr attr;
		order_attr_init(&attr,$1,$3,OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	|ID ASC order_list{
		OrderAttr attr;
		order_attr_init(&attr,NULL,$1,OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	|ID DOT ID ASC order_list{
		OrderAttr attr;
		order_attr_init(&attr,$1,$3,OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	|ID DESC order_list{
		OrderAttr attr;
		order_attr_init(&attr,NULL,$1,ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	|ID DOT ID DESC order_list{
		OrderAttr attr;
		order_attr_init(&attr,$1,$3,ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	;
order_list:
	/* empty */
	| COMMA ID order_list{
		OrderAttr attr;
		order_attr_init(&attr,NULL,$2,OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	| COMMA ID DOT ID order_list{
		OrderAttr attr;
		order_attr_init(&attr,$2,$4,OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	| COMMA ID ASC order_list{
		OrderAttr attr;
		order_attr_init(&attr,NULL,$2,OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	| COMMA ID DOT ID ASC order_list{
		OrderAttr attr;
		order_attr_init(&attr,$2,$4,OASC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	| COMMA ID DESC order_list{
		OrderAttr attr;
		order_attr_init(&attr,NULL,$2,ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	| COMMA ID DOT ID DESC order_list{
		OrderAttr attr;
		order_attr_init(&attr,$2,$4,ODESC);
		selects_append_order(&CONTEXT->ssql->sstr.selection,&attr);
	}
	;

select_attr:
    STAR {  
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 0);
			selects_append_attribute(st, &attr);
		}
    | ID attr_list {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, $1, 0);
			selects_append_attribute(st, &attr);
		}
  	| ID DOT ID attr_list {
		  	Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, $1, $3, 0);
			selects_append_attribute(st, &attr);
		}
	| ID DOT STAR attr_list{// add t1.*
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, $1, "*", 0);
			selects_append_attribute(st, &attr);
	}

	//TODO: 添加对聚合函数的解析
	| COUNT LBRACE STAR RBRACE attr_list{// add COUNT(*)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*", 5);
			selects_append_attribute(st, &attr);
	}

	| COUNT LBRACE ID RBRACE attr_list{// add COUNT(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, $3, 1);
			selects_append_attribute(st, &attr);
	} 

	| COUNT LBRACE ID DOT ID RBRACE attr_list{// add COUNT(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, $3, $5, 1);
			selects_append_attribute(st, &attr);
	}

	| MAX LBRACE ID RBRACE attr_list{// add MAX(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, $3, 2);
			selects_append_attribute(st, &attr);
	} 

	| MAX LBRACE ID DOT ID RBRACE attr_list{// add MAX(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, $3, $5, 2);
			selects_append_attribute(st, &attr);
	}

	| MIN LBRACE ID RBRACE attr_list{// add MIN(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, $3, 3);
			selects_append_attribute(st, &attr);
	} 

	| MIN LBRACE ID DOT ID RBRACE attr_list{// add MIN(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, $3, $5, 3);
			selects_append_attribute(st, &attr);
	}

	| AVG LBRACE ID RBRACE attr_list{// add AVG(id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, $3, 4);
			selects_append_attribute(st, &attr);
	} 

	| AVG LBRACE ID DOT ID RBRACE attr_list{// add AVG(t.id)
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, $3, $5, 4);
			selects_append_attribute(st, &attr);
	}	


    ;
attr_list:
    /* empty */
    | COMMA ID attr_list {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, NULL, $2, 0);
			selects_append_attribute(st, &attr);
     	  // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].relation_name = NULL;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].attribute_name=$2;
      }
    | COMMA ID DOT ID attr_list {
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			RelAttr attr;
			relation_attr_init(&attr, $2, $4, 0);
			selects_append_attribute(st, &attr);
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length].attribute_name=$4;
        // CONTEXT->ssql->sstr.selection.attributes[CONTEXT->select_length++].relation_name=$2;
  	  }
    | COMMA COUNT LBRACE STAR RBRACE attr_list{// add COUNT(*)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, "*", 5);
            selects_append_attribute(st, &attr);
    }

    | COMMA COUNT LBRACE ID RBRACE attr_list{// add COUNT(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, $4, 1);
            selects_append_attribute(st, &attr);
    }

    | COMMA COUNT LBRACE ID DOT ID RBRACE attr_list{// add COUNT(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, $4, $6, 1);
            selects_append_attribute(st, &attr);
    }

    | COMMA MAX LBRACE ID RBRACE attr_list{// add MAX(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, $4, 2);
            selects_append_attribute(st, &attr);
    }

    | COMMA MAX LBRACE ID DOT ID RBRACE attr_list{// add MAX(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, $4, $6, 2);
            selects_append_attribute(st, &attr);
    }

    | COMMA MIN LBRACE ID RBRACE attr_list{// add MIN(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, $4, 3);
            selects_append_attribute(st, &attr);
    }

    | COMMA MIN LBRACE ID DOT ID RBRACE attr_list{// add MIN(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, $4, $6, 3);
            selects_append_attribute(st, &attr);
    }

    | COMMA AVG LBRACE ID RBRACE attr_list{// add AVG(id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, NULL, $4, 4);
            selects_append_attribute(st, &attr);
    }

    | COMMA AVG LBRACE ID DOT ID RBRACE attr_list{// add AVG(t.id)
            Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
            RelAttr attr;
            relation_attr_init(&attr, $4, $6, 4);
            selects_append_attribute(st, &attr);
    }
  	;

rel_list:
/* empty */
| table_factor {	
		}
| join_table{//TODO: add inner join
}
;
table_factor:
	COMMA ID rel_list {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);	
		selects_append_relation(st, $2);
	}
	;
join_table:
	INNER JOIN ID join_on rel_list{//TODO: add inner join
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		selects_append_relation(st, $3);
	}
;
join_on:
	/* empty */
	| ON condition condition_list{//TODO: add inner join

	}
;
where:
    /* empty */ 
    | WHERE condition condition_list {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
    ;
condition_list:
    /* empty */
    | AND condition condition_list {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
    ;
condition:
    ID comOp value 
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1, 0);

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;

			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name = NULL;
			// $$->left_attr.attribute_name= $1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
		|value comOp value 
		{
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 0, NULL, right_value);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
		|ID comOp ID 
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1, 0);
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3, 0);

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
    |value comOp ID
		{
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3, 0);

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
	|ISNULL comOp value
	    {
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
            Value left_value;
			value_init_nullvalue(&left_value);
			Condition condition;
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, &left_value, 0, NULL, right_value);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp ,0, NULL, &left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}	
	|value comOp ISNULL
	    {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 0, NULL, &right_value);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
	|ISNULL comOp ISNULL
		{
			Condition condition;
			Value right_value;
			value_init_nullvalue(&right_value);
			Value left_value;
            value_init_nullvalue(&left_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, &left_value, 0, NULL, &right_value);
			selects_append_condition(st,&condition);
			// condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, &right_value);
			// CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, &left_value, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}		
    |ID DOT ID comOp value
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3, 0);
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
			Condition condition;
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			selects_append_condition(st,&condition);

			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
	|ID comOp ISNULL
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, $1, 0);
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ISNULL comOp ID
		{
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3, 0);
			Value left_value;
			value_init_nullvalue(&left_value);
			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 0, NULL, &left_value, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, &left_value, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, &left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		}
	|ID DOT ID comOp ISNULL
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3, 0);
            Value right_value;
			value_init_nullvalue(&right_value);
			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, &right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}

    |value comOp ID DOT ID
		{
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, $3, $5, 0);

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
    |ID DOT ID comOp ID DOT ID
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3, 0);
			RelAttr right_attr;
			relation_attr_init(&right_attr, $5, $7, 0);

			Condition condition;
			// condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
			condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			selects_append_condition(st,&condition);
			//为支持旧功能如update,delete, 新的select不需要
			Condition condition2;
			condition_init(&condition2, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
	| ID comOp sub_select{
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1, 0);
		RelAttr right_attr;
		relation_attr_init_query(&right_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
	| ID DOT ID comOp sub_select{
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3, 0);
		RelAttr right_attr;
		relation_attr_init_query(&right_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
	| sub_select comOp ID{
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, $3, 0);
		RelAttr left_attr;
		relation_attr_init_query(&left_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
	| sub_select comOp ID DOT ID{
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr right_attr;
		relation_attr_init(&right_attr, $3, $5, 0);
		RelAttr left_attr;
		relation_attr_init_query(&left_attr,0,st->sub_num-1);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
	|sub_select comOp sub_select{
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		RelAttr right_attr;
		relation_attr_init_query(&right_attr,0,st->sub_num-1);
		RelAttr left_attr;
		relation_attr_init_query(&left_attr,0,st->sub_num-2);
		Condition condition;
		condition_init(&condition, st->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		selects_append_condition(st,&condition);
	}
    ;

comOp:
  	  EQ { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		CONTEXT->comp = EQUAL_TO; 
		st->comp=EQUAL_TO;
			}
    | LT { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=LESS_THAN;
		CONTEXT->comp = LESS_THAN; 
		}
    | GT { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=GREAT_THAN;
		CONTEXT->comp = GREAT_THAN; 
		}
    | LE { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=LESS_EQUAL;
		CONTEXT->comp = LESS_EQUAL; 
		}
    | GE { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=GREAT_EQUAL;
		CONTEXT->comp = GREAT_EQUAL; 
		}
    | NE { 
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=NOT_EQUAL;
		CONTEXT->comp = NOT_EQUAL; 
		}
	| NOT IN_T{

		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=NOT_IN;
		CONTEXT->comp = NOT_IN; 
		}
	| IN_T{
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IN;
		CONTEXT->comp = IN;
		}
	| IS {
		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IS_;
		CONTEXT->comp = IS_;
		}
	| IS NOT{

		Selects* st=to_subquery(&CONTEXT->ssql->sstr.selection,CONTEXT->now_select_dep,CONTEXT->path_to_sub);
		st->comp=IS_NOT;
		CONTEXT->comp = IS_NOT;
		}
    ;

load_data:
		LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON
		{
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, $7, $4);
		}
		;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}