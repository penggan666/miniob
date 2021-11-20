#include "lru_replacer.h"
LRUReplacer::LRUReplacer(int num_pages):num_pages(num_pages) {
  m_lru_map.reserve(this->num_pages);
}

LRUReplacer::~LRUReplacer() = default;

bool LRUReplacer::Victim(int *frame_id) {
  //删除链表中队尾的值, 也就是最久没使用的
  if(Size()==0) {
    return false;
}
  //记录该值
  *frame_id=m_lru_list.back();
  m_lru_list.pop_back();
  m_lru_map.erase(*frame_id);
  return true;
}

void LRUReplacer::Pin(int frame_id) {
  //将Pin的frame_id从监控中删除
  if(m_lru_map.find(frame_id)==m_lru_map.end()) {
    return;
}
  m_lru_list.erase(m_lru_map[frame_id]);
  m_lru_map.erase(frame_id);
}

void LRUReplacer::Unpin(int frame_id) {
  //unpin的frame_id说明可以进行调度, 将其放入lru_list里,并更新map的元数据
  //确认是否已经放入
  if(m_lru_map.find(frame_id)==m_lru_map.end()){
    //没有放入, 新加入的值放到队头
    m_lru_list.emplace_front(frame_id);
//    m_lru_map.emplace(frame_id,m_lru_list.begin());//注意这里是begin, 因为存储的是指针而不是值
    m_lru_map[frame_id]=m_lru_list.begin();
  }


}

int LRUReplacer::Size() { return m_lru_map.size(); }