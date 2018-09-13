//
//  DateCalculate.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>

int mouth[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isRunYear(int year)
{
    if (year % 400 == 0)
        return 1;
    else
    {
        if (year % 4 == 0 && year % 100 != 0)
            return 1;
    }
    return 0;
}

int main()
{
    int year = 0, day = 0;
    scanf("%d %d", &year, &day);
    int op = isRunYear(year);
    int resMouth = 0;
    int resDay = 1;
    while(day > mouth[op][resMouth])
    {
        day -= mouth[op][resMouth];
        resMouth++;
    }
    resDay = day;
    printf("%d\n%d\n", resMouth+1, resDay);
    return 0;
}
