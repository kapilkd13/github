#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int checkblast(int i,int);
static int arr[5][5];
int count1=0,count2=0;
int danger1();
int p,q;
int myballs(int);
int duplicateballs(int);
int crushposition(int a);
int danger[30],crush[30];
int dangerposition[20];
int consumer(int,int,int,int);
int cellformat(int,int);
void extractor(int m,int *t,int *y);
void blast(int i,int j,int k,int player);
void placement(int *y,int *t);
void general(int*a,int*b);
void insert(int a);
void increaseandoccupy(int i,int j,int player);
int dele();
int count=0;
int front=-1,rear=-1;
int queue[50];
int checkcrush(int a);
int duplicate[5][5];
int checkdestroyer(int i,int a);
int main(){
  int i,j,x,y,a,b,t1=0,t2=0,m;
for(i=0;i<=4;i++)
{
	for(j=0;j<=4;j++)
	{
		scanf("%d",&arr[i][j]);
	}
}

  scanf("%d",&p);
  if(p==1)
  q=2;
  else 
  q=1;
  	count=0;
 
  	
  		t1=myballs(p);
  	
  		t2=myballs(q);
  		
  		count=count+t1+t2;
 
  if(count<=3)
  {
  		if(arr[0][0]==0)
  		{	x=0;
  		y=0;
		  }
  	
  		else if(arr[4][0]==0)
  		{	x=4;
  		y=0;
		  }
  	
  		else if(arr[0][4]==0)
  		{
  			x=0;
  		y=4;
		  }
  		
  		else
  		{
  			x=4;
  		y=4;
		  }
  }
  else
  {
  	count2=checkcrush(p);
  
    m=crushposition(p);
  
	
    if(m==999)
    {
    	placement(&x,&y);
	}
	else
	{
		extractor(m,&x,&y);
	}

  }
  if(x<0||x>4||y<0||y>4)
  {
  	do
  	{
	  
  	x=rand()%5;
  	y=rand()%5;
  }while(arr[x][y]/10==q);
  }
 
  printf("%d %d",x,y);
  
}

int checkblast(int i,int a)
{
	int k,l,m,f;
	extractor(i,&k,&l);
	m=duplicate[k][l]%10;
	
	f=cellformat(k,l);
	if(duplicate[k][l]/10!=a||duplicate[k][l]==0)
	return 0;
	switch(f)
	{
		case 1:
			{
				if(m>=2)
				return 1;
				break;
			}
		case 2:
			{
				if(m>=3)
				return 1;
				break;
			}
		case 3:
			{
				if(m>=4)
				return 1;
				break;
			}
	}
	return 0;
}
void extractor(int m,int *t,int *y)
{
	int temp=m;
	*y=temp%10;
	*t=temp/10;
	return;
}
int noofballs(int a,int b)
{
	return arr[a][b]%10;
}
int cellformat(int i,int j)
{
if((i==0&&j==0)||(i==0&&j==4)||(i==4&&j==0)||(i==4&&j==4))
return  1;
else if(i==0||j==0||i==4||j==4)
return 2;
else 
return 3;
}
int crushposition(int a)
{
	int i,k,l,m,n,j,flag,b,y;
	int initial,final,profit[20];
	for(i=0;i<count2;i++)
	{
		for(m=0;m<=4;m++)
		{
			for(n=0;n<=4;n++)
			{
				duplicate[m][n]=arr[m][n];
			}
		}
	
		
		m=crush[i];
		
		extractor(m,&k,&l);
		increaseandoccupy(k,l,p);
		insert(m);
	   initial=duplicateballs(p);
	  
	   
	  
		while(front!=-1)
		{
			m=dele();
			
					if(checkblast(m,p))
		{   
			extractor(m,&j,&k);
			y=cellformat(j,k);
			blast(j,k,y,p);
		}
		
		}
		front=-1;
		rear=-1;
		final=duplicateballs(p);
	
		profit[i]=final-initial;
		
	
		
		
	
	}
	flag=0;
	for(i=0;i<count2;i++)
	{
	if(i==0)
    {
	}
	else
	{
		if(profit[i]>profit[flag])
		{
			flag=i;
		}
	}
	}
	if(profit[flag]<1)
	return 999;
	else
	return crush[flag];
}


