#include <stdio.h>

#define MAX 2  

typedef struct 
{
    int s1[MAX];  
    int s2[MAX];  
    int top1;         
    int top2;         
} MyQueue;

MyQueue myQueueCreate() {
    MyQueue queue;
    queue.top1 = -1;  
    queue.top2 = -1;
    return queue;
}

// Push in s1
void myQueuePush(MyQueue* obj, int x) {
    if ((*obj).top1 == MAX - 1) {
        printf("Queue is full\n");
        // return;
    }
    else
        (*obj).s1[++((*obj).top1)] = x;  
}

int myQueuePop(MyQueue* obj) 
{
    int val;
    // s1 to s2
    if ((*obj).top2 == -1) 
    {
        while ((*obj).top1 != -1) 
        {
            (*obj).s2[++((*obj).top2)] = (*obj).s1[((*obj).top1)--];
        }
        (*obj).top1 = -1;
    }

    // Pop and S2 to back to s1
    if ((*obj).top2 == -1) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        val = (*obj).s2[((*obj).top2)--];
        while ((*obj).top2 != -1)
        {
            (*obj).s1[++((*obj).top1)] = (*obj).s2[((*obj).top2)--];
        }
        (*obj).top2 = -1;
    }
    return val;
}

// Displaying Queue
void myQueuePeek(MyQueue* obj) 
{
    int i = (*obj).top1;
    if ((*obj).top2 == -1)
    {
        while ((*obj).top1 != -1) 
        {
            (*obj).s2[++((*obj).top2)] = (*obj).s1[((*obj).top1)--];
        }
        (*obj).top1 = i;
    }

    if ((*obj).top2 == -1) 
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue =  ");
        while ((*obj).top2 != -1)
        {
            printf("%d\t", (*obj).s2[(*obj).top2--]);
        }
        (*obj).top2 = -1;
    }
}

// int myQueueEmpty(MyQueue* obj) 
// {
//     printf("Queue is empty now");
//     return ((*obj).top1 == -1 && (*obj).top2 == -1);
// }

// void myQueueFree(MyQueue* obj) {
//     // No memory to free since we are not using dynamic allocation
// }

int main() {
    MyQueue obj = myQueueCreate();   //Imp
    int opt, in;
    while (1)
    {
        printf("\n1=Push\t2=Pop\t3=Display\t4=Exit");
        printf("\nSelect Option: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
            {
                printf("Enter Push Element: ");
                scanf("%d", &in);
                myQueuePush(&obj, in);  
                break;
            }
            case 2:
            {
                myQueuePop(&obj);
                break;
            }
            case 3:
            {
                myQueuePeek(&obj);
                break;
            }
            case 4:
            {
                printf("Program Exited");
                return 0;
            }
            default:
                printf("Invalid Operations");
        }
    }
    return 0;
}
