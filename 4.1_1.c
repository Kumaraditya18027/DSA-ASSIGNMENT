#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;
void push(int x)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    printf("Stack overflow\n");
    else{
    t->data=x;
    t->next=top;
    top=t;}
}
int pop()
{
    struct node *p;
    if(top==NULL)
    printf("Stack Underflow\n");
    else
    {
    p=top;
    top=top->next;
    int x=p->data;
    free(p);
    return x;
    }
}
void display()
{
    struct node *p=top;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void main()
{
    int choice,p,q;
    printf("\n1. for push\n2 for pop\n3 for display\n0. To quit\n");
    do{
    printf("\nEnter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the number to be pushed in stack\n");
               scanf("%d",&p);
               push(p);
               break;
        case 2:printf("The poped item is %d",pop());
               break;
        case 3:printf("The stack elements are\n");
               display();
               break;
        case 0:exit(1);
               
        default:printf("Wrong choice\n");
                break;
    }
    }while(choice!=0);
}