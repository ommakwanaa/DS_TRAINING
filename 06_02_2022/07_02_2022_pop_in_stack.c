#include<stdio.h>
int push(int [],int *,int,int);
int pop(int [],int *t);
int n=3;
int s[3],top=0;
int main(){
    while(1){
    int x;
    printf("enter elements to push\n");
    scanf("%d",&x);
    int z = push(s,&top,x,n);
    if(z==0){break;}
    else{printf("\nelement pushed\n");}}
    for(int i=n;i>=1;i--){printf("\npush%d\n",s[i]);}
    while(1){
        int k = pop(s,&top);
        if(k!=0){printf("pop: %d\n",k);}
        else{
        break;}
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
    if(*t==0){printf("stack underflow\n");return 0;}
    else{*t=*t-1;return a[*t+1];}
}