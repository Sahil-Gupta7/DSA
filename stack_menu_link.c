//Program to perform certain Operations of a Stack using LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct
{
    struct node *top;
} STACK;
int push(STACK *s, int v)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        return 1;
    }
    temp->data = v;
    temp->next = s->top;
    s->top = temp;
    return 0;
}
int pop(STACK *s, struct node **v)
{
    struct node *temp;
    if (s->top == NULL)
    {
        return 1;
    }
    temp = s->top;
    s->top = temp->next;
    *v = temp;
    return 0;
}
void empty(STACK *s)
{
    if (s->top == NULL)
        printf("\n\t STACK is EMPTY!!!\n");
    else
        printf("\n\t STACK is NOT EMPTY!!!\n");
}
void display(STACK *s)
{
    if (s->top == NULL)
        printf("\n\t STACK is EMPTY!!!\n");
    else
    {
        struct node *temp;
        printf("\n\t Elements in STACK : \n");
        for (temp = s->top; temp != NULL; temp = temp->next)
            printf(" %d   ", temp->data);
    }
    printf("\n");
}
int main()
{
    struct node *m;
    STACK s1;
    s1.top = NULL;
    int ch, v, q, k;
    printf("\n\t\t STACK OPERATIONS USING LINKED LIST\n");
    printf("\n\t\t 1 -> CHECK if STACK is EMPTY\n\t\t 2 -> DISPLAY\n\t\t 3 -> PUSH\n\t\t 4 -> POP\n\t\t 5 -> EXIT\n");
    while (1)
    {
        printf("\t Enter your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            empty(&s1);
            break;
        case 2:
            display(&s1);
            break;
        case 3:
            printf(" Enter a Value to  be PUSHED : ");
            scanf("%d", &v);
            k = push(&s1, v);
            if (k == 1)
                printf("\n\t STACK is OVERFLOW...");
            else
                printf("\t '%d' PUSHED\n", v);
            break;
        case 4:
            q = pop(&s1, &m);
            if (q == 1)
                printf("\n\t STACK is UNDERFLOW...");
            else
                printf(" POPPED Element is '%d'\n", m->data);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\n\t Please Enter a VALID CHOICE!!!\n");
        }
    }
}