//
//  main.c
//  struct
//
//  Created by 王显朋 on 2019/6/27.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main_(int argc, const char * argv[]) {
    char s[] = "abc";
    char *t = "sss";
    t = s;
    printf("%s\n", t);
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
