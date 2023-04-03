//Program to sort an array
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, temp, n; //Variable Declaration
    int *p;
    printf("Enter Number of Elements for Array : ");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) //for loop begin
    {
        printf("Enter Values : ");
        scanf("%d", &p[i]); //Taking input in an array
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i]; //Swapping elements in ascending order
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("Ascending Order : ");
    for (i = 0; i < n; i++)
        printf("%d\t", p[i]); //Printing Statement
    return 0;
}