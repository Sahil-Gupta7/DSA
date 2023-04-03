//C program for Sparse Matrix Representation using Linked Lists
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int value;
	int row_position;
	int column_postion;
	struct Node *next;
};
void create_new_node(struct Node **start, int non_zero_element, int row_index, int column_index)
{
	struct Node *temp, *r;
	temp = *start;
	if (temp == NULL)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->value = non_zero_element;
		temp->row_position = row_index;
		temp->column_postion = column_index;
		temp->next = NULL;
		*start = temp;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;

		r = (struct Node *)malloc(sizeof(struct Node));
		r->value = non_zero_element;
		r->row_position = row_index;
		r->column_postion = column_index;
		r->next = NULL;
		temp->next = r;
	}
}
void PrintList(struct Node *start)
{
	struct Node *temp, *r, *s;
	temp = r = s = start;

	printf("\t\t ROW POSITION -> \t"); 
	while (temp != NULL)
	{
		printf("%d \t", temp->row_position); //Printing the Row Position of Values
		temp = temp->next;
	}
	printf("\n");
	printf("\t\t COLUMN POSITION -> \t"); 
	while (r != NULL)
	{
		printf("%d \t", r->column_postion); //Printing the Column Position of Values
		r = r->next;
	}
	printf("\n");
	printf("\t\t VALUES -> \t\t");
	while (s != NULL)
	{
		printf("%d \t", s->value); //Printing the Values
		s = s->next;
	}
	printf("\n");
}
//Driver Code
int main(void)
{
	int m, n, i, j, z = 0, p = 0, t = 0; //Variable Declaration
	printf(" Enter the ROW of Matrix : ");
	scanf("%d", &m); //Taking No. of Rows as Input
	printf(" Enter the COLUMN of Matrix : ");
	scanf("%d", &n); //Taking No. of Columns as Input
	printf("\n\t\tEnter the Matrix : \n");
	int sparseMatrix[m][n]; //Array Declaration
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf(" Enter x%d%d Value : ", i + 1, j + 1);
			scanf("%d", &sparseMatrix[i][j]); //Taking Elements of Matrix as Input
			t = m * n;
			if (sparseMatrix[i][j] == 0) //Checking for Zero in Matrix
				z = z + 1;				 //Counter to Count No. of Zero
			else
				p = p + 1; //Counter to Count No. of Non Zero
		}
	}
	printf("\n\t\t MATRIX FORM : \n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d  ", sparseMatrix[i][j]); //Printing in Matrix Form
			if (j + 1 == n)
				printf("\n");
		}
	}
	printf("\n\tTOTAL No. of ELEMENTS : %d", t); //Printing Total No. of Elements in the Matrix
	printf("\n\tNO. of NON-ZERO Elements in given Sparse Matrix : %d", p); //Printing No. of Non Zero
	printf("\n\tNO. of ZERO Elements in given Sparse Matrix : %d", z);		//Printing No. of Zero
	printf("\n\n\t 3-TUPLE REPRESENTATION of the given Sparse Matrix :\n");
	struct Node *start = NULL;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (sparseMatrix[i][j] != 0)
				create_new_node(&start, sparseMatrix[i][j], i, j);
	PrintList(start);
	return 0;
}