#include<cstdio>
#include<algorithm>
using namespace std;
#define max 100010
#define maxn 1010
int main()
{
	int distance[maxn]={0};
	int temp[max]={0};
	int distance1;
	int point[max]={0};
	int num,sum=0;
	int m,n;
	int group;
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		scanf("%d",&point[i]);	
		sum+=point[i];
		distance[i]=sum;
	}
	
	scanf("%d",&group);
	for(int a=0;a<group;a++)
	{
	scanf("%d %d",&m,&n);
	
	if(m>n) swap(m,n);
	int distance1=distance[n-1]-distance[m-1];
		
	temp[a]=min(distance1,sum-distance1);
	
		


	}
	for(int q=0;q<group;q++)
	printf("%d\n",temp[q]);
	
	
/*	for(int x=0;x<group;++x)
	{
		printf("%d\n",min(distance1,sum-distance1));
	}
	*/
} 
