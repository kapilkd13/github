#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[5][5],score[5][5],max=0;
	int critical[5][5],not_empty;
	int n=5,p,p2,flag=1,r,c,i,j;
	for(i=0;i<n;i++){
		for( j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			score[i][j]=0;
			if(a[i][j]!=0)
				not_empty++;
		}
	}  
	scanf("%d",&p);
	if(p==1)
		p2=2;
	else
		p2=1;
	//Assigning critical values
	critical[4][4]=critical[4][0]=critical[0][4]=critical[0][0]=2;
	for(j=1;j<=3;j++)
		critical[0][j]=3;
	for(i=1;i<=3;i++)
		critical[i][0]=3;
	for(i=1;i<=3;i++)
		critical[i][4]=3;
	for(j=1;j<=3;j++)
		critical[4][j]=3;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			critical[i][j]=4;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]/10!=p2)
			{	
			if( (a[i-1][j]/10==p2 && a[i-1][j]%10 == 3) || (a[i][j-1]/10==p2 && a[i][j-1]%10 == 3) || (a[i+1][j]/10==p2 && a[i+1][j]%10 == 3) ||(a[i][j+1]/10==p2 && a[i][j+1]%10 == 3) )
			if( (a[i][j]%10) == critical[i][j]-1 )
				{
					r=i;
					c=j;
					goto z;
				}
			if( ( a[i-1][j]/10==p && a[i-1][j]%10==3 ) || (a[i][j-1]/10==p && a[i][j-1]%10==3) || (a[i+1][j]/10==p && a[i+1][j]%10==3) ||(a[i][j+1]/10==p && a[i][j+1]%10==3) )
			if( (a[i][j]%10) == critical[i][j]-1 && (a[i-1][j]%10 == critical[i][j]-1 || a[i+1][j]%10 == critical[i][j]-1
			 || a[i][j-1]%10 == critical[i][j]-1 || a[i][j+1]%10 == critical[i][j]-1 )   )
				{
					r=i;
					c=j;
					goto z;
				}

			if( (a[i-1][j]/10==p2) || (a[i][j-1]/10==p2) || (a[i+1][j]/10==p2) ||(a[i][j+1]/10==p2) )
			if( (a[i][j]%10) == critical[i][j]-1 && (a[i-1][j]%10 == critical[i][j]-1 || a[i+1][j]%10 == critical[i][j]-1
			 || a[i][j-1]%10 == critical[i][j]-1 || a[i][j+1]%10 == critical[i][j]-1 )   )
				{
					r=i;
					c=j;
					goto z;
				}
			if( ( a[i-1][j]/10==p && a[i-1][j]%10==3 ) || (a[i][j-1]/10==p && a[i][j-1]%10==3) || (a[i+1][j]/10==p && a[i+1][j]%10==3) ||(a[i][j+1]/10==p && a[i][j+1]%10==3) )
			if( (a[i][j]%10) == critical[i][j]-1 && (a[i-1][j]%10 == critical[i][j]-1 || a[i+1][j]%10 == critical[i][j]-1
			 || a[i][j-1]%10 == critical[i][j]-1 || a[i][j+1]%10 == critical[i][j]-1 )   )
				{
					r=i;
					c=j;
					goto z;
				}
			if( ( a[i-1][j]/10==p && a[i-1][j]%10==critical[i][j]-1 ) || (a[i][j-1]/10==p && a[i][j-1]%10==critical[i][j]-1) || (a[i+1][j]/10==p && a[i+1][j]%10==critical[i][j]-1) ||(a[i][j+1]/10==p && a[i][j+1]%10==critical[i][j]-1) )
			if( (a[i][j]%10) == critical[i][j]-1 && (a[i-1][j]%10 == critical[i][j]-1 || a[i+1][j]%10 == critical[i][j]-1
			 || a[i][j-1]%10 == critical[i][j]-1 || a[i][j+1]%10 == critical[i][j]-1 )   )
				{
					r=i;
					c=j;
					goto z;
				}			
			}
		}	
	}
	
	
	if(not_empty<=4) 
	{
		if(a[0][0]==0||a[0][4]==0||a[4][0]==0||a[4][4]==0)
		{
			if(a[0][4]==0)
			{
				r=0;
				c=4;
				goto z;	
			}
			else if(a[4][0]==0)
			{
				r=4;c=0;
				goto z;
			}
			else if(a[4][4]==0)
			{
				r=4;c=4;
				goto z;
			}
			else
			{
				r=c=0;
				goto z;	
			}
		}
	}		
			
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			if(a[i][j]/10!=p2)
			{
				if( (a[i][j]%10) == critical[i][j]-1)
				{
					r=i;
					c=j;
					goto z;
				}
				if((i==0||i==4)&&(j==0||j==4))
				{
					if(a[i][j]==0)
					{
						r=i;
						c=j;
						goto z;
					}
					else if(a[i][j]/10==p)
					{
						r=i;
						c=j;
						goto z;
					}
				}
			}
		}
			
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]/10!=p2)
			{
				if( ((a[i-1][j]==10*p2+1)||(a[i-1][j]==10*p2+2)||(a[i-1][j]==10*p2+3)) 
				&&  ((a[i][j-1]==10*p2+1)||(a[i][j-1]==10*p2+2)||(a[i][j-1]==10*p2+3))
				&&  ((a[i][j+1]==10*p2+1)||(a[i][j+1]==10*p2+2)||(a[i][j+1]==10*p2+3))
				&&  ((a[i+1][j]==10*p2+1)||(a[i+1][j]==10*p2+2)||(a[i+1][j]==10*p2+3))
				)
				{
					score[i][j]=score[i][j]-(5-critical[i][j]);
				}
				if( ((a[i-1][j]==0)||(a[i-1][j]==10*p+1)||(a[i-1][j]==10*p+2)||(a[i-1][j]==10*p+3)) 
				&&       ((a[i][j-1]==0)||(a[i][j-1]==10*p+1)||(a[i][j-1]==10*p+2)||(a[i][j-1]==10*p+3))
				&&       ((a[i][j+1]==0)||(a[i][j+1]==10*p+1)||(a[i][j+1]==10*p+2)||(a[i][j+1]==10*p+3))
				&&       ((a[i+1][j]==0)||(a[i+1][j]==10*p+1)||(a[i+1][j]==10*p+2)||(a[i+1][j]==10*p+3))
				)
				{
					if((i==0&&j==0) || (i==4&&j==0) || (i==0&&j==4) ||(i==4&&j==4))
						score[i][j]=score[i][j]+3;
					else
						score[i][j]=score[i][j]+2;
					if( (a[i][j]%10) == critical[i][j]-1 )
						score[i][j]=score[i][j]+6;
				}
				if( (a[i-1][j]==10*p+1) )
				{
					score[i][j]=score[i][j]+1;
				}
				if(a[i][j-1]==10*p+1)
				{
					score[i][j]=score[i][j]+1;
				}
				if(a[i][j+1]==10*p+1)
				{
					score[i][j]=score[i][j]+1;
				}
				if(a[i+1][j]==10*p+1)
				{
					score[i][j]=score[i][j]+1;
				}
				if( (a[i-1][j]==10*p+2) )
				{
					score[i][j]=score[i][j]+2;
				}
				if(a[i][j-1]==10*p+2)
				{
					score[i][j]=score[i][j]+2;
				}
				if(a[i][j+1]==10*p+2)
				{
					score[i][j]=score[i][j]+2;
				}
				if(a[i+1][j]==10*p+2)
				{
					score[i][j]=score[i][j]+2;
				}
				if( (a[i-1][j]==10*p+3) )
				{
					score[i][j]=score[i][j]+3;
				}
				if(a[i][j-1]==10*p+3)
				{
					score[i][j]=score[i][j]+3;
				}
				if(a[i][j+1]==10*p+3)
				{
					score[i][j]=score[i][j]+3;
				}
				if(a[i+1][j]==10*p+3)
				{
					score[i][j]=score[i][j]+3;
				}
			}
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(score[i][j]>max)
				max=score[i][j];
		}
	}
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
				if(max==score[i][j])	
				{
					if(a[i][j]/10!=p2)
					{
						r=i;
						c=j;	
					}
				}
		}
	}
	if(a[r][c]==p2*10+1 || a[r][c]==p2*10+2 || a[r][c]==p2*3)
		score[r][c]=-1;
	
	z:
	printf("%d %d",r,c);
}  