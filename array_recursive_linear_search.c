#include <stdio.h>
#include <stdlib.h>
int linearsearch(int arr[], int size, int x)
{
    int rec;
    size--;
    if (size >= 0)
    {
        if (arr[size] == x)
            return size;
        else
            rec = linearsearch(arr, size, x);
    }
    else
        return -1;
    return rec;
}

int main(void)
{
    printf(" Enter the Number of Elements you want to Enter : ");
    int n, *arr, i, s, index;
    scanf("%d", &n);
    printf("\tEnter the Elements : \n");
    arr = (int *)malloc(n * sizeof(int));
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
    index = linearsearch(arr, n, s);
    if (index != -1)
        printf(" Element was FOUND at '%d' Position\n", index+1);
    else
        printf(" Element was NOT FOUND in the given Array ");
    return 0;
}