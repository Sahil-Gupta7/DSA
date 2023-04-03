//WAP to read an array of integers and search for an element using Binary Search
#include <stdio.h>
int main(void)
{
    printf("Enter the number of elements you want to enter : ");
    int n, i, s, f = 0, u, m, l = 0;
    scanf("%d", &n);
    printf("\tEnter the Elements : \n");
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("\t\t");
        scanf("%d", &arr[i]);
    }
    printf(" The Entered Elements of the Array are : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n Enter the Element to be Searched : ");
    scanf("%d", &s);
    u = n - 1;
    l = 0;
    while (u >= 1)
    {
        m = l + (u - 1) / 2;

        if (arr[m] == s)
        {
            printf(" Element '%d' was FOUND at '%d' Position \n", s, m+1);
            f = 1;
            break;
        }
        else if (arr[m] > s)
        {
            u = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    if (f == 0)
    {
        printf(" Element '%d' was NOT FOUND in the given Array \n", s);
    }
    return 0;
}