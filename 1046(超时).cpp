#include<cstdio>
#include<algorithm>
using namespace std;
#define max 100010
#define maxn 1010
int main()
{
	int distance[maxn]={0};
	int distance2,distance3,distance4=0;
	int distance1=0;
	int point[max]={0};
	int num,sum=0;
	int m,n;
	int group;
	scanf("%d",&num);
	for(int i=1;i<=num;++i)
	{
		scanf("%d",&point[i]);	
		sum+=point[i];
			
	}
	
	scanf("%d",&group);
	for(int a=0;a<group;++a)
	{
	scanf("%d %d",&m,&n);
	
	if(m>n) swap(m,n);

		for(int j=n;j<=num;++j)
		{
			distance4+=point[j];
		
		} 
		for(int y=1;y<m;++y)
		{
			distance3+=point[y];
		}
	
		distance2=distance3+distance4;
		distance1=sum-distance2;
	
		distance3=0;
		distance4=0;
		
		if(distance2>distance1){
			distance[a]=distance1;
		}else distance[a]=distance2;
		


	}

	
	
	
	for(int x=0;x<group;++x)
	{
		printf("%d\n",distance[x]);
	}
	
} 
