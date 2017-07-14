#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(int a[])
{
    a[1]=11;
}

int main()
{
    int b[5]={1,2,3,4,5},c=8;
    float f=1.5678e3;
    double d=3.3,dd;
  //  scanf("%d",&b[3]);
    
    c=(int)(float)c;
    
    
    if(f==(float)(double)f)
        d+=1;
    add(b);
    printf("%f\n",d);
    return 0;
}
