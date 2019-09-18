#include<stdio.h>
#include<vector>

using namespace std;

struct Node
{
	vector<long long> child;
	int level=-1;
	long long childnum=0;
}node[100005];
void dfs(long long level,long long id)
{
	node[id].level=level;
	if(node[id].childnum!=0)
	{
		for(long long t=0;t<node[id].childnum;t++)
		{
			dfs((node[id].level)+1,node[id].child[t]);
		}
		
	}
	
}
int main()
{
	double lowprice;
	long long lowpricenum=0;
	double price;
	long long num;
	double rate;
	scanf("%lld %lf %lf\n",&num,&price,&rate);
	for(long long i=0;i<num;i++)
	{
		long long childnum;
		scanf("%lld",&childnum);
		node[i].childnum=childnum;
		for(long long j=0;j<childnum;j++)
		{
			long long temp;
			scanf("%lld",&temp);
			node[i].child.push_back(temp);
		}
	}
	dfs(1,0);
	long long min=100005;
	for(long long i=0;i<num;i++)
	{
		//printf("%d ",node[i].level);
		if(node[i].childnum==0&&node[i].level<min)
		{
			min=node[i].level;
		}
	}
	for(long long i=0;i<num;i++)
	{
		if(node[i].childnum==0&&node[i].level==min)
		lowpricenum++;
	}
	lowprice=price;
	for(long long i=0;i<min-1;i++)
	{
		lowprice*=(1.0+rate/100.0);
	}
	 
	

	printf("%.4f %lld",lowprice,lowpricenum);
 }   //其实没必要long long  数据中没越界的 
