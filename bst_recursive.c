#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}
void postorder(struct node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}
void preorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}
int maximum(struct node *node)
{
    struct node *current = node;
    while (current->right != NULL)
        current = current->right;

    return (current->data);
}
struct node *search(struct node *root, int key)
{
    if (root == NULL)
        printf("\tElement Not Found...");
    else if (key < root->data)
    {
        root->left = search(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = search(root->right, key);
    }
    else
        printf("\t'%d' Element Found...", root->data);
    return root;
}
struct node *minimum(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    printf("%d", current->data);
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    printf("\n 0 -> Quit\n 1 -> Create\n 2 -> Inorder\n 3 -> Preorder\n 4 -> Postorder\n 5 -> Search\n 6 -> Minimum Element\n 7 -> Maximum Element\n 8 -> Deletion\n");
    struct node *root = NULL;
    int n,d;
    char ch = 'y';
    do
    {
        printf(" Enter your Choice : ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf(" No. of data to be entered : ");
            scanf("%d", &n);
            int x;
            printf(" Enter the value : ");
            scanf("%d", &x);
            root = insert(root, x);
            int m;
            for (int i = 0; i < n - 1; i++)
            {
                printf(" Enter the value : ");
                scanf("%d", &m);
                insert(root, m);
            }
            break;
        case 2:
            printf(" Inorder Traversal of BST : \n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf(" Preorder Traversal of BST : \n");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf(" Postorder Traversal of BST : \n");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf(" Enter the Element to be Searched : ");
            int data;
            scanf("%d", &data);
            search(root, data);
            printf("\n");
            break;
        case 6:
            printf(" Maximum value in BST is '%d'\n\n", maximum(root));
            break;
        case 7:
            printf(" Minimum value in BST is '%d'\n\n", minimum(root));
            break;
        case 8:
            printf(" Enter the Position to be Deleted : ");
            scanf("%d",&d);
            deleteNode(root, d);
            printf("\n BST after Deleting : ");
            inorder(root);
            break;
        case 0:
            exit(1);
            printf(" Do you wish to continue ? ");
            scanf("%d", &ch);
        }
    } while (ch == 'y' || ch == 'Y');
    return 0;
}