//Program to take an Array of 0 and 1 as Input and then Print all Zeroes followed by all One using Single Loop
#include<stdio.h>
int main()
{
    int a[50]; //Declaring Array
    int i,n,temp,zero=0,p=0; //Variable Declaration
    printf("\n Enter No. of Elememts : ");
    scanf("%d",&n); //Taking No. of Elements as Input
    for(i=0;i<n;i++)
    { //Loop to take Elements as Input
        printf("\n Enter Elements as 0 nd 1 only : ");
        scanf("%d",&a[i]); //Taking Input
        if(a[i]==0 || a[i]==1) p=p+1; //Counter 
    }
    if(p!=n) printf("\n WRONG ENTRY!! Enter No. as 0 nd 1 ONLY.."); //If statement to check whether Elements taken Input are 0 or 1 Only
    else
    {
        printf("\n\t SORTED LIST : \n");
        for(i=0;i<n;i++)
        {
            if(a[i]==0) //If statement to Check for 0
            { 
                temp=a[i];
                a[i]=a[zero];
                a[zero]=temp; //Swaping Statements
                zero+=1;
            }
        }
        for(i=0;i<n;i++)
            printf("%d  ",a[i]); //Printing Statement
    }
    return 0;
}