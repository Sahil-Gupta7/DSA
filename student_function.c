//Program to perform certain tasks in an array
#include <stdio.h>
int main()
{
    char s;
    int a[10]; //Declaring Array of size 10
    int i,n,ele,x,pos,j,p; //Variable Declaration
    printf("\n Enter No. of Elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    { //Taking Input
        printf("\n Enter Element : ");
        scanf("%d",&a[i]);
    }
    do
    {   
    printf("\n Default Size of Array taken is 10 \n");
    printf("\n Enter 1 to Insert Element at Beginning");
    printf("\n Enter 2 to Insert Element at End");
    printf("\n Enter 3 to Insert Element at any Position");
    printf("\n Enter 4 to Delete Element at Beginning");
    printf("\n Enter 5 to Delete Element at End");
    printf("\n Enter 6 to Delete Element at any Position");
    printf("\n Enter 7 to Display the Array");
    printf("\n Enter 8 to Sort the Array");
    printf("\n Enter Your Choice : ");
    scanf("%d",&x);
    switch(x) //Giving Choices with switch case
    {
        case 1: //To Insert Element at Beginning
        if(n<10)
        {
            printf("\n Enter Element to be Inserted : ");
            scanf("%d",&ele);
            for(i=n;i>=0;i--) 
            {
                a[i+1]=a[i];
            }
            a[0]=ele;
            n++; //Increasing size
            printf("\n Array after Insertion : \n");
            for(i=0;i<n;i++) 
            { //Printing Statement
                printf(" Array[%d] = %d\n",i,a[i]);
            }
        }
        else printf("\nArray is FULL");
        break; //Break Statement
        case 2: //To Insert Element at End
        if(n<10)
        {
            pos=n+1;
            n++;
            printf("\n Enter Element to be Inserted : ");
            scanf("%d",&ele);
            for(i=n-1;i>=pos;i--) 
            {
                a[i]=a[i-1];
            }
            a[pos-1]=ele;
            printf("\n Array after Insertion : \n");
            for(i=0;i<n;i++) 
            {
                printf(" Array[%d] = %d\n",i,a[i]);
            }
        }
        else printf("\nArray is FULL");
        break;
        case 3: //To Insert Element at any Position
        if(n<10)
        {
            pos=n+1;
            n++;
            printf("\n Enter Element to be Inserted : ");
            scanf("%d",&ele);
            printf("\n Enter Position at which Element is to be Inserted : ");
            scanf("%d",&pos);
            for(i=n-1;i>=pos;i--) 
            {
                a[i]=a[i-1];
            }
            a[pos-1]=ele;
            printf("\nArray after Insertion : \n");
            for(i=0;i<n;i++) 
            {
                printf(" Array[%d] = %d\n",i,a[i]);
            }
        }
        else printf("\nArray is FULL");
        break;
        case 4: //To Delete Element at Beginning
        if(n<=10)
        {
            pos=0;
            for(i=pos;i<n-1;i++) 
            {
                a[i] = a[i+1];
            }
            n=n-1;
            printf("\nArray after Insertion : \n");
            for(i=0;i<n;i++) 
            {
                printf(" Array[%d] = %d\n",i,a[i]);
            }
        }
        else printf("\nArray is FULL");
        break;
        case 5: //To Delete Element at End
        if(n<=10)
        {
            pos=n;
            for(i=pos;i<n-1;i++) 
            {
                a[i]=a[i+1];
            }
            n=n-1;
            printf("\nArray after Insertion : \n");
            for(i=0;i<n;i++) 
            {
                printf(" Array[%d] = %d\n",i,a[i]);
            }
        }
        else printf("\nArray is FULL");
        break;
        case 6: //To Delete Element at any Position
        if(n<=10)
        {
            printf("\n Enter the Position of the Element which is to be Deleted : ");
            scanf("%d",&pos);
            for(i=pos;i<n-1;i++) 
            {
                a[i]=a[i+1];
            }
            n=n-1;
            printf("\nArray after Insertion : \n");
            for(i=0;i<n;i++) 
            {
                printf(" Array[%d] = %d\n",i,a[i]);
            }
        }
        else printf("\nArray is FULL");
        break;
        case 7: //To Print the Array
        printf("\n Array is : \n");
        for(i=0;i<n;i++)
        {
            printf(" Array[%d] = %d\n",i,a[i]);
        }
        break;
        case 8: //To Sort Array
        for(i=0;i<n;i++) 
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j]) 
                {
                    p=a[i];
                    a[i]=a[j];
                    a[j]=p;
                }
            }
        }
        printf("\n Sorted Array in Ascending Order : \n");
        for(i=0;i<n;i++)
        {
            printf(" Array[%d] = %d\n",i,a[i]);
        }
        break;
        default: printf("\n SORRY WRONG ENTRY "); //Default Case
    }
    printf("\n Do u want to CONTINUE? (Y/N) : ");
    scanf(" %c",&s);
    } while (s=='y' || s=='Y'); //Statement to check if user want to continue to execute 
    return 0;
}