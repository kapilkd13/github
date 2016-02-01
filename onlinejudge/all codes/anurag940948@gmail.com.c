#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[5][5];
	int n=5,p,flag=1,r,c,i,j;
//Taking input matrix
	for(i=0;i<n;i++){
		for( j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}  
//taking players-code 
	scanf("%d",&p);
		
	for(r=0;r<5;r++){
		for(c=0;c<5;c++){
	if(a[r][c]/10==p||a[r][c]/10==0){	
	if((r==0&&c==0)||(r==4&&c==4)||(r==0&&c==4)||(r==4&&c==0)){
	printf("%d %d",r,c);
	exit(1);}
	if((a[r][c]==p-1)||(a[r][c]==p+1)){
		
		if(r==0&&c==0) {printf("%d %d",r+1,c+1);exit(1);}
		else 
		if(r==0&&c==4) {printf("%d %d",1,2+1);exit(1);}
		else 
		if(r==4&&c==4) {printf("%d %d",r-1,c-1);exit(1);}
		else 
		if(r==4&&c==0) {printf("%d %d",2+1,1);exit(1);}}
		
		}}}
	
	while(flag){
		r=rand()%5;//randomly placing output
		c=rand()%5;
		if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
		{
			if((r==0&&c==0)||(r==4&&c==4))flag=0;
		if(r==c){
		flag=0;
	}
	else if((a[r][c]%10)>=1&&((r==0&&c==0)||(r==4&&c==4))){flag=0;}
	else if((a[r][c]%10)>=2&&((r==0&&c>0)||(r==4&&c>0))){flag=0;}
	else if((a[r][c]%10)>=3){flag=0;}
}
}
	printf("%d %d",r,c);//outputs your move
}  
