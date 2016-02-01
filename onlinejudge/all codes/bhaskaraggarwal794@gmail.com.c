#include<stdio.h>
#include<stdlib.h>
int main()
{
int a[5][5];
int n=5,flag=1,p,r,c,i,j;

for(i=0;i<5;i++)
{
for( j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
} 
scanf("%d",&p);
while(flag)
{
r=rand()%5;//randomly placing output
c=rand()%5;
if(a[r][c]/10==p||a[r][c]/10==0) 
flag=0;
}
printf("%d %d",r,c);//outputs your move
}