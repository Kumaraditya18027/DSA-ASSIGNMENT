#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;
//void create(int *a,int n)
//{
//    int i,j;
//    struct node *t,*last;
//    first=(struct node *)malloc(sizeof(struct node));
//    first->prev=NULL;
//    first->data=a[0];
//    first->next=NULL;
//    last=first;
//    for(i=1;i<n;i++)
//    {
//      t=(struct node *)malloc(sizeof(struct node));
//      t->data=a[i];
//      t->next=last->next;
//      t->prev=last;
//      last->next=t;
//      last=t;
//
//    }
//}
void display()
{
    struct node *p=first;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void reverse(struct node *p)
{
     if(p)
     {
        reverse(p->next);
        printf("%d ",p->data);
     }
}
void insert(int position,int x)
{
    struct node *p=first;
    struct node *t;
    if(position==1)
    {
        t=(struct node*)malloc(sizeof(struct node));
        if(first==NULL)
        {
            t->data=x;
            t->prev=NULL;
            t->next=NULL;
            first=t;
        }
        else
        {
            t->data=x;
            t->prev=NULL;
            t->next=first;
            first->prev=t;
            first=t;
        }
    }
    else
    {
         t=(struct node *)malloc(sizeof(struct node));
         for(int i=1;i<position-1;i++)
         {
            p=p->next;   
         }
         t->data=x;
         t->next=p->next;
         t->prev=p;
         if(p->next)
         p->next->prev=t;
         p->next=t;
    }
}
int delete(int position)
{
    int x;
    struct node *p=first;
     if(position==1)
     {
          first=first->next;
          x=p->data;
          if(first)
          first->prev=NULL;
          free(p);
          return x;    
     }
     else
     {
        for(int i=0;i<position-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        p->next->prev=p->prev;
        x=p->data;
        free(p);
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
      //printf("1 for insert\n2 for delete\n3 for display\n4 for reverse\n0 for exit\n");

       do{
            printf("Enter your choice\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:printf("Enter the element you want ot insert and also the positon of the element\n");
                       scanf("%d %d",&x,&p);
                       insert(p,x);
                       break;
                case 2:printf("From which positon you want to delete\n");
                       scanf("%d",&d);
                       delete(d);
                       break;
                case 3:display();
                       break;
                case 4:reverse(first);
                       break;
                case 0:break;
            
            }
        printf("\n");
       }while(c!=0);
       fflush(stdin);
       getchar();//just to hold the cmd screen
    
}