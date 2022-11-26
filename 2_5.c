#include<stdio.h>
void toh(int*,int,char,char,char);
void main()
{
    int n,sc=0;
    printf("Enter the no.of disk\n");
    scanf("%d",&n);
    toh(&sc,n,'s','a','t');
}
void toh(int *sc,int n,char s,char a, char t)
{
    if (n>0)
    {
    toh(sc,n-1,s,t,a);
    printf("\n step %d move disk %d from rod %c to %c",++(*sc),n,s,a);
    toh(sc,n-1,a,s,t);

    }
}
