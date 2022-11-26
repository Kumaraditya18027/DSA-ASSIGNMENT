#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue(int x)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("Queue is full\n");
    }
    else
    {  t->data=x;
      t->next=NULL;
     if(front==NULL)
     {
        front=rear=t;
     }
     else
     {
        rear->next=t;
        rear=t;
     }
    }
}
int dequeue()
{
    int x=-1;
    struct node*p;
    p=front;
    if(front==NULL)
    printf("Queue is empty\n");
    else
    {
        front=front->next;
        x=p->data;
        free(p);
        return x;
    }
}

void display()
{
    struct node *p;
    p=front;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void main()
{
    int choice,p,q;
    printf("\n1 for insertion\n2 for deletion\n3 for display\n0 To quit\n");
    do{
    printf("\nEnter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the number to be inserted in Queue\n");
               scanf("%d",&p);
               enqueue(p);
               break;
        case 2:printf("The deleted item is %d",dequeue());
               break;
        case 3:printf("The Queue elements are\n");
               display();
               break;
        case 0:exit(1);
               
        default:printf("Wrong choice\n");
                break;
    }
    }while(choice!=0);


}