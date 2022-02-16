#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
    struct Node *head;
    struct Node *second;
//1.insert at first
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node *temp=NULL;
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
	new_node->data=data;
	new_node->next=NULL;
	temp=head;
	while(temp->next!=head)
	    temp=temp->next;
	temp->next=new_node;
	new_node->next=head;
	head=new_node;
	
	return head;
} 
//2.insert at last
struct Node * insertAtLast(struct Node *head,int data){
    struct Node *temp;
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data=data;
	temp=head;
    while(temp -> next != head)  {  
        temp = temp -> next;  
    }  
    temp -> next = new_node;   
    new_node -> next = head;  
    return head;
}  
//3.insertion at ith position
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
//4.delete first
struct Node * deleteFromFirst(struct Node *head){
    struct Node *temp;
	temp=head;
	while(temp->next!=head)
	    temp=temp->next;
	temp->next=head->next;
	free(head);
	head=temp->next;
	return head;
} 
//5.delete Last
struct Node * deleteFromLast(struct Node *head){
    struct Node *temp,*preptr;
    temp=head;
    while(temp->next!=head){
        preptr=temp;   
        temp=temp->next;
    }
    preptr->next=temp->next;
    free(temp);
    
    return head;
}
//7. delete ith position
struct Node * deleteAtIthIndex(struct Node *head,int index){
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
//8.search
struct Node * search(struct Node *head,int item){
    struct Node *ptr;
    int i=1,flag=0;
    ptr=head;
    if(head->data==item){
        printf("Element found at %d location",i);
        flag=0;
    }
    while(ptr->next!=head){
        if(ptr->data==item){
            printf("Element found at %d location.",i);
            flag=0;
            break;
        }
        else{
            flag=1;
        }
        i++;
        ptr=ptr->next;
    }
    if(flag!=0){
        printf("\nElement not found\n");
    }
}
//8.display
void display(){
    struct Node *ptr;
    ptr=head;
    if(head==NULL)
        printf("\nLinkedList is empty...\n");
    else{
        while(ptr->next!=head){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d ",ptr->data);
    }
}
void main(){

    int choice,ag,ele,pos;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = second;
    
    second->data=20;
    second->next=head;
    printf("\n1-insert begining\n2-insert last\n3-inser at ith position\n4-delete begining\n5-delete last\n6-delete from ith position\n7-search\n8-display");
    do{
        printf("\nEnter your choice:");
        scanf("%d",&choice);    
        switch(choice){
            case 1:
                //insert at begining
                printf("\nEnter Element to insert at first:");
                scanf("%d",&ele);
                head=insertAtFirst(head,ele);
                break;
                
            case 2:
                //insert at last
                printf("\nEnter Element to insert at Last:");
                scanf("%d",&ele);
                head=insertAtLast(head,ele);
                break;
                
            case 3:
                printf("\nEnter Element to insert at ith position:");
                scanf("%d",&ele);
                printf("\nEnter position to insert element:");
                scanf("%d",&pos);
                head=insertAtPos(head,ele,pos);
                break;
                
            case 4:
                //delete first
                head=deleteFromFirst(head);
                break;
            case 5:
                //delete last
                head=deleteFromLast(head);
                break;
            case 6:
                //delete ith position
                printf("\nEnter position to delete element:");
                scanf("%d",&pos);
                head=deleteAtIthIndex(head,pos);
                break;
            case 7:
                //search
                printf("Enter Element to search:");
                scanf("%d",&ele);
                search(head,ele);
                break;
                
            case 8:
                //display
                display();
                break;
                
            default:
                printf("\nInvalid Choice...");
                break;
        }
        printf("\nperform operation again? yes-1 no-0:");
        scanf("%d",&ag);
    }while(ag==1);
}