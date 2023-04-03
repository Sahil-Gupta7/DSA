//Program to take an Array as Input and then Print all Even No. followed by all Odd No.
#include<stdio.h>
int main()
{
    int a[50]; //Declaring Array
    int n,i,j; //Variable Declaration
    printf("\t Enter No. of Elements : ");
    scanf("%d",&n); //Taking No. of Elements as Input
    for(i=0;i<n;i++)
    {// Loop to take Elements as Input
        printf("\n Enter Element a[%d] : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n\n\tSORTED LIST : \n\n");
    for(i=0;i<n;i++)  if(a[i]%2==0) printf("%d  ",a[i]); //Statement to check and Print EVEN NO. first
    for(i=0;i<n;i++)  if(a[i]%2!=0) printf("%d  ",a[i]); //Statement to check and Print ODD NO.
    return 0;
}