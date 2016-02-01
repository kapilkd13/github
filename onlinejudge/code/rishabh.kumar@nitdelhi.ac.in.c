#include<stdio.h>
#include<stdlib.h>
int a[5][5],b[5][5],arr[5][5],me,other;
int r,c,i,j,m,n,k,flag,p,x,y;

void init_mat()
{
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		 {
		 	a[i][j]=0;
		 	b[i][j]=-1;
 		 }
	}
}

void move(int x,int y)
{
 r=x;
 c=y;
}

int corner()
{
flag=1;
i=0; j=0; m=1; k=1;
if(b[i][j]==me)
 flag=-1;
else if(b[i][j+k]==other)
   {
    if(a[i][j+k]==2)
    flag=-1;
   }
else if(b[i+m][j]==other)
   {
    if(a[i+m][j]==2)
      flag=-1;
   }
if(flag==1)
   {
    move(i,j);
    return 1;
   }

flag=1; i=0; j=4; m=1; k=-1;
if(b[i][j]==me)
 flag=-1;
else if(b[i][j+k]==other)
   {
   if(a[i][j+k]==2)
    flag=-1;
   }
else if(b[i+m][j]==other)
   {
    if(a[i+m][j]==2)
      flag=-1;
   }
if(flag==1)
   {
    move(i,j);
    return 1;
   } 

flag=1; i=4; j=0; m=-1; k=1;
if(b[i][j]==me)
 flag=-1;
else if(b[i][j+k]==other)
   {
   if(a[i][j+k]==2)
    flag=-1;
   }
else if(b[i+m][j]==other)
   {
    if(a[i+m][j]==2)
      flag=-1;
  }
if(flag==1)
   {
    move(i,j);
    return 1;
   }

flag=1; i=4; j=4; m=-1; k=-1;
if(b[i][j]==me)
 flag=-1;
else if(b[i][j+k]==other)
   {
    if(a[i][j+k]==2)
    flag=-1;
   }
else if(b[i+m][j]==other)
   {
    if(a[i+m][j]==2)
      flag=-1;
  }
if(flag==1)
   {
    move(i,j);
    return 1;
   }
return 0;
}

int edge()
{
 flag=1;
 if(b[0][2]==-1 && b[0][1]!=other && b[0][3]!=other && b[1][2]!=other )
     flag=-1;
 else if(b[0][2]==me && a[0][2]==1)
 {
   if(b[0][1]!=other && b[0][3]!=other && b[1][2]!=other)
     flag=-1;
   else if(b[0][1]==other && a[0][1]>a[0][2])
       flag=-1;
   else if(b[0][3]==other && a[0][3]>a[0][2])
       flag=-1;
   else if(b[1][2]==other && a[1][2]>a[0][2])
       flag=-1;
 }
 else if(b[0][2]==other)
   flag=-1;
 else if(b[0][2]==me && a[0][2]==2)
   flag=-1;
 
 if(flag==1)
  {
    move(0,2);
    return 1;
  } 
 
 flag=1;
 if(b[4][2]==-1 && b[4][1]!=other && b[4][3]!=other && b[3][2]!=other)
     flag=-1;
 else if(b[4][2]==me && a[4][2]==1)
 {
   if(b[4][1]!=other && b[4][3]!=other && b[3][2]!=other)
     flag=-1;
   else if(b[4][1]==other && a[4][1]>a[4][2])
       flag=-1;
   else if(b[4][3]==other && a[4][3]>a[4][2])
       flag=-1;
   else if(b[3][2]==other && a[3][2]>a[3][2])
       flag=-1;
 }
 else if(b[4][2]==other)
   flag=-1;
 else if(b[4][2]==me && a[4][2]==2)
   flag=-1;
 
 if(flag==1)
  {
    move(4,2);
    return 1;
  }

flag=1;
 if(b[2][0]==-1 && b[1][0]!=other && b[3][0]!=other && b[2][1]!=other)
     flag=-1;
 else if(b[2][0]==me && a[2][0]==1)
 {
   if(b[1][0]!=other && b[3][0]!=other && b[2][1]!=other)
     flag=-1;
   else if(b[1][0]==other && a[1][0]>a[2][0])
       flag=-1;
   else if(b[3][0]==other && a[3][0]>a[2][0])
       flag=-1;
   else if(b[2][1]==other && a[2][1]>a[2][0])
       flag=-1;
 }
 else if(b[2][0]==other)
   flag=-1;
 else if(b[2][0]==me && a[2][0]==2)
   flag=-1;
   
 if(flag==1)
  {
    move(2,0);
    return 1;
  } 
 
 flag=1;
 if(b[2][4]==-1 && b[1][4]!=other && b[3][4]!=other && b[2][3]!=other)
     flag=-1;
 else if(b[2][4]==me && a[2][4]==1)
 {
   if(b[1][4]!=other && b[3][4]!=other && b[2][3]!=other)
     flag=-1;
   else if(b[1][4]==other && a[1][4]>a[2][4])
       flag=-1;
   else if(b[3][4]==other && a[3][4]>a[2][4])
       flag=-1;
   else if(b[2][3]==other && a[2][3]>a[2][3])
       flag=-1;
 }
 else if(b[2][4]==other)
   flag=-1;
 else if(b[2][4]==me && a[2][4]==2)
   flag=-1;
   
 if(flag==1)
  {
    move(2,4);
    return 1;
  }
return 0;
}

