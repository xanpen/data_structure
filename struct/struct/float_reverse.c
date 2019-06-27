//
//  float_reverse.c
//  c_data_structure
//
//  Created by 王显朋 on 2019/6/22.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//
//void itoaa(double, char s[], int m);
//int mainfloat (int argc, char *argv[]) {
//    char s[100000];
//    itoaa(2019.1234, s, 4);
//    
//    printf("%s", s);
//    return 0;
//}
//
//
//void itoaa(double f , char s[], int m) {
//
//    long n = (long)floor(f*pow(10, m));
//    
//    int i = 0;
//    do {
//        s[i++] = (n % 10) + '0';
//    } while ((n /= 10) > 0);
//    
//    s[i] = '\0';
//    
//    int sum1 = 0 ,sum2 = 0;
//    for (int j=0; s[j] != '\0'; j++) {
//        if (j < m) {
//            sum1 = sum1 * 10 + (s[j] - '0');
//        } else {
//            sum2 = sum2 * 10 + (s[j] - '0');
//        }
//    }
//    
//    double ff = sum2 + (sum1 / pow(10, 4));
//    printf("%.4f\n", ff);
//}
