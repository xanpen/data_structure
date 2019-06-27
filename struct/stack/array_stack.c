//
//  array_stack.c
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/10.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN  100

static char var[MAXLEN];
static int sp = 0;

int is_legal(char *s);

int main_arraystack(int argc, char *argv[]) {
    char *s = "{[ 7 + (77*7)] + 8}";
    printf("s : %d\n", is_legal(s));
    return 0;
}

//利用栈结构判别括号配对是否合法
int is_legal(char *s) {
    void push(char i);
    char pop(void);
    int is_empty(void);
    int i;
    char c;
    for (i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case '[':
            case '(':
            case '{':
                push(s[i]);
                break;
            case ']':
                c = pop();
                if (c != '[') {
                    return -1;
                }
                break;
            case '}':
                c = pop();
                if (c != '{') {
                    return -1;
                }
                break;
            case ')':
                c = pop();
                if (c != '(') {
                    return -1;
                }
                break;
            default:
                break;
        }
    }
    if (is_empty()) {
        return 1;
    } else {
        return -1;
    }
}
//入栈
void push(char i) {
    if (sp >= MAXLEN) {
        printf("error: stack is full");
    } else {
        var[sp++] = i;
    }
}
//出栈
char pop(void) {
    if (sp <= 0) {
        printf("error: stack is empty");
        return -1;
    } else {
        return var[--sp];
    }
}
//is_empty
int is_empty(void) {
    return (sp <=0) ? 1 : 0;
}
//清空栈
void clearup(void) {
    sp = 0;
}
