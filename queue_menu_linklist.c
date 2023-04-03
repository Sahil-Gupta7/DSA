//Menu Driven Program to implement certain queue operations using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display();
struct node *front;
struct node *rear;
void enqueue()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\t OVERFLOW...\n");
        return;
    }
    else
    {   
        printf(" Enter the Element to be inserted : ");
        scanf("%d", &item);
        ptr->data = item;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
    display();
}
void dequeue ()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("\t UNDERFLOW...\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
    display();
}
void isEmpty()
{
    if (front == NULL)
        printf(" The QUEUE is EMPTY...\n");
    else
    {
        printf(" The QUEUE is NOT EMPTY...\n");
        display();
    }
}
void peek()
{
    if (front == NULL)
        printf(" The QUEUE is EMPTY...\n");
    else
    {
        printf(" The FRONT/PEEK Element is '%d' \n",front->data);
        display();
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
        printf(" EMPTY QUEUE...\n");
    else
    {
        printf(" The Current QUEUE is : ");
        while (ptr != NULL)
        {
            printf(" %d  ", ptr->data);
            ptr = ptr->next;
        }
    }
}
int main()
{
    int choice;
    printf("\n*************************Main Menu*****************************\n");
    printf("\n----------------------------------------------------------------\n");
    printf("\n1 -> ENQUEUE an Element\n2 -> DEQUEUE an Element\n3 -> PEEK\n4 -> DISPLAY the QUEUE\n5 -> Check if QUEUE is EMPTY\n6 -> EXIT\n");
    while (choice != 6)
    {
        printf("\n\n\t Enter your CHOICE : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue ();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n Please Enter Valid Choice...\n");
        }
    }
    return 0;
}