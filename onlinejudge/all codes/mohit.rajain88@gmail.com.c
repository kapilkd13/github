#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int co=1,d=25;
void set(int N[5][15],int C[5][5] );


void build(int N[5][15], int a, int b ) ;

void manage(int N[5][15], int k, int z ,int C[5][5] );

void del(int *S,int *D,int x){
	int i,y=0;
	for(i=0;i<d;i++)
	if(S[i]==x){
	y=1;
	break;}

	if(y==1){
//	printf("\n deleted %d \n",x);
	i=0;
	while(S[i]!=x){
	i++;
	}
	for(;i<d-1;i++){	
	S[i]=S[i+1];
	D[i]=D[i+1];
	}

	/*printf("\nd=%d\n",d-1);
	for(i=0;i<d-1;i++)
	printf(" %d ",S[i]);

	scanf("%d",&i);*/
       d--;			}

}

/*int comp2(int N[5][15],int C[5][5])
{
int c=0,o=0,sf=0,at=0,A[25],B[25],NN[5][15],CC[5][5],NNN[5][15],CCC[5][5],AA[25],BB[25],BBB[25],AAA[25],a=0,cc=0,oo=0,ooo=0,ccc=0,i=0,j=0;
int oooo=0,D[25]={0},S[25],b,k=0,l=0;
	for(i=1;i<=25;i++)
	S[i-1]=i;

	d=25;

	for(i=0;i<5;i++)
	for(j=0;j<5;j++){ 
	if(C[i][j]>=0)
	A[c++]=(5*i)+j+1;
	
	else if(C[i][j]<0){
	B[o++]=(5*i)+j+1;
	del(S,D,((5*i)+j+1));}
		}

	for(i=0;i<5;i++)
	for(j=0;j<5;j++) 
	if(C[i][j]>0)
	b++;

	ooo=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(N[k][j]<0)
	++ooo;

	ccc=0;
	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(N[k][j]>0)
	++ccc;

//defence
	sf=0;
	for(i=0;i<o;i++)     {
	
	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NN[k][j]=N[k][j];
	 CC[k][j/3]=C[k][j/3];
		}

	manage(NN,1,B[i],CC);
	set(NN,CC);
//printf("\n Printing\n");
//build(NN,0,1);

	oo=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NN[k][j]<0){
	++oo;
//printf("\nNN k=%d j=%d\n",k,j);
				}

//	printf("\noo=%d\n",oo);
	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CC[k][j]<0){
	++oo;
//printf("\nCC k=%d j=%d\n",k,j);
				}
	BB[i]=oo-o-ooo-1;

	//printf("\n BB[i]=%d  oo=%d  o=%d ooo=%d \n",BB[i],oo,o,ooo);
//safe attack check
	if(BB[i]>0) {

	at=0;


	for(l=0;l<c;l++)     {
	
	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NN[k][j]=N[k][j];
	 CC[k][j/3]=C[k][j/3];
		}

	manage(NN,0,A[l],CC);
	set(NN,CC);

	cc=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NN[k][j]>0)
	++cc;

	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CC[k][j]>0)
	++cc;

	AA[l]=cc-b-ccc-1;
//printf("\n AA[l]=%d  cc=%d  b=%d ccc=%d \n",AA[l],cc,b,ccc);
//safety check again

	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NNN[k][j]=NN[k][j];
	 CCC[k][j/3]=CC[k][j/3];
		}

	manage(NNN,1,B[i],CCC);
	set(NNN,CCC);

	oooo=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NNN[k][j]<0)
	++oooo;

	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CCC[k][j]<0)
	++oooo;
			
	sf=oooo-oo-1;

//	printf("\n sf=%d  oo=%d  oooo=%d at=%d  (AA[l]-sf)=%d A[l]=%d\n",sf,oo,oooo,at,(AA[l]-sf),A[l]);
	
	D[l]=AA[l];	

	if(sf>=0)
	del(S,D,A[l]);
	

				}

		    }	

		}

//attack

	for(i=0;i<c;i++)     {
	
	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NN[k][j]=N[k][j];
	 CC[k][j/3]=C[k][j/3];
		}

	manage(NN,0,A[i],CC);
	set(NN,CC);

	cc=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NN[k][j]>0)
	++cc;

	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CC[k][j]>0)
	++cc;

	AA[i]=cc-b-ccc-1;

	set(NN,CC);

	o=0;

	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CC[k][j]<0)
	B[o++]=(5*k)+j+1;

	ooo=0;
	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NN[k][j]<0)
	++ooo;

	sf=0;

	for(l=0;l<o;l++)     {
	
	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NNN[k][j]=NN[k][j];
	 CCC[k][j/3]=CC[k][j/3];
		}

	manage(NNN,1,B[l],CCC);
	set(NNN,CCC);
//printf("\n Printing\n");
//build(NN,0,1);

	oo=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NNN[k][j]<0){
	++oo;
//printf("\nNN k=%d j=%d\n",k,j);
				}

//	printf("\noo=%d\n",oo);
	
	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CCC[k][j]<0){
	++oo;
//printf("\nCC k=%d j=%d\n",k,j);
				}
	BB[l]=oo-o-ooo-1;
//	printf("\nBB[%d]=%d\n",BB[l],l);

	if(BB[l]>sf)
	sf=BB[l];

						}

	AAA[i]=sf;
				}

	k=0;
 	for(i=1;i<c;i++){
	if(AA[i]>AA[k])
	 k=i;
	else if(AA[i]==AA[k]){
	if(AAA[k]>AAA[i])
	k=i;
	}
	}


	if(d>0) {
	l=0;
 	for(i=1;i<d;i++)
	if(D[i]>=D[l])
	 l=i;

	if(AA[k]>D[l]){
//	printf("\nAttacking\n");
	return A[k];}

	else{
//	printf("\n defencing\n");
	return S[l]; }
			}

	else{
//	printf("\n Attacking \n");
	return A[k];
			}
								
		}
*/

