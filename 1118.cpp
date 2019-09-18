#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool numbird[10005];
vector<bool> result;
int father[10005];
int treebird[10005];
int findfather(int x)
{
	if(x==father[x]) return x;
	else return findfather(father[x]);
}
void Union(int a,int b)
{
	int faA=findfather(a);
	int faB=findfather(b);
	if(faA!=faB)
	{
		father[max(faA,faB)]=min(faA,faB);
	}
}
int main()
{

	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int K;
		scanf("%d",&K);
		int ttemp;
		scanf("%d",&ttemp);
		numbird[ttemp]=true;
		if(father[ttemp]==0)
		father[ttemp]=ttemp;
		for(int j=1;j<K;j++)
		{
			int temp;
			scanf("%d",&temp);
			numbird[temp]=true;
			if(father[temp]==0)	father[temp]=temp;
			Union(ttemp,temp);
		}

	}
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int bird1,bird2;
		scanf("%d %d",&bird1,&bird2);
		if(findfather(bird1)==findfather(bird2))
		{
			result.push_back(true);
		}
		else
		{
			result.push_back(false);
		}
	}
	int birdnum=-1;
	for(int i=1;i<100005;i++)
	{
		if(numbird[i]==false)
		{
			birdnum=i-1;
			break; 
		} 
	}
	for(int i=1;i<=birdnum;i++)
	{
		treebird[findfather(i)]++;
	
	}
	int treenum=0;
	for(int i=0;i<10005;i++)
	{
		if(treebird[i]>0) treenum++;
	}
	printf("%d %d",treenum,birdnum);
	for(int i=0;i<result.size();i++)
	{
		if(result[i]==true) printf("\nYes");
		else printf("\nNo");
	}
}
