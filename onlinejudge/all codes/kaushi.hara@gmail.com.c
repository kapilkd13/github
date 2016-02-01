#include<stdio.h>
#include<stdlib.h>
int main(){
int a[5][5],n=5,p,flag=1,r,c,i,j;
static int count=1;
static int x=1;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
  scanf("%d",&a[i][j]);
  }
  }
  scanf("%d",&p);
  while(flag)
  {
  if(count==1)
  {r=0;c=0;

  if(a[r][c]/10==p||a[r][c]/10==0)
  {flag=0;x=0; }
  else {r=1;c=1;
	if(a[r][c]/10==p||a[r][c]/10==0)
  flag=0;}
	 }
  if(count==2)
  {     if(x==0)
	{ r=0;c=0;	if(a[r][c]/10==p||a[r][c]/10==0)
  flag=0;}
	else { r=1;c=1;
	  if(a[r][c]/10==p||a[r][c]/10==0)
  flag=0;} }

	count++;
  if(count>2)
  {
	 r=rand()%3;
	 c=rand()%3;
	 if(a[r][c]/10==p||a[r][c]/10==0)
	 flag=0;
  } }
  printf("%d %d",r,c);

  }