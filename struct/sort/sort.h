//
//  sort.h
//  struct
//
//  Created by 王显朋 on 2019/9/10.
//  Copyright © 2019 wongxp. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>

void bubble_sort(int a[], int n);
void insertion_sort(int a[], int n);
void selection_sort(int a[], int n);
void merge_sort(int [], int, int);
void quick_sort(int [], int, int);
int find_kth(int [], int, int, int);
void print_array(int a[], int n);

#endif /* sort_h */
