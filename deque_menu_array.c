//Menu Driven Program to implement certain deueue operations using static array
#include <stdio.h>
#include <stdlib.h>
#define size 6
int deque[size];
int f=-1, r=-1;
void enqueue_front(int x)
{
    if((f==0 && r==size-1) || (f==r+1))
        printf("\t DEQUE is FULL... \n");
    else if((f==-1) && (r==-1))
    {
        f=r=0;
        deque[f]=x;
    }
    else if(f==0)
    {
        f=size-1;
        deque[f]=x;
    }
    else
    {
        f=f-1;
        deque[f]=x;
    }
}
void enqueue_rear(int x)
{
    if((f==0 && r==size-1) || (f==r+1))
        printf("\t DEQUE is FULL...\n");
    else if((f==-1) && (r==-1))
    {
        r=0;
        deque[r]=x;
    }
    else if(r==size-1)
    {
        r=0;
        deque[r]=x;
    }
    else
    {
        r++;
        deque[r]=x;
    }
}
void display()
{
    int i=f;
    printf(" Elements in the DEQUE are : ");
    while(i!=r)
    {
        printf("%d  ",deque[i]);
        i=(i+1)%size;
    }
    printf("%d  ",deque[r]);
}
void isEmpty()
{
    if((f==-1) && (r==-1))
        printf("\t DEQUE is EMPTY...\n");
    else
        printf("\t DEQUE is NOT EMPTY...\n");
}
void isFull()
{
    if((f==0 && r==size-1) || (f==r+1))
        printf("\t DEQUE is FULL...\n");
    else
        printf("\t DEQUE is NOT FULL...\n");
}
void getfront()
{
    if((f==-1) && (r==-1))
        printf("\t DEQUE is EMPTY...\n");
    else
        printf(" The Value of the FRONT is '%d'\n", deque[f]);
}
void getrear()
{
    if((f==-1) && (r==-1))
        printf("\t DEQUE is EMPTY...\n");
    else
        printf(" The Value of the REAR is '%d'\n", deque[r]);
}
void dequeue_front()
{
    if((f==-1) && (r==-1))
        printf("\t DEQUE is EMPTY...\n");
    else if(f==r)
    {
        printf(" The DELETED Element is '%d'\n", deque[f]);
        f=-1;
        r=-1;
    }
    else if(f==(size-1))
    {
        printf(" The DELETED Element is '%d'\n", deque[f]);
        f=0;
    }
    else
    {
        printf(" The DELETED Element is '%d'\n", deque[f]);
        f=f+1;
    }
}
void dequeue_rear()
{
    if((f==-1) && (r==-1))
        printf("\t DEQUE is EMPTY...\n");
    else if(f==r)
    {
        printf(" The DELETED Element is '%d'\n", deque[r]);
        f=-1;
        r=-1;
    }
    else if(r==0)
    {
        printf(" The DELETED Element is '%d'\n", deque[r]);
        r=size-1;
    }
    else
    {
        printf(" The DELETED Element is '%d'\n", deque[r]);
        r=r-1;
    }
}
int main()
{
    int choice = 0, x;
    printf("\n*************************Main Menu*****************************");
    printf("\n----------------------------------------------------------------");
    printf("\n 1 -> ENQUEUE FRONT ");
    printf("\n 2 -> ENQUEUE REAR ");
    printf("\n 3 -> DEQUEUE FRONT");
    printf("\n 4 -> DEQUEUE REAR ");
    printf("\n 5 -> Get FRONT Element");
    printf("\n 6 -> Get REAR Element");
    printf("\n 7 -> DISPLAY Elements");
    printf("\n 8 -> Check for EMPTY ");
    printf("\n 9 -> Check for FULL ");
    printf("\n 10 -> EXIT ");
    while (choice != 10)
    {
        printf("\n\n\t Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Enter the Element to be Inserted : ");
            x = 0;
            scanf("%d", &x);
            enqueue_front(x);
            display();
            break;
        case 2:
            printf(" Enter the Element to be Inserted : ");
            x = 0;
            scanf("%d", &x);
            enqueue_rear(x);
            display();
            break;
        case 3:
            dequeue_front();
            display();
            break;
        case 4:
            dequeue_rear();
            display();
            break;
        case 5:
            getfront();
            display();
            break;
        case 6:
            getrear();
            display();
            break;
        case 7:
            display();
            break;
        case 8:
            isEmpty();
            display();
            break;
        case 9:
            isFull();
            display();
            break;
        case 10:
            printf("\n EXITING.....");
            exit(0);
            break;
        default:
            printf("\n Please Enter a Valid Choice...\n");
        }
    }
    return 0;
}