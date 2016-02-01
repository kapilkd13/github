#include<stdio.h>
#include<stdlib.h>
int c[5][5],l,k,t=0;
int squaretype(int n1,int n2)
{
	if((n1==0&&(n2==0||n2==4))||(n1==4&&(n2==0||n2==4)))
	return 1;
	else if(n1==0||n2==0||n1==4||n2==4)
	return 2;
	else
	return 3;
	
}

int main(){
	int code,max=0;
	int i,j,m,n;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	scanf("%d",&c[i][j]);

	
	scanf("%d",&code);
	while(1)
	{
		
		
	    if(c[0][0]==0)
	    k=l=0;
	    else if(c[0][4]==0)
		{
			k=0;l=4;
		}	
		else if(c[4][0]==0)
		{
			k=4;
			l=0;
		}
		else if(c[4][4]==0)
		{
			k=4;
			l=4;
		}
		else if(c[0][2]==0||c[2][0]==0||c[4][2]==0||c[2][4]==0)
		{
		     if(c[0][2]==0)
		     {
		     	k=0;
		     	l=2;
		     }
		     else if(c[2][0]==0)
		     {
		     	k=2;
		     	l=0;
		     }
		     else if(c[4][2]==0)
		     {
		     	k=4;
		     	l=2;
		     }
		     else
		     {
		     	k=2;
		     	l=4;
		     }
		}
		
	    else
	    {
	    	for(i=0;i<5;i++)
	    	for(j=0;j<5;j++)
	    	{
	    		if(c[i][j]%10==3&&(c[i+1][j]%10==3||c[i-1][j]%10==3||c[i][j+1]%10==3||c[i][j-1]%10==3))
	    		{
	    		k=i;
	    		j=l;
	    		goto m;
	    	    }
	    	}
	    	for(i=0;i<5;i++)
	    	for(j=0;j<5;j++)
	    	{
	    		t=squaretype(i,j);
	    		if(t==2&&(c[i][j]%10==2)&&(c[i+1][j]%10>=2||c[i-1][j]%10>=2||c[i][j+1]%10>=2||c[i][j-1]%10>=2))
	    		{
	    			k=i;
	    			j=l;
	    			goto m;
	    		}
	    	}
	    	
	    	
	    	
		
		
		
				q:
				k=rand()%5;
				l=rand()%5;
				if(c[k][l]/10!=code||c[k][l]!=0)
				goto q;
			
		}
		m:
		printf("%d %d",k,l);
		exit(0);
	    
	}
	
}
