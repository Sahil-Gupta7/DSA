//Program to Check whether the Input sequence of Brackets is Balanced or Not
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int same(char a, char b)
{
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    return 0;
}
int check(char *a)
{
    char stack[1001], top = -1;
    for (int j = 0; j < strlen(a); j++)
    {
        if (a[j] == '[' || a[j] == '{' || a[j] == '(')
            stack[++top] = a[j];
        if (a[j] == ']' || a[j] == '}' || a[j] == ')')
        {
            if (top == -1)
                return 0;
            else
            {
                if (!same(stack[top--], a[j]))
                    return 0;
            }
        }
    }
    if (top != -1)
        return 0;
    return 1;
}
int main()
{
    int n, valid;
    printf("\n Enter the Number of CHECKS you want to make : ");
    scanf("%d", &n);
    char a[n];
    for (int i = 0; i < n; i++)
    {
        printf("\n\t Enter the Number of Pairs to be Checked : ");
        scanf("%s", a);
        valid = check(a);
        if (valid == 1)
            printf("\t\t YES");
        else
            printf("\t\t NO");
    }
    return 0;
}