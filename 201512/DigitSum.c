//
//  DigitSum.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>

int main()
{
    int source_num = 0;
    int result = 0;
    scanf("%d", &source_num);
    while (source_num > 0) {
        result += source_num % 10;
        source_num /= 10;
    }
    printf("%d\n", result);
    return 0;
}
