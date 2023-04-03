#include <stdio.h>
#include <stdlib.h>
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;
NODE *node;
NODE *createtree(NODE *node, int data)
{
    if (node == NULL)
    {
        NODE *temp;
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < (node->data))
    {
        node->left = createtree(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = createtree(node->right, data);
    }
    return node;
}
NODE *search(NODE *node, int data)
{
    if (node == NULL)
        printf("\n\tELEMENT NOT FOUND ");
    else if (data < node->data)
    {
        node->left = search(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = search(node->right, data);
    }
    else
        printf("\n\t '%d' ELEMENT FOUND", node->data);
    return node;
}
void inorder(NODE *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}
void preorder(NODE *node)
{
    if (node != NULL)
    {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(NODE *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}
NODE *findMin(NODE *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->left)
        return findMin(node->left);
    else
        return node;
}
NODE *smallest(NODE *node)
{
    if(node!=NULL)
        while(node->left!=NULL)
            node=node->left;
    printf("%d",node);
}
NODE *largest(NODE *node)
{
    if(node!=NULL)
        while(node->right!=NULL)
            node=node->right;
    return node;
}
void main()
{
    int data, ch, i, n;
    NODE *root = NULL;
    while (1)
    {
        printf("\n 0 -> Exit ");
        printf("\n 1 -> Insertion in Binary Search Tree");
        printf("\n 2 -> In-Order Traversal ");
        printf("\n 3 -> Pre-Order Traversal ");
        printf("\n 4 -> Post-Order Traversal ");
        printf("\n 5 -> Search Element in Binary Search Tree");
        printf("\n\t Enter your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
            printf("\n Enter N Value : ");
            scanf("%d", &n);
            printf("\nEnter the values to create BST : \n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = createtree(root, data);
            }
            break;
        case 2:
            printf("\n In-Order Traversal : \n");
            inorder(root);
            break;
        case 3:
            printf("\n Pre-Order Traversal : \n");
            preorder(root);
            break;
        case 4:
            printf("\n Post-Order Traversal : \n");
            postorder(root);
            break;
        case 5:
            printf("\n Enter the Element to be searched : ");
            scanf("%d", &data);
            root = search(root, data);
            break;
        case 6:
            printf("\n SMALLEST Element : ");
            smallest(root);
            break;
        case 7:
            printf("\n LARGEST Element : ");
            largest(root);
            break;
        default:
            printf("\n\t INVALID CHOICE ");
            break;
        }
    }
}