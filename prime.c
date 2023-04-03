#include<stdio.h>
int main()
{
    int n,i,flag=0;
    printf("\n Enter A Positive Number : ");
    scanf("%d",&n);
    if(n==1) printf("\n Number Is NEITHER PRIME nor COMPOSITE\n");
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0) 
        {
            flag=1;
            break;
        }
    }
    if(flag==0) printf("\n Number is PRIME\n");
    else printf("\n Number is COMPOSITE\n");
    return 0;
}