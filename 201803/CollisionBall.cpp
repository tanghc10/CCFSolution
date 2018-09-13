//
//  180302.cpp
//  test
//
//  Created by 汤汇川 on 2018/9/9.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void quickSort(int* array, int left, int right);

int main()
{
    int num, length, time;
    scanf("%d %d %d", &num, &length, &time);
    int* array = (int *)malloc(sizeof(int) * length);
    int* index = (int *)malloc(sizeof(int) * length);
    int* temp = (int *)malloc(sizeof(int) * length);
    memset(array, 0, sizeof(int) * length);
    memset(index, -1, sizeof(int) * length);
    memset(temp, 0, sizeof(int) * length);
    for(int i = 0; i < num; ++i)
    {
        scanf("%d", &array[i]);
        temp[i] = array[i];
    }
    quickSort(temp, 0, num - 1);
    for(int i = 0; i < num; ++i)
    {
        for(int j = 0; j < num; j++)
        {
            if (array[i] == temp[j])
                index[i] = j;
        }
        array[i] += time;
        bool towardRight = true;
        while (array[i] > length) {
            towardRight = !towardRight;
            array[i] -= length;
        }
        if (towardRight == false){
            array[i] = length - array[i];
        }
    }
    quickSort(array, 0, num - 1);
    for (int i = 0; i < num; i++)
        printf("%d ", array[index[i]]);
    printf("\n");
    return 0;
}

void quickSort(int* array, int left, int right)
{
    if (left < right)
    {
        int i = left, j = right;
        int x = array[i];
        while (i < j) {
            while (i < j && array[j] >= x)
                j--;
            if (i < j)
                array[i++] = array[j];
            
            while (i < j && array[i] <= x)
                i++;
            if (i < j)
                array[j--] = array[i];
        }
        array[i] = x;
        quickSort(array, left, i - 1);
        quickSort(array, i + 1, right);
    }
}
