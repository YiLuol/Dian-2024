#include <stdio.h>

int main(){
    int price;
    scanf("%d",&price);
    int putin=0;
    while(putin<price){
        int put;
        scanf("%d",&put);
        putin+=put;
    }
    printf("%d",putin-price);
    return 0;
}