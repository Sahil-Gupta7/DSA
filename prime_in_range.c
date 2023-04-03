#include<stdio.h>
int main()
{
    int a,b,flag=0,i,j;
    printf("\n Enter Starting Range : ");
    scanf("%d",&a);
    printf("\n Enter Ending Range : ");
    scanf("%d",&b);
    printf("\n PRIME NUMBERS between %d and %d are :- ",a,b);
    for(i=a;i<=b;i++)
    {
        if(i==1) printf("\n 1 is neither Prime nor Composite");
        else if(i==2) printf("\n 2 is Prime Number");
        else
        {
            for(j=2;j<=i/2;j++)
            {
                flag=0;
                if(i%j==0) 
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) printf("\n %d is Prime Number",i);
        }
    }
    return 0;
}