int myballs(int a)
{
	int i,j,counter=0;
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			if(arr[i][j]/10==a)
			{
				
				counter=counter+arr[i][j]%10;
			}
		}
	}
	return counter;
}
void blast(int i,int j,int k,int player)
{
	int m;
	duplicate[i][j]=00;
	switch(k)
	{
		case 3:
			{
				increaseandoccupy(i+1,j,player);
				increaseandoccupy(i-1,j,player);
				increaseandoccupy(i,j-1,player);
				increaseandoccupy(i,j+1,player);
				insert(((i+1)*10)+(j));
				insert(((i-1)*10)+(j));
				insert(((i)*10)+(j-1));
				insert(((i)*10)+(j+1));
				break;
			}
		case 2:
			{
				if(j==0||j==4)
				{
					increaseandoccupy(i+1,j,player);
					increaseandoccupy(i-1,j,player);
					insert(((i+1)*10)+(j));
				    insert(((i-1)*10)+(j));
					if(j==0)
					{
					increaseandoccupy(i,j+1,player);
					insert(((i)*10)+(j+1));			
					}
					else
					{
					increaseandoccupy(i,j-1,player);
					insert(((i)*10)+(j-1));	
					}
				
				    break;
				}
			
			else
			{
			
					increaseandoccupy(i,j+1,player);
					increaseandoccupy(i,j-1,player);
					insert(((i)*10)+(j+1));
				    insert(((i)*10)+(j-1));
					if(i==4)
					{
						increaseandoccupy(i-1,j,player);
						insert(((i-1)*10)+(j));
					}
					else
					{
						increaseandoccupy(i+1,j,player);
						insert(((i+1)*10)+(j));
					}
				    break;
				}
					
				}
			
				
			
		
			case 1:
				{
				  if(i==0)
				  {
				  		increaseandoccupy(i+1,j,player);
				  		m=(i+1)*10;
				  		m=m+j;
				  		insert(m);
				 
				  		if(j==0)
				  		{
				  		increaseandoccupy(i,j+1,player);
				  		m=i*10;
				  		m=m+j+1;
				  		insert(m);
				  	
						  }
						  if(j==4)
						  {
						increaseandoccupy(i,j-1,player);
				  		insert(((i)*10)+(j-1));
						  }
				  	
				  }
				  if(i==4)
				  {
				  		increaseandoccupy(i-1,j,player);
				  		insert(((i-1)*10)+(j));
				  		if(j==0)
				  		{
				  		increaseandoccupy(i,j+1,player);
				  		insert(((i)*10)+(j+1));
				    	}
				    	if(j==4)
				    	{
				    	increaseandoccupy(i,j-1,player);
				  		insert(((i)*10)+(j-1));
				    		
						}
				  }
				
					
				     }
				
				    
					}
					
				}


void placement(int *y,int *t)

