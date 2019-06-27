//
//  dlink.h
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/23.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#ifndef dlink_h
#define dlink_h
/**
 *  双链表节点
 */
typedef struct DLinkNodeStruct {
    struct DLinkNodeStruct *next;
    struct DLinkNodeStruct *prev;
    int _data;
} DlinkNode;
/**
 *  双链表
 */
typedef struct DLinkStruct {
    int _size;
    DlinkNode *head;
    DlinkNode *tail;
} DLink;

DLink *dlink_init(DLink *dlink);
void dlink_destroy(DLink *dlink);
int dlink_insert_before_head(DLink *dlink, DlinkNode *dnode, int data);
DlinkNode *dlink_delete_tail(DLink *dlink);
DlinkNode *dlink_delete_node(DLink *dlink, DlinkNode *dnode);
DlinkNode *dlink_search(DLink *dlink, int data);
void dlink_dump(DLink *dlink);
DlinkNode *dlink_lru(DLink *dlink, int data);
#endif /* dlink_h */
