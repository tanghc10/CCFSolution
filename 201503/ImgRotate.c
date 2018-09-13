//
//  ImgRotate.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>

int n, m;
int matrix[1010][1010];

void readData()
{
    scanf("%d %d", &n, &m);
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main()
{
    readData();
    int i = 0, j = 0;
    for(i = m - 1; i >= 0; i--)
    {
        for(j = 0; j < n; j++)
            printf("%d ", matrix[j][i]);
        printf("\n");
    }
    return 0;
}
