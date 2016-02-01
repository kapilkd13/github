#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[5][5];
	int n=5,p,flag=1,r,c,i,j;
	for(i=0;i<n;i++)
    {
		for( j=0;j<n;j++)
        {
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&p);
	for(i=0;i<n;i++)
        for( j=0;j<n;j++)
        {
                if((i==0||i==4)&&(j==0||j==4))
                    if(a[i][j]/10!=p&&a[i][j]==0)
                    {
                        r=i;
                        c=j;
                        goto aa;
                    }
    	}
    for(i=0;i<n;i++)
        for( j=0;j<n;j++)
        {
                if(a[2][2]/10==p||a[2][2]==0)
                {
                    r=2;
                    c=2;
                    goto aa;
                }
                if(a[2][1]/10==p||a[2][1]==0)
               	{
               		r=2;
               		c=1;
               		goto aa;
				}
				if(a[1][2]/10==p||a[1][2]==0)
               	{
               		r=1;
               		c=2;
              		goto aa;
				}
				if(a[2][3]/10==p||a[2][3]==0)
               	{
               		r=2;
              		c=3;
               		goto aa;
				}
				if(a[3][2]/10==p||a[3][2]==0)
               	{
               		r=3;
               		c=2;
               		goto aa;
				}
                if(a[2][0]/10==p||a[2][0]==0)
                {
                    r=2;
                    c=0;
                    goto aa;
				}
				if(a[1][1]/10==p||a[1][1]==0)
                {
                    r=1;
                    c=1;
                    goto aa;
				}
				if(a[3][1]/10==p||a[3][1]==0)
                {
                    r=3;
                    c=1;
                    goto aa;
				}
				if(a[0][2]/10==p||a[0][2]==0)
                {
                    r=0;
                    c=2;
                    goto aa;
				}
				if(a[1][3]/10==p||a[1][3]==0)
                {
                    r=1;
                    c=3;
                    goto aa;
				}
				if(a[2][4]/10==p||a[2][4]==0)
                {
                    r=2;
                    c=4;
                    goto aa;
				}
				if(a[3][3]/10==p||a[3][3]==0)
                {
                    r=3;
                    c=3;
                    goto aa;
				}
				if(a[4][2]/10==p||a[4][2]==0)
                {
                    r=4;
                    c=2;
                    goto aa;
				}
				if(a[0][1]/10==p||a[0][1]==0)
                {
                    r=0;
                    c=1;
                    goto aa;
				}
				if(a[1][0]/10==p||a[1][0]==0)
                {
                    r=1;
                    c=0;
                    goto aa;
				}
				if(a[0][3]/10==p||a[0][3]==0)
                {
                    r=0;
                    c=3;
                    goto aa;
				}
				if(a[1][4]/10==p||a[1][4]==0)
                {
                    r=1;
                    c=4;
                    goto aa;
				}
				if(a[3][4]/10==p||a[3][4]==0)
                {
                    r=3;
                    c=4;
                    goto aa;
				}
				if(a[4][3]/10==p||a[4][3]==0)
                {
                    r=4;
                    c=3;
                    goto aa;
				}
				if(a[4][1]/10==p||a[4][1]==0)
                {
                    r=4;
                    c=1;
                    goto aa;
				}
				if(a[3][0]/10==p||a[3][0]==0)
                {
                    r=3;
                    c=0;
                    goto aa;
				}
        }
    aa:
	printf("%d %d",r,c);
}