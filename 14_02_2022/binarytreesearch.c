#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
//insert
struct node* insert(struct node* node,int data){
    if(node==NULL){
        return newNode(data);
    }
    if(data < node->data){
        node->left=insert(node->left,data);
    }
    else if(data>node->data){
        node->right=insert(node->right,data);
    }
    return node;
}

//inOrder
void inOrder(struct node* node){
    if (node == NULL){
        printf("Empty");
    }
    else{
        if(node->left!=NULL){
            inOrder(node->left);
        }
        printf("%d ", node->data);
        if(node->right!=NULL){
            inOrder(node->right);
        }
    }
}
// void search(struct node* node,int ele){
//     int flag=0;
//     printf("%d",ele);
//     if (node->data == ele){
//         printf("\nElement Found");
//         flag=1;
//     }
//     else{
//         if(node->left!=NULL){
//             if(node->data!=ele)
//             inOrder(node->left);
//         }
//         printf("\nElement Found");
//         flag=1;
//         if(node->right!=NULL){
//             if(node->data!=ele)
//             inOrder(node->right);
//         }
//         printf("\nElement Found");
//         flag=1;
//     }
//     if(flag!=1){
//         printf("\nElement not found...");
//     }
// }

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
//search
struct node* search(struct node* root,int ele){
    // struct node* current = root;
    // int flag=0;
    if(root==NULL){
        return NULL;
    }
    if(root->data==ele){
        return root;
    }
    else if(root->data>ele){
        return search(root->left,ele);
    }
    else{
        return search(root->right,ele);
    }
}
//delete
struct node* deleteNode(struct node* root, int key){
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void main(){
    int x;
    struct node* root=NULL;
    root=insert(root,50);
    insert(root,25);
    insert(root,75);
    insert(root,22);
    insert(root,40);
    insert(root,60);
    insert(root,80);
    insert(root,90);
    insert(root,15);
    insert(root,30);
    
    inOrder(root);
    
    printf("\nenter element to search");
    scanf("%d",&x);
    struct node* n = search(root, x);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
    // root=search(root,x);
    printf("\nenter element to delete:");
    scanf("%d",&x);
    root = deleteNode(root, x);
    printf("Inorder traversal of the tree \n");
    inOrder(root);
 
    // printf(search(root,x));
}