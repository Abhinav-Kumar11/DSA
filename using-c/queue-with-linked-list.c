#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *next;
};
void enqueue(struct node **front,struct node **rear,int *cnt){
    ++(*cnt);
    struct node *nw=(struct node*)malloc(sizeof(struct node));
    if (!nw) {                  
    printf("Memory allocation failed!\n");
    return;
    }
    printf("Enter value for info of node:");
    scanf("%d",&nw->info);
    nw->next=NULL;
    if(!(*front)){
        *front=nw;
        *rear=nw;
        return;
    }
    (*rear)->next=nw;
    *rear=nw;
}
void dequeue(struct node **front,struct node **rear,int *cnt){
    if(!(*front)){
        printf("queue underflow!!\n");
        return;
    }
    --(*cnt);
    *front=(*front)->next;
}
void peek(struct node **front){
    if(!(*front)){
        printf("Queue is empty!!\n");
    }
    struct node *temp=*front;
    printf("queue: ");
    while(temp){
        printf("%d ",temp->info);
        temp=temp->next;
    }
    printf("\n");
}
void isempty(struct node **front){
    if(!(*front)) printf("Queue is empty!!\n");
    else printf("Queue is not empty!!\n");
}
void size(int *cnt){
    printf("size of queue=%d\n",*cnt);
}
int main(){
    struct node *front=NULL,*rear=NULL;
    int n,count=0;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. peek\n");
        printf("4. isempty\n");
        printf("5. size\n");
        printf("6. exit\n");
        printf("Enter n for operation in stack=");
        scanf("%d",&n);
        if(n==1) enqueue(&front,&rear,&count);
        else if(n==2) dequeue(&front,&rear,&count);
        else if(n==3) peek(&front);
        else if(n==4) isempty(&front);
        else if(n==5) size(&count);
        else if(n==6) break;
        else printf("oops!! u entered wrong input.\n");
    }
}