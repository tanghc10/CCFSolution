//
//  160402.c
//  test
//
//  Created by 汤汇川 on 2018/9/10.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>

int matrix[15][10];
int blocks[4][4];
int left_margin = 15;
int top_margin = 15;

void readData()
{
    
    for(int i = 0; i < 15; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            scanf("%d", &blocks[i][j]);
        }
    }
    scanf("%d", &left_margin);
    left_margin--;
}

int main()
{
    readData();
    //printf("left_margin [%d]\n", left_margin);
    for(int i = 0; i < 4; ++i)
    {
        int hight = 0, blankNum = 0;
        int k = 0, j = 0;
        // printf("line [%d]\n", left_margin + i);
        for(j = 0; j < 15; j++)
        {
            if (matrix[j][left_margin+i] == 1)
            {
                break;
            }
        }
        hight = 15 - j;
        
        for(k = 0; k < 4; ++k)
        {
            if (blocks[3-k][i] == 1)
                break;
        }
        blankNum = k;
        int current_margin = 11 + blankNum - hight;
        if (blankNum == 4)
            current_margin = 14;
        // printf("hight=%d, blanknum=%d, currentmargin=%d\n", hight, blankNum, current_margin);
        top_margin = top_margin < current_margin ? top_margin : current_margin;
    }
    
    // printf("top_margin = %d, left_margin = %d\n", top_margin, left_margin);
    
    for (int i = 0; i < 4; ++i)
    {
        if (top_margin + i > 14)
        {
            break;
        }
        for (int j = 0; j < 4; ++j)
        {
            if (left_margin + j >= 10)
                break;
            matrix[top_margin + i][left_margin + j] += blocks[i][j];
        }
    }
    
    for( int i = 0; i < 15; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
