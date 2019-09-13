//
//  sort.c
//  struct
//
//  Created by 王显朋 on 2019/9/10.
//  Copyright © 2019 wongxp. All rights reserved.
//

#include "sort.h"

//Bubble Sort(base on array)
void bubble_sort(int a[], int n) {
    if (n <= 1) {
        return;
    }
    
    for (int i=0; i<n; ++i) {
        //标志位：某次循环没有发生数据交换，说明已经处于满有序度，不需要再进行后续循环了。
        int flag = 0;
        for (int j=0; j<n-i-1; ++j) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

//Insertion Sort(base on array)
void insertion_sort(int a[], int n) {
    if (n <= 1) {
        return;
    }
    
    for (int i = 1; i < n; ++i) {
        //先保存值，后面数据移动的时候会被覆盖
        int value = a[i];
        int j;
        for (j = i - 1; j >= 0; --j) {
            if (a[j] > value) {
                //数据移动
                a[j+1] = a[j];
            } else {
                break;
            }
        }
        //插入数据到合适的位置
        a[j+1] = value;
    }
}

//Selection Sort(base on array)
void selection_sort(int a[], int n) {
    if (n <= 1) {
        return;
    }
    int min_index;
    for (int i = 0; i < n - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (a[i] != a[min_index]) {
            int tmp;
            tmp = a[i];
            a[i] = a[min_index];
            a[min_index] = tmp;
        }
    }
}

//Print array
void print_array(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            printf("%d", a[i]);
        } else {
            printf(",%d", a[i]);
        }
    }
    printf("\n");
}
