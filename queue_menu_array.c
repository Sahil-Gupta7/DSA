//Menu Driven Program to implement certain queue operations using static array
#include <stdio.h>
#include <stdlib.h>
#define max 7
int queue[max];
int front = -1;
int rear = -1;
void enqueue(int element)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = element;
    }
    else if ((rear + 1) % max == front)
        printf("\t QUEUE is OVERFLOW...");
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = element;
    }
}
int dequeue()
{
    if ((front == -1) && (rear == -1))
        printf("\t QUEUE is UNDERFLOW...");
    else if (front == rear)
    {
        printf(" The DEQUEUED Element is '%d'\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf(" The DEQUEUED Element is '%d'\n", queue[front]);
        front = (front + 1) % max;
    }
}
void display()
{
    int i;
    if (front == -1 && rear == -1)
    printf(" QUEUE is EMPTY\n");
    else
    {
        printf("\n FRONT INDEX : %d ", queue[front]);
        printf("\n QUEUE ELEMENTS : ");
        for (i = front; i !=rear; i = ((i + 1) % max))
            printf(" %d\t", queue[i]);
        printf("%d ", queue[i]);
        printf("\n REAR INDEX : %d \n", rear);
    }
}
void peek()
{
    if (front == -1 && rear == -1)
        printf(" QUEUE is EMPTY...");
    else
        printf(" The FRONT/PEEK Element is : '%d'\n", queue[front]);
}
void isEmpty()
{
    if (front == -1 && rear == -1)
        printf(" QUEUE is EMPTY...");
    else
        printf(" QUEUE is NOT EMPTY... ");
}
void isFull()
{
    if ((rear + 1) % max == front)
        printf(" QUEUE is FULL...");
    else
        printf(" QUEUE is NOT FULL... ");
}
int main()
{
    int choice = 0, x;
    printf("\n*************************Main Menu*****************************");
    printf("\n----------------------------------------------------------------");
    printf("\n 1 -> ENQUEUE");   
    printf("\n 2 -> DEQUEUE");   
    printf("\n 3 -> PEEK");
    printf("\n 4 -> DISPLAY Elements");
    printf("\n 5 -> Check if QUEUE is EMPTY");    
    printf("\n 6 -> Check if QUEUE is FULL ");
    printf("\n 7 -> EXIT ");
    while (choice != 7)
    {
        printf("\n\t Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter the Element to be inserted : ");
            x = 0;
            scanf("%d", &x);
            enqueue(x);
            display();
            break;
        case 2:
            dequeue();
            display();
            break;
        case 3:
            peek();
            display();
            break;
        case 4:
            display();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            isFull();
            break;
        case 7:
            printf("\n EXITING.....");
            exit(0);
            break;
        default:
            printf("\n\t Please Enter a Valid Choice...\n");
        }
    }
    return 0;
}