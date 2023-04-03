#include<stdio.h>
int main()
{
    int a=77;
    int *ptr=&a;
    printf("\n Address of Pointer : %p",&ptr);
    printf("\n Address of a : %p",&a);
    printf("\n Address of a : %x",ptr);
    printf("\n Value of a : %d",*ptr);
    printf("\n Value of a : %d",a);
    return 0;
}