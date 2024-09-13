#include <stdio.h>

int main(){
    char item;
    int num,price,count,i=0;
    start:scanf("%c",&item);
    scanf("%d %d %d",&num,&price,&count);
    if(num>5||num<=0){
        printf("无该通道,通道数为5\n");
        i++;
    }
    if(count>50||count<=0){
        printf("无法摆放,货物数量在0-50之间\n");
        i++;
    }
    if(price>10||price<=0){
        printf("价格不合适,价格应在0-10之间\n");
        i++;
    }
    if(i!=0){
        printf("请重新摆放货物\n");
        i=0;
        scanf("\n");
        goto start;
    }
    char choice_item;
    int choice_num,choice_count;
    //next_turn:
    scanf("\n%c",&choice_item);
    scanf("%d %d",&choice_num,&choice_count);
    if(choice_count>count){
        printf("购买数量大于库存，无法购买\n");
    }else if(count==0){
        printf("商品已售罄");
    }else{
        int putin=0;
        int total=price*choice_count;
        while(putin<total){
            int put;
            scanf("%d",&put);
            putin+=put;
        }
        count-=choice_count;
        printf("%d\n",putin-total);
    }
    //goto next_turn;
    return 0;
}