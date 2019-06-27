//
//  min_value_stack.h
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/10.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#ifndef min_value_stack_h
#define min_value_stack_h

struct StackNodeStruct {
    int _data;
    struct StackNodeStruct *next;
    struct StackNodeStruct *nextMinNode;
};
typedef struct StackNodeStruct StackNode;

struct StackStruct {
    int _count;
    StackNode *top;
    StackNode *currentMinNode;
};
typedef struct StackStruct Stack;


Stack *stack_new();
void stack_push(Stack *st, int data);
int stack_pop(Stack *st);
void stack_print(Stack *st);
int stack_min(Stack *st);
void stack_free(Stack *st);
int stack_top(Stack *st);
int stack_size(Stack *st);
int stack_is_empty(Stack *st);
#endif /* min_value_stack_h */
