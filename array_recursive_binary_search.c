#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int array[], int start_index, int end_index, int element)
{
    if (end_index >= start_index)
    {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == element)
            return middle;
        if (array[middle] > element)
            return BinarySearch(array, start_index, middle - 1, element);
        return BinarySearch(array, middle + 1, end_index, element);
    }
    return -1;
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
    index = BinarySearch(arr, 0, n - 1, s);
    if (index != -1)
        printf(" Element was FOUND at '%d' Position\n", index+1);
    else
        printf(" Element was NOT FOUND in the given Array ");
    return 0;
}