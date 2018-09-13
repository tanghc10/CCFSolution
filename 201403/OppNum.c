//
//  OppNum.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n = 0, i = 0;
    int array[510];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &array[i]);
    qsort(array, n, sizeof(int), cmp);
    int left = 0, right = n - 1;
    int result = 0;
    while (left < right) {
        if (array[left] + array[right] == 0)
        {
            result++;
            left++;
            right--;
        }
        else if (array[left] + array[right] > 0)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    printf("%d\n", result);
    return 0;
}