int center()
{
 flag=1;
 if(b[2][2]==other)
  flag=-1;
 else if(b[2][2]==me)
 {
 	if((b[1][2]==other && a[1][2]>a[2][2]) || (b[2][1]==other && a[2][1]>a[2][2]) || (b[2][3]==other && a[2][3]>a[2][2]) || (b[3][2]==other && a[3][2]>a[2][2]))
 	 flag=-1;
 	else if((a[1][2]<a[2][2]) && (a[2][1]<a[2][2]) && (a[2][3]<a[2][2]) && (a[3][2]<a[2][2]))
 	 flag=-1;
 } 
 if(flag==1 && a[2][2]!=3)
  {
   move(2,2);
   return 1;
  }
return 0;
}

int forall()
{
 if(b[2][2]==me && a[2][2]==3)
 if((b[1][2]==other && a[1][2]==a[2][2]) || (b[2][1]==other && a[2][1]==a[2][2]) || (b[2][3]==other && a[2][3]==a[2][2]) || (b[3][2]==other && a[3][2]==a[2][2]))
  {
  	move(2,2);
  	return 1;
  }
  
 if(b[0][0]==me)
  if((b[0][1]==other && a[0][1]==2) || (b[1][0]==other && a[1][0]==2))
   {
    move(0,0);
    return 1;
   }

 if(b[0][4]==me)
  if((b[0][3]==other && a[0][3]==2) || (b[1][4]==other && a[1][4]==2))
   {
    move(0,4);
    return 1;
   }
  
 if(b[4][0]==me)
  if((b[3][0]==other && a[3][0]==2) || (b[4][1]==other && a[4][1]==2))
   {
    move(4,0);
    return 1;
   } 
 
 if(b[4][4]==me)
  if((b[4][3]==other && a[4][3]==2) || (b[3][4]==other && a[3][4]==2))
   {
    move(4,4);
    return 1;
   } 

if(b[0][1]==me && a[0][1]==2)
  if((b[0][2]==other && a[0][2]==2) || (b[1][1]==other && a[1][1]==3) || (b[0][0]==other))
   {
    move(0,1);
    return 1;
   } 

if(b[0][3]==me && a[0][3]==2)
  if((b[0][2]==other && a[0][2]==2) || (b[1][3]==other && a[1][3]==3) || (b[0][4]==other))
   {
    move(0,3);
    return 1;
   } 

if(b[4][1]==me && a[4][1]==2)
  if((b[4][2]==other && a[4][2]==2) || (b[3][1]==other && a[3][1]==3) || (b[4][0]==other))
   {
    move(4,1);
    return 1;
   } 

if(b[4][3]==me && a[4][3]==2)
  if((b[4][2]==other && a[4][2]==2) || (b[3][3]==other && a[3][3]==3) || (b[4][4]==other))
   {
    move(4,3);
    return 1;
   }

if(b[1][0]==me && a[1][0]==2)
  if((b[2][0]==other && a[2][0]==2) || (b[1][1]==other && a[1][1]==3) || (b[0][0]==other))
   {
    move(1,0);
    return 1;
   } 

if(b[3][0]==me && a[3][0]==2)
  if((b[2][0]==other && a[2][0]==2) || (b[3][1]==other && a[3][1]==3) || (b[4][0]==other))
   {
    move(3,0);
    return 1;
   } 

if(b[1][4]==me && a[1][4]==2)
  if((b[2][4]==other && a[2][4]==2) || (b[1][3]==other && a[1][3]==3) || (b[0][4]==other))
   {
    move(1,4);
    return 1;
   } 

if(b[3][4]==me && a[3][4]==2)
  if((b[2][4]==other && a[2][4]==2) || (b[3][3]==other && a[3][3]==3) || (b[4][4]==other))
   {
    move(3,4);
    return 1;
   }

if(b[0][2]==me && a[0][2]==2)
  if((b[0][3]==other && a[0][3]==2) || (b[0][1]==other && a[0][1]==2) || (b[1][2]==other && a[1][2]==3))
   {
    move(0,2);
    return 1;
   }

if(b[4][2]==me && a[4][2]==2)
  if((b[4][3]==other && a[4][3]==2) || (b[4][1]==other && a[4][1]==2) || (b[3][2]==other && a[3][2]==3))
   {
    move(4,2);
    return 1;
   }

if(b[2][0]==me && a[2][0]==2)
  if((b[3][0]==other && a[3][0]==2) || (b[1][0]==other && a[1][0]==2) || (b[2][1]==other && a[2][1]==3))
   {
    move(2,0);
    return 1;
   }

if(b[2][4]==me && a[2][4]==2)
  if((b[3][4]==other && a[3][4]==2) || (b[1][4]==other && a[1][4]==2) || (b[2][3]==other && a[2][3]==3))
   {
    move(2,4);
    return 1;
   }
return 0;
}

