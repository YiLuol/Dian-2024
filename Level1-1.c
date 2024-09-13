#include <stdio.h>

int main(){
    char item;
    int num,price,count;
    scanf("%c %d %d %d",&item,&num,&price,&count);
    printf("%d: ",num);
    for(int i=0;i<count;i++){
        printf("%c",item);
    }
    printf(" %d",price);
    return 0;
}