int comp(int N[5][15],int C[5][5])
{
int c=0,o=0,sf=0,at=0,A[25],B[25],NN[5][15],CC[5][5],NNN[5][15],CCC[5][5],AA[25],BB[25],BBB[25],AAA[25],a=0,cc=0,oo=0,ooo=0,ccc=0,i=0,j=0;
int oooo=0,D[25]={0},S[25],b,k=0,l=0;
	for(i=1;i<=25;i++)
	S[i-1]=i;

	d=25;

	for(i=0;i<5;i++)
	for(j=0;j<5;j++){ 
	if(C[i][j]<=0)
	A[c++]=(5*i)+j+1;
	
	else if(C[i][j]>0){
	B[o++]=(5*i)+j+1;
	del(S,D,((5*i)+j+1));}
		}

	for(i=0;i<5;i++)
	for(j=0;j<5;j++) 
	if(C[i][j]<0)
	b++;

	ooo=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(N[k][j]>0)
	++ooo;

	ccc=0;
	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(N[k][j]<0)
	++ccc;

//defence
	if(oo>10)
	{
	sf=0;
	for(i=0;i<o;i++)     {
	
	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NN[k][j]=N[k][j];
	 CC[k][j/3]=C[k][j/3];
		}

	manage(NN,0,B[i],CC);
	set(NN,CC);
//printf("\n Printing\n");
//build(NN,0,1);

	oo=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NN[k][j]>0){
	++oo;
//printf("\nNN k=%d j=%d\n",k,j);
				}

//	printf("\noo=%d\n",oo);
	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CC[k][j]>0){
	++oo;
//printf("\nCC k=%d j=%d\n",k,j);
				}
	BB[i]=oo-o-ooo-1;

	//printf("\n BB[i]=%d  oo=%d  o=%d ooo=%d \n",BB[i],oo,o,ooo);
//safe attack check
	if(BB[i]>0) {

	at=0;


	for(l=0;l<c;l++)     {
	
	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NN[k][j]=N[k][j];
	 CC[k][j/3]=C[k][j/3];
		}

	manage(NN,1,A[l],CC);
	set(NN,CC);

	cc=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NN[k][j]<0)
	++cc;

	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CC[k][j]<0)
	++cc;

	AA[l]=cc-b-ccc-1;
//printf("\n AA[l]=%d  cc=%d  b=%d ccc=%d \n",AA[l],cc,b,ccc);
//safety check again

	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NNN[k][j]=NN[k][j];
	 CCC[k][j/3]=CC[k][j/3];
		}

	manage(NNN,0,B[i],CCC);
	set(NNN,CCC);

	oooo=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NNN[k][j]>0)
	++oooo;

	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CCC[k][j]>0)
	++oooo;
			
	sf=oooo-oo-1;

