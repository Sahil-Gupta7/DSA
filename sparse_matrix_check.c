//C Program to Check whether the Matrix is Sparse Matrix or Not
#include <stdio.h>
#include<stdlib.h>
int main()
{
    int x[100][100]; //Array Declaration
    int c, r, i, j, p = 0, r1 = 0, c1 = 0, z = 0, t; //Variable Declaration
    printf(" Enter No. of Rows : ");
    scanf("%d", &r); //Taking No. of Rows as Input
    printf(" Enter No. of Columns : ");
    scanf("%d", &c); //Taking No. of Columns as Input
    printf("\n");
    t = r * c; //Element to store Total No. of Elements in Matrix
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf(" Enter x%d%d value : ", i + 1, j + 1);
            scanf("%d", &x[i][j]); //Taking Elements of Matrix as Input
            if (x[i][j] == 0)      //Checking for Zero in Matrix
                z = z + 1;         //Counter to Count No. of Zero
            else
                p = p + 1; //Counter to Count No. of Non Zero
        }
    }
    printf("\n\t\t MATRIX FORM : \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d  ", x[i][j]); //Printing in Matrix Form
            if (j + 1 == c)
                printf("\n");
        }
    }
    //Checking For Sparse Matrix
    if (z > t / 2)
    { //If the Matrix is Sparse
        printf("\n\tTOTAL No. of ELEMENTS : %d", t); //Printing Total No. of Elements in the Matrix
        printf(" \n\tNO. of NON-ZERO Elements in given Sparse Matrix : %d", p); //Printing No. of Non Zero
        printf(" \n\tNO. of ZERO Elements in given Sparse Matrix : %d", z);     //Printing No. of Zero
        printf("\n\tNumber of ZERO are more than half of Total No. of Elements of Matrix...");
        printf("\n\tProvided Matrix is SPARSE MATRIX..");
        printf("\n\n\t 3-TUPLE REPRESENTATION of the given Sparse Matrix :");
        printf("\n ROWS\t\tCOLUMNS\t\tVALUES");
        printf("\n %d\t\t%d\t\t%d", r, c, p); //Printing 3 Tuple Representation
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (x[i][j] != 0)
                { //Checking for Non Zero
                    r1 = i + 1;
                    c1 = j + 1;
                    printf("\n %d\t\t%d\t\t%d", r1, c1, x[i][j]); //Printing Non Zero Values and there Positions
                }
            }
        }
    }
    else
    { //If the Matrix is Not a Sparse Matrix
        printf("\n\tTOTAL No. of ELEMENTS : %d", t);
        printf(" \n\tNO. of NON-ZERO Elements in given Sparse Matrix : %d", p);
        printf(" \n\tNO. of ZERO Elements in given Sparse Matrix : %d", z);
        printf("\n\tNumber of ZERO are NOT more than half of Total No. of Elements of Matrix...");
        printf("\n\tProvided Matrix is NOT SPARSE MATRIX..");
    }
    return 0;
}