#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[5][5];
	int p1,n=5,p,r,c,i,j,flg=0;
//Taking input matrix
	for(i=0;i<n;i++){
		for( j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}  
//taking players-code 
	scanf("%d",&p);

if(p==1)
  p1=2;
else if(p==2)
  p1=1;

if(a[0][0]==0)
 {r=c=0;goto prt;}
else if(a[0][4]==0)
 {r=0;c=4;goto prt;}
else if(a[4][0]==0)
 {r=4;c=0;goto prt;}
else if(a[4][4]==0)
 {r=4;c=4;goto prt;}

if(a[0][0]==(p*10)+1 && (a[0][1]==(p1*10)+2||a[1][0]==(p1*10)+2))
 {r=c=0;goto prt;}
else if(a[0][4]==(p*10)+1 && (a[0][3]==(p1*10)+1||a[1][4]==(p1*10)+2))
 {r=0;c=4;goto prt;}
else if(a[4][0]==(p*10)+1 && (a[3][0]==(p1*10)+1||a[4][1]==(p1*10)+2))
 {r=4;c=0;goto prt;}
else if(a[4][4]==(p*10)+1 && (a[4][3]==(p1*10)+1||a[3][4]==(p1*10)+2))
 {r=4;c=4;goto prt;}
else if(a[0][0]==(p*10)+1 && (a[0][1]==(p1*10)+1&&a[1][0]==(p1*10)+1))
 {r=c=0;goto prt;}
else if(a[0][4]==(p*10)+1 && (a[0][3]==(p1*10)+1&&a[1][4]==(p1*10)+1))
 {r=0;c=4;goto prt;}
else if(a[4][0]==(p*10)+1 && (a[3][0]==(p1*10)+1&&a[4][1]==(p1*10)+1))
 {r=4;c=0;goto prt;}
else if(a[4][4]==(p*10)+1 && (a[4][3]==(p1*10)+1&&a[3][4]==(p1*10)+1))
 {r=4;c=4;goto prt;}
else
{
 for(i=1;i<n-1;i++)
   {
     if(a[0][i]==(p*10)+2 && (a[0][i+1]==(p1*10)+2||a[0][i-1]==(p1*10)+2||a[1][i]>=(p1*10)+2))
      {r=0;c=i;goto prt;}
     else if(a[i][0]==(p*10)+2 && (a[i][1]>=(p1*10)+2||a[i-1][0]==(p1*10)+2||a[i+1][0]==(p1*10)+2))
      {r=i;c=0;goto prt;}
     else if(a[4][i]==(p*10)+2 && (a[4][i+1]==(p1*10)+2||a[4][i-1]==(p1*10)+2||a[3][i]==(p1*10)+3))
      {r=4;c=i;goto prt;}
     else if(a[i][4]==(p*10)+2 && (a[i+1][4]==(p1*10)+2||a[i-1][4]==(p1*10)+2||a[i][3]==(p1*10)+3))
      {r=i;c=4;goto prt;}
     else if(a[0][i]==(p*10)+2 && (a[0][i+1]>=(p1*10)+1||a[0][i-1]==(p1*10)+1||a[1][i]==(p1*10)+2))
      {r=0;c=i;goto prt;}
     else if(a[i][0]==(p*10)+2 && (a[i][1]>=(p1*10)+2||a[i-1][0]==(p1*10)+1||a[i+1][0]==(p1*10)+1))
      {r=i;c=0;goto prt;}
     else if(a[4][i]==(p*10)+2 && (a[4][i+1]>=(p1*10)+1||a[4][i-1]==(p1*10)+1||a[3][i]==(p1*10)+2))
      {r=4;c=i;goto prt;}
     else if(a[i][4]==(p*10)+2 && (a[i+1][4]==(p1*10)+1||a[i-1][4]==(p1*10)+1||a[i][3]==(p1*10)+2))
      {r=i;c=4;goto prt;}
   } 
}

for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
   {
    if(a[i][j+1]==(p1*10)+3&&a[i][j]==(p*10)+3)
      {r=i;c=j;goto prt;}
    else if(a[i+1][j]==(p1*10)+3&&a[i][j]==(p*10)+3)
      {r=i;c=j;goto prt;}
    else if(a[i-1][j]==(p1*10)+3&&a[i][j]==(p*10)+3)
      {r=i;c=j;goto prt;}
    else if(a[i][j-1]==(p1*10)+3&&a[i][j]==(p*10)+3)
      {r=i;c=j;goto prt;}
    else if(a[i][j+1]==(p1*10)+2&&a[i][j]==(p*10)+3)
      {r=i;c=j;goto prt;}
    else if(a[i+1][j]==(p1*10)+2&&a[i][j]==(p*10)+3)
      {r=i;c=j;goto prt;}
    else if(a[i-1][j]==(p1*10)+2&&a[i][j]==(p*10)+3)
      {r=i;c=j;goto prt;}
    else if(a[i][j-1]==(p1*10)+2&&a[i][j]==(p*10)+3)
      {r=i;c=j;goto prt;}
    /*else if(a[i][j+1]>=(p1*10)+2&&a[i][j]/10==p)
      {r=i;c=j;goto prt;}
    else if(a[i+1][j]>=(p1*10)+2&&a[i][j]/10==p)
      {r=i;c=j;goto prt;}
    else if(a[i-1][j]>=(p1*10)+2&&a[i][j]/10==p)
      {r=i;c=j;goto prt;}
    else if(a[i][j-1]>=(p1*10)+2&&a[i][j]/10==p)
      {r=i;c=j;goto prt;}*/
  }
}
if(flg==0)
{
if(a[0][0]==0)
 {r=c=0;goto prt;}
else if(a[0][4]==0)
 {r=0;c=4;goto prt;}
else if(a[4][0]==0)
 {r=4;c=0;goto prt;}
else if(a[4][4]==0)
 {r=4;c=4;goto prt;}
else
{
 for(i=1;i<n-1;i++)
   {
     for(j=1;j<n-1;j++)
     {
       if(a[i][j]==0||a[i][j]/10==p)
        {r=i;c=j;goto prt;}
     }
   } 
}
}	
prt:
{
	 printf("%d %d",r,c);//outputs your move 
}
}  