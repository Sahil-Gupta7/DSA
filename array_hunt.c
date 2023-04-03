#include <stdio.h>
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
    int n, i, hunt;
    scanf("%d", &n);
    printf("\tEnter the Elements : \n");
    int container[n];
    for (i = 0; i < n; i++)
    {
        printf("\t\t");
        scanf("%d", &container[i]);
    }
    printf(" The Entered Elements of the Array are : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", container[i]);
    }
    printf("\n\n Enter the Element to be Searched : ");
    scanf("%d", &hunt);
    while (BinarySearch(container, 0, n - 1, hunt) != -1)
    {
        hunt *= 3;
    }
    printf(" The Value of Hunt after execution is : %d\n", hunt);
}