//C Program to Add Two Polynomials
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef, expo;
    struct node *next;
};
struct node *insertpoly(struct node *thead, int c, int e);
struct node *append(struct node *thead, int c, int e);
struct node *polyaddition(struct node *p1thead, struct node *p2thead);
void display(struct node *thead);
void main()
{
    int a, b, n, i;
    struct node *p1head, *p2head, *p3head;
    p1head = p2head = NULL;
    printf(" Enter the No. of Terms of Polynomial 1 : ");
    scanf("%d", &n); //Taking No. of Terms in Polynomial 1 as Input
    printf("\n Enter the Polynomial : \n");
    for (i = 0; i < n; i++)
    {
        printf(" Enter the Coefficient and Exponent of the term : ");
        scanf("%d%d", &a, &b); //Taking the Elements of Polynomial 1 as Input
        p1head = insertpoly(p1head, a, b);
    }
    printf("\n Enter the No. of Terms of Polynomial 2 : ");
    scanf("%d", &n); //Taking No. of Terms in Polynomial 2 as Input
    printf("\n Enter the Polynomial : \n");
    for (i = 0; i < n; i++)
    {
        printf(" Enter the Coefficient and Exponent of the Term : ");
        scanf("%d%d", &a, &b); //Taking the Elements of Polynomial 2 as Input
        p2head = insertpoly(p2head, a, b);
    }
    p3head = polyaddition(p1head, p2head);
    printf("\n\t The POLYNOMIAL 1 is : "); //Printing Polynomial 1
    display(p1head);
    printf("\n\t The POLYNOMIAL 2 is : "); //Printing Polynomial 2
    display(p2head);
    printf("\n\t The SUM of the Two POLYNOMIALS is : "); //Printing Sum of Two Polynomials
    display(p3head);
}
struct node *append(struct node *thead, int c, int e)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = c;
    newnode->expo = e;
    if (thead == NULL)
    {
        newnode->next = NULL;
        return newnode;
    }
    struct node *trav = thead;
    while (trav->next != NULL)
        trav = trav->next;
    trav->next = newnode;
    newnode->next = NULL;
    return thead;
}
struct node *insertpoly(struct node *thead, int c, int e)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = c;
    newnode->expo = e;
    if (thead == NULL)
    {
        newnode->next = NULL;
        return newnode;
    }
    struct node *prev, *curr;
    prev = curr = thead;
    while (curr != NULL && curr->expo > e)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == thead)
    {
        newnode->next = curr;
        return newnode;
    }
    else if (curr == NULL)
    {
        prev->next = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = curr;
        prev->next = newnode;
    }
    return thead;
}
struct node *polyaddition(struct node *p1thead, struct node *p2thead) //To Find Sum
{
    struct node *ans = NULL;
    struct node *t1, *t2;
    t1 = p1thead;
    t2 = p2thead;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->expo > t2->expo)
        {
            ans = append(ans, t1->coef, t1->expo);
            t1 = t1->next;
        }
        else if (t1->expo < t2->expo)
        {
            ans = append(ans, t2->coef, t2->expo);
            t2 = t2->next;
        }
        else
        {
            ans = append(ans, (t1->coef) + (t2->coef), t1->expo);
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while (t1 != NULL)
    {
        ans = append(ans, t1->coef, t1->expo);
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        ans = append(ans, t2->coef, t2->expo);
        t2 = t2->next;
    }
    return ans;
}
void display(struct node *thead) //To Display
{
    struct node *temp = thead;
    if (temp == NULL)
    { //If the List is Empty
        printf("\nEmpty..");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf(" %dx^%d +", temp->coef, temp->expo);
            temp = temp->next;
        }
        printf(" %d x^%d ", temp->coef, temp->expo); //Printing the Elements of Polynomial
    }
}