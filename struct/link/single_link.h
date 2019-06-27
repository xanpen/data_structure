//
//  single_link.h
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/25.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#ifndef single_link_h
#define single_link_h
#include <stdbool.h>

typedef struct SingleLinkNode {
    int data;
    struct SingleLinkNode *next;
} SingleLinkNode;


/**
 *  在头结点前插入新节点
 *
 */
void single_link_insert_node(SingleLinkNode **pHead, int data);
/**
 *  dump single link
 */
void single_link_dump(SingleLinkNode **pHead);
/**
 *  *pSrc头结点 移动到 *pDest头结点
 */
void single_link_move_node(SingleLinkNode **pDest, SingleLinkNode **pSrc);
/**
 *  翻转单链表，空间复杂度O(1)
 */
void single_link_reverse (SingleLinkNode ** pHead);
/**
 *  链表中环的检测
 */
bool single_link_is_cyclic(SingleLinkNode **pHead);
/**
 *  两个有序的链表合并
 */
SingleLinkNode *single_link_merge(SingleLinkNode *la, SingleLinkNode *lb);
/**
 *  删除链表倒数第 k 个结点
 */
void single_link_del_Kth(SingleLinkNode **pHead, int k);
/**
 *  求链表的中间结点
 */
SingleLinkNode *single_link_middle(SingleLinkNode **pHead);

#endif /* single_link_h */
