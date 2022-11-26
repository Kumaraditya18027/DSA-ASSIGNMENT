#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 20
typedef struct pp
{
   int n;
	char str[MAX],stack[MAX];
	int top;
}st;
void push(char c,st* s)
{
	s->top+=1;
   s->stack[s->top]=c;
}
char pop(st *s)
{
	char x=s->stack[s->top];
	s->top-=1;
   return x;
}
void pre_post()
{ 
   st s;
   s.top=-1;
   int n,i,j=0; 
   char c[20];
   char a,b,op;
   printf("Enter the prefix expression\n");
   scanf("%[^\n]",s.str);
   s.str[strlen(s.str)]='\0';
   n=strlen(s.str);
   
   for(i=0;i<MAX;i++)
   		s.stack[i]='\0';
   	
   printf("Postfix expression is:\t");
   for(i=0;i<n;i++)
   {
      if(s.str[i]=='+'||s.str[i]=='-'||s.str[i]=='*'||s.str[i]=='/')
        push(s.str[i],&s);
      else
      { 
	    c[j++]=s.str[i];
        while((s.top!=-1)&&(s.stack[s.top]=='#'))
        {
            a=pop(&s); 
			c[j++]=pop(&s);
        }
        push('#',&s);
      }
   }
   c[j]='\0';
   printf("%s",c);
}
void main()
{
    pre_post();
}

