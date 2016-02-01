#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[5][5];
	int n=5,p,flag=1,num,r,c,i,j;
scanf("%d",&num);
	for(i=0;i<n;i++){
		for( j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}  
	scanf("%d",&p);
	
	while(flag){
		r=rand()%5;
		c=rand()%5;
		if(((a[r][c]<=(num+1)*10)&&(a[r][c]>=num*10))||a[r][c]/10==0)
		flag=0;
	}
	printf("%d\n%d",r,c);
}  
