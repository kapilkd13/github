#include<stdio.h>
#include<stdlib.h>


int a[5][5],corner[4] = {0,4,10,44},p,o,r=0,c=0;
	
int totalempty=0,emptyspace[25],emptyc =0,empty[25];

int count[3]= {0,0,0}, taken[3][25];

int blimit[5][5] = {{1,2,2,2,1},{2,3,3,3,2},{2,3,3,3,2},{1,2,2,2,1}};
int moveto[25][1] = {0}, totalmoves=0;

int oppmax(){
	int i,j,n=5,lplayer,rplayer,lcount,rcount;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(a[i][j]/10 == o){//if opponents
				if(i-1 >= 0){
					if(a[i-1][j]/10 == p && (a[i][j]%10+ blimit[i][j] == a[i-1][j]%10 +  blimit[i-1][j] )){
						moveto[totalmoves][0] = ((i-1)*10) + j;
						moveto[totalmoves][1] = blimit[i][j] + blimit[i-1][j];
						totalmoves++;
					}
				}
				if(i+1 <= 4){
					if(a[i+1][j]/10 == p && (a[i][j]%10+ blimit[i][j] == a[i+1][j]%10 +  blimit[i+1][j] )){
						moveto[totalmoves][0] = ((i+1)*10) + j;
						moveto[totalmoves][1] = blimit[i][j] + blimit[i+1][j];
						totalmoves++;
					}
				}
				if(j-1 >= 0){
					if(a[i][j-1]/10 == p && (a[i][j]%10+ blimit[i][j] == a[i][j-1]%10 +  blimit[i][j-1] )){
						moveto[totalmoves][0] = (i*10) + (j-1);
						moveto[totalmoves][1] = blimit[i][j] + blimit[i][j-1];
						totalmoves++;
					}
				}
				if(j+1 <= 4){
					if(a[i][j+1]/10 == p && (a[i][j]%10+ blimit[i][j] == a[i][j+1]%10 +  blimit[i][j+1] )){
						moveto[totalmoves][0] = (i*10) + (j+1);
						moveto[totalmoves][1] = blimit[i][j] + blimit[i][j+1];
						totalmoves++;
					}
				}
			}
		}
	}
}

int main(){
	int temp=0,temp2=0,safe=1,color=0,endloop=0,thisPosX,thisPosY;
	
	//neighbour check vars
	int rowNum=0,colNum=0,lplayer,rplayer,lcount,rcount,deadloop=1;
	
	int n=5,flag=1,i,j;
	//Taking input matrix
	for( i=0;i<n;i++){
		for( j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			//count player balls
			if(a[i][j]/10 != 0){
				count[a[i][j]/10] +=  a[i][j]%10;
				taken[i][count[i]] = (i*10) + 10;
			}
			//empty corners
			if((i==0 && j==0) || (i==0 && j==4)|| (i==4 && j==0)|| (i==4 && j==4)){
				if(a[i][j]/10 == 0){
					empty[emptyc] = (i*10)+j;
					emptyc++;
				}
			}
			//saving empty grids
			if(a[i][j]/10 == 0){
				emptyspace[totalempty] = (1*10) + j;
				totalempty++;				
			}
		}
	} 
	//checking if center is empty
	if(a[2][2]/10 == 0){
		empty[emptyc] = 22;
					emptyc++;
	}
	//taking players-code 
	scanf("%d",&p);
	
	
	if(p == 1){
		o = 2;
	}else{
		o = 1;
	}
	safe = oppmax();
	//main code
	if((count[1] + count[2]) <= 1){
		temp = rand()%emptyc;
		r = empty[temp]/10;
		c = empty[temp]%10;
	}
	/*int tt,yy;
	for(i=0;i<totalmoves;i++){
		tt = moveto[i][1]/10;
		yy = moveto[i][1]%10;
		//printf("moveto[%d][%d] \n",tt,yy);
	}*/
	//if corner is free
	if(emptyc > 0){
		temp = rand()%emptyc;
		r = empty[temp]/10;
		c = empty[temp]%10;
	}
	//	
	if(totalmoves>0){
		r =moveto[0][1]/10;
		c = moveto[0][1]%10;
	}
	//corners
	if(emptyc > 0){
		for(i=0;i<emptyc;i++){
			thisPosX = empty[i]/10;
			thisPosY = empty[i]%10;
			int startPosX = (thisPosX - 1 < 0) ? thisPosX : thisPosX-1;
			int startPosY = (thisPosY - 1 < 0) ? thisPosY : thisPosY-1;
			int endPosX =   (thisPosX + 1 > 4) ? thisPosX : thisPosX+1;
			int endPosY =   (thisPosY + 1 > 4) ? thisPosY : thisPosY+1;
						
			if(thisPosX == thisPosY){
				startPosY = startPosY + endPosY;
				endPosY = startPosY - endPosY;
				startPosY = startPosY - endPosY;
			}
			
			lplayer = a[startPosX][startPosY]/10;
			rplayer = a[endPosX][endPosY]/10;
			lcount = a[startPosX][startPosY]%10;
			rcount = a[endPosX][endPosY]%10;
			//if both sides of corner has exactly one enemy ball in each
			if(lplayer == o && rplayer == o && lcount == 1 && rcount == 1){
				r = thisPosX;
				c = thisPosY;
			}	
			if(lplayer == p && rplayer == p && lcount == 2 && rcount == 2){
				r = thisPosX;
				c = thisPosY;
			}else if(lplayer == p && rplayer == p && lcount >= 1 && rcount >= 1){
				r = thisPosX;
				c = thisPosY;
			}	
		}
	}
	//
	if(a[r][c]/10 == o){
		while(deadloop){
			r = rand()%5;
			c = rand()%5;
			if(a[r][c]/10 == p && (r*10)+c != 0 && (r*10)+c != 4 && (r*10)+c != 44 && (r*10)+c != 40 ) {
				deadloop = 0;
			}	
		}
	}
	
		printf("%d %d",r,c);	
		return 0;
			
}