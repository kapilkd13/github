#include<stdio.h>
#include<stdlib.h>

int z = 0; int pc;
int ia[25] = {2,1,1,2,3,3,3,2,1};
int ja[25] = {2,2,1,1,1,2,3,3,3};
int aai[25] = {2,1,1,2,3,3,3,2,1,0,0,0,0,1,2,3,4,4,4,4,4,3,2,1,0};
int aaj[25] = {2,2,1,1,1,2,3,3,3,3,2,1,0,0,0,0,0,1,2,3,4,4,4,4,4};
int mati[25]={0,4,4,0,0,1,3,4,4,3,1,0,0,2,4,2,2,1,2,3,2,1,3,3,1};
int matj[25]={0,0,4,4,1,0,0,1,3,4,4,3,2,0,2,4,2,2,1,2,3,1,1,3,3};
int aa[5][5];

int acquire(int M1[5][5],int pc)
{
int a, count, i, j;
count = 0;
for(i=0;i<5;i++)
{
for(j=0;j<5;j++)
{
a = M1[i][j];
if(a!=0)
{
if(pc == 1)
{
if(a==11 || a==12 || a==13)
count = count + 1 + a%10;
}
else
{
if(a==21 || a==22 || a==23)
count= count + 1 + a%10;
}
}
}
}
return count;
}

int checkMat(int M1[5][5], int i, int j)
{
int flag;
flag = 0;
if((i == 0 && j == 0) || (i == 0 && j == 4) || (i == 4 && j == 0) || (i == 4 && j == 4))
{
if(((M1[i][j] % 10) >=2))
flag = 1;
}
else if(i == 0 || i == 4 || j == 0 || j == 4)
{
if(((M1[i][j] % 10) >=3) )
flag = 1;
}
else
{
if(((M1[i][j] % 10) >=4) )
flag = 1;
}
return flag;
}

