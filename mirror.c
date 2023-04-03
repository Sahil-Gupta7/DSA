#include<stdio.h>
int main()
{
    int n,x,m=0;
    printf("\n Enter a Number : ");
    scanf("%d",&n);
    while(n>0)
    {
        x=n%10;
        m=m*10+x;
        n=(n-x)/10;
    }
    printf("\n MIRROR IMAGE : %d\n",m);
    return 0;
} 