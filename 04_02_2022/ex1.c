#include<stdio.h>
int main(){
    int baseadd,indexi;
    printf("address = ");
    scanf("%d",&baseadd);
    scanf("%d",&indexi);
    printf("address = \n");
    int ss=0;
    ss = baseadd+(indexi-1)*sizeof(int);
    printf("%d",ss);

}