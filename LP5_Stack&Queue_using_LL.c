#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top=NULL, *front=NULL, *rear=NULL;

void push(int val)
{
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->data=val;
    new->next=top;
    top=new;
}
void pop()
{
    struct Node *temp;
    if (top==NULL)
        printf("Stack Underflow ");
    else 
    {
        temp=top;
        top=top->next;
        free(temp);
    }
}
void displayStack()
{
    struct Node *temp=top;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

void enQueue(int val)
{
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    if (rear==NULL && front==NULL)
        rear=front=new;
    else
    {
        rear->next=new;
        rear=new;
    }
}
void deQueue()
{
    struct Node *temp;
    if (front==NULL)
        printf("Queue Underflow\n ");
    else 
    {
        temp=front;
        front=front->next;
        if (front==NULL)
            rear=NULL;
        free(temp);
    }
}
void displayQueue()
{
    struct Node *temp=front;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

int main()
{
 int choice, data;
    printf("\n1. Stack PUSH\t2. Stack POP\t3. Display Stack\n4. Queue Insertion\t5. Queue Deletion\t6. Display Queue\n7. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &data);
                enQueue(data);
                break;
            case 5:
                deQueue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