{
	int a,b;
	int i=danger1();
	
	int k,j;
	
    int flag=0;
	
		if(count<=16)
		{
			if(arr[0][0]/10==p)
			{
				if(arr[1][0]/10==0)
				{
					for(k=0;k<i;k++)
			{
				if(danger[i]==10)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=1;
			*t=0;
			return;
		}
				}
				if(arr[0][1]/10==0)
				{	for(k=0;k<i;k++)
			{
				if(danger[i]==01)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=0;
			*t=1;
			return;
		}
				}
			}
		else if(arr[0][4]/10==p)
			{
				if(arr[0][3]/10==0)
				{
					for(k=0;k<i;k++)
			{
				if(danger[i]==03)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=0;
			*t=3;
			return;
		}
				}
				if(arr[1][4]/10==0)
				{	for(k=0;k<i;k++)
			{
				if(danger[i]==14)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=1;
			*t=4;
			return;
		}
				}
			}
				else if(arr[4][0]/10==p)
			{
				if(arr[3][0]/10==0)
				{
					for(k=0;k<i;k++)
			{
				if(danger[i]==30)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=3;
			*t=0;
			return;
		}
				}
				if(arr[4][1]/10==0)
				{	for(k=0;k<i;k++)
			{
				if(danger[i]==41)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=4;
			*t=1;
			return;
		}
				}
			}
				else
				{
				
				 if(arr[4][4]/10==p)
			{
				if(arr[4][3]/10==0)
				{
					for(k=0;k<i;k++)
			{
				if(danger[i]==43)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=4;
			*t=3;
			return;
		}
				}
				
			}
				
				
				if(arr[3][4]/10==0)
				{	for(k=0;k<i;k++)
			{
				if(danger[i]==34)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=3;
			*t=4;
			return;
		}
				}
			}
			//opponent
			if(arr[0][0]/10==q)
			{
				if((arr[0][2]/10==0||arr[0][2]/10==p)&&myballs(p)<2)
				{
					for(k=0;k<i;k++)
			{
				if(danger[i]==02)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=0;
			*t=2;
			return;
		}
				}
			if((arr[2][0]/10==0||arr[2][0]/10==p)&&myballs(p)<2)

				{	for(k=0;k<i;k++)
			{
				if(danger[i]==20)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=2;
			*t=0;
			return;
		}
				}
			}
		else if(arr[0][4]/10==q)
			{
				if((arr[2][4]/10==0||arr[2][4]/10==p)&&myballs(p)<2)

				{
					for(k=0;k<i;k++)
			{
				if(danger[i]==24)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=2;
			*t=4;
			return;
		}
				}
				if((arr[0][2]/10==0||arr[0][2]/10==p)&&myballs(p)<2)

				{	for(k=0;k<i;k++)
			{
				if(danger[i]==02)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=0;
			*t=2;
			return;
		}
				}
			}
				else if(arr[4][0]/10==q)
			{
				if((arr[2][0]/10==0||arr[2][0]/10==p)&&myballs(p)<2)

				{
					for(k=0;k<i;k++)
			{
				if(danger[i]==20)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=2;
			*t=0;
			return;
		}
				}
				if((arr[4][2]/10==0||arr[4][2]/10==p)&&myballs(p)<2)
				{	for(k=0;k<i;k++)
			{
				if(danger[i]==42)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=4;
			*t=2;
			return;
		}
				}
			}
				else if(arr[4][4]/10==q)
			{
			if((arr[4][2]/10==0||arr[4][2]/10==p)&&myballs(p)<2)

				{
					for(k=0;k<i;k++)
			{
				if(danger[i]==42)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=4;
			*t=2;
			return;
		}
				}
				if((arr[2][4]/10==0||arr[2][4]/10==p)&&myballs(p)<2)

				{	for(k=0;k<i;k++)
			{
				if(danger[i]==24)
				flag=1;
				
			}
			if(flag==0)
		{
			*y=2;
			*t=4;
			return;
		}
				}
			}
			else
			{
			
			general(&a,&b);
			*y=a;
			*t=b;
			return;
		}
		}
			general(&a,&b);
			*y=a;
			*t=b;
}
int danger1()
{
	int l=0,a,b;
	int flag;
	int temper=0;
	int i,j,temp;

     
		for(i=0;i<=4;i++)
	
		{
		for(j=0;j<=4;j++)
		{
		
		for(a=0;a<=4;a++)
	
		{
		for(b=0;b<=4;b++)
		{duplicate[a][b]=arr[a][b];
		
		}
	}

		if(duplicate[i][j]/10==q||duplicate[i][j]%10==cellformat(i,j))
		continue;
		
		increaseandoccupy(i,j,p);
		
		  temp =consumer(i,j,q,cellformat(i,j));
		
		  
		  
		  
		  
		  if(temp!=0)
		  {
		  	
		  	danger[l++]=i*10+j;
		  	
		  }
		
		}
	}
	
	return l;
	
}
int consumer(int a,int j,int c,int d)
{

	
	switch(d)
	{
		case 1:
			{
				if(a==0&&j==0)
				{
					
					if(checkdestroyer(10,q)||checkdestroyer(01,q))
					{
						
						return 1;
					}
				}
				else if(a==0&&j==4)
				{
					if(checkdestroyer(03,q)||checkdestroyer(14,q))
					{
						return 1;
					}
				}
				else if(a==4&&j==0)
				{
					if(checkdestroyer(30,q)||checkdestroyer(41,q))
					{
						return 1;
					}
				}
				else
				{
					if(checkdestroyer(34,q)||checkdestroyer(43,q))
					{
						return 1;
					}
					
				}
				break;
			}
			case 2:
				{
					if(a==0||a==4)
					{
						if(checkdestroyer(a*10+(j-1),q)||checkdestroyer(a*10+(j+1),q))
						return 1;
						if(a==0)
						{
							if(checkdestroyer((a+1)*10+j,q))
							return 1;
						}
						else 
						{
							if(checkdestroyer((a-1)*10+j,q))
							return 1;
						}
						
					}
					else
					{
						if(checkdestroyer((a+1)*10+j,q)||checkdestroyer((a-1)*10+j,q))
						return 1;
						if(j==0)
						{
							if(checkdestroyer((a*10)+j+1,q))
							return 1;
						}
						else
						{
							if(checkdestroyer((a*10)+j-1,q))
							return 1;
						}
					}
					break;
					
				}
			case 3:
				{
				if(checkdestroyer((a+1)*10+j,q)||checkdestroyer((a-1)*10+j,q)||checkdestroyer((a)*10+j+1,q)||checkdestroyer((a)*10+j-1,q))
				return 1;
				}
				
	}
	return 0;
}
void general(int*a,int*b)
{
	int i,j,c,m,k,l;
	k=danger1();
	int flag=0;
	do
	{
		flag=0;
		i=rand()%5;
		j=rand()%5;
		c=cellformat(i,j);
		l=i*10+j;
		for(m=0;m<k;m++)
		{
			if(danger[m]==l)
			flag=1;
		}
	
	}while(arr[i][j]/10==q||arr[i][j]%10==c+1||flag==1);
	*a=i;
	*b=j;
}
void insert(int a)
{
	if(rear==49)
	{
		return;
	}
    if(front==-1)
    front=0;
    rear++;
    queue[rear]=a;
}


