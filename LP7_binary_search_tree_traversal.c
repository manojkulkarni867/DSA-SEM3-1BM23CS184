#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *create(Node* root, int val){
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node *insert(Node* root, int val){
    if (root == NULL)
        return create(root, val);
    else if (val<(root->data))
        root->left = insert(root->left, val);
    else if (val>(root->data))
        root->right = insert(root->right, val);
    return root;
}

void preOrder(Node *root){
    if (root!=NULL){
        printf(" %d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root){
    if (root!=NULL){
        inOrder(root->left);
        printf(" %d", root->data);
        inOrder(root->right);
    }
}
void postOrder(Node *root){
    if (root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d", root->data);
    }
}


int main()
{
    Node *root = NULL;
    int data, no;
    printf("Enter a new Binary Search Tree\n");
    printf("Enter No. of Nodes: ");
    scanf("%d", &no);
    printf("Enter value: ");
    for(int i=0; i<no;i++){
        scanf("%d", &data);
        if (i==0)
            root=create(root, data);
        else
            insert(root, data);
    }
    printf("\nPre-Order : ");
    preOrder(root);
    printf("\nIn-Order : ");
    inOrder(root);
    printf("\nPost-Order : ");
    postOrder(root);
}
