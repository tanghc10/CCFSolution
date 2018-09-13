//
//  ArrayCut.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>

int n;
int array[1010];

void readData()
{
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

int main()
{
    readData();
    int pre_num = 0;
    int result = 0;
    int i = 0;
    for (; i < n; i++)
    {
        if (i == 0)
        {
            pre_num = array[i];
            result++;
        }
        else
        {
            if (array[i] != pre_num)
            {
                result++;
                pre_num = array[i];
            }
        }
    }
    printf("%d\n", result);
    return 0;
}