//	printf("\n sf=%d  oo=%d  oooo=%d at=%d  (AA[l]-sf)=%d A[l]=%d\n",sf,oo,oooo,at,(AA[l]-sf),A[l]);
	
	D[l]=AA[l];	

	if(sf>=0)
	del(S,D,A[l]);
	

				}

		    }	

		}

}

//attack

	for(i=0;i<c;i++)     {
	
	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NN[k][j]=N[k][j];
	 CC[k][j/3]=C[k][j/3];
		}

	manage(NN,1,A[i],CC);
	set(NN,CC);

	cc=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NN[k][j]<0)
	++cc;

	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CC[k][j]<0)
	++cc;

	AA[i]=cc-b-ccc-1;

	set(NN,CC);

	o=0;

	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CC[k][j]>0)
	B[o++]=(5*k)+j+1;

	ooo=0;
	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NN[k][j]>0)
	++ooo;

	sf=0;

	for(l=0;l<o;l++)     {
	
	for(k=0;k<5;k++)
	for(j=0;j<15;j++){
	 NNN[k][j]=NN[k][j];
	 CCC[k][j/3]=CC[k][j/3];
		}

	manage(NNN,0,B[l],CCC);
	set(NNN,CCC);
//printf("\n Printing\n");
//build(NN,0,1);

	oo=0;

	for(k=0;k<5;k++)
	for(j=0;j<15;j++)
	if(NNN[k][j]>0){
	++oo;
//printf("\nNN k=%d j=%d\n",k,j);
				}

//	printf("\noo=%d\n",oo);
	
	for(k=0;k<5;k++)
	for(j=0;j<5;j++)
	if(CCC[k][j]>0){
	++oo;
//printf("\nCC k=%d j=%d\n",k,j);
				}
	BB[l]=oo-o-ooo-1;
//	printf("\nBB[%d]=%d\n",BB[l],l);

	if(BB[l]>sf)
	sf=BB[l];

						}

	AAA[i]=sf;
/*	k=0;
 	for(j=1;j<o;j++)
	if(BB[j]>BB[k])
	 k=j;
	AAA[i]=BB[k];
	printf("\n AAA[i]=%d  BB[k]=%d",AAA[i],BB[k]);
							}*/
				}

/*	printf("\n attack \n");
	for(i=0;i<c;i++)
	printf(" %d ",A[i]);
	printf("\n");
	for(i=0;i<c;i++)
	printf(" %d ",AA[i]);
	printf("\n");
	for(i=0;i<c;i++)
	printf(" %d ",AAA[i]);*/

//	printf("\ndefence\n");
	k=0;
 	for(i=1;i<c;i++){
	if(AA[i]>AA[k])
	 k=i;
	else if(AA[i]==AA[k]){
	if(AAA[k]>AAA[i])
	k=i;
	}
	}

/*	if(t<4){

	if(C[0][0]==0)
		return 1;
	else if(C[0][4]==0)
		return 5;
	else if(C[4][0]==0)
		return 21;
	else if(C[4][4]==0)
		return 25;

			}

	else{*/

	if(d>0) {
	l=0;
 	for(i=1;i<d;i++)
	if(D[i]>=D[l])
	 l=i;

/*	for(i=0;i<d;i++)
	printf(" %d ",S[i]);
	printf("\n");
	for(i=0;i<d;i++)
	printf(" %d ",D[i]);
	printf("\nAA[k]=%d  D[l]=%d A[k]=%d  S[l]=%d \n",AA[k],D[l],A[k],S[l]);*/

	if(AA[k]>D[l]){
//	printf("\nAttacking\n");
	return A[k];}

	else{
//	printf("\n defencing\n");
	return S[l]; }
			}

	else{
//	printf("\n Attacking \n");
	return A[k];
			}
								
		}

