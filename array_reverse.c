// Program to reverse an array
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,n,i; //Declaring Variables
    printf("How many numbers you want to enter: ");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("\nEnter %d Numbers : ",n); //Taking input
        scanf("%d",p+i);
    }
    printf("\nArray in Reverse Order : \n");
    for(i=n-1;i>=0;i--)
    {
        printf(" %d\n",*(p+i)); //Printing Statement
    }
    return 0;
}