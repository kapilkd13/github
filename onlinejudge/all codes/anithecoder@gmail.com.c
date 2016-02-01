# include<stdio.h>
# include<stdlib.h>
int main(){
int a[5][5];
int p,flag=1,flag1=1,r=9,c=9,i,j,s,l,k;
//Taking input matrix
for(i=0;i<5;i++){
for( j=0;j<5;j++){
scanf("%d",&a[i][j]);
}
}
//taking players-code 
scanf("%d",&p);
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
		for( k=0;k<5;k++)
		{
			for( l=0;l<5;l++)
			{
				s=s+a[k][l];
				
			}
			
		}
		if(s==0)
		{
			c=0;
			r=0;
			flag=0;
			break;
		}
		else if(s==(p%2+1)*10+1)
		{
		   if(a[0][0]==0)
		   {c=0;r=0;
		   flag=0;
		   	break;
			   }	
			   else
			   {
			   	c==4;r==4;
			   	flag=0;
			   	break;
			   }
			
			
		}
		if(a[i][j]%10==3 && (a[i][j]/10==p) && ((a[i-1][j])/10==p%2+1 || (a[i+1][j])/10==p%2+1 || (a[i][j-1])/10==p%2+1 || (a[i][j+1])/10==p%2+1 ))
		{
		r=i;c=j;
		}
		else if(a[i][j]%10==2 &&(a[i][j]/10==p) && ((i!=0 && j!=0) || (i!=0 && j!=4) ||(i!=4 && j!=0) ||(i!=4 && j!=4) )&& ((a[i-1][j])/10==p%2+1 || (a[i+1][j])/10==p%2+1 || (a[i][j-1])/10==p%2+1 || (a[i][j+1])/10==p%2+1 ))
		{
		r=i;c=j;
		}
		else if(a[i][j]%10==1 && (a[i][j]/10==p) && (((i==0 && j==0) || (i==0 && j==4) ||(i==4 && j==0) ||(i==4 && j==4)))&& ((a[i-1][j])/10==p%2+1 || (a[i+1][j])/10==p%2+1 || (a[i][j-1])/10==p%2+1 || (a[i][j+1])/10==p%2+1 ))
		{
		r=i;c=j;
		}
		/*else if(((a[i-1][j])/10!=p%2+1 || (a[i+1][j])/10!=p%2+1 || (a[i][j-1])/10!=p%2+1 || (a[i][j+1])/10!=p%2+1 || (a[i][j+1])/10!=p%2+1) && ((a[i-1][j])/10!=p || (a[i-1][j])/10!=p || (a[i][j-1])/10!=p || (a[i+1][j])/10!=p || (a[i][j+1])/10!=p))
		{
		r=i;c=j;
		flag=0;
		break;
		}*/
		else if(a[i][j]%10==3 && (a[i][j]/10==p) )
		{
		r=i;c=j;
		}
		else if(a[i][j]%10==2 &&(a[i][j]/10==p) && ((i!=0 && j!=0) || (i!=0 && j!=4) ||(i!=4 && j!=0) ||(i!=4 && j!=4) ))
		{
		r=i;c=j;
		}
		else if((a[i][j]%10==1) && (a[i][j]/10==p) && ((i!=0 && j!=0) && (i!=0 && j!=4) && (i!=4 && j!=0) && (i!=4 && j!=4)))
		{
			r=i;
			c=j;
				}
				
					
			}if(flag==0)
			break;
		
	}
	if(c==9 && r==9)
	{
		 
	
	for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
		if((a[i][j]==0)&&((a[i-1][j])/10!=p%2+1 || (a[i+1][j])/10!=p%2+1 || (a[i][j-1])/10!=p%2+1 || (a[i][j+1])/10!=p%2+1 || (a[i][j+1])/10!=p%2+1) && ((a[i-1][j])/10!=p || (a[i-1][j])/10!=p || (a[i][j-1])/10!=p || (a[i+1][j])/10!=p || (a[i][j+1])/10!=p))
		{
		r=i;c=j;
		flag1=0;
		break;
		}
		else
		{
			c=rand()%5;
			r=rand()%5;
		}
		
}
if(flag1==0)
			break;
				
}
}

printf("%d %d",r,c);//outputs your move
}