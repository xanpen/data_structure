//
//  link_queue.h
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/11.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#ifndef link_queue_h
#define link_queue_h

struct QueueNodeStruct {
    int _data;
    struct QueueNodeStruct *next;
};
typedef struct QueueNodeStruct QueueNode;

struct QueueStruct {
    int _count;
    QueueNode *head;
    QueueNode *tail;
};
typedef struct QueueStruct Queue;

Queue *queue_new();
void en_queue(Queue *q, int data);
int de_queue(Queue *q);
void queue_print(Queue *q);
int queue_size(Queue *q);
void queue_free(Queue *q);
#endif /* link_queue_h */
