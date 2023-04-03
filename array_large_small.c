//Program to find largest and smallest element in array
#include<stdio.h>
int main()
{
    int a[100],i,n,small,large; //declaring variables
    printf(" Enter Number Of Elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf(" Enter Array Elements : "); //taking input
        scanf("%d",&a[i]);
    }
    large=small=a[0]; //storing a number in large and small 
    for(i=0;i<n;i++)
    {
    if(a[i]>large) large=a[i]; //checking for large and small
    if(a[i]<small) small=a[i];
    }
    printf(" SMALLEST NUMBER : %d\n",small); //printing statement
    printf(" LARGEST NUMBER : %d\n",large);
    return 0;
}