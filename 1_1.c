#include<stdio.h>
#include<stdlib.h>
typedef struct matrix
{
    int row;
    int col;
    int **a;
}matrix;
void input(matrix *m)
{
    int i=0,j=0;
    printf("Enter the no. of rows and columns\n");
    scanf("%d %d",&m->row,&m->col);
    m->a=(int**)malloc(sizeof(int*)*m->row);
    for(i=0;i<m->row;i++)
    {
        m->a[i]=(int*)malloc(sizeof(int)*m->col);
        for(j=0;j<m->col;j++)
        {
            printf("Enter the element [%d][%d]\n",i+1,j+1);
            scanf("%d",&m->a[i][j]);
        }
    }

}
void m_display(matrix m)
{
    int i,j;
    for(i=0;i<m.row;i++)
    {
        for(j=0;j<m.col;j++)
        {
            printf("%d ",m.a[i][j]);
        }
        printf("\n");
    }
}
int check(matrix m)
{
    int i,j;
    int count=0;
      for(i=0;i<m.row;i++)
    {
        for(j=0;j<m.col;j++)
        {
              if(m.a[i][j]==0)
              count++;
        }
    }
    if(count>(m.row*m.col)/2)
    return 1;
    else
    return 0;
}
void s_display(matrix m)
{
      int i,j;
      for(i=0;i<m.row;i++)
    {
        for(j=0;j<m.col;j++)
        {
            if(m.a[i][j]!=0)
            printf("%d  %d  %d",i+1,j+1,m.a[i][j]);
        }
        printf("\n");
    }
}
void trans(matrix m)
{
      int i,j;
      for(i=0;i<m.col;i++)
    {
        for(j=0;j<m.row;j++)
        {
            printf("%d ",m.a[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    matrix m;
    input(&m);
    m_display(m);
    if(check(m))
    {
        printf("The given matrix is a sparse matrix\n");
        printf("3 tuple form of the given matrix is as follows\n");
        s_display(m);
        printf("\n\n The transpose is\n");
        trans(m);
    }
    else
    printf("The given matrix is not a sparse matrix\n");

}