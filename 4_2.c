#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int coeff;
    int expo;
    struct node*next;
}*poly1=NULL;struct node*poly2=NULL;
void create1()
{
   int num,i=0;
   struct node *t,*last=NULL;
   printf("Enter the no. of elements in 1st polynomial\n");
   scanf("%d",&num);
   printf("Enter the coeff elements and their exponents\n");
   for(i=0;i<num;i++)
   {
      t=(struct node*)malloc(sizeof(struct node));
      scanf("%d%d",&t->coeff,&t->expo);
      t->next=NULL;
      if(poly1==NULL)
      {
        poly1=last=t;
      }
      else{
        last->next=t;
        last=t;
      }
   }

}
void create2()
{
   int num,i=0;
   struct node *t,*last=NULL;
   printf("Enter the no. of elements in 2nd polynomial\n");
   scanf("%d",&num);
   printf("Enter the coeff elements and their exponents\n");
   for(i=0;i<num;i++)
   {
      t=(struct node*)malloc(sizeof(struct node));
      scanf("%d%d",&t->coeff,&t->expo);
      t->next=NULL;
      if(poly2==NULL)
      {
        poly2=last=t;
      }
      else{
        last->next=t;
        last=t;
      }
   }

}
void display(struct node *p)
{
    while(p)
    {
        printf("%dx^%d+",p->coeff,p->expo);
        p=p->next;
    }
    printf("\n");
} 

void add(struct node **result)
{
    struct node*p=poly1,*q=poly2;
    struct node *res=NULL,*last=NULL;
    res=(struct node*)malloc(sizeof(struct node));
    res->next=NULL;
    *result=res;
    while(p&&q)
    {
        if(p->expo<q->expo)
        {
            res->coeff=p->coeff;
            res->expo=p->expo;
            p=p->next;
        }
        else if(p->expo>q->expo)
        {
            res->coeff=q->coeff;
            res->expo=q->expo;
            q=q->next;
        }
        else
        {
            res->coeff=p->coeff+q->coeff;
            res->expo=p->expo;
            p=p->next;
            q=q->next;
        }
        if(p&&q)
        {
            res->next=(struct node*)malloc(sizeof(struct node));
            res=res->next;
            res->next=NULL;
        }
    }
    while(p||q)
    {
        res->next=(struct node*)malloc(sizeof(struct node));
        res=res->next;
        res->next=NULL;
        if(p)
       { res->coeff=p->coeff;
        res->expo=p->expo;
        p=p->next; 
       }
       else if(q)
      {
          res->coeff=q->coeff;
          res->expo=q->expo;
          q=q->next;
      }
       
            
    }
    
    
}

void main()
{
    struct node *result;
    create1();
    create2();
    display(poly1);
    display(poly2);
    add(&result);
    display(result);
}