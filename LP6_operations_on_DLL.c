#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev; 
};
struct Node *create(int val)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void createList(struct Node **head, int val){
    *head=create(val);
}

void insertLeft (struct Node **head, int find, int val){
    if ((*head)==NULL){
        printf("No LL Exist");
        return;
    }
    struct Node *temp=*head;
    struct Node *new=create(val);
    while(temp!=NULL && temp->data!=find){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("No Node found with value %d", find);
        return;
    }
    new->next=temp;
    new->prev=temp->prev;
    if (temp->prev!=NULL)
        temp->prev->next=new;
    else   
        (*head)=new;
    temp->prev=new;
}

void deleteVal (struct Node **head, int del){
    if ((*head)==NULL){
        printf("LL doesn't exist");
        return;
    }
    struct Node *temp=*head;
    while(temp!=NULL && temp->data!=del){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("No Node found with value %d", del);
        return;
    }
    if (temp->prev!=NULL)
        temp->prev->next=temp->next;
    else   
        (*head)=temp->next;
    if (temp->next!=NULL)
        temp->next->prev=temp->prev;
    free(temp);
}

void display(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp=temp->next;
    }
}

int main(){
    struct Node *head = NULL;
    int choice, data, pos;
    printf("\n1. Create a new LL\t2. Insert Left to\t3. Delete by value\t4. Display\t5. Exit\t\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                createList(&head, data);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                printf("Enter to the left of value: ");
                scanf("%d", &pos);
                insertLeft(&head, pos, data);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteVal(&head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
