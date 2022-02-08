#include<stdio.h>
int push(int [],int *,int,int);
int change(int [],int *,int,int);
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
    int po,nv;
    printf("\nenter the position and new value:");
    scanf("%d\n%d",&po,&nv);
    change(s,&top,po,nv);}
        
}
int push(int a[],int* t,int e,int n){
    if(*t<n){
        *t=*t+1;
        a[*t]=e;
        return 1;}
    else{printf("\nstack overflow\n");return 0;}
}
int change(int a[],int* t,int po,int nv){
    if(*t-po+1==0 || *t-po+1>n ){printf("\nstack underflow\n");return 0;}
    else{
        a[*t-po+1]=nv;
        for(int i=n;i>=1;i--){printf("push%d\n",s[i]);}
        printf("\nthe change value is %d at location %d\n",a[*t-po+1],*t-po+1);
        }
}