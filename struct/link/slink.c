//
//  slink.c
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/23.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include "slink.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mainslink(int argc, char *argv[]) {
    SlinkHead shead = {NULL};
    SlinkNode lists[10];
    SlinkNode **prev;
    int idx;
    for (idx = 0; idx < 10; idx++) {
        lists[idx]._data = idx;
        lists[idx].next = NULL;
    }
    
    slink_insert_after_head(&shead, &lists[8]);
    slink_insert_after_head(&shead, &lists[7]);
    slink_insert_after_head(&shead, &lists[6]);
    slink_insert_after_head(&shead, &lists[5]);
    slink_insert_after_head(&shead, &lists[1]);
    
    slink_dump(&shead);
    
    prev = slink_search(&shead, 2);
    slink_insert(prev, &lists[2]);
    prev = slink_search(&shead, 3);
    slink_insert(prev, &lists[3]);
    
    slink_dump(&shead);
    printf("mid elem: %d\n", slink_mid_node(&shead)->_data);
    
    slink_reverse(&shead);
    slink_dump(&shead);
    slink_del(&(lists[1].next));
    
    SlinkNode *xnode = slink_kth_node(&shead, 7);
    xnode && printf("倒数第7个结点：%d\n", xnode->_data);
    prev = slink_k_node(&shead, 6);
    prev && printf("倒数第6个结点：%d\n", (*prev)->_data);
    slink_del(prev);
    slink_dump(&shead);
    
    printf("单链表是否存在环:%d\n", slink_is_cyclic(&shead));
    lists[1].next = &lists[5];
    printf("单链表是否存在环:%d\n", slink_is_cyclic(&shead));
    return 0;
}

/**
 *  单链表是否为空
 */
bool slink_is_empty(SlinkHead *shead) {
    return shead->head == NULL;
}
/**
 *  dump
 */
void slink_dump(SlinkHead *shead) {
    SlinkNode *slnode;
    int n = 0;
    if (slink_is_empty(shead)) {
        printf("error: single link is empty");
    } else {
        slnode = shead->head;
        while (slnode) {
            printf("[%d] = %d\n", n++, slnode->_data);
            slnode = slnode->next;
        }
    }
}
/**
 *  insert(任意位置)
 */
void slink_insert(SlinkNode **ppnode, SlinkNode *elem) {
    if (ppnode == NULL) {
        return;
    }
    if (*ppnode) {
        elem->next = *ppnode;
    }
    *ppnode = elem;
}
/**
 *  del（任意位置）
 **/
SlinkNode *slink_del(SlinkNode **ppnode) {
    SlinkNode *slnode;
    if (ppnode == NULL) {
        return NULL;
    }
    //这里需不需要判断呢？
    if (*ppnode == NULL) {
        return NULL;
    }
    slnode = *ppnode;
    *ppnode = (*ppnode)->next;
    slnode->next = NULL;
    return slnode;
}
/**
 * 头结点之后插入
 */
void slink_insert_after_head(SlinkHead *shead, SlinkNode *elem) {
    slink_insert(&shead->head, elem);
}
/**
 *  头结点之后删除
 */
SlinkNode *slink_del_after_head(SlinkHead *shead) {
    return slink_del(&shead->head);
}
/**
 *  search
 */
SlinkNode **slink_search(SlinkHead *shead, int data) {
    if (slink_is_empty(shead)) {
        return NULL;
    }
    SlinkNode **ppnode, *snode;
    for (ppnode = &shead->head, snode = *ppnode; snode && snode->_data < data;
         ppnode = &snode->next, snode = *ppnode) {
        ;
    }
    
    return ppnode;
}
/**
 *  单链表翻转
 */
void slink_reverse(SlinkHead *shead) {
    SlinkHead tmp = {NULL};
    SlinkNode *snode;
    while (!slink_is_empty(shead)) {
        snode = slink_del_after_head(shead);
        slink_insert_after_head(&tmp, snode);
    }
    shead->head = tmp.head;
}
/**
 *  单链表是否有环
 **/
bool slink_is_cyclic(SlinkHead *shead) {
    SlinkNode *pslow, *pfast;
    if (slink_is_empty(shead)) {
        return false;
    }
    pslow = pfast = shead->head;
    while (pslow && pfast ) {
        pslow = pslow->next;
        pfast = (pfast->next) ? pfast->next->next : pfast->next;
        if (pslow == pfast) {
            return true;
        }
    }
    return false;
}
/**
 *  返回中间结点
 */
SlinkNode *slink_mid_node(SlinkHead *shead) {
    SlinkNode *pslow, *pfast;
    if (slink_is_empty(shead)) {
        return NULL;
    }
    pslow = pfast = shead->head;
    while (pfast && pfast->next) {
        pfast = pfast->next->next;
        pslow = pslow->next;
    }
    return pslow;
}
/**
 * 返回倒数第k个结点
 */
SlinkNode *slink_kth_node(SlinkHead *shead, int k) {
    SlinkNode *pslow, *pfast;
    if (slink_is_empty(shead)) {
        return NULL;
    }
    if (k <= 0) {
        return NULL;
    }
    pslow = pfast = shead->head;
    while (k > 0) {
        if (!pfast) {
            return NULL;
        }
        pfast = pfast->next;
        k--;
    }
    while (pfast) {
        pfast = pfast->next;
        pslow = pslow->next;
    }
    return pslow;
}

/**
 * 返回倒数第k个结点
 */
SlinkNode **slink_k_node(SlinkHead *shead, int k) {
    SlinkNode **ppslow, **ppfast, *snode = NULL, *fnode = NULL;
    if (slink_is_empty(shead)) {
        return NULL;
    }
    if (k <= 0) {
        return NULL;
    }
    for (ppfast = &shead->head, fnode = *ppfast; k > 0;
         ppfast = &fnode->next, fnode = *ppfast) {
        if (fnode == NULL) {
            return NULL;
        }
        k--;
    }
    
    ppslow = &shead->head;
    snode = *ppslow;
    while (fnode) {
        fnode = fnode->next;
        ppslow = &snode->next;
        snode = *ppslow;
    }
    return ppslow;
}
