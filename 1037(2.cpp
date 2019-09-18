#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
/*struct maxnum{
	int max;
	int flag=0;
}mmax[100005];*/
 bool cmp(int a,int b);

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
	sort(ncnum,ncnum+nc);
	scanf("%d",&np);
	for(int j=0;j<np;j++)
	{
		scanf("%d",&npnum[j]);
	}
	sort(npnum,npnum+np);
	int i=0;
	int j=0;
	while(i<nc&&i<np&&ncnum[i]<0&&npnum[i]<0)
	{
		sum+=ncnum[i]*npnum[i];
		i++;
	}
	 i=nc-1;
	 j=np-1;
	while(i>=0&&ncnum[i]>0&&j>=0&&npnum[j]>0)
	{
		sum+=ncnum[i]*npnum[j];
		i--;
		j--;
		
	}
	printf("%d",sum);
 } 
bool cmp(int a,int b)
{
	return a<b;
}

