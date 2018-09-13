//
//  NumOrder.c
//  test
//
//  Created by 汤汇川 on 2018/9/13.
//  Copyright © 2018年 汤汇川. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node
{
    int num;
    struct _Node* next;
}Node;

int counter[1010];  // count[i] 表示:数字i出现的次数
Node* result[1010]; // result[i] 表示:出现次数为i的数字组成的链表

int main()
{
    int i = 0;
    // init
    for(i = 0; i < 1010; i++)
    {
        counter[i] = 0;
        result[i] = NULL;
    }
    // read
    int n = 0;
    scanf("%d", &n);
    int temp = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        counter[temp]++;    // 数字temp的出现次数++
    }
    
    // 把数字出现的次数插入到出现次数的链表中
    // 如：数字3出现了4次，则在result[4]插入一个：
    // num:3 next:NULL的节点
    for(i = 0; i < 1010; i++)
    {   // 从小到大遍历，为了保证小的数字的节点在大的数字的节点之前
        if (counter[i] != 0)
        {
            Node* node = (Node*)malloc(sizeof(Node));
            node->num = i;
            node->next = NULL;
            if (result[counter[i]] == NULL) // 如果没有出现次数相同的，则直接插入
                result[counter[i]] = node;
            else
            {   // 有相同出现次数的数字，插入到链表尾部
                Node* pNode = result[counter[i]];
                while (pNode->next) {
                    pNode = pNode->next;
                }
                pNode->next = node;
            }
        }
    }
    
    for(i = 1009; i > 0; i--)
    {   // 从出现次数大的往出现次数小的方向遍历
        if (result[i] != NULL)
        {
            Node* pNode = result[i];
            while (pNode) {
                printf("%d %d\n", pNode->num, i);
                pNode = pNode->next;
            }
        }
    }
    return 0;
}
