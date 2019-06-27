//
//  dlink.c
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/23.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include "dlink.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main_dlink (int argc, char *argv[]) {
    //初始化方式一
    DLink dlink1 = {0};
    DlinkNode *dnode1;
    dlink_init(&dlink1);
    dlink_insert_before_head(&dlink1, NULL, 11);
    dlink_insert_before_head(&dlink1, NULL, 12);
    dlink_insert_before_head(&dlink1, NULL, 14);
    dlink_insert_before_head(&dlink1, NULL, 15);
    //dlink_dump(&dlink1);
    dnode1 = dlink_delete_tail(&dlink1);
    dlink_insert_before_head(&dlink1, dnode1, 18);
    //dlink_destroy(&dlink1);
    dlink_lru(&dlink1, 11);
    dlink_lru(&dlink1, 14);
    dlink_lru(&dlink1, 12);
    dlink_dump(&dlink1);
    
    //初始化方式二
    DLink *dlink2;
    DlinkNode *dnode2;
    dlink2 = dlink_init(NULL);
    dlink_insert_before_head(dlink2, NULL, 11);
    dlink_insert_before_head(dlink2, NULL, 12);
    dlink_insert_before_head(dlink2, NULL, 14);
    dlink_insert_before_head(dlink2, NULL, 15);
    //dlink_dump(dlink2);
    dnode2 = dlink_delete_tail(dlink2);
    dlink_insert_before_head(dlink2, dnode2, 18);
    //dlink_destroy(dlink2);
    dlink_lru(dlink2, 11);
    dlink_lru(dlink2, 14);
    dlink_lru(dlink2, 12);
    dlink_dump(dlink2);
    return 0;
}

/**
 *  双链表初始化
 */
DLink *dlink_init(DLink *dlink) {
    if (dlink == NULL) {
        dlink = (DLink *)malloc(sizeof(DLink));
    }
    dlink->_size = 0;
    dlink->head = NULL;
    dlink->tail = NULL;
    return dlink;
}
/**
 *  删除链表
 */
void dlink_destroy(DLink *dlink) {
    DlinkNode *dnode, *pnode;
    if (dlink && dlink->_size > 0) {
        dnode = dlink->head;
        while (dnode) {
            pnode = dnode;
            free(pnode);
            dnode = dnode->next;
            dlink->_size--;
        }
        //memset(dlink, 0, sizeof(DLink));
        dlink->head = NULL;
        dlink->tail = NULL;
    }
}
/**
 *  在表头前插入节点
 *
 */
int dlink_insert_before_head(DLink *dlink, DlinkNode *dnode, int data) {
    if (dlink == NULL) {
        return -1;
    }
    if (dnode == NULL) {
        if ((dnode = (DlinkNode *)malloc(sizeof(DlinkNode))) == NULL) {
            return -1;
        }
    }
    dnode->_data = data;
    dnode->next = NULL;
    dnode->prev = NULL;
    
    if (dlink->_size == 0) {
        dlink->head = dnode;
        dlink->tail = dnode;
    } else {
        dnode->next = dlink->head;
        dlink->head->prev = dnode;
        dlink->head = dnode;
    }
    dlink->_size++;
    return 0;
}
/**
 *  删除尾节点
 */
DlinkNode *dlink_delete_tail(DLink *dlink) {
    DlinkNode *dnode = dlink->tail;
    if (dlink->_size == 0) {
        return NULL;
    } else if (dlink->_size == 1) {
        dlink->head = NULL;
        dlink->tail = NULL;
    } else if (dlink->_size > 1) {
        dlink->tail = dlink->tail->prev;
        dlink->tail->next = NULL;
    }
    dlink->_size--;
    dnode->next = NULL;
    dnode->prev = NULL;
    return dnode;
}
/**
 *  删除指定节点
 */
DlinkNode *dlink_delete_node(DLink *dlink, DlinkNode *dnode) {
    if (dlink == NULL || dnode == NULL) {
        return NULL;
    }
    if (dlink->head == dnode) {
        dlink->head = dlink->head->next;
        //if (dlink->tail != dnode) {
        //    dlink->head->prev = NULL;
        //}
    } else if (dlink->tail == dnode) {
        dlink->tail = dlink->tail->prev;
        dlink->tail->next = NULL;
    } else {
        dnode->prev->next = dnode->next;
        dnode->next->prev = dnode->prev;
    }
    dnode->next = NULL;
    dnode->prev = NULL;
    dlink->_size--;
    
    if (dlink->_size == 0) {
        dlink->head = NULL;
        dlink->tail = NULL;
    }
    return dnode;
}
/**
 *  查找指定值的节点
 */
DlinkNode *dlink_search(DLink *dlink, int data) {
    DlinkNode *dnode;
    if (dlink == NULL || dlink->_size == 0) {
        return NULL;
    }
    dnode = dlink->head;
    while (dnode) {
        if (dnode->_data == data) {
            return dnode;
        }
        dnode = dnode->next;
    }
    return NULL;
}
/**
 *  dump
 */
void dlink_dump(DLink *dlink) {
    DlinkNode *dnode;
    int n = 0;
    if (dlink == NULL || dlink->_size == 0) {
        printf("error: link empty\n");
    }
    dnode = dlink->head;
    while (dnode) {
        printf("[%d] = %d\n", n++, dnode->_data);
        dnode = dnode->next;
    }
}
/**
 *  有序链表实现lru(最近最少使用)算法
    描述：1 查找链表，在链表中：删除该节点，在表头插入该节点
         2 查找链表，不在表中
            1）表未满：在表头插入
            2）表已满：删除表尾节点，在表头插入
 */
DlinkNode *dlink_lru(DLink *dlink, int data) {
    DlinkNode *dnode;
    if (dlink == NULL) {
        return NULL;
    }
    if ((dnode = dlink_search(dlink, data)) != NULL) {
        dlink_delete_node(dlink, dnode);
    } else if (dlink->_size >= 5) {
        dnode = dlink_delete_tail(dlink);
    }
    dlink_insert_before_head(dlink, dnode, data);
    return dnode;
}
