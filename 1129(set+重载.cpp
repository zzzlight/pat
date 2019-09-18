#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set> 
using namespace std;

struct Node
{
	int id;
	int weight;
	Node(int idtemp,int weighttemp)
	{
		id=idtemp;
		weight=weighttemp;
	}
	Node():id(0),weight(0){}  //必须要 否则过不了编译 
	bool operator<(const Node &n)const
	{
		if(n.weight!=weight) return weight>n.weight;
		else return id<n.id; 
	}
}node;

int mark[50050];
set<Node> myset;

int main()
{
	int num;
	scanf("%d",&num);
	int maxnum;
	scanf("%d",&maxnum);

	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(i!=0)
		{
			printf("%d:",temp);
			int count=0;
			for(auto it=myset.begin();it!=myset.end()&&count<maxnum;count++,it++)
			{
			  printf(" %d",it->id);
			}
			if(i!=num-1) printf("\n");
		}
		if(myset.find(Node(temp,mark[temp]))!=myset.end())
		{
			myset.erase(myset.find(Node(temp,mark[temp])));
		}
		mark[temp]++;
		node.id=temp;
		node.weight=mark[temp];
	
		myset.insert(node);
		
	}
}
