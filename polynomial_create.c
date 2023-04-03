//C Program to Represent Polynomial using Linked List
#include <stdio.h>
#include <stdlib.h>
//Declaring Structure for Polynomial
struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};
void create(int x, int y, struct Node **temp) //To Create
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = (struct Node *)malloc(sizeof(struct Node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct Node *)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = (struct Node *)malloc(sizeof(struct Node));
        r = r->next;
        r->next = NULL;
    }
}
void display(struct Node *node) //To Display
{
    while (node->next != NULL)
    {
        printf("%d x^%d ", node->coeff, node->pow); //Printing the Polynomial
        node = node->next;
        if (node->coeff >= 0)
        {
            if (node->next != NULL)
                printf("+");
        }
    } //Ending of While Loop
}
//Driver Code
int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    create(5, 7, &poly1); //Taking Input
    create(-3, 5, &poly1);
    create(1, 2, &poly1);
    create(9, 0, &poly1);
    printf(" NUMBER : "); //Printing the Polynomial
    display(poly1);
    return 0;
}