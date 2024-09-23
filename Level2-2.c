#include <stdio.h>
#include <string.h>

struct item{
    char name;
    int price;
    int count;
    int number;
    int sign;
};

int change(char a){
    return(a-'0');
}

int main(){
    struct item a[5];
    struct item back[3];
    for(int i=0;i<3;i++){
        back[i].number=0;
        back[i].count=0;
        back[i].price=0;
        back[i].name='0';
        back[i].sign=0;
    }
    for(int i=0;i<5;i++){
        a[i].count=0;
        a[i].price=0;
        a[i].number=0;
        a[i].name='0';
        a[i].sign=1;
    }
    first:
    while(1){
        int num1,num,i=0;
        char test[5];
        scanf("%s",&test);
        if(strcmp(test,"END")==0){
            back[2]=back[1],back[1]=back[0],back[0].number=100;
            break;
        }else if(strcmp(test,"back")==0){
            if(back[0].sign==0){
                printf("无法进行回退操作\n");
            }else{
                a[back[0].number-1].count-=back[0].count;
                if(a[back[0].number-1].count==0){
                    a[back[0].number-1].price=0;
                    a[back[0].number-1].number=0;
                    a[back[0].number-1].name='0';
                }
                back[0]=back[1],back[1]=back[2],back[2].sign=0;
            }
        }else{
            scanf("%d",&num1);
            num=num1-1;
            int price,count;
            scanf("%d %d",&price,&count);
            if(num>=5||num<0){
                printf("无该通道,通道数为5\n");
                i++;
            }
            if(i!=0){
                again:printf("请重新摆放货物\n");
                i=0;
            }else{
                if(a[num].count==0){
                    if(count>50||count<=0){
                        printf("无法摆放,货物数量在0-50之间\n");
                        goto again;
                    }
                    a[num].name=test[0];
                    a[num].count+=count;
                    a[num].price=price;
                    a[num].number=num1;
                    back[2]=back[1],back[1]=back[0],back[0]=a[num],back[0].count=count;
                }else if(a[num].count!=0&&a[num].name==test[0]){
                    if(a[num].name==test[0]||a[num].name=='0'){
                        if(a[num].price!=price){
                            printf("价格不符,该货物价格应为%d",a[num].price);
                            goto again;
                        }
                        a[num].count+=count;
                    }else{
                        printf("此通道已被占用");
                    goto again;
                    }
                }else{
                    printf("此通道已被占用");
                    goto again;
                }
            }
            scanf("\n");
        }
    }
    int total=0,x=0;
    while(x==0){
    second:
    while(1){
        int num1,num,i=0;
        char test[5];
        scanf("%s",&test);
        if(strcmp(test,"END")==0){
            back[2]=back[1],back[1]=back[0],back[0].number=100;
            break;
        }else if(strcmp(test,"back")==0){
            if(back[0].number==100){
                back[0]=back[1],back[1]=back[2],back[2].number=0;
                goto first;
            }else if(back[0].number==0){
                printf("无法进行回退操作\n");
            }else{
                a[back[0].number-1].count+=back[0].count;
                total-=back[0].price;
                back[0]=back[1],back[1]=back[2],back[2].number=0;
            }
        }else{
            scanf("%d",&num1);
            num=num1-1;
            int count;
            scanf("%d",&count);
            if(a[num].count==0){
                printf("该通道无货物\n");
            }else if(a[num].name==test[0]){
                if(a[num].count>=count){
                    total+=count*a[num].price;
                    a[num].count-=count;
                    a[num].number=num1;
                    back[2]=back[1],back[1]=back[0],back[0]=a[num],back[0].count=count;
                    back[0].price=count*a[num].price;
                }else if(a[num].count<count){
                    printf("购买数量大于库存，无法购买\n");
                }
            }else{
                printf("该通道无此货物，无法购买\n");
            }
        }
    }
    int putin=0;
    while(putin<total||total==0){
        char put[5];
        scanf("%s",&put);
        if(strcmp(put,"back")==0){
            if(back[0].number==100){
                back[0]=back[1],back[1]=back[2],back[2].number=0;
                goto second;
            }else if(back[0].number==0){
                printf("无法进行回退操作\n");
            }else{
                putin-=back[0].number;
                back[0]=back[1],back[1]=back[2],back[2].number=0;
            }
        }else if(strcmp(put,"END")==0){
            x++;
            break;
        }else if(total==0){
            printf("%d\n",putin);
        }else{
            int put1 =change(put[0]);
            putin+=put1;
            back[2]=back[1],back[1]=back[0],back[0].number=put1;
        }
    }
    if(x==0){
        printf("%d\n",putin-total);
    }
    }
    return 0;
}
