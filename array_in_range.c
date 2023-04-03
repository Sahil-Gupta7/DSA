//Printing elements of array in given range
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,temp,n,a,b,x,y,c=0; //Variable Declaration
    int *p;
    int s[100];
    printf("Enter Number of Elements for Array : ");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter Values : ");
        scanf("%d",&p[i]); //Taking input in an array
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]>p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    s[i]=p[i];
    printf(" Enter Value of a : ");
    scanf("%d",&a);
    printf(" Enter Value of b : ");
    scanf("%d",&b);
    for(i=0;i<n;i++)
    {
        if(s[i]==a) x=i;
        if(s[i]==b) y=i;
    }
    for(i=x;i<=y;i++) //Loop to print elements in give range
    {
        printf("%d\t",s[i]); 
        c=c+1;
    }
    printf("\n No. of Elements : %d\n",c); //Printing Statement
    return 0;
}