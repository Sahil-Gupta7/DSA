#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * head;
void initialize()
{
    head = NULL;
}
void insert(int num)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = head;
    head = newNode;
    printf(" Inserted Element : %d\n", num);
}
void delete (int num)
{
    struct node *h = head;
    struct node *temp;
    while (h->next != NULL)
    {
        if (h->next->data == num)
        {
            temp = h->next;
            h->next = h->next->next;
            free(temp);
            break;
        }
        else
        {
            h = h->next;
        }
    }
}
void findloop(struct node *head)
{
    struct node *slow, *fast;
    slow = fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            printf(" Linked List Contains a LOOP\n");
            return;
        }
    }
    printf(" NO LOOP in Linked List\n");
}
void printLinkedList()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL)
            printf(" -> ");
    }
}
void looper(int n)
{
    int f = 0;
    struct node *temp = head;
    struct node *loop = head;
    while (temp != NULL)
    {
        if (f != n)
        {
            f++;
            loop = loop->next;
        }
        if (temp->next == NULL)
        {
            temp->next = loop;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
}
int main()
{
    int choice, n;
    initialize();
    printf(" 1 -> INSERT Element\n 2 -> DELETE Element \n 3 -> DISPLAY Elements\n 4 -> CREATE LOOP\n 5 -> CHECK for LOOP\n 6 -> EXIT\n");
    while (1)
    {
        printf("\n\t Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" Please Enter the Element you want to INSERT : ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            printf(" Please Enter the Element you want to DELETE : ");
            scanf("%d", &n);
            delete (n);
            break;
        case 3:
            printf(" The Entered Linked List is : ");
            printLinkedList();
            printf("\n");
            break;
        case 4:
            printf(" Please Enter the Position you want to LOOP at : ");
            scanf("%d", &n);
            looper(n);
            break;
        case 5:
            findloop(head);
            break;
        case 6:
            printf(" EXITING.......");
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}