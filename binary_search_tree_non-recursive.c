#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};
struct node *search(struct node *root, int skey);
struct node *smallest(struct node *root);
struct node *largest(struct node *root);
struct node *insert(struct node *root, int ikey);
void preorder_trav(struct node *root);
void inorder_trav(struct node *root);
void post_trav(struct node *root);
struct node *queue[MAX];
int front = -1, rear = -1;
void insert_queue(struct node *item);
struct node *del_queue();
int queue_empty();
struct node *stack[MAX];
int top = -1;
void push_stack(struct node *item);
struct node *pop_stack();
int stack_empty();
int main()
{
    struct node *root = NULL, *ptr;
    int choice, k;
    printf("\n");
    printf(" 0 -> Quit\n");
    printf(" 1 -> Create\n");
    printf(" 2 -> In-Order Traversal\n");
    printf(" 3 -> Pre-Order Traversal\n");
    printf(" 4 -> Post-Order Traversal\n");
    printf(" 5 -> Search\n");
    printf(" 6 -> Find Smallest Element\n");
    printf(" 7 -> Find Largest Element\n");
    while (1)
    {
        printf("\n\t Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            printf(" Enter the Element to be Inserted : ");
            scanf("%d", &k);
            root = insert(root, k);
            break;
        case 2:
            printf(" IN-ORDER TRAVERSAL : ");
            inorder_trav(root);
            printf("\n");
            break;
        case 3:
            printf(" PRE-ORDER TRAVERSAL : ");
            preorder_trav(root);
            printf("\n");
            break;
        case 4:
            printf(" POST-ORDER TRAVERSAL : ");
            post_trav(root);
            printf("\n");
            break;
        case 5:
            printf(" Enter the Element to be Searched : ");
            scanf("%d", &k);
            ptr = search(root, k);
            if (ptr == NULL)
                printf("\t Element NOT PRESENT...\n");
            else
                printf("\t Element PRESENT...\n");
            break;
        case 6:
            ptr = smallest(root);
            if (ptr != NULL)
                printf(" SMALLEST Element is '%d'\n", ptr->info);
            break;
        case 7:
            ptr = largest(root);
            if (ptr != NULL)
                printf(" LARGEST Element is '%d'\n", ptr->info);
            break;
        default:
            printf("\n\t INVALID CHOICE...\n");
        }
    }
    return 0;
}
struct node *search(struct node *ptr, int skey)
{
    while (ptr != NULL)
    {
        if (skey < ptr->info)
            ptr = ptr->lchild;
        else if (skey > ptr->info)
            ptr = ptr->rchild;
        else
            return ptr;
    }
    return NULL;
}
struct node *insert(struct node *root, int ikey)
{
    struct node *tmp, *par, *ptr;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        par = ptr;
        if (ikey < ptr->info)
            ptr = ptr->lchild;
        else if (ikey > ptr->info)
            ptr = ptr->rchild;
        else
        {
            printf("\t DUPLICATE ELEMENT...");
            return root;
        }
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = ikey;
    tmp->lchild = NULL;
    tmp->rchild = NULL;
    if (par == NULL)
        root = tmp;
    else if (ikey < par->info)
        par->lchild = tmp;
    else
        par->rchild = tmp;
    return root;
}
struct node *smallest(struct node *ptr)
{
    if (ptr != NULL)
        while (ptr->lchild != NULL)
            ptr = ptr->lchild;
    return ptr;
}
struct node *largest(struct node *ptr)
{
    if (ptr != NULL)
        while (ptr->rchild != NULL)
            ptr = ptr->rchild;
    return ptr;
}
void preorder_trav(struct node *root)
{
    struct node *ptr = root;
    if (ptr == NULL)
    {
        printf("\t Tree is EMPTY...\n");
        return;
    }
    push_stack(ptr);
    while (!stack_empty())
    {
        ptr = pop_stack();
        printf("%d  ", ptr->info);
        if (ptr->rchild != NULL)
            push_stack(ptr->rchild);
        if (ptr->lchild != NULL)
            push_stack(ptr->lchild);
    }
}
void inorder_trav(struct node *root)
{
    struct node *ptr = root;
    if (ptr == NULL)
    {
        printf("\t Tree is EMPTY...\n");
        return;
    }
    while (1)
    {
        while (ptr->lchild != NULL)
        {
            push_stack(ptr);
            ptr = ptr->lchild;
        }
        while (ptr->rchild == NULL)
        {
            printf("%d  ", ptr->info);
            if (stack_empty())
                return;
            ptr = pop_stack();
        }
        printf("%d  ", ptr->info);
        ptr = ptr->rchild;
    }
}
void post_trav(struct node *root)
{
    struct node *ptr = root;
    struct node *q;
    if (ptr == NULL)
    {
        printf("\t Tree is EMPTY...\n");
        return;
    }
    q = root;
    while (1)
    {
        while (ptr->lchild != NULL)
        {
            push_stack(ptr);
            ptr = ptr->lchild;
        }
        while (ptr->rchild == NULL || ptr->rchild == q)
        {
            printf("%d  ", ptr->info);
            q = ptr;
            if (stack_empty())
                return;
            ptr = pop_stack();
        }
        push_stack(ptr);
        ptr = ptr->rchild;
    }
}
void insert_queue(struct node *item)
{
    if (rear == MAX - 1)
    {
        printf("\t QUEUE OVERFLOW...\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = item;
}
struct node *del_queue()
{
    struct node *item;
    if (front == -1 || front == rear + 1)
    {
        printf("\t QUEUE UNDERFLOW...\n");
        return 0;
    }
    item = queue[front];
    front = front + 1;
    return item;
}
int queue_empty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}
void push_stack(struct node *item)
{
    if (top == (MAX - 1))
    {
        printf("\t STACK OVERFLOW...\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}
struct node *pop_stack()
{
    struct node *item;
    if (top == -1)
    {
        printf("\t STACK UNDERFLOW...\n");
        exit(1);
    }
    item = stack[top];
    top = top - 1;
    return item;
}
int stack_empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}