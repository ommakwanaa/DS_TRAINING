#include<stdio.h>
int push(int [],int *,int,int);
int pop(int [],int *t);
int peep(int [],int *t,int);
int change(int [],int *,int,int);
int n=0;
int s[10],top=0;
int x;
int main(){
    printf("Hey!! Wellcome to stack operations\n");
    printf("lets start with creating a stack\nenter number of value you want to push\n");
    scanf("%d",&n);

    // pushing to stack
    for(int p=0;p<n;p++){
        printf("Enter %d value to push: ",p+1);
        scanf("%d",&x);
        int z = push(s,&top,x,n);
        if(z==0){break;}
        else{printf("pushed\n\n");}}
    // pushing to stack

    // printing from stack
    printf("\nvalue you have pushed are....\n");
    for(int i=n;i>=1;i--){printf("push%d\n",s[i]);}
    // printing from stack

    // operation of stack
    int sc;
    printf("\n1 = pop\n2 = peep\n3 = change\n4 = quit\n-->");
    scanf("%d",&sc);
    switch(sc){
        case 1:
        while(1){
        int k = pop(s,&top);
        if(k!=0){printf("pop: %d\n",k);}
        else{
        break;}
        }break;
        case 2:
        while(1){
        int z;
        printf("enter location to peep\n");
        scanf("%d",&z);
        int k = peep(s,&top,z);
        if(k!=0){printf("\npeep: %d\n",k);}
        else{
        break;}
        }break;
        case 3:
        while(1){
        int po,nv;
        printf("\nenter the position and new value:");
        scanf("%d\n%d",&po,&nv);
        change(s,&top,po,nv);}break;
        case 4:
        break;
        // operation of stack
    }
}


int push(int a[],int* t,int e,int n){
    if(*t<n){
        *t=*t+1;
        a[*t]=e;
        return 1;}
    else{printf("\nstack overflow\n");return 0;}
}

int pop(int a[],int *t){
    if(*t==0){printf("\nstack underflow\n");return 0;}
    else{*t=*t-1;return a[*t+1];}
}

int peep(int a[],int *t,int z){
    if(*t-z+1==0 || *t-z+1>n ){printf("\nstack underflow\n");return 0;}
    else{
        return a[*t-z+1];}
}

int change(int a[],int* t,int po,int nv){
    if(*t-po+1==0 || *t-po+1>n ){printf("\nstack underflow\n");return 0;}
    else{
        a[*t-po+1]=nv;
        for(int i=n;i>=1;i--){printf("push%d\n",s[i]);}
        //printf("\nthe change value is %d at location %d\n",a[*t-po+1],*t-po+1);
        }
}
