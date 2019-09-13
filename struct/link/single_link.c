//
//  single_link.c
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/25.
//  Copyright © 2019年 wongxp. All rights reserved.
//
/**
 *
 * 1) 单链表反转
 * 2) 链表中环的检测
 * 3) 两个有序的链表合并
 * 4) 删除链表倒数第 n 个结点
 * 5) 求链表的中间结点
 *
 */

#include "single_link.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main_single_link(int argc, char *argv[]) {
    SingleLinkNode *head = NULL;
    single_link_insert_node(&head, 11);
    single_link_insert_node(&head, 12);
    single_link_insert_node(&head, 13);
    single_link_insert_node(&head, 14);
    single_link_insert_node(&head, 15);
    //single_link_dump(&head);
    single_link_reverse(&head);
    printf("single link middle node: %d\n", single_link_middle(&head)->data);
    printf("single link is cyclic or not: %d\n", single_link_is_cyclic(&head));
    single_link_del_Kth(&head, 2);
    single_link_dump(&head);
    
    //make circle
    SingleLinkNode n5 = {5, NULL};
    SingleLinkNode n4 = {4, &n5};
    SingleLinkNode n3 = {3, &n4};
    SingleLinkNode n2 = {2, &n3};
    SingleLinkNode n1 = {1, &n2};
    SingleLinkNode *h = &n1;
    n5.next = &n3;
    printf("single link is cyclic or not: %d\n", single_link_is_cyclic(&h));
    
    //两个有序链表的合并
    printf("-----------------两个有序链表的合并:\n");
    SingleLinkNode *la = NULL, *lb = NULL;
    single_link_insert_node(&la, 100);
    single_link_insert_node(&la, 45);
    single_link_insert_node(&la, 44);
    single_link_insert_node(&la, 14);
    single_link_insert_node(&la, 2);
    single_link_insert_node(&lb, 999);
    single_link_insert_node(&lb, 14);
    single_link_insert_node(&lb, 13);
    single_link_insert_node(&lb, 12);
    single_link_insert_node(&lb, 8);
    SingleLinkNode *l = single_link_merge(la, lb);
    single_link_dump(&la);
    printf("---------------------------------\n");
    single_link_dump(&lb);
    printf("---------------------------------\n");
    single_link_dump(&l);
    
    return 0;
}

/**
 *  在头结点前插入新节点
 *
 */
void single_link_insert_node(SingleLinkNode **pHead, int data) {
    SingleLinkNode *slNode;
    if (!pHead) {
        return;
    }
    if ((slNode = (SingleLinkNode *)malloc(sizeof(SingleLinkNode))) == NULL) {
        return;
    }
    slNode->data = data;
    slNode->next = *pHead;
    *pHead = slNode;
}
/**
 *  dump single link
 */
void single_link_dump(SingleLinkNode **pHead) {
    SingleLinkNode *slNode = *pHead;
    int idx = 0;
    if (!pHead) {
        return;
    }
    while (slNode) {
        printf(" [%d] = %d\n", idx++, slNode->data);
        slNode = slNode->next;
    }
}
/**
 *  *pSrc头结点 移动到 *pDest头结点
 */
void single_link_move_node(SingleLinkNode **pDest, SingleLinkNode **pSrc) {
    if (!pSrc || !*pSrc) {
        return;
    }
    SingleLinkNode *slNode = *pSrc;
    *pSrc = slNode->next;
    slNode->next = *pDest;
    *pDest = slNode;
}
/**
 *  翻转单链表，空间复杂度O(1)
 */
void single_link_reverse (SingleLinkNode ** pHead) {
    if (!pHead || !(*pHead)) {
        return;
    }
    SingleLinkNode *prev = NULL;
    SingleLinkNode *current = *pHead;
    SingleLinkNode *next;
    while (current) {
        next = current->next;
        if (next == NULL) {
            *pHead = current;
        }
        current->next = prev;
        prev = current;
        current = next;
    }
}
/**
 *  链表中环的检测
 */
bool single_link_is_cyclic(SingleLinkNode **pHead) {
    if (!pHead || *pHead == NULL) {
        return false;
    }
    SingleLinkNode *pSlow, *pFast;
    pSlow = pFast = *pHead;
    while (pFast != NULL && pFast->next != NULL) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
        if (pSlow == pFast) {
            return true;
        }
    }
    return false;
}
/**
 *  两个有序的链表合并
 */
SingleLinkNode *single_link_merge(SingleLinkNode *la, SingleLinkNode *lb) {
    SingleLinkNode dummy;
    SingleLinkNode *tail = &dummy;
    while (true) {
        if (!la) {
            tail->next = lb;
            break;
        } else if (!lb) {
            tail->next = la;
            break;
        }
        
        if (la->data <= lb->data) {
            single_link_move_node(&(tail->next), &la);
        } else {
            single_link_move_node(&(tail->next), &lb);
        }
        tail = tail->next;
    }
    return dummy.next;
}
/**
 *  删除链表倒数第 k 个结点
 */
void single_link_del_Kth(SingleLinkNode **pHead, int k) {
    if (!pHead || *pHead == NULL) {
        return;
    }
    if (k <= 0) {
        printf("error: k <= 0");
        return;
    }
    SingleLinkNode *pSlow, *pFast, *prev = NULL;
    pSlow = pFast = *pHead;
    while (k > 1) {
        pFast = pFast->next;
        if (pFast == NULL) {
            printf("error: single link size less than k");
            return;
        }
        k--;
    }
    while (pFast->next) {
        pFast = pFast->next;
        prev = pSlow;
        pSlow = pSlow->next;
    }
    //prev=null 表示*pHead就是倒数第k节点
    if (prev == NULL) {
        *pHead = (*pHead)->next;
    } else {
        prev->next = pSlow->next;
    }
    free(pSlow);
}
/**
 *  求链表的中间结点
 */
SingleLinkNode *single_link_middle(SingleLinkNode **pHead) {
    if (pHead == NULL || *pHead == NULL) {
        return NULL;
    }
    SingleLinkNode *pSlow, *pFast;
    pSlow = pFast = *pHead;
    while (pFast && pFast->next) {
        pFast = pFast->next->next;
        pSlow = pSlow->next;
    }
    return pSlow;
}
