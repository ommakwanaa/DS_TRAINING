#include<stdio.h>
#include<string.h>

int main(){
    char poly_1[100], poly_2[100];
    printf("enter the polynomial equation-1: ");
    gets(poly_1);
    printf("enter the polynomial equation-2: ");
    gets(poly_2);
    puts(poly_1);
    puts(poly_2);
    
    for (int i = 0; i < strlen(poly_1); i++)
    {
        if (isdigit(poly_1[i]))
        {
            printf("%d",poly_1[i]);
        }
        
    }

    for (int i = 0; i < strlen(poly_2); i++)
    {
        if (isdigit(poly_2[i]))
        {
            printf("%d",poly_2[i]);
        }
        
    }
    

    return 0;
}