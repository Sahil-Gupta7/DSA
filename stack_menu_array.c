//Program to perform certain Operations of a Stack using ARRAY
#include <stdio.h>
int stack[100], choice, n, top, x, i;
void empty(void);
void push(void);
void pop(void);
void display(void);
int main()
{
    top = -1;
    printf("\n Enter the Size of STACK [MAX = 100] : ");
    scanf("%d", &n);
    printf("\n\t\t STACK OPERATIONS USING ARRAY\n");
    printf("\n\t\t 1 -> Check if STACK is EMPTY\n\t\t 2 -> DISPLAY\n\t\t 3 -> PUSH\n\t\t 4 -> POP\n\t\t 5 -> EXIT\n");
    do
    {
        printf("\t\t Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            empty();
            break;
        case 2:
            display();
            break;
        case 3:
            push();
            break;
        case 4:
            pop();
            break;
        case 5:
            printf("\n\t EXIT POINT ");
            break;
        default:
            printf("\n\t Please Enter a VALID CHOIC!!!\n");
        }
    } while (choice != 5);
    return 0;
}
void push()
{
    if (top >= n - 1)
        printf("\n\t STACK is OVERFLOW... ");
    else
    {
        printf(" Enter a Value to be PUSHED : ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("\t '%d' PUSHED\n", x);
    }
}
void pop()
{
    if (top <= -1)
        printf("\n\t STACK is UNDERFLOW... ");
    else
    {
        printf(" The POPPED Element is  '%d'\n", stack[top]);
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        printf("\n\t Elements in STACK : \n");
        for (i = top; i >= 0; i--)
            printf(" %d   ", stack[i]);
    }
    else
        printf("\n\t The STACK is EMPTY!!! ");
    printf("\n");
}
void empty()
{
    if (top < 0)
        printf("\n\t The STACK is EMPTY!!!\n");
    else
        printf("\n\t The STACK is NOT EMPTY!!!\n");
}