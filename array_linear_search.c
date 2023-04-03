//WAP to read an array of integers and search for an element using Linear Search
#include <stdio.h>
int main(void)
{
    printf(" Enter the Number of Elements you want to Enter : ");
    int n, s, f = 0, i;
    scanf("%d", &n);
    printf("\tEnter the Elements :\n");
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("\t\t");
        scanf("%d", &arr[i]);
    }
    printf("\n The Entered Elements of the Array are : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n Enter the Element to be Searched : ");
    scanf("%d", &s);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            printf(" Element '%d' was FOUND at '%d' Position \n", s, i+1);
            f = 1;
        }
    }
    if (f == 0)
    {
        printf(" Element '%d' was NOT FOUND in the given Array \n", s);
    }
    return 0;
}