int play()
{
  if(forall())
  return 0;
 else if(center())
  return 0;
 else if(corner())
  return 0;
 else if(edge())
  return 0;
 else
  {
   for(i=0;i<5;i++)
     for(j=0;j<5;j++)
      if(b[i][j]==-1)
        {
          move(i,j);
          return 0;
        }
    for(i=0;i<5;i++)
     for(j=0;j<5;j++)
      if(b[i][j]==me)
        {
          move(i,j);
          return 0;
        }
  }
}
 
int main(){
//Taking input matrix
init_mat();
	for(i=0;i<5;i++)
		for( j=0;j<5;j++)
	    	scanf("%d",&arr[i][j]);
//taking players-code 
	scanf("%d",&p);
	for(i=0;i<5;i++)
		for( j=0;j<5;j++)
              if(arr[i][j]!=0)
                        {
                          x=(arr[i][j]/10);
                          y=(arr[i][j]%10);
                          b[i][j]=x;
                          a[i][j]=y;
                        }		  
	flag=1;
        if(p==1)
        {
          me=1;
          other=2;
        }
        else
        {
          me=2;
          other=1;
        }

        y=play();

	while(flag)
	{
		x=arr[r][c]/10;
		if(x==p || x==0)//check randomly generated box to be 
		  flag=0;
	}
	
	printf("%d %d\n",r,c);//outputs your move
    return 0;
} 
