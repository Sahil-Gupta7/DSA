//Program to take an Array as Input and then print Second Largest and Second Smallest No. in that Array
#include <stdio.h>
int main()
{
    int a[50]; //Declaring Array of size 50
    int i,j,n,temp; //Variable Declaration
    printf("\n Enter No. of Elements : ");
    scanf("%d",&n); //Taking No. of Elements as Input
    for(i=0;i<n;i++)
    { //Taking Input
        printf("\n Enter Element : ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<=a[j]) //If Statement to check and sort array in Descending Order
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp; //Swaping Statements
            }
        }
    }
    printf("\n\t\t SECOND LARGEST ELEMENT : %d",a[1]); //Statemment to Print SECOND LARGEST NO.
    printf("\n\t\t SECOND SMALLEST ELEMENT : %d",a[n-2]); //Statemment to Print SECOND SMALLEST NO.
    return 0;
}