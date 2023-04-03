#include <stdio.h>
int main(void)
{
    printf(" Enter the Number of Elements you want to Enter : ");
    int n, i, c = 0;
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
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= n / 2)
        {
            c++;
        }
    }
    printf("\n\n Numbers which are more than or equal to %d (n/2) are appeared '%d' times in the given Array", n / 2, c);
    return 0;
}