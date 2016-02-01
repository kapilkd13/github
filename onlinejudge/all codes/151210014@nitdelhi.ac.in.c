#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[5][5];
	int n=5,p,flag=1,fl=0,s=0,ss=0,sum=0,sum1=0,g=0,sum2=0,sum3=0,sum4=0,l=0,r,c,i,j,f=0;
//Taking input matrix
	for(i=0;i<n;i++){
		for( j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
//taking players-code
	scanf("%d",&p);
	//for corners

    while(flag)
    {
        for(i=0;i<5;i++)
            for(j=0;j<5;j++)
        {
            l+=a[i][j]%10;
        }
        if(l<=7)
        {
            if(a[0][0]==0)
            {
                r=0;
                c=0;
                break;
            }
            if(a[4][4]==0)
            {
                r=4;
                c=4;
                break;
            }
            if(a[0][4]==0)
            {
                r=0;
                c=4;
                break;
            }
            if(a[4][0]==0)
            {
                r=4;
                c=0;
                break;
            }
        }


        if((a[4][4]/10)!=p && (a[4][4]%10)!=0)
        {
            if(a[3][4]/10==(p*10+2))
            {
                r=3;c=4;break;
            }
            if(a[4][3]/10==(p*10+2))
            {
                r=4;c=3;break;
            }
        }

            if((a[0][0]/10)!=p && (a[0][0]%10)!=0)
        {
            if(a[0][1]/10==(p*10+2))
            {
                r=0;c=1;break;
            }
            if(a[1][0]/10==(p*10+2))
            {
                r=1;c=0;break;
            }
        }
        if((a[0][4]/10)!=p && (a[0][4]%10)!=0)
        {
            if(a[0][3]/10==(p*10+2))
            {
                r=0;c=3;break;
            }
            if(a[1][4]/10==(p*10+2))
            {
                r=1;c=4;break;
            }
        }

        if((a[4][0]/10)!=p && (a[4][0]%10)!=0)
        {
            if(a[4][1]/10==(p*10+2))
            {
                r=4;c=1;break;
            }
            if(a[3][0]/10==(p*10+2))
            {
                r=3;c=0;break;
            }
        }

        //for center 9

        for(i=1;i<4;i++)
            for(j=3;j>0;j--)
        {
            if(i==2 && j==2 && a[2][2]/10!=p)
            {
                if((a[i+1][j]%10>2)||(a[i][j+1]%10>2)||(a[i-1][j]%10>2)||(a[i][j-1]%10>2))
                    {
                        r=i;c=j;
                        g=1;
                        break;
                    }
            }
            else if(a[i][j]/10==p&&a[i][j]%10==3)
            {
                if((a[i+1][j]%10>1)||(a[i][j+1]%10>1)||(a[i-1][j]%10>1)||(a[i][j-1]%10>1))
                    {
                        r=i;c=j;
                        g=1;
                        break;
                    }
            }

        }
        if(g==1)
            break;



if(a[0][0]/10==p)
        {
            if(a[0][1]/10!=p && a[0][1]%10!=0)
            {
                r=0;
                c=0;
                break;
            }
            if(a[1][0]/10!=p && a[1][0]%10!=0)
            {
                r=0;
                c=0;
                break;
            }
        }
        if(a[0][4]/10==p)
        {
            if(a[0][3]/10!=p && a[0][3]%10!=0)
            {
                r=0;
                c=4;
                break;
            }
            if(a[1][4]/10!=p && a[1][4]%10!=0)
            {
                r=0;
                c=4;
                break;
            }
        }
        if(a[4][0]/10==p)
        {
            if(a[4][1]/10!=p && a[4][1]%10!=0)
            {
                r=4;
                c=0;
                break;
            }
            if(a[3][0]/10!=p && a[3][0]%10!=0)
            {
                r=4;
                c=0;
                break;
            }
        }
        if(a[4][4]/10==p)
        {
            if(a[4][3]/10!=p && a[4][4]%10!=0)
            {
                r=4;
                c=4;
                break;
            }
            if(a[3][4]/10!=p && a[3][4]%10!=0)
            {
                r=4;
                c=4;
                break;
            }
        }




        //for sides
        for(i=4,j=1;j<4;j++)
        {
            if(a[i][j]/10==p&&a[i][j]%10==2)
            {
                if(a[3][j]>2)
                {
                    r=4;
                    c=j;
                    f=1;
                    break;
                }
            }
        }
        for(i=0,j=1;j<4;j++)
        {
            if(a[i][j]/10==p&&a[i][j]%10==2)
            {
                if(a[1][j]>2)
                {
                    r=0;
                    c=j;
                    f=1;
                    break;
                }
            }
        }
for(i=1,j=0;i<4;i++)
        {
            if(a[i][j]/10==p&&a[i][j]%10==2)
            {
                if(a[i][1]>2)
                {
                    r=i;
                    c=0;
                    f=1;
                    break;
                }
            }
        }
for(i=1,j=4;i<4;i++)
        {
            if(a[i][j]/10==p&&a[i][j]%10==2)
            {
                if(a[i][3]>2)
                {
                    r=i;
                    c=4;
                    f=1;
                    break;
                }
            }
        }

        if(f==1)
            break;

            if((a[0][0]/10==p)&&((a[0][1]/10!=p&&a[0][1]%10==2)&& (a[1][0]/10!=p&&a[1][0]%10==2)))
                {
                    r=0;
                    c=0;
                    break;
                }
if((a[0][4]/10==p)&&((a[0][3]/10!=p&&a[0][3]%10==2)|| (a[1][4]/10!=p&&a[1][4]%10==2)))
                {
                    r=0;
                    c=4;
                    break;
                }
if((a[4][0]/10==p)&&((a[4][1]/10!=p&&a[4][1]%10==2)|| (a[3][0]/10!=p&&a[3][0]%10==2)))
                {
                    r=4;
                    c=0;
                    break;
                }
if((a[4][4]/10==p)&&((a[4][3]/10!=p&&a[4][3]%10==2)|| (a[3][4]/10!=p&&a[3][4]%10==2)))
                {
                    r=4;
                    c=4;
                    break;
                }



        //for taking the sides
        if(a[0][2]/10==p  &&  a[0][2]%10==2 && ((a[0][1]/10!=p && a[0][1]%10==2) || (a[0][3]/10!=p && a[0][3]%10==2)))
        {
            r=0;
            c=2;
            break;
        }
        if(a[2][0]/10==p  &&  a[2][0]%10==2 && ((a[3][0]/10!=p && a[3][0]%10==2) || (a[1][0]/10!=p && a[1][0]%10==2)))
        {
            r=2;
            c=0;
            break;
        }
        if(a[2][4]/10==p  &&  a[2][4]%10==2 && ((a[1][4]/10!=p && a[1][4]%10==2) || (a[3][4]/10!=p && a[3][4]%10==2)))
        {
            r=2;
            c=4;
            break;
        }
        if(a[4][2]/10==p  &&  a[4][2]%10==2 && ((a[4][1]/10!=p && a[4][1]%10==2) || (a[4][3]/10!=p && a[4][3]%10==2)))
        {
            r=4;
            c=2;
            break;
        }


//for center
if((a[2][2]/10==p||a[2][2]/10==0)&&(a[2][2]%10<3)&&a[2][3]==0&&a[2][1]==0&&a[1][2]==0&&a[3][2]==0)
{
    r=2;
    c=2;
    break;
}
if(a[2][2]/10==p||a[2][2]/10==0)
{
    for(i=0;i<5;i++)
        for(j=2;j<5;j++)
        sum1+=a[i][j];
    sum1=sum1-(a[2][2]%10);
    sum=sum1;
    for(i=2;i<5;i++)
        for(j=0;j<5;j++)
        sum2+=a[i][j];
    sum2=sum2-(a[2][2]%10);
    if(sum<sum2)
        sum=sum2;
    for(i=0;i<5;i++)
        for(j=0;j<3;j++)
        sum3+=a[i][j];
    sum3=sum3-(a[2][2]%10);
    if(sum<sum3)
        sum=sum3;
    for(i=0;i<3;i++)
        for(j=0;j<5;j++)
        sum4+=a[i][j];
    sum4=sum4-(a[2][2]%10);
    if(sum<sum4)
    sum=sum4;

    if(sum<=21)
    {
        r=2;
        c=2;
        break;
    }
}



    for(i=0;i<5;i+=4)
	    for(j=4;j>=0;j-=4)
	    {
	        if(a[i][j]==0)
            {
                r=i;
                c=j;
                fl=1;
                break;
	         }

	    }
	    if(fl==1)
            break;


        for(i=1;i>0;i--)
            for(j=1;j>0;j--)
        {
            if(a[i][j]==0)
            {
                r=i;c=j;
                s=1;
                break;
            }
        }
        if(s==1)
            break;

        for(i=1;i<5;i++)
            for(j=1;j<5;j++)
        {
            if(a[i][j]==0)
            {
                r=i;c=j;
                ss=1;
                break;
            }
        }
        if(ss==1)
            break;





    }



	printf("%d %d",r,c);//outputs your move
}
