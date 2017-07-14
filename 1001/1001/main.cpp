//
//  main.cpp
//  1001
//
//  Created by 蒋丽婷 on 16/7/10.
//  Copyright © 2016年 蒋丽婷. All rights reserved.
//

#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int a[200],b[10];
int l;
int m;//小数位数
void count(int t)
{
    int k,m,temp;
    int ll=l;//乘数长度
    int L=0;//每次乘法后a的长度
    int c[200];
    for (int i=1; i<t; i++)//t次幂
    {
        for (int g=0; g<l; g++) {
            c[g]=a[g];
        }
        memset(a,0,sizeof(a));
        for (int j=0; j<ll; j++ )//b
        {
        
            k=0;
            for (int k=0; k<l; k++ )//a
            {
                temp=c[k]*b[j]+a[k+j];
                if((temp)>9)
                {
                    a[k+j]=temp%10;
                    a[k+j+1]+=temp/10;
                    L=k+j+1;
                }
                else
                {
                    a[k+j]=temp;
                    L=k+j;
                }
            }
        }
        l=L+1;
//        int x=0;
//        while(x<l)
//            printf("%d",a[x++]);
//        printf("\n");
    }
}

void out(int d)
{
    int i,q=0,p=0;
    m=m*d;
    //计算前导0个数
    i=l-1;
    while(i>=m&&i>=0&&a[i--]==0)
        p++;
    //计算尾部0个数
    i=0;
    while(i<m&&i<l&&a[i++]==0)
        q++;
    
    for(i=l-p-1;i>=q;i--)
    {
        if(i>m-1)//整数部分
          printf("%d",a[i]);
        else if(i==m-1)
        {
            if(m==q)//结果为整数
                break;
            else
                printf(".%d",a[i]);
        }
        else//小数部分
            printf("%d",a[i]);
    }
    printf("\n");

}
int main()
{
    int n,i,k;
    char s[10];
    while(scanf("%s%d",s,&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        l=0;
        l=strlen(s);
        m=0;
        for (i=l-1,k=0; i>=0; i--) {
            if(s[i]!='.')
            {
                a[k]=s[i]-'0';
                b[k++]=a[k];
            }
            else
            {
                m=k;
                l--;
            }
        }
        count(n);
        out(n);
//        i=0;
//        i=l-1;
//        while(i>=0)
//            printf("%d",a[i--]);
//        printf("\n");
    }
   
    return 0;
}
