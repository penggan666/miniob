#pragma once
#include <list>
#include <unordered_map>
#include "replacer.h"
class LRUReplacer : public Replacer {
 public:
  /**
   * Create a new LRUReplacer.
   * @param num_pages the maximum number of pages the LRUReplacer will be required to store
   */
  explicit LRUReplacer(int num_pages);

  /**
   * Destroys the LRUReplacer.
   */
  ~LRUReplacer() override;

  bool Victim(int *frame_id) override;

  void Pin(int frame_id) override;

  void Unpin(int frame_id) override;

  int Size() override;

 private:
  //定义别名
  using lru_iter=typename std::list<int >::const_iterator ;
  using lru_map=std::unordered_map<int ,lru_iter >;//数组里的frame索引 map 到lru list里
  //管理frame的双向链表
  std::list<int > m_lru_list;
  //hash表
  lru_map m_lru_map;
  int num_pages;
};