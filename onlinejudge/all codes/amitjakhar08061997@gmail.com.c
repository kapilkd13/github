#include<stdio.h>
#include<stdlib.h>
int main(){
int a[5][5];
int n=5,p,flag=1,r,c,i,j;
for(i=0;i<n;i++){
for( j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
} 
scanf("%d",&p);
while(flag)
{
		int mi;
		int x=0;
		for(j=3;j>=1;j--)
		{
			if(a[4][j]%10==2&&a[4][j]/10==p)
			{
				r=4;c=j;flag=0;x=1;
				break;
			}
		}
		if(x==0)
		{	int y=0;
			for(i=3;i>=1;i--)
			{
				if(a[i][4]%10==2&&a[i][4]/10==p)
				{
					r=i;c=4;flag=0;y=1;
					break;
				}	
				if(i==1&&y==0)
				{
					for(j=3;j>=1;j--)
					{
						if(a[j][0]%10==2&&a[j][0]/10==p)
						{
							r=j;
							c=0;
							flag=0;
							y=1;
							break;
						}
					}
				}
			}
			if(y==0)
			{
				int z=0;
				for(i=3;i>=1;i--)
				{
					
					for(j=3;j>=1;j--)
					{
						if(a[i][j]%10==3&a[i][j]/10==p)
						{
							r=i;c=j;flag=0;z=1;
							break;
						}
					}
					if(z==1)
					break;
				}
				if(z==0)
				{
						mi=0;
							if(a[0][0]==0)
							{
								r=0;c=0;flag=0;
								mi=1;
							}
						else if((a[0][1]%10==2||a[1][0]%10==2)&&a[0][0]/10==p)
							{
								r=0;c=0;flag=0;
								mi=1;
							}
						else if(a[4][4]==0)
						{
							r=4;
							c=4;
							flag=0;
							mi=1;
						}
						else if((a[3][4]%10==2||a[4][3]%10==2)&&a[4][4]/10==p)
						{
							r=4;c=4;flag=0;
							mi=1;
						}
						else if(a[4][0]==0)
						{
								r=4;c=0;flag=0;
								mi=1;
						}
						else if(a[0][4]==0)
						{
							r=0;c=4;flag=0;
							mi=1;
						}
						else if((a[0][3]%10>=1||a[1][4]%10>=1)&&a[0][4]/10==p)
						{
							r=0;c=4;flag=0;
							mi=1;
						}
						else 
						{
						if((a[3][0]%10==2||a[4][1]%10==2)&&a[4][0]/10==p)
						{
							r=4;c=0;flag=0;
							mi=1;
						}	
						}
				}
				if(mi==0)
				{
					int z1=0;
					for(i=3;i>=1;i--)
					{
						for(j=3;j>=1;j--)
						{
							if(a[i][j]/10!=p&&a[i][j]%10==3)
							{
								if(a[i+1][j]==0)
								{
									r=i+1;c=j;flag=0;z1=1;
								}
								else if(a[i-1][j]==0)
								{
									r=i-1;c=j;flag=0;z1=1;
								}
								else if(a[i][j+1]==0)
								{
									r=i;c=j+1;flag=0;z1=1;
								}
								else if(a[i][j-1]==0)
								{
									r=i;c=j-1;flag=0;z1=1;
								}
								else
								{
								}
							}
							if(z1==1)
							break;
						}
						if(z1==1)
						break;
					}
					if(z1==0)
					{
						int z2=0;
						for(i=4;i>=1;i--)
						{
							for(j=4;j>=1;j--)
							{
								if((i==4&&j==3)||(j==4&&i==3))
								{
									continue;
								}
								if(a[i][j]==0)
								{
									r=i;c=j;flag=0;z2=1;
									break;
								}
							}
							if(z2==1)
							break;
						}
						if(z2==0)
						{
							r=rand()%5;
							c=rand()%5;
							if(r==0&&c==0)
							{
								flag=1;
							}
							else if(r==4&&c==4)
							{
								flag=1;
							}
							else if(r==4&&c==0)
							{
								flag=1;
							}
							else if(r==4&&c==0)
							{
								flag=1;
							}
							else
							{
								if(a[r][c]/10==p||a[r][c]==0)
								{
									flag=0;
								}
							}
						}
					}
				}
			}
		}
	
	
	
}
printf("%d %d",r,c);
}