//Program to print next greatest integer
#include<stdio.h>
int main()
{
    int a[100],i,n,j,ng; //Variable Declaration
    printf("Enter Number of Elements for Array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Values : ");
        scanf("%d",&a[i]); //Taking input
    }
    for(i=0;i<n;i++) //Beginning of loop
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j]) ng=-1; //if statement to so=tore NGE
            else if(a[j]>a[i]) 
            {
                ng=a[j]; 
                break;
            }
        }
        printf(" Element : %d\tNGE : %d\n",a[i],ng); //Printing Statement
    }
    return 0;
}