int dele()
{
	int temp;
	if(front==-1)
	return 0;
	temp=queue[front];
	if(front==rear)
	{
		front=-1;
		
	}
	else
	front++;
	return temp;
}
void increaseandoccupy(int i,int j,int player)
{
	
	
int ball=duplicate[i][j]%10;
ball++;

duplicate[i][j]=(player*10)+ball;

}
int checkcrush(int a)
{
	int m,i,j,l=0,u;
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			if(arr[i][j]/10!=p)
			{
			}
			else
			{
				m=i*10+j;
			u=cellformat(i,j);
		   
		    			if(arr[i][j]%10==u)
		    			{
						
		    			crush[l++]=m;
		    			
		    		}
		    			
			}
			
		    			
		    			
			
		}
	}
return l;
}
int duplicateballs(int a)
{
	int i,j,counter=0;
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			if(duplicate[i][j]/10==a)
			{
				
				counter=counter+duplicate[i][j]%10;
			}
		}
	}
	return counter;
}
int checkdestroyer(int i,int a)
{
	int k,l,m,f;
	extractor(i,&k,&l);
	m=duplicate[k][l]%10;
	
	f=cellformat(k,l);
	if(duplicate[k][l]/10!=a||duplicate[k][l]==0)
	return 0;
	if(duplicate[k][l]%10==f)
	return 1;
	else 
	return 0;
}