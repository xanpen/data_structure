//
//  slink.h
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/23.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#ifndef slink_h
#define slink_h
#include <stdbool.h>

typedef struct SlinkNode {
    int _data;
    struct SlinkNode *next;
} SlinkNode;

typedef struct SlinkHead {
    SlinkNode *head;
} SlinkHead;

/**
 *  单链表是否为空
 */
bool slink_is_empty(SlinkHead *shead);
/**
 *  dump
 */
void slink_dump(SlinkHead *shead);
/**
 *  insert(任意位置)
 */
void slink_insert(SlinkNode **ppnode, SlinkNode *elem);
/**
 *  del（任意位置）
 **/
SlinkNode *slink_del(SlinkNode **ppnode);
/**
 * 头结点之后插入
 */
void slink_insert_after_head(SlinkHead *shead, SlinkNode *elem);
/**
 *  头结点之后删除
 */
SlinkNode *slink_del_after_head(SlinkHead *shead);
/**
 *  search
 */
SlinkNode **slink_search(SlinkHead *shead, int data);
/**
 *  单链表翻转
 */
void slink_reverse(SlinkHead *shead);
/**
 *  单链表是否有环
 **/
bool slink_is_cyclic(SlinkHead *shead);
/**
 *  返回中间结点
 */
SlinkNode *slink_mid_node(SlinkHead *shead);
/**
 * 返回倒数第k个结点
 */
SlinkNode *slink_kth_node(SlinkHead *shead, int k);
SlinkNode **slink_k_node(SlinkHead *shead, int k);
#endif /* slink_h */
