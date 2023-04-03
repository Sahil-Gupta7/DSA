#include <stdio.h>
void arrange(int a[], int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)
            count++;
    }
    for (i = 0; i < count; i++)
        a[i] = 0;
    for (i = count; i < n; i++)
        a[i] = 1;
}
void print(int a[], int n)
{
    int i;
    printf("\t Array after Arrangement : ");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}
int main()
{
    int a[40], n, i;
    printf(" Enter Length of Array : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf(" Enter either 0 or 1 : ");
        scanf("%d", &a[i]);
    }
    arrange(a, n);
    print(a, n);
    return 0;
}