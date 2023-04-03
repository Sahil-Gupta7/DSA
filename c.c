#include <stdio.h>
#include <stdlib.h>
typedef struct node_list *node;
struct node_list
{
    int info;
    node next;
};
node display(node);
node check_empty(node);
node insert_beg(node, int);
node insert_pos(node, int, int);
node delete_pos(node, int);
node delete_key(node, int);
node count_nodes(node);
node search_key(node, int);
node *reverseKNodes(node, int);
node head = NULL;
void main()
{
    int ch, k;
    int item, pos;
    printf("\n 1 -> DISPLAY the List \n 2 -> CHECK for EMPTY List \n 3 -> INSERT at BEGINNING \n 4 -> INSERT at any POSITION \n 5 -> DELETE Node from a Certain POSITION \n 6 -> DELETE a given Item \n 7 -> Count TOTAL Number of Nodes \n 8 -> SEARCH for an Element in Linked List \n 9 -> REVERSE 'k' Nodes of Linked List \n 10 -> EXIT ");
    while (1)
    {
        printf("\n\t Enter your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = display(head);
            break;
        case 2:
            head = check_empty(head);
            break;
        case 3:
            printf(" Enter the Element which is to be INSERTED : ");
            scanf("%d", &item);
            head = insert_beg(head, item);
            break;
        case 4:
            printf(" Enter the Element which is to be INSERTED : ");
            scanf("%d", &item);
            printf(" Enter the Position where the Element is to be INSERTED : ");
            scanf("%d", &pos);
            head = insert_pos(head, pos, item);
            break;
        case 5:
            printf(" Enter the Position from where the Node is to be DELETED : ");
            scanf("%d", &pos);
            head = delete_pos(head, pos);
            break;
        case 6:
            printf(" Enter ITEM which is to be DELETED : ");
            scanf("%d", &item);
            head = delete_key(head, item);
            break;
        case 7:
            head = count_nodes(head);
            break;
        case 8:
            printf(" Enter Element to be SEARCHED : ");
            scanf("%d", &item);
            head = search_key(head, item);
            break;
        case 9:
            printf(" Enter the Value of 'k' to REVERSE 'k' Nodes : ");
            scanf("%d", &k);
            head = reverseKNodes(head, k);
            break;
        case 10:
            printf(" EXITING...");
            exit(0);
            break;
        default:
            printf("\n INVALID CHOICE...");
        }
    }
}
node display(node head)
{
    if (head == NULL)
    {
        printf(" LIST is EMPTY...\n");
        return head;
    }
    node ptr = head;
    printf(" LIST : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
        if (ptr != NULL)
            printf(" -> ");
    }
    printf("\n");
    return head;
}
node check_empty(node head)
{
    if (head == NULL)
        printf(" LIST is EMPTY...\n");
    return head;
}
node insert_beg(node head, int item)
{
    struct node_list *newnode = (struct node_list *)malloc(sizeof(struct node_list));
    if (newnode == NULL)
    {
        printf(" OVERFLOW...");
        return head;
    }
    node ptr = head;
    newnode->info = item;
    newnode->next = head;
    head = newnode;
    return head;
}
node insert_pos(node head, int pos, int item)
{
    struct node_list *newnode = (struct node_list *)malloc(sizeof(struct node_list));
    if (newnode == NULL)
    {
        printf(" OVERFLOW...");
    }
    newnode->info = item;
    newnode->next = NULL;
    node ptr = head;
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    else
    {
        node temp;
        for (int i = 1; i <= pos - 1; i++)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        newnode->next = ptr;
        temp->next = newnode;
    }
    return head;
}
node delete_pos(node head, int pos)
{
    if (head == NULL)
    {
        printf(" UNDERFLOW OCCURED...");
        return head;
    }
    if (pos == 1)
    {
        head = head->next;
        return head;
    }
    node temp, ptr = head;
    for (int i = 1; i < pos; i++)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    free(ptr);
    return head;
}
node delete_key(node head, int item)
{
    if (head == NULL)
    {
        printf(" UNDERFLOW OCCURED...");
        return head;
    }
    node temp, ptr = head;
    while (ptr->info != item)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    free(ptr);
    return head;
}
node count_nodes(node head)
{
    if (head == NULL)
    {
        printf(" LIST is EMPTY...\n");
        return head;
    }
    node ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\t TOTAL NODES = %d\n", count);
    return head;
}
node search_key(node head, int item)
{
    if (head == NULL)
    {
        printf(" LIST is EMPTY...");
        return head;
    }
    node ptr = head;
    int flag = 0;
    while (ptr != NULL)
    {
        if (ptr->info == item)
        {
            flag = 1;
            printf("\t Element is FOUND...\n");
            return head;
        }
        ptr = ptr->next;
    }
    printf(" Element is NOT FOUND...\n");
    return head;
}
node *reverseKNodes(node head, int k)
{
    node q = head;
    node r = NULL;
    node s;
    int count = 0;

    while (q != NULL && count < k)
    {
        s = r;
        r = q;
        q = q->next;
        r->next = s;
        count++;
    }
    if (q != NULL)
        head->next = reverseKNodes(q, k);
    return r;
}