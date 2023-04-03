// C program for the operations in the Singly Linked List
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct node 
{
	int info;
	struct node* link;
};
struct node* start = NULL;
void checkEmpty()
{
	if (start == NULL)
		printf("\nList is empty\n");
	else
		printf("\nList is not empty\n");
}
void traverse()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");

	else 
	{
		temp = start;
		while (temp != NULL) 
		{
			printf("Data = %d\n",temp->info);
			temp = temp->link;
		}
	}
}

void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	temp->info = data;

	temp->link = start;
	start = temp;
}

void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));

	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);

	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) 
	{
		head = head->link;
	}
	head->link = temp;
}

void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));

	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);

	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) 
	{
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}

void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else 
	{
		temp = start;
		start = start->link;
		free(temp);
	}
}

void deleteEnd()
{
	struct node *temp, *prevnode;
	if (start == NULL)
		printf("\nList is Empty\n");
	else 
	{
		temp = start;
		while (temp->link != 0) 
		{
			prevnode = temp;
			temp = temp->link;
		}
		free(temp);
		prevnode->link = 0;
	}
}

void deletePosition()
{
	struct node *temp, *position;
	int i = 1, pos;

	if (start == NULL)
		printf("\nList is empty\n");

	else 
	{
		printf("\nEnter index : ");

		scanf("%d", &pos);
		position = malloc(sizeof(struct node));
		temp = start;

		while (i < pos - 1) 
		{
			temp = temp->link;
			i++;
		}

		position = temp->link;
		temp->link = position->link;
		free(position);
	}
}
int countNodes() 
{  
    int count = 0;  
    struct node *current = start;  
      
    while(current != NULL) 
	{  
        count++;  
        current = current->link;  
    }  
    return count;  
}  

bool search(int x)
{
    struct node* current = start;  // Initialize current
    while (current != NULL)
    {
        if (current->info == x)
            return true;
        current = current->link;
    }
    return false;
}
void deleteKey(int key)
{
    struct node *temp = start,*prev;
 
    while (temp != NULL && temp->info == key)
    {
        start = temp->link; 
        free(temp); 
        temp = start; 
    }

    while (temp != NULL)
    {
        while (temp != NULL && temp->info != key)
        {
            prev = temp;
            temp = temp->link;
        }

        if (temp == NULL)
            return;

        prev->link = temp->link;
 
        free(temp);
        temp = prev->link;
    }
}

int main()
{
	int choice;
	while (1) 
	{

		printf("\n\t1 To see list\n");
		printf("\t2 For insertion at"
			" starting\n");
		printf("\t3 For insertion at"
			" end\n");
		printf("\t4 For insertion at "
			"any position\n");
		printf("\t5 For deletion of "
			"first element\n");
		printf("\t6 For deletion of "
			"last element\n");
		printf("\t7 For deletion of "
			"element at any position\n");
		printf("\t8 To find the number of nodes \n");
		printf("\t9 To search for a given element in the list\n");
		printf("\t10 To delete a node for a given key\n");
		printf("\t11 To check if the list is empty \n");
		printf("\t12 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) 
		{
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;
	    case 8:
			printf("The number of nodes are : %d",countNodes());
			break;
		case 9:
			printf("Enter the key to be searched: ");
			int s;
			scanf("%d",&s);
			if(search(s))
			{
				printf("Element found in linked list");
			}
			else
			{
				printf("Element not found in linked list");
			}
			break;
		case 10:
			printf("Enter the key to be deleted: ");
			scanf("%d",&s);
			deleteKey(s);
			break;
		case 11:
			checkEmpty();
			break;
		case 12:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}