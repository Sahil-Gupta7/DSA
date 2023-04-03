//C program to reverse a Singly Linked List
#include <stdio.h>
#include <stdlib.h>
//Structure of a node
struct node 
{
    int data; //Data part
    struct node *next; //Address part
}*head;
//Functions used in the program 
void createList(int n);
void reverse();
void displayList();
int main()
{
    int n,m,choice;
    // Create a singly linked list of n nodes
    printf("\n Enter the Total Number of Nodes : ");
    scanf("%d",&n);
    createList(n);
    printf("\n\t Data in the Linked List : \n");
    displayList();
    //Reverse the list
    printf("\n Enter the Number M to reverse first m Node : ");
    scanf("%d", &m);
    printf("\n\t REVERSED List...\n");
    if(m>1)
    {
        reverse(&head,m - 2);
    }
    displayList();
    return 0;
}
//Create a list of n nodes
void createList(int n)
{
    struct node *newNode,*temp;
    int data,i;
    if(n<=0)
    {
        printf("\n List Size must be Greater than Zero.\n");
        return;
    }
    head=(struct node *)malloc(sizeof(struct node));
    //If unable to allocate memory for head node
    if(head == NULL)
    {
        printf("\n\t Unable to Allocate Memory...");
    }
    else
    {
        //Read data of node from the user
        printf("\n Enter the Data of Node 1 : ");
        scanf("%d", &data);
        head->data=data; // Link the data field with data
        head->next=NULL; // Link the address field to NULL
        temp=head;
        //Create n nodes and adds to linked list
        for(i=2;i<=n;i++)
        {
            newNode=(struct node *)malloc(sizeof(struct node));
            //If memory is not allocated for newNode 
            if(newNode == NULL)
            {
                printf("\n\t Unable to Allocate Memory...");
                break;
            }
            else
            {
                printf(" Enter the data of Node %d : ",i);
                scanf("%d",&data);
                newNode->data=data; // Link the data field of newNode with data
                newNode->next=NULL; // Link the address field of newNode with NULL
                temp->next=newNode; // Link previous node i.e. temp to the newNode
                temp=temp->next;
            }
        }
    }
}
//Reverse the order of nodes of a singly linked list
void reverse(struct node **head,int m)
{
    struct node *p,*q,*r,*rear;
    p=q=r=*head;
    if(m == 0)
    {
        q=q->next;
        p->next=q->next;
        q->next=p;
        *head=q;
    }
    else
    {
        p=p->next->next;
        q=q->next;
        r->next=NULL;
        rear=r;
        q->next=r;
        while (m>0 && p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
            m--;
        }
        *head=q;
        rear->next=p;
    }
}
//Display entire list
void displayList()
{
    struct node *temp;
    //If the list is empty i.e. head = NULL
    if(head == NULL)
    {
        printf("\n\t List is EMPTY...");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf(" %d ->", temp->data); //Print the data of current node
            temp=temp->next; // Move to next node
        }
		printf(" NULL");
    }
}