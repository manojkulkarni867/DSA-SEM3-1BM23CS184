#include <stdio.h>

void insert(int *queue, int *front ,int *rear, int value, int MAX){
    if ((*front ==0 && *rear == (MAX -1)) || (*rear == *front -1))
    // if ((*rear + 1) % MAX == *front)
    {
        printf("Queue Overflow");
        return ;
    }
    else if (*front == -1){
        *front = *rear = 0;
        // queue[*rear]=value;
    }
    else if ((*rear == MAX -1 && *front != 0)){
        *rear =0;
        // queue[*rear]=value;
    }
    else{
        (*rear)++;
        // queue[*rear]=value;
    }
    queue[*rear]=value;
}
void delete (int *queue, int *front ,int *rear, int MAX){
    if (*front ==-1){
        printf("Queue Underflow");
    }
    else if (*front == *rear){
        *front = *rear=-1;
    }
    else if (*front == MAX-1){
        *front=0;
    }
    else{
        (*front)++;
    }
}
void display (int *queue, int front ,int rear, int MAX){
    if (front == -1){
        printf("Queue Underflow");
        return;
    }
    printf("Queue = ");
    if (rear >= front){
        for (int i=front; i<=rear;i++){
            printf("%d\t", queue[i]);
        }
    }  
    else{
        for (int j=front; j<MAX; j++){
            printf("%d\t", queue[j]);
        }
        for (int k=0; k<=rear; k++){
            printf("%d\t", queue[k]);
        }
    }  
}

int main()
{
    int MAX = 2;
    int queue[MAX];
    int fr=-1, re=-1;
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
                insert(queue, &fr, &re, no, MAX);
                break;
            }
            case 2:
            {
                delete(queue, &fr, &re, MAX);
                break;
            }
            case 3:
            {
                display(queue, fr, re, MAX);
                break;
            }
            case 4:
                return 0;
            default:
                printf("Incorrect Input\nTry Again");
        }
    }
}
