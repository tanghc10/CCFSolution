//
//  Draw.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    int matrix[110][110];
    int i = 0, j = 0;
    for(i = 0; i < 110; i++)
        for (j = 0; j < 110; j++) 
            matrix[i][j] = 0;
    
    int n = 0;
    scanf("%d", &n);
    while (n--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int i = x1, j = y1;
        for (i = x1; i < x2; i++) {
            for(j = y1; j < y2; j++)
                matrix[i][j] = 1;
        }
    }
    int result = 0;
    for(i = 0; i < 110; i++)
    {
        for(j = 0; j < 110; j++)
            if (matrix[i][j] == 1)
                result++;
    }
    printf("%d\n", result);
    return 0;
}
