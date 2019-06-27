//
//  min_value_stack.c
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/10.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include "min_value_stack.h"
#include <stdlib.h>
#include <stdio.h>

//最小值栈：使得push pop min等函数的时间复杂度都是O(1)
int main_minvalue (int argc, char *argv[]) {
    Stack *st = stack_new();
    stack_push(st, 99);
    stack_push(st, 88);
    stack_push(st, 111);
    stack_push(st, 3);
    stack_push(st, 66);
    stack_push(st, 12);
    printf("stack min value:%d\n", stack_min(st));
    
    stack_pop(st);
    stack_pop(st);
    stack_pop(st);
    stack_print(st);
    
    return 0;
}

//新节点
StackNode *stack_node_new(int data) {
    StackNode *sn;
    if ((sn = (StackNode *)malloc(sizeof(StackNode))) != NULL) {
        sn->_data = data;
        sn->next = sn->nextMinNode = NULL;
    }
    return sn;
}
//释放节点
void stack_node_free(StackNode *sn) {
    if (sn) {
        free(sn);
    }
}
//新stack
Stack *stack_new() {
    Stack *s;
    if ((s = (Stack *)malloc(sizeof(Stack))) != NULL) {
        s->_count = 0;
        s->top = s->currentMinNode = NULL;
    }
    return s;
}

void stack_push(Stack *st, int data) {
    StackNode *sn = stack_node_new(data);
    st->_count++;
    sn->next = st->top;
    st->top = sn;
    
    if (st->currentMinNode == NULL) {
        st->currentMinNode = sn;
    } else if (sn->_data < st->currentMinNode->_data) {
        sn->nextMinNode = st->currentMinNode;
        st->currentMinNode = sn;
    }
}
int stack_pop(Stack *st) {
    StackNode *sn;
    int data = -1;
    
    if (st->top) {
        if (st->top->nextMinNode != NULL) {
            st->currentMinNode = st->top->nextMinNode;
        }
        data = st->top->_data;
        sn = st->top;
        st->top = st->top->next;
        stack_node_free(sn);
    }
    
    return data;
}
void stack_print(Stack *st) {
    StackNode *sn;
    if (st) {
        printf("stack size:%d\n", st->_count);
        printf("stack min:%d\n", stack_min(st));
        printf("stack list:");
        sn = st->top;
        while (sn) {
            printf("%d ", sn->_data);
            sn = sn->next;
        }
        printf("\n");
    }
}
int stack_min(Stack *st) {
    if (st->top) {
        return st->currentMinNode->_data;
    }
    return -1;
}
void stack_free(Stack *st) {
    StackNode *sn;
    StackNode *iter;
    if (st) {
        iter = st->top;
        while (iter) {
            sn = iter;
            iter = iter->next;
            stack_node_free(sn);
        }
    }
}
int stack_top(Stack *st) {
    if (st->top) {
        return st->top->_data;
    }
    return -1;
}
int stack_size(Stack *st) {
    if (st) {
        return st->_count;
    }
    return -1;
}
int stack_is_empty(Stack *st) {
    if (st->top == NULL) {
        return 1;
    }
    return 0;
}
