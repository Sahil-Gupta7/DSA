//Program to search an element and its location
#include<stdio.h>
int main()
{
    int a[100],i,n,c=0,r;
    printf("Enter size of the array : ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter elements in array : ");
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d", &r);
    for(i=0; i<n; i++)
    {
        if(a[i]==r)
        {
            c=i+1;
            printf(" Element Found \n");
            printf(" Location : %d\n",c);
        }
    }
    if(c==0) printf(" Element Not Found");
    return 0;
}