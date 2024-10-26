#include <stdio.h>

#define MAX 5
int stack[MAX];
int top = -1;

void push(int ele)
{
    if (top == (MAX-1))
        printf("Stack Overflow");
    else
    {
        top = top + 1;
        stack[top] = ele;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow ");
    else 
    {
        int popele = stack[top];
        printf("Pop element = %d", popele);
        top--;
    }
}

void display()
{
    if (top == -1)
        printf("Stack is empty");
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\n%d", stack[i]);
        }
    }
}

int main()
{
    int opt, in;
    while (1)
    {
        printf("\n\n1=Push\t2=Pop\t3=Display\t4=Exit");
        printf("\nSelect Option: ");
        scanf("%d", &opt);

        if (opt == 1)
        {
            printf("Enter Push Element: ");
            scanf("%d", &in);
            push(in);
        }
        else if (opt == 2)
        {
            pop();
        }
        else if (opt == 3)
        {
            display();
        }
        else if (opt == 4)
        {
            printf("Program Exited");
            return 0;
        }
        else
        {
            printf("Invalid Operation");
        }
    }
    return 0;
}
