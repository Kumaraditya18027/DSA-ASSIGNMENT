#include<stdio.h>
#include<stdlib.h>
 typedef struct stack
{
    int n;
    int top;
    int *s;
}stack;
void push(stack *st,int x)
{
    if(st->top==st->n-1)
    printf("stack overflow\n");
    else 
    {
        st->top++;
        st->s[st->top]=x;
    }
}
void display(stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d \n",st.s[i]);
    }
}

int pop(stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
    printf("Stack Underflow\n");
    return x;
    }
    else
    {
        x=st->s[st->top];
        st->top--;
        return x;
    }


}

int stacktop(stack st)
{
    if(st.top==-1)
    {
        return -1;
    }
    else 
    return st.s[st.top];
}
int isFull(stack st)
{
    if(st.top==st.n-1)
    return 1;
    else
    return 0; 
}
int isEmpty(stack st)
{
    if(st.top==-1)
    return 1;
    else 
    return 0;
}
void main()
{
     stack st;
    printf("Enter the size of the stack\n");
    scanf("%d",&st.n);
    st.s=(int *)malloc(sizeof(int)*st.n);
    st.top=-1;
        int choice,item,n;
       
       while(1)
       {
        
        
                printf("\n1.Push\n");
                printf("2.Pop\n");
                printf("3.Display the top element\n");
                printf("4.Display all stack elements\n");
                printf("5.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                 case 1 :
                        printf("\nEnter the item to be pushed : ");
                        scanf("%d",&item);
                        push(&st,item);
                        break;
                 case 2:
                        item = pop(&st);
                        printf("\nPopped item is : %d\n",item );
                        break;
                 case 3:
                        printf("\nItem at  top is : %d\n", stacktop(st) );
                        break;
                 case 4:
                        display(st);
                        break;
                 case 5:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }
        }

        


}