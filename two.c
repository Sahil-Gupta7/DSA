//This is a C Program to Implement two Stacks using a Single Array & Check for Overflow & Underflow
#include <stdio.h>
#define SIZE 10

int ar[SIZE];
int top1 = -1;
int top2 = SIZE;
void push_stack1(int data)
{
    if (top1 < top2 - 1)
    {
        ar[++top1] = data;
    }
    else
    {
        printf("Stack Full!!! Cannot Push...\n");
    }
}
void push_stack2(int data)
{
    if (top1 < top2 - 1)
    {
        ar[--top2] = data;
    }
    else
    {
        printf("Stack Full!!! Cannot Push...\n");
    }
}
void pop_stack1()
{
    if (top1 >= 0)
    {
        int popped_value = ar[top1--];
        printf("'%d' is popped from Stack 1\n", popped_value);
    }
    else
    {
        printf("Stack Empty!!! Cannot Pop...\n");
    }
}
void pop_stack2()
{
    if (top2 < SIZE)
    {
        int popped_value = ar[top2++];
        printf("'%d' is popped from Stack 2\n", popped_value);
    }
    else
    {
        printf("Stack Empty!!! Cannot Pop...\n");
    }
}
void print_stack1()
{
    int i;
    for (i = top1; i >= 0; --i)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}
void print_stack2()
{
    int i;
    for (i = top2; i < SIZE; ++i)
    {
        printf("%d   ", ar[i]);
    }
    printf("\n");
}

int main()
{
    int ar[SIZE];
    int i, m = 10, n = 200;
    int num_of_ele;
    printf("Total of 10 values can be pushed\n");
    for (i = 1; i <= 6; ++i)
    {
        push_stack1(m);
        printf("Value Pushed in Stack 1 is '%d'\n", m);
        m++;
    }
    printf("\n");
    for (i = 1; i <= 4; ++i)
    {
        push_stack2(n);
        printf("Value Pushed in Stack 2 is '%d'\n", n);
        n++;
    }
    printf("\n");
    print_stack1();
    print_stack2();
    printf("\n");
    printf("Pushing Value in Stack 1 is '%d'\n", 77);
    push_stack1(77);
    num_of_ele = top1 + 1;
    printf("\n");
    while (num_of_ele)
    {
        pop_stack1();
        --num_of_ele;
    }
    pop_stack1();
    int um;
    um = top2 - 1;
    printf("\n");
    while (um)
    {
        pop_stack2();
        --um;
    }
    return 0;
}