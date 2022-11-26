#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack 
{
    int top;
    char stk[20];
}stack;
void push(char c,stack* s)
{
	s->top+=1;
   s->stk[s->top]=c;
}
char pop(stack *s)
{
	char x=s->stk[s->top];
	s->top-=1;
   return x;
}
int isoperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    return 1;
    else 
    return 0;
}
void pr_to_post(stack *st,char *expr)
{

    int i,j=0;
    char c;
    int n=strlen(expr);
    char postfix[30];
    for(i=0;i<n;i++)
    {
        if(isoperator(expr[i]))
        push(expr[i],st);
        else
        {
            postfix[j++]=expr[i];
            while((st->top!=-1)&&(st->stk[st->top]=='#'))
            {
                c=pop(st);
                postfix[j++]=pop(st);
            }
            push('#',st);
        }
    }
    postfix[j]='\0';
    printf("The postfix expression is %s",postfix);
}
void main()
{
    char expr[30];
    stack st;
    printf("Enter the expression\n");
    scanf("%s",expr);
    st.top=-1;
    for(int i=0;i<20;i++)
    {
        st.stk[i]=0;
    }
    pr_to_post(&st,expr);

}

