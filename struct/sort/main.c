//
//  main.c
//  struct
//
//  Created by 王显朋 on 2019/9/10.
//  Copyright © 2019 wongxp. All rights reserved.
//

#include <stdio.h>
#include "sort.h"

int main (int argc, char *argv[]) {
    
    int bubble_a[] = {4,5,6,3,2,1};
    bubble_sort(bubble_a, 6);
    print_array(bubble_a, 6);
    
    int insertion_a[] = {4,5,6,3,2,1};
    insertion_sort(insertion_a, 6);
    print_array(insertion_a, 6);
    
    int selection_a[] = {4,5,6,3,2,1};
    selection_sort(selection_a, 6);
    print_array(selection_a, 6);
    
    int merge_a[] = {4,5,6,3,2,1,7,8,9,0};
    merge_sort(merge_a, 0, 9);
    print_array(merge_a, 10);
    
    int quick_a[] = {4,5,6,3,2,1,7,8,9,0};
    quick_sort(quick_a, 0, 9);
    print_array(quick_a, 10);
    
    int kth_a[] = {4,2,5,12,3};
    int kth = find_kth(kth_a, 0, 4, 3);
    printf("kth: %d\n", kth);
}
