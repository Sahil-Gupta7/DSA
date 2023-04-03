#include<stdio.h>
int main()
{
    int x[100][100],y[100][100],a[100][100];
    int c1,r1,c2,r2,i,j,k;
    printf("\n Enter No. of Rows : ");
    scanf("%d",&r1);
    printf("\n Enter No. of Columns : ");
    scanf("%d",&c1);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("\n Enter x%d%d value : ",i+1,j+1);
            scanf("%d",&x[i][j]);
        }
    }
    printf("\n Enter No. of Rows : ");
    scanf("%d",&r2);
    printf("\n Enter No. of Columns : ");
    scanf("%d",&c2);
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("\n Enter x%d%d value : ",i+1,j+1);
            scanf("%d",&y[i][j]);
        }
    }
    printf("\n MATRIX A : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d  ",x[i][j]);
            if(j+1==c1) printf("\n");
        }
    }
    printf("\n MATRIX B : \n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d  ",y[i][j]);
            if(j+1==c2) printf("\n");
        }
    }
    if(c1==c2 && r1==r2)
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                a[i][j]=x[i][j]+y[i][j];
            }
        }
    }
    printf("\n ADDED MATRIX (A+B) : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d  ",a[i][j]);
            if(j+1==c1) printf("\n");
        }
    }
    if(c1==c2 && r1==r2)
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                a[i][j]=x[i][j]-y[i][j];
            }
        }
    }
    printf("\n SUBTRACTED MATRIX (A-B) : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d  ",a[i][j]);
            if(j+1==c1) printf("\n");
        }
    }
    return 0;
}