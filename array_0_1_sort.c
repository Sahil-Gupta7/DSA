#include<stdio.h>
int main()
{
    int a[50];
    int i,j,n,temp;
    printf("\n Enter No. of Elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter Element : ");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
    return 0;
}