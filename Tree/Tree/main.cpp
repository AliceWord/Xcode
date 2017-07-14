#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int length;
char s[100];
typedef struct node
{
    char c;
    struct node *left,*right;
}Node;
void creatTree(Node *p,int i)
{
    Node *l,*r;
    p->c=s[i];
    if(s[2*i+1]=='#'||2*i+1>=length)
        p->left=NULL;
    else
    {
        l=(Node*)malloc(sizeof(Node));
        p->left=l;
        creatTree(l,2*i+1);
    }
    if(s[2*i+2]=='#'||2*i+2>=length)
        p->right=NULL;
    else
    {
        r=(Node*)malloc(sizeof(Node));
        p->right=r;
        creatTree(r,2*i+2);
    }
    return ;
}
void xianxu(Node*p,int deep)
{
    int d=deep;
    if(p)
    {
        while(d--)
            printf(" ");
        printf("%c\n",p->c);
        xianxu(p->left,deep+1);
        xianxu(p->right,deep+1);
    }
    return;
}
int main()
{
    
    Node *head;
    scanf("%s",s);
    length=strlen(s);
    head=(Node*)malloc(sizeof(Node));
    creatTree(head,0);
    xianxu(head,0);
    return 0;
}
