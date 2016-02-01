#include<stdio.h> 
#include<stdlib.h>
 int check(int r,int c,int *s,int p); 
int main(){ int a[5][5]; 
int n=5,p,flag=1,r,c,i,j,s; 
for(i=0;i<n;i++){ 
for( j=0;j<n;j++){ 
scanf("%d",&a[i][j]); 
}
 }
 scanf("%d",&p); 
while(flag) {

r=rand()%5; 
c=rand()%5;
 if(a[r][c]/10==p){
 if(check(r,c,&a[r][c],p)==1) 
{
 flag=0;
 } 
else 
flag=1;
 } 
if(a[r][c]==0) 
flag=0;
 } printf("%d %d",r,c); 
} 
int check(int r,int c,int *s,int p) 
{ int x; if(r>0&&r<4&&c>0&&c<4) 
{ if(*(s+(5*r)+c+1)/10==p||*(s+(5*(r-1))+c)/10==p||*(s+(5*(r+1))+c)/10==p||*(s+(5*r)+c-1)/10==p){ x=1; 
}
 } 
return(x);
 }