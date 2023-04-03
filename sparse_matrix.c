#include<stdio.h>
int main()
{
    int x[100][100];
    int c,r,i,j,p=0,r1=0,c1=0;
    printf("\n Enter No. of Rows : ");
    scanf("%d",&r);
    printf("\n Enter No. of Columns : ");
    scanf("%d",&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(" Enter x%d%d value : ",i+1,j+1);
            scanf("%d",&x[i][j]);
            if(x[i][j]!=0) p=p+1;
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
    printf("\n ROWS\t\tCOLUMNS\t\tVALUES");
    printf("\n %d\t\t%d\t\t%d",r,c,p);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(x[i][j]!=0)
            {
                r1=i+1;
                c1=j+1;
                printf("\n %d\t\t%d\t\t%d",r1,c1,x[i][j]);
            }
        }
    }
    return 0;
}