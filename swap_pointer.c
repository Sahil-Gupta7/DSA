#include <stdio.h>
// function to swap the two numbers
void swap(int *x,int *y)
{
    int t;
     t   = *x;
    *x   = *y;
    *y   =  t;
}

int main()
{
    int num1,num2;

    printf(" Enter the Value of num1 : ");
    scanf("%d",&num1);
    printf(" Enter the Value of num2 : ");
    scanf("%d",&num2);

    //displaying numbers before swapping
    printf("\n\tBefore Swapping :\n Num1 : %d\t\t Num2 : %d\n",num1,num2);

    //calling the user defined function swap()
    swap(&num1,&num2);

    //displaying numbers after swapping
    printf("\t After  Swapping :\n Num1 : %d\t\t Num2 : %d\n",num1,num2);

    return 0;
}