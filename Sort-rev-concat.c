#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *create(int val)
{
     Node *newN = (struct Node *) malloc(sizeof(Node));
     newN->data=val;
     newN->next=NULL;
     return newN;
}
Node *insertBeg(Node *head,int val)
{
    Node *new=create(val);
    new->next=head;
    head=new;
    return head;
}

Node *concate(Node *head1, Node *head2)
{
    Node *temp=head1;
    while (temp->next != NULL)
        temp=temp->next;
    temp->next=head2;
    return head1;
}

Node *sort(Node *head)
{
    int t;
    Node *temp, *curr;
    curr=head;
    while (curr!=NULL)
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if ((temp->data) > (temp->next->data))
            {
                t=temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp=temp->next;
        }
        curr=curr->next;
    }
    return head;
}

Node *reverse(Node *head)
{
    Node *temp, *new, *prev=NULL;
    temp = head;
    while (temp!=NULL)
    {
        new=temp->next;
        temp->next=prev;
        prev=temp;
        temp=new;
    }
    return prev;
}

void display(Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    Node *l1 = NULL;
    Node *l2 = NULL;

    l1 = insertBeg(l1, 5);
    l1 = insertBeg(l1, 3);
    l1 = insertBeg(l1, 7);

    l2 = insertBeg(l2, 4);
    l2 = insertBeg(l2, 8);
    l2 = insertBeg(l2, 6);

    printf("List 1 = ");
    display(l1);
    printf("List 2 = ");
    display(l2);

    l1 = sort(l1);
    l2 = sort(l2);

    l2 = reverse(l2);
                                                                                                                                                                                                                                                                                  
    printf("Sorted List 1 = ");
    display(l1);
    printf("Sorted and then Reversed List 2 = ");
    display(l2);

    printf("List 1 + List 2 = ");
    l1=concate(l1, l2);
    display(l1);
}