void rec(int M1[5][5], int M2[5][5], int i, int j)
{int I,J;
z++;
if(z>3000)
{
	//printf("\nzzzzzzzzzzz\n");
	int flag=1,r=0,c=0,ii,jj,f=0,k,p=pc;
	//display(aa);
	for(k=0;k<25;k++){
		if(aa[aai[k]][aaj[k]]/10==p)
		{	r=aai[k];c=aaj[k]; ////printf("\ntrap : %d %d\n",r,c);
		break;}
	}
	
	
if((aa[0][0]/10==0 && aa[0][1]/10==3-p && aa[1][0]/10==3-p))
		{
			r=0;c=0;	//printf("\ntrap1 : %d %d\n",r,c);
		}
		else if((aa[0][4]/10==0 && aa[0][3]/10==3-p && aa[1][4]/10==3-p))
		{
			r=0;c=4;
		}
		else if((aa[4][0]/10==0 && aa[4][1]/10==3-p && aa[3][0]/10==3-p))
		{
			r=4;c=0;
		}
		else if((aa[4][4]/10==0 && aa[3][4]/10==3-p && aa[4][3]/10==3-p))
		{
			r=4;c=4;
		}
		else if(aa[0][0]==0)
		{r=0;c=0;		//printf("\ntrap2 : %d %d\n",r,c);
		}
		else if(aa[0][4]==0)
		{
			r=0;c=4;
		}
		else if(aa[4][0]==0)
		{
			r=4;c=0;
		}
		else if(aa[4][4]==0)
		{
			r=4;c=4;
		}
		else
		{
			for(k=0;k<9;k++)
			{
				ii=ia[k];jj=ja[k];
				////printf("^^\n%d\n%d\n",ii,jj);
				//	if(aa[i][j]==0 && aa[i-1][j]/10==3-p && aa[i+1][j]/10==3-p && aa[i][j+1]/10==3-p && aa[i][j-1]/10==3-p)
				//	{
				//		r=i;c=j;f=1;break;
				//	}
					if(aa[ii][jj]/10==p && aa[ii][jj]%10==3 && aa[ii-1][jj]/10==3-p && aa[ii+1][jj]/10==3-p && aa[ii][jj+1]/10==3-p && aa[ii][jj-1]/10==3-p)
					{
						r=ii;c=jj;f=1;break;//printf("1 : r:%d c:%d",r,c);
					}
					
			
			}
		
			if(ii==0 && jj>0 && jj<4 && aa[ii][jj]/10==p && aa[ii][jj]%10==2 && aa[ii][jj-1]/10==3-p && aa[ii][jj+1]/10==3-p && aa[ii+1][jj]/10==3-p )
					{
						r=ii;c=jj;////printf("2 : r:%d c:%d",r,c);
					}
			else if(ii==4 && jj<4 && jj>0 && aa[ii][jj]/10==p && aa[ii][jj]%10==2 && aa[ii][jj+1]/10==3-p && aa[ii][jj-1]/10==3-p && aa[ii-1][jj]/10==3-p )
					{
						r=ii;c=jj;////printf("3 : r:%d c:%d",r,c);
					}
			else if(jj==0 && ii>0 && ii<4 && aa[ii][jj]/10==p && aa[ii][jj]%10==2 && aa[ii-1][jj]/10==3-p && aa[ii+1][jj]/10==3-p && aa[ii][jj+1]/10==3-p )
					{
						r=ii;c=jj;////printf("4 : r:%d c:%d",r,c);
					}
			else if(jj==4 && ii>0 && ii<4 && aa[ii][jj]/10==p && aa[ii][jj]%10==2 && aa[ii-1][jj]/10==3-p && aa[ii+1][jj]/10==3-p && aa[ii][jj-1]/10==3-p )
					{
						r=ii;c=jj;////printf("5 : r:%d c:%d",r,c);
					}
			
					
			else if(ii==0 && jj==0 && aa[ii][jj]/10==p && aa[ii+1][jj]/10==3-p && aa[ii][jj+1]/10==3-p)	
			{
				r=ii+1;c=jj;//printf("6 : r:%d c:%d",r,c);
			}
			else if(ii==0 && jj==4 && aa[ii][jj]/10==p && aa[ii+1][jj]/10==3-p && aa[ii-1][jj]/10==3-p)	
			{
				r=ii+1;c=jj;////printf("7 : r:%d c:%d",r,c);
			}
			else if(ii==4 && jj==0 && aa[ii][jj]/10==p && aa[ii-1][jj]/10==3-p && aa[ii][jj+1]/10==3-p)	
			{
				r=ii;c=jj+1;////printf("8 : r:%d c:%d",r,c);
			}	
			else if(ii==4 && jj==4 && aa[ii][jj]/10==p && aa[ii-1][jj]/10==3-p && aa[ii][jj-1]/10==3-p)	
			{
				r=ii-1;c=jj;////printf("9 : r:%d c:%d",r,c);
			}
			
			
			
			
			int var=0,balls=0;f=0;////printf("##\n");
			//display(aa);
			for(k=0;k<9;k++)
			{
				ii=ia[k];jj=ja[k];
				
					if(aa[ii][jj]/10==p && aa[ii][jj]%10==3)
					{
						//printf("\n!!r: %d c: %d\n",ii,jj);
						if(aa[ii][jj-1]/10==p)
							{var++;	balls+=aa[ii][jj-1]%10;}
						if(aa[ii][jj+1]/10==p)
							{var++;	balls+=aa[ii][jj+1]%10;}
						if(aa[ii-1][jj-1]/10==p)
							{var++;	balls+=aa[ii-1][jj-1]%10;}
						if(aa[ii-1][jj+1]/10==p)
							{var++;	balls+=aa[ii-1][jj+1]%10;}
						if(aa[ii-1][jj]/10==p)
							{var++;	balls+=aa[ii-1][jj]%10;}
						if(aa[ii+1][jj-1]/10==p)
							{var++;	balls+=aa[ii+1][jj-1]%10;}
						if(aa[ii+1][jj+1]/10==p)
							{var++;	balls+=aa[ii+1][jj+1]%10;}
						if(aa[ii+1][jj]/10==p)
							{var++;	balls+=aa[ii+1][jj]%10;}
							
						if(var>=3 && balls>=8)
						{
							r=ii;c=jj;f=1;//printf("14 : r:%d c:%d",r,c);
							break;
						}
					}
			
			}
			
			if(aa[0][0]/10==p && aa[0][1]/10==p && aa[1][0]/10==p && aa[0][1]%10==2 && aa[1][0]%10==2 && ((aa[1][1]!=0) || aa[2][0]/10!=0 || aa[0][2]/10!=0))
			{
				r=ii;c=jj;//printf("10 : r:%d c:%d",r,c);
			} 
			else if(aa[4][0]/10==p && aa[3][0]/10==p && aa[4][1]/10==p && aa[4][1]%10==2 && aa[3][0]%10==2 && ((aa[3][1]!=0) || aa[2][0]/10!=0 || aa[4][2]/10!=0))
			{
				r=ii;c=jj;////printf("11 : r:%d c:%d",r,c);
			} 
			else if(aa[4][4]/10==p && aa[4][3]/10==p && aa[3][4]/10==p && aa[3][4]%10==2 && aa[4][3]%10==2 && ((aa[3][3]!=0) || aa[2][4]/10!=0 || aa[4][2]/10!=0))
			{
				r=ii;c=jj;////printf("12 : r:%d c:%d",r,c);
			} 
			else if(aa[0][4]/10==p && aa[0][3]/10==p && aa[1][4]/10==p && aa[0][3]%10==2 && aa[1][4]%10==2 && ((aa[1][3]!=0) || aa[0][2]/10!=0 || aa[2][4]/10!=0))
			{
				r=ii;c=jj;////printf("13 : r:%d c:%d",r,c);
			} 
			
			//printf("\n####\n");
			
			
			if(ii==0 && jj!=0 && jj!=4 && ((aa[ii][jj]%10>0 && aa[ii][jj]/10==p) || aa[ii][jj]==0))
			{
				r=ii;jj=c;////printf("15 : r:%d c:%d",r,c);
			}		
			else if(ii==4 && jj!=0 && jj!=4 && ((aa[ii][jj]%10>0 && aa[ii][jj]/10==p) || aa[ii][jj]==0))
			{
				r=ii;jj=c;////printf("16 : r:%d c:%d",r,c);
			}
			else if(jj==4 && ii!=0 && ii!=4 && ((aa[ii][jj]%10>0 && aa[ii][jj]/10==p) || aa[ii][jj]==0))
			{
				r=ii;jj=c;////printf("17 : r:%d c:%d",r,c);
			}
			else if(jj==0 && ii!=0 && ii!=4 && ((aa[ii][jj]%10>0 && aa[ii][jj]/10==p) || aa[ii][jj]==0))
			{
				r=ii;jj=c;////printf("18 : r:%d c:%d",r,c);
			}
			
			//printf("\n@#\n");
			
			for(k=0;k<9;k++)
			{
				ii=ia[k];jj=ja[k];
				
					if(aa[ii][jj]/10==p && aa[ii][jj]%10>=1 && aa[ii-1][jj]/10==3-p && aa[ii-1][jj]%10!=3 && aa[ii+1][jj]/10==3-p && aa[ii+1][jj]%10!=3  && aa[ii][jj+1]/10==3-p && aa[ii][jj+1]%10!=3  && aa[ii][jj-1]/10==3-p && aa[ii][jj-1]%10!=3 )
					{
						r=ii;c=jj;f=1;////printf("19 : r:%d c:%d",r,c);
						break;
					}		
				
			}
			//printf("!!\n");
		}

printf("%d %d",r,c);
exit(1);
}



if(i == 0 && j == 0)
{
if(M1[i][j]%10>2)
M1[i][j]=pc*10+((M1[i][j]%10)-2);
else
M1[i][j] = 0; 
M1[i+1][j]%=10; M1[i+1][j]= M1[i+1][j]+pc*10+1;   
M1[i][j+1]%=10; M1[i][j+1]= M1[i][j+1]+pc*10+1;
}
else if(i == 0 && j == 4)
{
if(M1[i][j]%10>2)
M1[i][j]=pc*10+((M1[i][j]%10)-2);
else
M1[i][j] = 0; 
M1[i+1][j]%=10; M1[i+1][j]= M1[i+1][j]+pc*10+1;
M1[i][j-1]%=10; M1[i][j-1]= M1[i][j-1]+pc*10+1;
}
else if(i == 4 && j == 0)
{
if(M1[i][j]%10>2)
M1[i][j]=pc*10+((M1[i][j]%10)-2);
else
M1[i][j] = 0; 
M1[i-1][j]%=10; M1[i-1][j]= M1[i-1][j]+pc*10+1;
M1[i][j+1]%=10; M1[i][j+1]= M1[i][j+1]+pc*10+1;
}
else if(i == 4 && j == 4)
{
if(M1[i][j]%10>2)
M1[i][j]=pc*10+((M1[i][j]%10)-2);
else
M1[i][j] = 0; 
M1[i-1][j]%=10; M1[i-1][j]= M1[i-1][j]+pc*10+1;
M1[i][j-1]%=10; M1[i][j-1]= M1[i][j-1]+pc*10+1;
}
else if(j == 0)
{

if(M1[i][j]%10>3)
M1[i][j]=pc*10+((M1[i][j]%10)-3);
else
M1[i][j] = 0; 
M1[i-1][j]%=10; M1[i-1][j]= M1[i-1][j]+pc*10+1;
M1[i+1][j]%=10; M1[i+1][j]= M1[i+1][j]+pc*10+1;
M1[i][j+1]%=10; M1[i][j+1]= M1[i][j+1]+pc*10+1;
}
else if(i == 0)
{

if(M1[i][j]%10>3)
M1[i][j]=pc*10+((M1[i][j]%10)-3);
else
M1[i][j] = 0; 
M1[i][j-1]%=10; M1[i][j-1]= M1[i][j-1]+pc*10+1;
M1[i][j+1]%=10; M1[i][j+1]= M1[i][j+1]+pc*10+1;
M1[i+1][j]%=10; M1[i+1][j]= M1[i+1][j]+pc*10+1;
}
else if(j == 4)
{

if(M1[i][j]%10>3)
M1[i][j]=pc*10+((M1[i][j]%10)-3);
else
M1[i][j] = 0; 
M1[i][j-1]%=10; M1[i][j-1]= M1[i][j-1]+pc*10+1;
M1[i+1][j]%=10; M1[i+1][j]= M1[i+1][j]+pc*10+1;
M1[i-1][j]%=10; M1[i-1][j]= M1[i-1][j]+pc*10+1;
}
else if(i == 4)
{

if(M1[i][j]%10>3)
M1[i][j]=pc*10+((M1[i][j]%10)-3);
else
M1[i][j] = 0; 
M1[i][j-1]%=10; M1[i][j-1]= M1[i][j-1]+pc*10+1;
M1[i][j+1]%=10; M1[i][j+1]= M1[i][j+1]+pc*10+1;
M1[i-1][j]%=10; M1[i-1][j]= M1[i-1][j]+pc*10+1;
}
else
{

if(M1[i][j]%10>4)
M1[i][j]=pc*10+((M1[i][j]%10)-4);
else
M1[i][j] = 0; 
M1[i][j-1]%=10; M1[i][j-1]= M1[i][j-1]+pc*10+1;
M1[i][j+1]%=10; M1[i][j+1]= M1[i][j+1]+pc*10+1;
M1[i+1][j]%=10; M1[i+1][j]= M1[i+1][j]+pc*10+1;
M1[i-1][j]%=10; M1[i-1][j]= M1[i-1][j]+pc*10+1;
}
if(i == 0 && j == 0)
{
if(checkMat(M1,i+1,j) == 1)
rec(M1,M2,i+1,j);
if(checkMat(M1,i,j+1) == 1)
rec(M1,M2,i,j+1);
}
else if(i == 0 && j == 4)
{
if(checkMat(M1,i+1,j) == 1)
rec(M1,M2,i+1,j);
if(checkMat(M1,i,j-1) == 1)
rec(M1,M2,i,j-1);
}
else if(i == 4 && j == 0)
{
if(checkMat(M1,i-1,j) == 1)
rec(M1,M2,i-1,j);
if(checkMat(M1,i,j+1) == 1)
rec(M1,M2,i,j+1);
}
else if(i == 4 && j == 4)
{
if(checkMat(M1,i-1,j) == 1)
rec(M1,M2,i-1,j);
if(checkMat(M1,i,j-1) == 1)
rec(M1,M2,i,j-1);
}
else if(j == 0)
{
if(checkMat(M1,i-1,j) == 1)
{
rec(M1,M2,i-1,j);}
if(checkMat(M1,i+1,j) == 1)
{
rec(M1,M2,i+1,j);}
if(checkMat(M1,i,j+1) == 1)
{
rec(M1,M2,i,j+1);}

}
else if(i == 0)
{
if(checkMat(M1,i,j-1) == 1)
{
rec(M1,M2,i,j-1);}
if(checkMat(M1,i,j+1) == 1)
{
rec(M1,M2,i,j+1);}
if(checkMat(M1,i+1,j) == 1)
{
rec(M1,M2,i+1,j);}
}
else if(j == 4)
{
if(checkMat(M1,i,j-1) == 1)
{
rec(M1,M2,i,j-1);}
if(checkMat(M1,i+1,j) == 1)
{
rec(M1,M2,i+1,j);}
if(checkMat(M1,i-1,j) == 1)
{
rec(M1,M2,i-1,j);}
}
else if(i == 4)
{
if(checkMat(M1,i,j-1) == 1)
{
rec(M1,M2,i,j-1);}
if(checkMat(M1,i,j+1) == 1)
{
rec(M1,M2,i,j+1);}
if(checkMat(M1,i-1,j+1) == 1)
{
rec(M1,M2,i-1,j);}
}
else
{
if(checkMat(M1,i,j-1) == 1)
{
rec(M1,M2,i,j-1);}
if(checkMat(M1,i,j+1) == 1)
{
rec(M1,M2,i,j+1);}
if(checkMat(M1,i+1,j) == 1)
{
rec(M1,M2,i+1,j);}
if(checkMat(M1,i-1,j) == 1)
{rec(M1,M2,i-1,j);}
}
for(I = 0; I < 5; I++)
{
for(J=0;J<5;J++)
M2[I][J] = M1[I][J];
}
}

