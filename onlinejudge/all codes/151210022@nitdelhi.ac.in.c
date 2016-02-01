#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[5][5];
	int n=5,p,flag=1,r,c,i,j;
//Taking input matrix
	for(i=0;i<n;i++){
		for( j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}  
//taking players-code 
	scanf("%d",&p);
	
	while(flag){
		 for(i=0;i<5;i++)
                {
                 for(j=0;j<5;j++)
                  {
                    if(a[r][c]/10==p&&a[r][c]%10==3)
                    { break;
                      n=4;
                    }
                  }
                }
                if(n==4)
                break;
		
		 r=0;
                c=0;
                if(a[r+1][c]/10==p+1||a[r+1][c]==p-1||a[r][c+1]==p+1||a[r][c+1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=4;
                c=0;
                if(a[r-1][c]/10==p+1||a[r-1][c]==p-1||a[r][c+1]==p+1||a[r][c+1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=0;
                c=4;
                if(a[r+1][c]/10==p+1||a[r+1][c]==p-1||a[r][c-1]==p+1||a[r][c-1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=4;
                c=4;
                if(a[r-1][c]/10==p+1||a[r-1][c]==p-1||a[r][c-1]==p+1||a[r][c-1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=2;
                c=2; for(i=0;i<5;i++)
                {
                 for(j=0;j<5;j++)
                  {
                    if(a[r][c]/10==p||a[r][c]%10==2||a[r][c]%10==3)
                    {
                      n=4;
                      break;
                    }
                  }
                }
                if(n==4)
                break;
			
		r=0;//randomly placing output
		c=0;
		if(a[r][c]/10==0)//check randomly generated box to be 
		
		break;
                r=0;
                c=4;
                if(a[r][c]/10==0)//check randomly generated box to be 
			
		break;
                r=4;
                c=0;
                if(a[r][c]/10==0)//check randomly generated box to be 
			
		break;
                r=4;
                c=4;
                if(a[r][c]/10==0)//check randomly generated box to be 
			
		break;
                r=2;
                c=2;
                if(a[r][c]/10==0)//check randomly generated box to be 
		break;
		 r=0;
                c=0;
                if(a[r+1][c]/10==p+1||a[r+1][c]==p-1||a[r][c+1]==p+1||a[r][c+1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=4;
                c=0;
                if(a[r-1][c]/10==p+1||a[r-1][c]==p-1||a[r][c+1]==p+1||a[r][c+1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=0;
                c=4;
                if(a[r+1][c]/10==p+1||a[r+1][c]==p-1||a[r][c-1]==p+1||a[r][c-1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=4;
                c=4;
                if(a[r-1][c]/10==p+1||a[r-1][c]==p-1||a[r][c-1]==p+1||a[r][c-1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=2;
                c=2;
			 for(i=0;i<5;i++)
                {
                 for(j=0;j<5;j++)
                  {
                    if(a[r][c]/10==p||a[r][c]%10==2||a[r][c]%10==3)
                    { break;
                      n=4;
                    }
                  }
                }
                if(n==4)
                break;
   
			  r=2;
                c=2;
                if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
			    break;
                
		break;
                r=1;
                c=0;
                if(a[0][0]==11&&a[r][c]/10==0)//check randomly generated box to be 
			
		break;
                r=0;
                c=1;
                if(a[0][0]=11&&a[r][c]/10==0)//check randomly generated box to be 
			
		break;
                r=3;
                c=0;
                if(a[4][0]==11&&a[r][c]/10==0)//check randomly generated box to be 
			
		break;
               
                r=4;
                c=1;
                if(a[4][0]==11&&a[r][c]/10==0)//check randomly generated box to be 
			
		break;
                r=0;
                c=3;
                if(a[0][4]==11&&a[r][c]/10==0)//check randomly generated box to be 
			    break;		
                r=1;
                c=4;
                if(a[0][4]==11&&a[r][c]/10==0)//check randomly generated box to be 
		        break;
                r=3;
                c=4;
                if(a[4][4]==11&&a[r][c]/10==0)//check randomly generated box to be 
			    break;
                r=4;
                c=3;
                if(a[4][4]=11&&a[r][c]/10==0)//check randomly generated box to be 
			    break;
                r=0;
                c=0;
                if(a[r+1][c]/10==p+1||a[r+1][c]==p-1||a[r][c+1]==p+1||a[r][c+1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=4;
                c=0;
                if(a[r-1][c]/10==p+1||a[r-1][c]==p-1||a[r][c+1]==p+1||a[r][c+1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=0;
                c=4;
                if(a[r+1][c]/10==p+1||a[r+1][c]==p-1||a[r][c-1]==p+1||a[r][c-1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=4;
                c=4;
                if(a[r-1][c]/10==p+1||a[r-1][c]==p-1||a[r][c-1]==p+1||a[r][c-1]==p-1&&(a[r][c]/10==p||a[r][c]/10==0))//check randomly generated box to be 
			    break;
                r=2;
                c=2;
                if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
			    break;
                r=2;
                c=3;
                if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
			    break;
                r=3;
                c=2;
                if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
			    break;
                r=1;
                c=2;
                if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
                break;
                r=2;
                r=1;
                if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
			    break;
                r=3;
                c=3;
                if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
			    break;
                r=4;
                c=4;
                if(a[r][c]/10==p||a[r][c]/10==0)//check randomly generated box to be 
			    break;


                
	}
	printf("%d %d",r,c);//outputs your move
}  