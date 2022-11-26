#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
  int *c;
  int n_queen; 
}board;
void initialisation(board *b,int n)
{
  int i;
  b->c=(int*)malloc(sizeof(int)*(n+1));
  b->n_queen=n;
  for( i=1;i<=n;i++)
    b->c[i]=-1;
}
int is_safe(board b,int x,int y)
{
   int i;
   for(i=1;i<x;i++)
       if(abs(b.c[i]-y)==2 && abs(x-i)==1 || abs(x-i)==2&& abs(y-b.c[i])==1)
           return 0;

   return 1;
}
void display(board b,int n, int *sol_no)
{
   int i,j;
   printf("\nSolution no...%d",++(*sol_no));
   for(i=1;i<=n;i++)
      {
      printf("\n");
      for(j=1;j<=n;j++)
         {
           if(b.c[i]==j)
              printf("K ");
           else
              printf("X ");
         }
      }
}
void queen(board *b,int k,int n,int *sol_no)
{
  int j;
  for(j=1;j<=n;j++)
   {
     if(is_safe(*b,k,j))
     {
       b->c[k]=j;
       if(k==n)
           display(*b,n,sol_no);
       else
           queen(b,k+1,n,sol_no); 
     }
   }
}
int main()
{
  int a;
  printf("enter no of KNIGHT:  ");
  scanf("%d",&a);
  board *b;
  b=(board*)malloc(sizeof(board));
  int sol_no=0;
  initialisation(b,a);
  queen(b,1,a,&sol_no);
  return 0;
}

