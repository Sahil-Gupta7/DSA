#include<stdio.h>
struct employee //Creating structure
{
    float bp;
    char name[30],des[30],dep[30],gen[10];
}emp[100]; 
void main()
{
    int i,n; //Variable Declaration
    float gp[100];
    float hr,da;
    printf("Enter the No. of Employees\n");
    scanf("%d",&n);
    printf("Enter Employee's Name , Gender , Designation , Department , Basic Pay\n");
    for(i=0;i<n;i++)
    { //Taking Input
        scanf("%s %s %s %s %f",&emp[i].name,emp[i].gen,&emp[i].des,&emp[i].dep,&emp[i].bp);
    } //End of for loop
    for(i=0;i<n;i++)
    {
        hr=0;da=0; //Calculating Gross Pay
        hr=(25*emp[i].bp)/100;
        da=(75*emp[i].bp)/100;
        gp[i]=emp[i].bp+hr+da;
    }
    printf("\nNAME\t\tGENDER\t\tDESIGNATION\t\tDEPARTMENT\t\tBASIC PAY\t\tGROSS SALARY\n");
    for(i=0;i<n;i++)
    { //Printing Output
        printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%f\t\t%f",emp[i].name,emp[i].gen,emp[i].des,emp[i].dep,emp[i].bp,gp[i]);
    }
}