void copy(int M3[5][5],int M1[5][5])
{
int i,j;
for(i = 0; i<5;i++)
{
for(j=0;j<5;j++)
{
M3[i][j]=M1[i][j];
}	
}
}

void display(int M1[5][5])
{int I,J;
		for(I=0;I<5;I++)
	{
		for(J=0;J<5;J++)
		{
			printf("%d\t",M1[I][J]);
		}
		printf("\n");
	}
	printf("\n");
}

int nz(int M1[5][5])
{int I,J,zeros=0;
		for(I=0;I<5;I++)
	{
		for(J=0;J<5;J++)
		{
			if(M1[I][J] == 0)
				zeros++;
		}
	}
	return zeros;
}

int main(){

//int a[5][5]={{11,12,12,0,0},{11,0,13,0,0},{0,0,0,0,22},{22,13,23,0,0},{0,21,0,0,21}};
/*int a[5][5] = {{11,0,12,21,21},
					{11,23,13,23,11},
					{11,21,23,11,11},
					{22,0,23,12,11},
					{12,21,22,11,21}}; */
int n=5,p,fl=0,r=0,c=0,i,j,count=0,count2=0,diff=-999,b,pli,plj,pl2,d,max,flg=0,k;
//int a[5][5];//={{11,12,12,12,21},{12,11,11,13,0},{11,11,13,12,11},{11,13,13,12,0},{21,12,12,0,21}};
int a[5][5];//={{21,11,11,12,11},{12,12,11,12,12},{12,13,13,12,11},{11,13,0,12,12},{11,11,12,22,21}};
int M1[5][5], M2[5][5];

//Taking input matrix

for(i=0;i<n;i++){
for( j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}
//taking players-code 
//display(a);
scanf("%d",&p);
pc = p;
/*while(flag){
r=rand()%5;//randomly placing output
c=rand()%5;
if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
flag=0;
} */
//count = 
//acquire(a,p);
//b = checkMat(a,2,3);
//rec(M1,M2,3,2);

for(i = 0; i<5;i++)
{//printf("\n-4: ***********\n");
for(j=0;j<5;j++)
{
	if(a[i][j]/10!=p)continue;
copy(M2,a);copy(aa,a);//printf("\n-1: i:%d j:%d r:%d c:%d\n",i,j,r,c);
M2[i][j]%=10;
M2[i][j]++;
M2[i][j]+=(10*p);
b=checkMat(M2,i,j);
//printf("\nb:%d\n",b);
if(b==1)
{//	//printf("\n-2: r:%d c:%d\n",r,c);
rec(M2,M1,i,j);// printf("\n-2: r:%d c:%d\n",r,c);
 count=acquire(M1,3-p);
if(count==0)
{
	r=i;c=j;flg=1;//printf("\n-3: r:%d c:%d\n",r,c);
}
else if((count==1 || count==2 || count==3 || count==4 || count==5) && nz(M1)<10)
{
	r=i;c=j;flg=1;
}
}

}
}
////printf("\n0: r:%d c:%d\n",r,c);
		if(a[0][0]/10==3-p && a[0][1]/10==p && a[1][0]/10==p && a[0][1]%10==2 )
		{
			r=0;c=1;flg=1;////printf("\n1: r:%d c:%d\n",r,c);|| a[1][0]%2==0)
		}
		else if(a[0][0]/10==3-p && a[1][0]/10==p && a[0][0]/10==p && a[1][0]%10==2 )
		{
			r=1;c=0;flg=1;////printf("\n1: r:%d c:%d\n",r,c);|| a[1][0]%2==0)
		}
		else if(a[0][4]/10==3-p && a[0][3]/10==p && a[1][4]/10==p && a[0][3]%10==2 )
		{
			r=0;c=3;flg=1;////printf("\n1: r:%d c:%d\n",r,c);|| a[1][0]%2==0)
		}
		else if(a[0][4]/10==3-p && a[0][3]/10==p && a[1][4]/10==p && a[1][4]%10==2 )
		{
			r=1;c=4;flg=1;////printf("\n1: r:%d c:%d\n",r,c);|| a[1][0]%2==0)
		}
		else if(a[4][0]/10==3-p && a[3][0]/10==p && a[4][1]/10==p && a[4][1]%10==2 )
		{
			r=4;c=1;flg=1;////printf("\n1: r:%d c:%d\n",r,c);|| a[1][0]%2==0)
		}
		else if(a[4][0]/10==3-p && a[3][0]/10==p && a[4][1]/10==p && a[3][0]%10==2 )
		{
			r=3;c=0;flg=1;////printf("\n1: r:%d c:%d\n",r,c);|| a[1][0]%2==0)
		}
		else if(a[4][4]/10==3-p && a[3][4]/10==p && a[4][3]/10==p && a[3][4]%10==2 )
		{
			r=3;c=4;flg=1;////printf("\n1: r:%d c:%d\n",r,c);|| a[1][0]%2==0)
		}
		else if(a[4][4]/10==3-p && a[3][4]/10==p && a[4][3]/10==p && a[4][3]%10==2 )
		{
			r=4;c=3;flg=1;////printf("\n1: r:%d c:%d\n",r,c);|| a[1][0]%2==0)
		}
		
		else if((a[0][0]/10==p && a[0][1]/10==3-p && a[1][0]/10==3-p && (a[0][1]%10==2 || a[1][0]%2==0)))
		{
			r=0;c=0;flg=1;//printf("\n-8: r:%d c:%d\n",r,c);
		}
		else if((a[0][4]/10==p && a[0][3]/10==3-p && a[1][4]/10==3-p && (a[1][4]%10==2 || a[0][3]%2==0)))
		{
			r=0;c=4;flg=1; ////printf("!!1");
		}
		else if((a[4][0]/10==p && a[4][1]/10==3-p && a[3][0]/10==3-p && (a[4][1]%10==2 || a[3][0]%2==0)))
		{
			r=4;c=0;flg=1;
		}
		else if((a[4][4]/10==p && a[3][4]/10==3-p && a[4][3]/10==3-p && (a[3][4]%10==2 || a[4][3]%2==0)))
		{
			r=4;c=4;flg=1;
		}
		
		else if(a[0][0]/10==0 && a[0][1]/10==3-p && a[1][0]/10==3-p&& a[0][1]%10!=2 && a[1][0]%10!=2)
		{
			r=0;c=0;flg=1;//printf("\n1: r:%d c:%d\n",r,c);
		}
		else if((a[0][4]/10==0 && a[0][3]/10==3-p && a[1][4]/10==3-p) && a[0][3]%10!=2 && a[1][4]%10!=2)
		{
			r=0;c=4;flg=1;////printf("!!2");
		}
		else if((a[4][0]/10==0 && a[4][1]/10==3-p && a[3][0]/10==3-p) && a[4][1]%10!=2 && a[3][0]%10!=2)
		{
			r=4;c=0;flg=1;
		}
		else if((a[4][4]/10==0 && a[3][4]/10==3-p && a[4][3]/10==3-p) && a[4][3]%10!=2 && a[3][4]%10!=2)
		{
			r=4;c=4;flg=1;
		}
		
		
		else if((a[0][0]/10==0 && (a[0][1]/10==3-p || a[1][0]/10==3-p))&& nz(a)>8 && a[0][1]%10!=2 && a[1][0]%10!=2)
		{
			r=0;c=0;flg=1;//printf("\n2: r:%d c:%d\n",r,c);
		}
		else if((a[0][4]/10==0 && (a[0][3]/10==3-p || a[1][4]/10==3-p))&& nz(a)>8 && a[0][3]%10!=2 && a[1][4]%10!=2)
		{
			r=0;c=4;flg=1;////printf("!!3");
		}
		else if((a[4][0]/10==0 && (a[4][1]/10==3-p || a[3][0]/10==3-p))&& nz(a)>8 && a[4][1]%10!=2 && a[3][0]%10!=2)
		{
			r=4;c=0;flg=1;
		}
		else if((a[4][4]/10==0 && (a[3][4]/10==3-p || a[4][3]/10==3-p))&& nz(a)>8 && a[4][3]%10!=2 && a[3][4]%10!=2)
		{
			r=4;c=4;flg=1;
		}
		else if((a[0][1]/10==p && a[0][1]%10==2)  && a[0][0]/10==3-p)
		{
			r=0;c=1;flg=1;
		}
		else if((a[1][0]/10==p && a[1][0]%10==2)  && a[0][0]/10==3-p)
		{
			r=1;c=0;flg=1;
		}
			else if((a[4][1]/10==p && a[4][1]%10==2)  && a[4][0]/10==3-p)
		{
			r=4;c=1;flg=1;
		}
			else if((a[3][0]/10==p && a[3][0]%10==2)  && a[4][0]/10==3-p)
		{
			r=3;c=0;flg=1;
		}
			else if((a[3][4]/10==p && a[3][4]%10==2)  && a[4][4]/10==3-p)
		{
			r=3;c=4;flg=1;
		}
			else if((a[4][3]/10==p && a[4][3]%10==2)  && a[4][4]/10==3-p)
		{
			r=4;c=3;flg=1;
		}
			else if((a[0][3]/10==p && a[0][3]%10==2)  && a[0][4]/10==3-p)
		{
			r=0;c=3;flg=1;
		}
			else if((a[1][4]/10==p && a[1][4]%10==2)  && a[0][4]/10==3-p)
		{
			r=1;c=4;flg=1;
		}
		else if(a[0][0]==0&& nz(a)>8 && a[0][1]%10!=2 && a[1][0]%10!=2)
		{r=0;c=0;flg=1;//printf("\n3: r:%d c:%d\n",r,c);
		}
		else if(a[0][4]==0&& nz(a)>8 && a[0][3]%10!=2 && a[1][4]%10!=2)
		{
			r=0;c=4;flg=1;////printf("!!4");
		}
		else if(a[4][0]==0&& nz(a)>8 && a[4][1]%10!=2 && a[3][0]%10!=2)
		{
			r=4;c=0;flg=1;
		}
		else if(a[4][4]==0&& nz(a)>8 && a[4][3]%10!=2 && a[3][4]%10!=2)
		{
			r=4;c=4;flg=1;
		}
		else if(a[0][0]!=0 && a[0][4]!=0 && a[4][0]!=0 && a[4][4]!=0 && a[2][2]/10!=3-p &&  nz(a)>10)
		{
		/*	if((a[0][0]/10 == 3-p && a[0][1]/10==3-p && a[1][0]/10==3-p)) 
				{r=1;c=1;flg=1;}
			else if (a[0][4]/10 == 3-p && a[0][3]/10==3-p && a[1][4]/10==3-p)
			{ r = 3; c = 1; flg = 1;}
			
			else if(a[4][0]/10 == 3-p && a[3][0]/10==3-p && a[4][1]/10==3-p )
			{
				r=3,c=1;flg=1;
			}
			else if(a[4][4]/10 == 3-p && a[4][3]/10==3-p && a[3][4]/10==3-p )
			{
				r=3,c=3;flg=1;
			}
			else
			{				*/
				r=2;c=2;flg=1;
		//	}
		}

if(flg==0){
max=-999;//printf("\nrec\n");
for(k=0;k<25;k++)
{	i=mati[k];j=matj[k];

copy(M2,a);

d=M2[i][j];z=0;pl2 = 0;
if((p==1 && (d != 21 && d != 22 && d != 23)) || (p==2 && (d != 11 && d != 12 && d != 13)))
{	if((a[0][0]==(p*10+1) && i==0 && j==0 && a[0][1]==0 && a[1][0]==0)	|| (a[0][4]==(p*10+1) && i==0 && j==4 && a[0][3]==0 && a[1][4]==0) ||(a[4][0]==(p*10+1) && i==4 && j==0 && a[4][1]==0 && a[0][3]==0)||(a[4][4]==(p*10+1) && i==4 && j==4 && a[4][3]==0 && a[3][4]==0))			
	continue;
M2[i][j]%=10;
M2[i][j]++;
M2[i][j]+=(10*p);
b=checkMat(M2,i,j);
if(b==1)
{copy(aa,a);rec(M2,M1,i,j); 
 count=acquire(M1,p);
 count2=acquire(M1,3-p);
 
if(count2==0)
{
	r=i;c=j;fl=1;break;
}
}
else
{
count=acquire(M2,p);
count2=acquire(M2,3-p);
if(count2==0)
{
	r=i;c=j;fl=1;break;
}
}
diff=count-count2;
if(diff > max)
{
max = diff;r = i;c = j;
}
}
}

}

printf("%d %d",r,c);//outputs your move
}