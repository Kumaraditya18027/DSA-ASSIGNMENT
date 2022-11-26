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

void add()
{
    struct node*p=poly1,*q=poly2;
    struct node *res=NULL,*last=NULL,*r1=NULL;
    while(p&&q)
    {
        res=(struct node*)malloc(sizeof(struct node));
        if(p->expo<q->expo)
        {
            res->coeff=p->coeff;
            res->expo=p->expo;
            if(r1==NULL)
            {
                res->next=NULL;
                r1=res;
                last=res;
            }
            else
            {
               last->next=res;
               last=res; 
            }
            p=p->next;
        }
        else if(p->expo>q->expo)
        {
            res->coeff=q->coeff;
            res->expo=q->expo;
             if(r1==NULL)
            {
                res->next=last;
                r1=res;
                last=res;
            }
            else
            {
               last->next=res;
               last=res; 
            }
            q=q->next;
        }
        else
        {
            res->coeff=p->coeff+q->coeff;
            res->expo=p->expo;
             if(r1==NULL)
            {
                res->next=last;
                r1=res;
                last=res;
            }
            else
            {
               last->next=res;
               last=res; 
            }
             p=p->next;
             q=q->next;
        }
    }
    while(p)
    {
        res=(struct node*)malloc(sizeof(struct node));
        res->coeff=p->coeff;
        res->expo=p->expo;
        last->next=res;
        last=res;
        p=p->next; 
            
    }
    while(q)
    {
        res=(struct node*)malloc(sizeof(struct node));
        res->coeff=q->coeff;
        res->expo=q->expo;
        last->next=res;
        last=res;
        q=q->next; 
            
    }
    last->next=NULL;
    printf("The resultant  is\n");
    display(r1);
    
}

void main()
{
    create1();
    create2();
    display(poly1);
    display(poly2);
    add();
}
