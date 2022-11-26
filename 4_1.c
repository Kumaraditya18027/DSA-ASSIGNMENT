#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *first=NULL;
void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node*p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void reverse(struct  node*p)
{
    if(p)
    {
        reverse(p->next);
        printf("%d ",p->data);
    }   
}
void insert(struct node*p,int pos,int x)
{
    struct node*t;
    if(pos==0)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        int i=0;
        p=first;
        for(i=0;i<pos-1&&p;i++)
        p=p->next;
        if(p)
        { 
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;

        }
    }
    
}
int delete(struct node *p,int pos)
{
    struct node *q,*r;
    int x=-1,i;
    if(pos==1)
    {
        x=p->data;
        q=p;
        p=p->next;
        free(q);
    }
    else 
    {
       q=p;
       r=NULL;
       for(i=0;i<pos-1;i++)
       {
         r=q;
         q=q->next; 
       }
       if(q)
       {
         x=q->data;
         r->next=q->next;
         free(q);
       }
    }

}
void sortList() 
{  
        
        struct node *current = first, *index = NULL;  
        int temp;  
          
        if(first == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                
                index = current->next;  
                  
                while(index != NULL) {  
                      
                    if(current->data > index->data) {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
}  
void main()
{
       int *a;
       int i,n,x,c,d,p;
     //printf("Enter how many number you want to add to the linked list intially\n");
     //scanf("%d",&n);
     //for(i=0;i<n;i++)
     //{ 
     //   printf("Enter the element %d ",i+1);
     //   scanf("%d",&a[i]);   
     //}
     //create(a,n);
       printf("1 for insert\n2 for delete\n3 for display\n4 for reverse\n5 for sorting\n0 for exit\n");

       do{
            printf("Enter your choice\n");
            scanf("%d",&c);
            switch(c)
            {
                case 1:printf("Enter the element you want to insert and also the positon of the element\n");
                       scanf("%d %d",&x,&p);
                       insert(first,p,x);
                       break;
                case 2:printf("From which positon you want to delete\n");
                       scanf("%d",&d);
                       delete(first,d);
                       break;
                case 3:display(first);
                       break;
                case 4:reverse(first);
                       break;
                case 5:printf("The sorted list is \n");
                       sortList();
                       display(first);
                       break;
                case 0:break;
            
            }
        printf("\n");
       }while(c!=0);
       
    
}

