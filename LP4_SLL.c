#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

void insertBeg(struct Node **head, int val){
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->data=val;
    new->next=*head;
    *head = new;
}

void insertEnd(struct Node **head, int val){
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->data=val;
    new->next=NULL;
    if (*head == NULL){
        *head=new;
        return;
    }    
    struct Node *temp = *head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=new;
}

void insertPos(struct Node **head, int val, int pos){
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new->data=val;
    if (pos==0){
        new->next=*head;
        *head = new;
        return;
    }
    struct Node *temp = *head;
    for (int i=0; temp->next!=NULL && i < pos-1; i++){
        temp = temp->next;
    }    
    if (temp == NULL){
        printf("Out of Range");
        return;
    }
    new->next=temp->next;
    temp->next = new;
}

void deleteBeg(struct Node **head){
    if (*head == NULL){
        printf("Empty LL");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteEnd(struct Node **head){
    if (*head == NULL){
        printf("Empty LL");
        return;
    }
    struct Node *temp = *head;
    if(temp->next == NULL){
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void deleteVal(struct Node **head, int val){
    if (*head == NULL){
        printf("Empty LL");
        return;
    }
    struct Node *temp = *head;
    if (temp->data == val){
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next->data!=val){
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("Value not present in LL");
        free(temp);
        // return;
    }
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next; // Bypass the node to be deleted
    free(toDelete);
}

void display(struct Node **head){
    struct Node *temp = *head;
    if (*head == NULL){
        printf("Empty LL");
        return;
    }
    printf("Queue = ");
    while (temp!=NULL){
        printf("\t%d", temp->data);
        temp = temp->next;
    }
    
}

int main(){
    struct Node *head = NULL;
    int choice, data, pos;
    printf("\n1. Insert at beginning\t2. Insert at end\t3. Insert at position\n4. Delete from beginning\t5. Delete from end\t6. Delete by Value\n7. Display\t8. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertBeg(&head, data);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter value & position: ");
                scanf("%d %d", &data, &pos);
                insertPos(&head, data, pos);
                break;
            case 4:
                deleteBeg(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &pos);
                deleteVal(&head, pos);
                break;
            case 7:
                display(&head);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
