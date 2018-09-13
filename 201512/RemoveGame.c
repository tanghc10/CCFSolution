//
//  RemoveGame.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>

int n = 0, m = 0;
int source_matrix[31][31];
int dest_matrix[31][31];

void readData()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &source_matrix[i][j]);
            dest_matrix[i][j] = source_matrix[i][j];
        }
    }
}

int main()
{
    readData();
    
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 看能否向右延伸
            int same_block = 1;
            for (int k = j + 1; k < m; k++)
            {
                if (source_matrix[i][j] != source_matrix[i][k])
                {
                    break;
                }
                same_block++;
                if (same_block == 3)
                {
                    dest_matrix[i][j] = 0;
                    dest_matrix[i][j+1] = 0;
                    dest_matrix[i][j+2] = 0;
                }
                else if (same_block > 3)
                {
                    dest_matrix[i][k] = 0;
                }
            }
            
            // 看能否向下延伸
            same_block = 1;
            for(int k = i + 1; k < n; k++)
            {
                if (source_matrix[i][j] != source_matrix[k][j])
                {
                    break;
                }
                same_block++;
                if (same_block == 3)
                {
                    dest_matrix[i][j] = 0;
                    dest_matrix[i+1][j] = 0;
                    dest_matrix[i+2][j] = 0;
                }
                else if (same_block > 3)
                {
                    dest_matrix[k][j] = 0;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", dest_matrix[i][j]);
        }
        printf("\n");
    }
    
    return  0;
}
