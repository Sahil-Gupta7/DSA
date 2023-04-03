#include <stdio.h>
#include <conio.h>
int main()
{
    int a[10];
    int n, i, j, temp;
    printf(" Enter the Range : ");
    scanf("%d", &n);
    printf("\n"); 
    for (i = 0; i < n; i++)
    {
        printf(" Enter the Number : ");
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\n SORTED LIST : ");
    for (i = 0; i < n; i++)
        printf(" %d   ", a[i]);
    return 0;
}