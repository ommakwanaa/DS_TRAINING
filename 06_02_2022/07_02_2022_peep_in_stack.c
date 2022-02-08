#include<stdio.h>
int push(int [],int *,int,int);
int peep(int [],int *t,int);
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
    while(1){
        int z;
        printf("enter location to peep\n");
        scanf("%d",&z);
        int k = peep(s,&top,z);
        if(k!=0){printf("\npeep: %d\n",k);}
        else{
        break;}
        }
}
int push(int a[],int* t,int e,int n){
    if(*t<n){
        printf("%d",*t);
        *t=*t+1;
        a[*t]=e;
        return 1;}
    else{printf("\nstack overflow\n");return 0;}
}
int peep(int a[],int *t,int z){
    if(*t-z+1==0 || *t-z+1>n ){printf("\nstack underflow\n");return 0;}
    else{
        return a[*t-z+1];}
}