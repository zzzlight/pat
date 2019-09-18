#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
	int id;
	int weight;
}node[50050];
Node backup[50050];
vector<int> seq;
bool cmp(Node a,Node b)
{
	if(a.weight!=b.weight) return a.weight>b.weight;
	else return a.id<b.id;
}
int main()
{
	int num;
	scanf("%d",&num);
	int maxnum;
	scanf("%d",&maxnum);
	int t;
	scanf("%d",&t);
//	seq.push_back(t);
	node[t].id=t;
	node[t].weight++;
	for(int i=1;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		for(int i=0;i<num;i++)
		{
			backup[i].id=node[i].id;
			backup[i].weight=node[i].weight;
		}
		sort(backup,backup+num,cmp);
		printf("%d:",temp);
		if(i<maxnum)
		{
			for(int j=0;j<i;j++)
			{
				printf(" %d",backup[j].id);
			}
			if(i!=num) printf("\n");
		}
		else
		{
			for(int j=0;j<maxnum;j++)
			{
				printf(" %d",backup[j].id);
			}
			if(i!=num) printf("\n");
		}
		node[temp].id=temp;
		node[temp].weight++;
	}
}
