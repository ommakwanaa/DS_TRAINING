#include<stdio.h>
int main(){
    int baseadd,row,rc, column, trow,tcol,totalans;

    printf("\nbase address:  ");
    scanf("%d",&baseadd);
    printf("\nrow address:  ");
    scanf("%d",&row);
    printf("\ncolumn address:  ");
    scanf("%d",&column);
    printf("\nenter 1 for row major system or 0 for column major system");
    scanf("%d",&rc);
    if(rc==0){
        printf("\nenter number of colums:  ");
        scanf("%d",&trow);
        totalans= baseadd+sizeof(int)*((column-1)*trow+(row-1));
    }
    else{
        printf("\nenter number of rows:  ");
        scanf("%d",&tcol);
        totalans= baseadd+sizeof(int)*((column-1)+(row-1)*tcol);        
    }
    printf("\naddress is:  %d",totalans);

}