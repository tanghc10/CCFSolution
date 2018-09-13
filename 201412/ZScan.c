//
//  ZScan.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>

int n;
int matrix[505][505];

void readData()
{
    scanf("%d", &n);
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main()
{
    readData();
    int down = 0, right = 1;
    int row = 0, col = 0;
        printf("%d ", matrix[row][col]);
    while (!(row == n - 1 && col == n - 1)) {
        // printf("down[%d], right[%d]  ", down, right);
        row += down;
        col += right;
        // printf("row[%d], col[%d] :  ", row, col);
        printf("%d ", matrix[row][col]);
        if (row == 0)
        {
            if (down == 0)
            {
                down = 1;
                right = -1;
            }
            else
            {
                if (col == n - 1)
                {
                    down = 1;
                    right = 0;
                }
                else
                {
                    down = 0;
                    right = 1;
                }
            }
        }
        else if (row == n - 1)
        {
            if (col != 0)
            {
                if (down == 1)
                {
                    down = 0;
                    right = 1;
                }
                else
                {
                    down = -1;
                    right = 1;
                }
            }
        }
        
        if (col == 0)
        {
            if (right == -1)
            {
                if (row == n - 1)
                {
                    down = 0;
                    right = 1;
                }
                else
                {
                    down = 1;
                    right = 0;
                }
            }
            else
            {
                down = -1;
                right = 1;
            }
        }
        else if (col == n - 1)
        {
            if (right == 1)
            {
                right = 0;
                down = 1;
            }
            else if (row != 0)
            {
                down = 1;
                right = -1;
            }
        }
    }
    printf("\n");
    return 0;
}
