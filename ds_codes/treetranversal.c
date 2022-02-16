#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* newNode(char data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
//preOrder
void preOrder(struct node* node){
    if(node==NULL){
        return;
    }
    printf("%c ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}
//postOrder
void postOrder(struct node* node){
    if(node==NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%c ",node->data);
}
//inOrder
void inOrder(struct node* node){
    if (node == NULL){
        return;
    }
    inOrder(node->left);
    printf("%c ", node->data);
    inOrder(node->right);
}
void main(){
    struct node * root=newNode('A');
    root->left=newNode('B');
    root->right=newNode('D');
    root->left->left=newNode('C');
    root->right->right=newNode('G');
    root->right->left=newNode('E');
    root->right->left->right=newNode('F');
    printf("\nPre Order traversal:\n");
    preOrder(root);
    printf("\nPost Order traversal:\n");
    postOrder(root);
    printf("\nIn Order traversal:\n");
    inOrder(root);
}