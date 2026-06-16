#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *next;
};
void push(struct node **head,int *cnt){
    ++(*cnt);
    struct node *nw=(struct node*)malloc(sizeof(struct node));
    printf("Enter value for info of node:");
    scanf("%d",&nw->info);
    nw->next=NULL;
    if (!(*head)){
        *head=nw;
        return;
    }
    nw->next=*head;
    *head=nw;
}
void pop(struct node **head,int *cnt){
    if(!(*head)){
        printf("stack underflow!!\n");
        return;
    }
    *head=(**head).next;
    --(*cnt);
}
void peek(struct node **head){
    if(!(*head)){
        printf("stack is empty!!");
    }
    struct node *temp=*head;
    printf("stack: ");
    while(temp){
        printf("%d ",temp->info);
        temp=temp->next;
    }
    printf("\n");
}
void isempty(struct node **head){
    if(!(*head)) printf("stack is empty!!\n");
    else printf("stack is not empty!!\n");
}
void size(int *cnt){
    printf("size of stack=%d\n",*cnt);
}
int main(){
    struct node *head=NULL;
    int n,count=0;
    while(1){
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. isempty\n");
        printf("5. size\n");
        printf("6. exit\n");
        printf("Enter n for operation in stack=");
        scanf("%d",&n);
        if(n==1) push(&head,&count);
        else if(n==2) pop(&head,&count);
        else if(n==3) peek(&head);
        else if(n==4) isempty(&head);
        else if(n==5) size(&count);
        else if(n==6) break;
        else printf("oops!! u entered wrong input.\n");
    }
}