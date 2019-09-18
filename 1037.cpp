#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
/*struct maxnum{
	int max;
	int flag=0;
}mmax[100005];*/
 bool cmp(int a,int b);
 int findmax(int a,int b); 
int main()
{
	int nc;
	int np;
	int ncnum[100005];
	int npnum[100005];
	memset(ncnum,0,sizeof(ncnum));
	memset(npnum,0,sizeof(npnum));
	int sum=0;
	scanf("%d",&nc);
	for(int i=0;i<nc;i++)
	{
		scanf("%d",&ncnum[i]);
	}
	sort(ncnum,ncnum+nc,cmp);
	scanf("%d",&np);
	for(int j=0;j<np;j++)
	{
		scanf("%d",&npnum[j]);
	}
	sort(npnum,npnum+np,cmp);
	int max=findmax(nc,np);
	int room;
	if(np!=nc) room=abs(np-nc);
	int min=max-room;
		
	 		int flag;
	 		if(np==min) flag=0;
	 		else flag=1;
	for(int i=0;i<max;i++)
	{
		if(ncnum[i]>0&&npnum[i]>0)
		sum+=ncnum[i]*npnum[i];
		else break;
		
	 } 
	 if(room==0)
	 {
	 		 for(int j=max-1;j>=0;j--)
	 	{
	 		if(ncnum[j]<0&&npnum[j]<0)
	 		sum+=ncnum[j]*npnum[j];
	 		else break;
	 	}
	 }
	 else
	 {

	 	 for(int j=max-1;j>=0;j--)
	 	{
	 	
	 		if(flag==0&&min>=0)
	 			{
				 	if(ncnum[j]<0&&npnum[(min-1)]<0)      //注意长短不一情况 
	 			{
	 			
	 				sum+=ncnum[j]*npnum[(min-1)];
	 				min--;
	 				
				 }
	 			else break;
				 }
				 
	 		if(flag==1&&min>=0)
	 		{
	 			
	 			
	 			if(ncnum[min-1]<0&&npnum[j]<0)
	 			{
	 					sum+=ncnum[min-1]*npnum[j];
				 		min--;
				 }
	 			else break;	
				 
				 
	 			
			 }
	 		
	 	}
	 }

	printf("%d",sum);
 } 
bool cmp(int a,int b)
{
	return a>b;
}
int findmax(int a,int b)
{
	if(a>b)
	return a;
	else return b;
}
