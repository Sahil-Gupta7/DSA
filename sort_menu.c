#include <stdio.h>
#include <stdlib.h>
void display(int a[], int n);
void bubble_sort_asc(int a[], int n);
void bubble_sort_desc(int a[], int n);
void selection_sort_asc(int a[], int n);
void selection_sort_desc(int a[], int n);
void insertion_sort_asc(int a[], int n);
void insertion_sort_desc(int arr[], int n);
void heap_sort_asc(int arr[], int n);
void heap_sort_desc(int arr[], int n);
int main()
{
    int n, choice, i;
    char ch[20];
    printf(" Enter No. of Elements you want to Sort : ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("\t Enter %d Element : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n\n\t SORTING MENU : \n");
    printf("\n 1 -> Bubble Sort in Ascending Order");
    printf("\n 2 -> Bubble Sort in Descending Order");
    printf("\n 3 -> Selection Sort in Ascending Order");
    printf("\n 4 -> Selection Sort in Descending Order");
    printf("\n 5 -> Insertion Sort in Ascending Order");
    printf("\n 6 -> Insertion Sort in Descending Order");
    printf("\n 7 -> Heap Sort in Ascending Order");
    printf("\n 8 -> Heap Sort in Descending Order");
    printf("\n 9 -> Display Array");
    printf("\n 10 -> Exit");
    while (1)
    {
        printf("\n\n\t Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubble_sort_asc(arr, n);
            break;
        case 2:
            bubble_sort_desc(arr, n);
            break;
        case 3:
            selection_sort_asc(arr, n);
            break;
        case 4:
            selection_sort_desc(arr, n);
            break;
        case 5:
            insertion_sort_asc(arr, n);
            break;
        case 6:
            insertion_sort_desc(arr, n);
            break;
        case 7:
            heap_sort_asc(arr, n);
            break;
        case 8:
            heap_sort_desc(arr, n);
            break;
        case 9:
            printf(" The Entered Array is : ");
            display(arr, n);
            break;
        case 10:
            return 0;
        default:
            printf("\n\t Wrong Entry!!! Please Select only 1-10 option...\n");
        }
    }
    return 0;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
}

void bubble_sort_asc(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf(" After Bubble Sort Element's in Ascending Order : ");
    display(arr, n);
}

void bubble_sort_desc(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf(" After Bubble Sort Element's in Descending Order : ");
    display(arr, n);
}

void selection_sort_asc(int arr[], int n)
{
    int i, j, temp, pos;
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[pos] > arr[j])
                pos = j;
            if (pos != i)
            {
                temp = arr[i];
                arr[i] = arr[pos];
                arr[pos] = temp;
            }
        }
    }
    printf(" After Selection Sort Element's in Ascending Order : ");
    display(arr, n);
}

void selection_sort_desc(int arr[], int n)
{
    int i, j, temp, pos;
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[pos] < arr[j])
                pos = j;
            if (pos != i)
            {
                temp = arr[i];
                arr[i] = arr[pos];
                arr[pos] = temp;
            }
        }
    }
    printf(" After Selection Sort Element's in Descending Order : ");
    display(arr, n);
}

void swap_asc(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_asc(int arr[], int n, int i)
{
    int largest, left, right;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap_asc(&arr[i], &arr[largest]);
        heapify_asc(arr, n, largest);
    }
}

void heap_sort_asc(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify_asc(arr, n, i);
    for (i = n - 1; i >= 0; i--)
    {
        swap_asc(&arr[0], &arr[i]);
        heapify_asc(arr, i, 0);
    }
    printf(" After Heap Sort Element's in Ascending Order : ");
    display(arr, n);
}

void swap_desc(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_desc(int arr[], int n, int i)
{
    int smallest, left, right;
    smallest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < n && arr[left] > arr[smallest])
        smallest = left;
    if (right < n && arr[right] > arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap_desc(&arr[i], &arr[smallest]);
        heapify_desc(arr, n, smallest);
    }
}

void heap_sort_desc(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify_desc(arr, n, i);
    for (i = n - 1; i >= 0; i--)
    {
        swap_desc(&arr[0], &arr[i]);
        heapify_desc(arr, i, 0);
    }
    printf(" After Heap Sort Element's in Descending Order : ");
    for (i = n - 1; i >= 0; i--)
    {
        printf(" %d ", arr[i]);
    }
}

void insertion_sort_asc(int arr[], int n)
{
    int i, j, min;
    for (i = 1; i < n; i++)
    {
        min = arr[i];
        j = i - 1;
        while (min < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = min;
    }
    printf(" After Insertion Sort Element's in Ascending Order : ");
    display(arr, n);
}

void insertion_sort_desc(int arr[], int n)
{
    int i, j, max;
    for (i = 1; i < n; i++)
    {
        max = arr[i];
        j = i - 1;
        while (max > arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = max;
    }
    printf(" After Insertion Sort Element's in Descending Order : ");
    display(arr, n);
}