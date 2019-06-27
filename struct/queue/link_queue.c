//
//  link_queue.c
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/11.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include "link_queue.h"
#include <stdio.h>
#include <stdlib.h>

int main_linkqueue (int argc, char *argv[]) {
    Queue *q = queue_new();
    en_queue(q, 22);
    en_queue(q, 33);
    en_queue(q, 44);
    en_queue(q, 55);
    en_queue(q, 11);
    printf("%d\n", de_queue(q));
    printf("%d\n", de_queue(q));
    queue_free(q);
    queue_print(q);
    return 0;
}

QueueNode *queue_node_new(int data) {
    QueueNode *qn = (QueueNode *)malloc(sizeof(QueueNode));
    if (qn) {
        qn->_data = data;
        qn->next = NULL;
    }
    return qn;
}
void queue_node_free(QueueNode *qn) {
    if (qn) {
        free(qn);
    }
}
Queue *queue_new() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q) {
        q->_count = 0;
        q->head = q->tail = NULL;
    }
    return q;
}
void en_queue(Queue *q, int data){
    QueueNode *qn = queue_node_new(data);
    
    if (q->tail == NULL) {
        q->head = q->tail = qn;
    } else {
        q->tail->next = qn;
        q->tail = qn;
    }

    q->_count++;
}

int de_queue(Queue *q){
    int data = -1;
    QueueNode *qn;
    
    if (q->head) {
        qn = q->head;
        data = q->head->_data;
        
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        queue_node_free(qn);
        q->_count--;
    }
    return data;
}
void queue_print(Queue *q){
    QueueNode *iter;
    if (q->head) {
        iter = q->head;
        printf("queue size:%d\n", q->_count);
        printf("queue list:");
        while (iter) {
            printf(" %d ", iter->_data);
            iter = iter->next;
        }
        printf("\n");
    }
}
int queue_size(Queue *q){
    if (q) {
        return q->_count;
    }
    return -1;
}
void queue_free(Queue *q){
    QueueNode *qn;
    QueueNode *iter;
    if (q) {
        iter = q->head;
        while (iter) {
            qn = iter;
            iter = iter->next;
            queue_node_free(qn);
        }
        q->head = q->tail = NULL;
    }
}
