#include <stdio.h>
#include <stdlib.h>
void repeating(int a[], int n)
{
    int *count = (int *)calloc(sizeof(int), (n - 2));
    int i;
    printf("\t Repeating Elements are : ");
    for (i = 0; i < n; i++)
    {
        if (count[a[i]] == 1)
            printf("%d\t", a[i]);
        else
            count[a[i]]++;
    }
}
int main()
{
    int a[40];
    int a_n, i;
    printf(" Enter Length of Array : ");
    scanf("%d", &a_n);
    for (i = 0; i < a_n; i++)
    {
        printf(" Enter Element : ");
        scanf("%d", &a[i]);
    }
    repeating(a, a_n);
    return 0;
}