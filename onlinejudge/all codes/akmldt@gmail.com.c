#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[5][5];
	int p,flag=1,counter=0,r,c,i,j;
	for(i=0;i<5;i++)
      {
		for( j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&p);
	for(c=0;c<5&&counter==0;c++)
        for(r=0;r<5;r++)
        {
              if(a[r][c]/10==p||a[r][c]/10==0)
              {
                    flag=0; counter=1;break;
              }

        }
    c--;
    printf("%d %d",r,c);
}
