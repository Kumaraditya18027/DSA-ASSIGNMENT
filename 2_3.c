#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node *next;
}*top=NULL;
void push(char x)
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
char  pop()
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
char stacktop()
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
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='z'))
    return 1;
    else 
    return 0;
}
int pre(char c)
{
    if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 2;
    else if(c=='^')
    return 3;
    else 
    return 0;
}
void in_to_post(char *c)
{
    int i=0,k=0;
    char postfix[strlen(c)+1];
    for(i=0;c[i]!='\0';i++)
    {
        if(isoperand(c[i]))
        postfix[k++]=c[i];
        else if(c[i]=='(')
        push(c[i]);
        else if(c[i]==')')
        {
            while(!isEmpty()&&stacktop()!='(')
            postfix[k++]=pop();
            if(stacktop()!='(')//!isEmpty()
            printf("Invalid expression\n");
            pop();
        }
        else
        {
            while(pre(c[i])<=pre(stacktop()))
            postfix[k++]=pop();
            push(c[i]);
        }
        
    }
    while(top)
    {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("%s",postfix);
}
void main()
{
    char expr[20];
    //printf("Enter the size of the expression\n");
    //scanf("%d",&n);
    printf("Enter the expression\n");
    scanf("%s",expr);
    
    in_to_post(expr);
    
}