int main(){
int N[5][15],C[5][5],k=0,x,y,z,j,i,A[5][5];
		int n=0,p=0,t=0,tt=1;

	for(i=0;i<5;i++)
	  for( j=0;j<15;j++)
		 {
			N[i][j]=0;
			 C[i][j/3]=0;
								 }
	for(i=0;i<5;i++)
	for( j=0;j<5;j++)

	scanf("%d",&A[i][j]);
		
		scanf("%d",&p);

if(p==2){


	for(i=0;i<5;i++)
	for( j=0;j<5;j++){

	if(A[i][j]/10==1)
	 x=1;
	else if(A[i][j]/10==2)
	x=-1;
	else 
	x=0;

	if((i==0 && j==0) || (i==0 && j==4) || (i==4 && j==0) || (i==4 && j==4)){
	N[i][3*j]=0;
	N[i][3*j+1]=0;
	N[i][3*j+2]=x;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
			}

	else if((i==1 && j==1)||(i==1 && j==2)||(i==1 && j==3)||(i==2 && j==1)||(i==2 && j==2)||(i==2 && j==3)||(i==3 && j==1)||(i==3 && j==2)||(i==3 && j==3)){
		
		if(A[i][j]%10==0){
		N[i][3*j]=0;
		N[i][3*j+1]=0;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

		else if(A[i][j]%10==1){
		N[i][3*j]=1;
		N[i][3*j+1]=0;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

		if(A[i][j]%10==2){
		N[i][3*j]=x;
		N[i][3*j+1]=x;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

		if(A[i][j]%10==3){
		N[i][3*j]=x;
		N[i][3*j+1]=x;
		N[i][3*j+2]=x;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

		}

 else{

	if(A[i][j]%10==0){
		N[i][3*j]=0;
		N[i][3*j+1]=0;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

	if(A[i][j]%10==1){
		N[i][3*j]=0;
		N[i][3*j+1]=x;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

	if(A[i][j]%10==2){
		N[i][3*j]=0;
		N[i][3*j+1]=x;
		N[i][3*j+2]=x;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}	
				}
		
					}
		set(N,C);
		n=comp(N,C);	}

else if(p==1){

for(i=0;i<5;i++)
	for( j=0;j<5;j++){

	if(A[i][j]/10==1)
	 x=1;
	else if(A[i][j]/10==2)
	x=-1;
	else 
	x=0;

	if((i==0 && j==0) || (i==0 && j==4) || (i==4 && j==0) || (i==4 && j==4)){
	N[i][3*j]=0;
	N[i][3*j+1]=0;
	N[i][3*j+2]=x;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
			}

	else if((i==1 && j==1)||(i==1 && j==2)||(i==1 && j==3)||(i==2 && j==1)||(i==2 && j==2)||(i==2 && j==3)||(i==3 && j==1)||(i==3 && j==2)||(i==3 && j==3)){
		
		if(A[i][j]%10==0){
		N[i][3*j]=0;
		N[i][3*j+1]=0;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

		else if(A[i][j]%10==1){
		N[i][3*j]=1;
		N[i][3*j+1]=0;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

		if(A[i][j]%10==2){
		N[i][3*j]=x;
		N[i][3*j+1]=x;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

		if(A[i][j]%10==3){
		N[i][3*j]=x;
		N[i][3*j+1]=x;
		N[i][3*j+2]=x;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

		}

 else{

	if(A[i][j]%10==0){
		N[i][3*j]=0;
		N[i][3*j+1]=0;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

	if(A[i][j]%10==1){
		N[i][3*j]=0;
		N[i][3*j+1]=x;
		N[i][3*j+2]=0;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}

	if(A[i][j]%10==2){
		N[i][3*j]=0;
		N[i][3*j+1]=x;
		N[i][3*j+2]=x;
	//printf("\nx=%d,i=%d j=%d A[i][j]=%d  N[i][j]=%d N[i][j]=%d  N[i][j]=%d\n",x,i,j,A[i][j],N[i][3*j],N[i][3*j+1],N[i][3*j+2]);
}	
				}
		
					}

		set(N,C);
		n=comp(N,C);				}

		printf("%d %d",(n-1)/5,(n-1)%5);
											}
		
void set(int N[5][15],int C[5][5])
{
  int i,j;

	 for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			C[i][j]=N[i][3*j]+N[i][3*j+1]+N[i][3*j+2];

							 }


void manage(int N[5][15],int k, int z, int C[5][5])
{
		int n=1,x,y,i;
		  int A[1000];		
             	A[0]=z;
		//printf("\nbreak\n");

	 do{	
		  for(i=0;i<n;i++)
			 {
				//printf("n=%d\n",n);
				set(N,C);

				  x=(A[i]-1)/5;
					y=(A[i]-1)%5;

					if(A[i]==1 || A[i]==5 || A[i]==21 || A[i]==25)
					 {
						if(C[x][y]==0){
						  if((k%2)==0)
							N[x][3*y+1]=1;
							 else if((k%2)==1)
								N[x][3*y+1]=-1;
														}

							 else if(C[x][y]==1 || C[x][y]==-1 )
								{
								  N[x][3*y+1]=0;

									 if(A[i]==1){
										A[n]=2;
										 A[n+1]=6;
														}

										else if(A[i]==5){
										 A[n]=4;
										  A[n+1]=10;
										  }

											else if(A[i]==21){
											  A[n]=22;
												A[n+1]=16;
																	 }

												else if(A[i]==25){
												 A[n]=24;
												  A[n+1]=20;
												  }

								 n=n+2;
													  }
															  }

			  else if(A[i]==2 || A[i]==3 || A[i]==4 || A[i]==10 || A[i]==15 || A[i]==20 ||A[i]==6 || A[i]==16 || A[i]==11 || A[i]==22 ||A[i]==23 || A[i]==24  )
				 {

					if(C[x][y]==0)
					 {
						if((k%2)==0)
						  N[x][3*y+1]=1;

							else if((k%2)==1)
							  N[x][3*y+1]=-1;
														 }

							  else if( C[x][y]==1 || C[x][y]==-1)
								 {
									if((k%2)==0)
									{
									  N[x][3*y+1]=1;
										N[x][3*y+2]=1;
															 }

										 else if((k%2)==1)
										  {
											 N[x][3*y+1]=-1;
												N[x][3*y+2]=-1;
																	  }

																		  }


										else if(C[x][y]==2 || C[x][y]==-2)
										  {
											  N[x][3*y+1]=0;
												N[x][3*y+2]=0;

											 if( A[i]==2 || A[i]==3 || A[i]==4)
												{
												  A[n]=A[i]+1;
													A[n+1]=A[i]-1;
													 A[n+2]=A[i]+5;
																			 }

												 else if(A[i]==6 || A[i]==11 || A[i]==16)
												  {
													 A[n]=A[i]+1;
													  A[n+1]=A[i]+5;
														A[n+2]=A[i]-5;
																				}

											 else if(A[i]==10 || A[i]==15 || A[i]==20)
												  {
													 A[n]=A[i]-1;
													  A[n+1]=A[i]+5;
														A[n+2]=A[i]-5;
																				}

											  else if(A[i]==22 || A[i]==23 || A[i]==24)
												  {
													 A[n]=A[i]+1;
													  A[n+1]=A[i]-1;
														A[n+2]=A[i]-5;
																				}

												 n=n+3;
																  }
																		  }



  else if(A[i]==7 || A[i]==8 || A[i]==9 || A[i]==12 || A[i]==13 ||A[i]==14 || A[i]==17 || A[i]==18 || A[i]==19)
	{
	  if(C[x][y]==0)
	  {
		if((k%2)==0)
		 N[x][3*y]=1;
		  else if((k%2)==1)
			N[x][3*y]=-1;
											 }

	  else if(C[x][y]==1 || C[x][y]==-1 )
		{
		  if((k%2)==0)
			{
			 N[x][3*y]=1;
			  N[x][3*y+1]=1;
								  }

				else if((k%2)==1)
				 {
					N[x][3*y]=-1;
					 N[x][3*y+1]=-1;
											 }

														}

		  else if(C[x][y]==2 || C[x][y]==-2)
			{
			  if((k%2)==0)
				{
				  N[x][3*y]=1;
					N[x][3*y+1]=1;
					 N[x][3*y+2]=1;
										 }

				  else if((k%2)==1)
					 {
						N[x][3*y]=-1;
						  N[x][3*y+1]=-1;
							N[x][3*y+2]=-1;
													 }

														  }

			else if(C[x][y]==3 || C[x][y]==-3)
			 {
				N[x][3*y]=0;
				 N[x][3*y+1]=0;
				  N[x][3*y+2]=0;

					 A[n]=A[i]+1;
					  A[n+1]=A[i]-1;
						A[n+2]=A[i]+5;
						 A[n+3]=A[i]-5;

							n=n+4;
												}

																		 }

																			  }


																					} while(n!=i);


						}