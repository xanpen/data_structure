//
//  array_queue.c
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/10.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN  5

static int var[MAXLEN];
static int head = 0;
static int tail = 0;

void enqueue(int c);
int dequeue(void);
void list(void);

int main_arrayqueue (int argc, char *argv[]) {
    enqueue('a');
    enqueue('b');
    enqueue('c');
    enqueue('d');
    dequeue();
    dequeue();
    enqueue('e');
    enqueue('f');
    list();
    //printf("dequeue:%c\n", dequeue());
    return 0;
}

//入队
void enqueue(int c) {
    if (tail >= MAXLEN) {
        if (head == 0) {
            printf("error: queue is full\n");
        } else {
            for (int i = head; i < tail; i++) {
                var[i-head] = var[i];
            }
            tail -= head;
            head = 0;
        }
    } else {
        var[tail++] = c;
    }
}
//出队
int dequeue(void) {
    if (head == tail) {
        printf("error:queue is empty\n");
        return -1;
    } else {
        return var[head++];
    }
}
//遍历队列
void list(void) {
    int i;
    if (head != tail) {
        for (i = head; i != tail; i++) {
            printf("%c\n", var[i]);
        }
    }
}
