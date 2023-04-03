#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} nodetype;
nodetype *insert(nodetype *);
void sort(nodetype *);
void main()
{
    nodetype *left = NULL;
    nodetype *right = NULL;
    int ch, c;
    printf("Enter 1 for Insert \nEnter 2 for Sort \nEnter 3 for Exit");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            right = insert(right);
            if (left == NULL)
            {
                left = right;
            }
            break;
        case 2:
            sort(left);
        case 3:
            exit(1);
        default:
            printf("Invalid choice...");
            break;
        }
        printf("Do you want to continue press 1 : ");
        scanf("%d", &c);
    } while (c == 1);
    getch();
}
nodetype *insert(nodetype *r)
{
    int n;
    nodetype *p;
    p = (nodetype *)malloc(sizeof(nodetype));
    printf("\nEnter the number : ");
    scanf("%d", &n);
    if (p != NULL)
    {
        p->info = n;
        p->next = NULL;
        if (r == NULL)
        {
            r = p;
        }
        else
        {
            r->next = p;
            r = p;
        }
        return (r);
    }
    else
    {
        printf("Not Enough Memory...");
    }
}
void sort(nodetype *l)
{
    nodetype *t;
    nodetype *s;
    int x;
    t = l;
    while (t != NULL)
    {
        s = t->next;
        while (s != NULL)
        {
            if (t->info > s->info)
            {
                x = t->info;
                t->info = s->info;
                s->info = x;
            }
            s = s->next;
        }
        t = t->next;
    }
    t = l;
    while (t != NULL)
    {
        printf(" %d  ", t->info);
        t = t->next;
    }
}