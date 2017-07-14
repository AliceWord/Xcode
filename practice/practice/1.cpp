//
//  1.cpp
//  practice
//
//  Created by 蒋丽婷 on 2017/3/12.
//  Copyright © 2017年 蒋丽婷. All rights reserved.
//

#include "1.hpp"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    int a;
    Node *next;
};
void insert(Node *p,int b)
{
    Node *q;
    while(p->next!=NULL&&p->next->a<b)
        p=p->next;
    q=(Node*)malloc(sizeof(Node));
    q->a=b;
    q->next=p->next;
    p->next=q;
}
int main()
{
    int n,b,c,s;
    Node *head,*p,*q;
    head=(Node*)malloc(sizeof(Node));
    while(~scanf("%d",&n))
    {
        head->next=NULL;
        s=0;
        while(n--)
        {
            // p=head;
            scanf("%d",&b);
            insert(head,b);
        }
        p=head->next;
        while(p->next!=NULL)
        {
            q=p->next;
            c=p->a+q->a;
            s+=c;
            head->next=q->next;
            free(p);
            free(q);
            insert(head,c);
            p=head->next;
        }
        printf("%d\n",s);
    }
    return 0;
}
