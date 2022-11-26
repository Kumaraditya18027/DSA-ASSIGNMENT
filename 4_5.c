#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
//void create(int a[],int n)
//{
//    int i=0,j=0;
//    struct node *t,*last;
//    head=(struct node*)malloc(sizeof(struct node));
//    head->data=a[0];
//    head->next=head;
//    last=head;
//    for(i=1;i<n;i++)
//    {
//        t=(struct node*)malloc(sizeof(struct node));
//        t->data=a[i];
//        t->next=last->next;
//        last->next=t;
//        last=t;
//    }
//}
void display()
{
    struct node *p=head;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while (p!=head);
    
}
void insert(int position,int x)
{
    int i,j;
    struct node *p;
    struct node *t=head;
    
    if(position==1)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
          if(head==NULL)
          {
            head=p;
            head->next=head;
          }
          else
          {
            while(t->next!=head)
           { t=t->next;}
            t->next=p;
            p->next=head;
            head=p;
          }
    }
    else
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        for(i=1;i<position-1;i++)
        {t=t->next;}
        p->next=t->next;
        t->next=p;


    }
}
int delete(int position)
{
   struct node *p=head;
   struct node *q;int x;
   if(position==1)
   {
       x=head->data;
       while(p->next!=head)
       {
           p=p->next;
       }
       p->next=head->next;
       free(head);
       head=p->next;
       return x;
   }
   else
   {
       for(int i=0;i<position-2;i++)
       {
           p=p->next;
       }
       q=p->next;
       x=q->data;
       p->next=q->next;
       free(q);
       return x;
   }
}
void main()
{
       int *a;
       int i,n,x,c,d,p;
       //printf("Enter how many number you want to add to the linked list\n");
       //scanf("%d",&n);
       //for(i=0;i<n;i++)
       //{ 
       //   printf("Enter the element %d ",i+1);
       //   scanf("%d",&a[i]);   
       //}
       //create(a,n);
       printf("1 for insert\n2 for delete\n3 for display\n0 for exit\n");

       do{
            printf("Enter your choice\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:printf("Enter the element you want to insert and also the positon of the element\n");
                       scanf("%d %d",&x,&p);
                       insert(p,x);
                       break;
                case 2:printf("From which positon you want to delete\n");
                       scanf("%d",&d);
                       delete(d);
                       break;
                case 3:display();
                       break;
                
                case 0:break;
            
            }
        printf("\n");
       }while(c!=0);
       
    
}