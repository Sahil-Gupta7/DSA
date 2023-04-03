//Menu Driven Program to implement certain circular queue operations using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = -1;
struct node *rear = -1;
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (rear == -1)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if ((front == -1) && (rear == -1))
        printf("\t QUEUE is EMPTY...\n");
    else if (front == rear)
    {
        front = rear = -1;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
int peek()
{
    if ((front == -1) && (rear == -1))
        printf("\t QUEUE is EMPTY...\n");
    else
        printf(" The FRONT Element is '%d'\n", front->data);
}
void isEmpty()
{
    if ((front == -1) && (rear == -1))
        printf("\t QUEUE is EMPTY... \n");
    else
        printf("\t QUEUE is NOT EMPTY... \n");
}
void display()
{
    struct node *temp;
    temp = front;
    printf(" The Elements in QUEUE are : ");
    if ((front == -1) && (rear == -1))
        printf("\t QUEUE is EMPTY...\n");
    else
    {
        while (temp->next != front)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("%d  ", temp->data);
    }
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
    printf("\n 5 -> Check for EMPTY");
    printf("\n 6 -> EXIT ");
    while (choice != 6)
    {
        printf("\n\n\t Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter the Element to be Inserted : ");
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
            printf("\n EXITING.....");
            exit(0);
            break;
        default:
            printf("\n Please Enter a Valid Choice...\n");
        }
    }
    return 0;
}