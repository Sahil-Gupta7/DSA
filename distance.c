#include<stdio.h>
struct dist
{  //Creating Structure
    int km;
    int m;
};
void addition(struct dist, struct dist, struct dist *);
void main()
{
    struct dist d1,d2,d3;
    printf("\nEnter km and m for 1st Distance : "); //Taking Input
    scanf("%d %d",&d1.km,&d1.m);
    printf("\nEnter km and m for 2nd Distance : ");
    scanf("%d %d",&d2.km,&d2.m);
    addition(d1,d2,&d3); //Calling Function
    printf("\n Addition of to Distances is %d km %d m",d3.km,d3.m); //Printing Statement
}
void addition(struct dist d1, struct dist d2, struct dist *d3) //Function
{
    (*d3).km=d1.km+d2.km; //Adding
    (*d3).m=d1.m+d2.m;
    if((*d3).m>=1000)
    { //If condition for changing m to km if it exceeds 1000
        (*d3).km++;
        (*d3).m-=1000;
    }
}