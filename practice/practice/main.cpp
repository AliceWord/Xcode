#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,flag;
    while(scanf("%d",&n))
    {
        flag=1;
        if(n==1||n==0)
            printf("YES");
        else
        {
            for(int i=2;i<n;i++)
            {
                if(n%i==0)
                {
                    flag=0;
                    printf("NO");
                    break;
                }
            }
            if(flag)
                printf("YES");
        }
        
    }
    
    return 0;
}
