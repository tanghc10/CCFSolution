//
//  NeiborPeer.c
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
    int array[1010];
    int result = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    qsort(array, n, sizeof(int), cmp);
    for(i = 0; i < n - 1; i++)
    {
        if (array[i+1] == array[i] + 1)
        {
            result++;
        }
    }
    printf("%d\n", result);
    return 0;
}
