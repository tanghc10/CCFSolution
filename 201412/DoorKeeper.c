//
//  DoorKeeper.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0, temp = 0;
    scanf("%d", &n);
    int counter[1010];
    memset(counter, 0, sizeof(int) * 1010);
    while (n--) {
        scanf("%d", &temp);
        counter[temp]++;
        printf("%d ", counter[temp]);
    }
    return 0;
}
