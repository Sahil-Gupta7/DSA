#include<stdio.h>
int main()
{
    int x[100][100];
    int c,r,i,j;
    printf("\n Enter No. of Rows : ");
    scanf("%d",&r);
    printf("\n Enter No. of Columns : ");
    scanf("%d",&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("\n Enter x%d%d value : ",i+1,j+1);
            scanf("%d",&x[i][j]);
        }
    }
    printf("\n MATRIX FORM : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d  ",x[i][j]);
            if(j+1==c) printf("\n");
        }
    }
    return 0;
}