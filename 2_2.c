#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;
void push(int x)
{
  struct node *t=(struct node*)malloc(sizeof(struct node));
   if(t==NULL)
   printf("Stack overflow\n");
   else
   {
    t->data=x;
    t->next=top;
    top=t;
   }  
}
int  pop()
{
    struct node *p;
    char  x=-1;
    if(top==NULL)
    printf("Underflow\n");
    else
    {
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}
int stacktop()
{
    if(top)
    return top->data;
    else 
    return -1;
}
int isEmpty()
{
    if(top==NULL)
    return 1;
    else 
    return 0;
}
int isoperand(char ch)
{
    if((ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'))//parenthesis does not make any sense here.
    return 0;
    else 
    return 1;
}
int post_eval(char *a)
{
    int i,j,x1,x2,r;
    for(i=0;a[i]!='\0';i++)
    {
        if(isoperand(a[i]))
        push(a[i]-'0');
        else
        {
            x2=pop();x1=pop();
            switch(a[i])
            {
                case '+':r=x1+x2;break;
                case '-':r=x1-x2;break;
                case '*':r=x1*x2;break;
                case '/':r=x1/x2;break;
            }
            push(r);
        }
    }
    //int p=stacktop();
    return top->data;
}

void main()
{
    
      char postfix[50];
      printf("Enter the postix expression\n");
      scanf("%s",postfix);
      post_eval(postfix);
     printf("The value of the espression is %d ",post_eval(postfix));
      
    
}