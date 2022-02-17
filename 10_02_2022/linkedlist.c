#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
//insert node at first
struct Node * insertAtFirst(struct Node *head, int data){
	struct Node*new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data  = data;
	new_node->next = head;
	head = new_node;
}
//insert node at last
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while(p->next!=NULL){
        p=p->next;
    }

    p->next = ptr;
    ptr->next=NULL;
    return head; 
}
//insert node at ith position
struct Node * insertAtPos(struct Node *head, int data, int pos){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=pos-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
//insert after node
struct Node * insertafternode(struct Node *head, int data, int value){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = p->data;

    while (i!=value)
    {
        p = p->next;
        i = p->data;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// delete first element
struct Node * deleteFirst(struct Node *head){
    struct Node *ptr = head;
    head=head->next;
    free(ptr);
    return head;
}
//delete ith element by index
struct Node * deleteAtIndex(struct Node *head,int index){
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
//delete by value
struct Node * deleteByValue(struct Node *head,int value){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data == value){
        p->next=q->next;
        free(q);
    }
    return head;
}
//delete last element
struct Node * deleteAtLast(struct Node *head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
//display linked list
void display(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
//copy
struct Node* copyList(struct Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = head->data;
		newNode->next = copyList(head->next);  
		return newNode;
	}
}
//count elements
int count(struct Node* head)
{
    int count = 0;  
    struct Node* current = head;  
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void main(){
    
    int x1,x2,x3;
    printf("\nEnter 3 elements for defaulf linkedlist:");
    scanf("%d%d%d",&x1,&x2,&x3);
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node* dup = copyList(head);
    
    head->data = x1;
    head->next = second;
 
    second->data = x2;
    second->next = third;
 
    third->data = x3;
    third->next = NULL;
    
    int choice,r,ele,pos;
    do{
        printf("\n1-Insert Node at First\n2-Insert Node at Last\n3-Insert into ith position\n4-Insert after element\n");
	printf("5-delete First\n6-delete using index\n7-delete using value\n8-delete last\n9-traverse list");
	printf("\n10-copy linked list\n11-count elements of linked list\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
    
        switch(choice){
            case 1:
                printf("\nEnter element you want to store at first:");
                scanf("%d",&ele);
                head=insertAtFirst(head,ele);
                break;
                
            case 2:
                printf("\n Enter Element you want to store at End:");
                scanf("%d",&ele);
                head=insertAtEnd(head,ele);
                break;
                
            case 3:
                printf("\n Enter Element you want to store:");
                scanf("%d",&ele);
                printf("\nEnter Position:");
                scanf("%d",&pos);
                head=insertAtPos(head,ele,pos);
                break;
                
            case 4:
                printf("\nEnter Element you want to store:");
                scanf("%d",&ele);
                printf("\nEnter element after which you want to enter:");
                scanf("%d",&pos);
                head=insertafternode(head,ele,pos);
                break;
            case 5:
                head = deleteFirst(head);
                break;
                
            case 6:
                printf("\nEnter Index you want to delete");
                scanf("%d",&pos);
                head = deleteByValue(head,pos);
                break;
            
            case 7:
                printf("\nEnter element you want to delete");
                scanf("%d",&ele);
                head = deleteAtIndex(head,ele);
                break;
                
            case 8:
                head=deleteAtLast(head);
                break;
            
            case 9:
                display(head);
                break;
            
            case 10:
                dup = copyList(head);
				printf("Duplicate ");
				display(dup);
				break;
			
			case 11: 
			    printf("\nTotal Elements: %d",count(head));
			    break;
            default:
                printf("\nInvalid choice...");
        }
        printf("\n Enter 1 to perform operation on linkedlist again...");
        scanf("%d",&r);
    }while(r==1);
}