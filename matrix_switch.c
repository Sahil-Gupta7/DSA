//Program to find non zero, product of diagonal, sum of element above leading diagonal and elements below leading diagonal
#include<stdio.h>
int main()
{
    int a[100][100]; //Array Declaration
    int i,j,r1,c1,c=0,p=1,s=0;
    printf(" Enter Rows : "); //Taking no. Of rows and column input
    scanf("%d",&r1);
    printf(" Enter Column : ");
    scanf("%d",&c1);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf(" Enter Elements a%d%d: ",i+1,j+1); //Taking Elements of matrix
            scanf("%d",&a[i][j]);
            if(a[i][j]>0 || a[i][j]<0) c=c+1;
        }
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(i==j) p=p*a[i][j]; //Product of diagonal
        }
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(j>i) s=s+a[i][j]; //Sum of element above diagonal
        }
    }
    printf("\n\tMatrix Form : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t",a[i][j]); //Printing Matrix
            if(j==c1-1) printf("\n");
        }
    }
    printf(" Number of Non Zero Elements : %d\n",c);
    printf(" Sum of Elements above Leading Diagonal : %d\n",s);
    printf(" Product of Diagonal : %d\n",p);
    printf(" Elements Below Leading Diagonal : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(j<i) printf("%d\t",a[i][j]); //Printing elements below leading diagonal
        }
    }
    return 0;
}