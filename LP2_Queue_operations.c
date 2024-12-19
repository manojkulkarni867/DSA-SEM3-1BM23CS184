#include <stdio.h>
#define MAX 2

int queue[MAX];
int front=-1, rear=-1;

void insertion(ele)
{
    if (rear == MAX-1)
    printf("Queue Overflow");
    else 
    {
        queue[++rear]=ele;
    }
}
void deletion()
{
    int del;
    if (rear == -1)
    printf("Queue is Empty");
    else
        del=queue[++front];
}
void display()
{
    int i = front;
    if (rear == -1)
    printf("Queue is Empty");
    else 
    {
        printf("Queue = ");
        while (i != rear)
        {
            printf("\t%d", queue[++i]);
        }
    }
}

int main()
{
    int opt, no;
    while (1)
    {
        printf("\n1. Insertion\t2. Deletion\t3. Display\t4. Exit\nEnter Option:");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
            {
                printf("Enter Element: ");
                scanf("%d", &no);
                insertion(no);
                break;
            }
            case 2:
            {
                deletion();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
                return 0;
            default:
                printf("Incorrect Input\nTry Again");
        }
    }
}
