#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
  //ac代码  while处分三个 然后最后按顺序进seq 
struct Node
{
	int xb;
	int data;
	int next;
}node[100005];
Node newnode[100005];
vector<Node> seq; 
vector<Node> v1;
vector<Node> v2;
vector<Node> v3; 
int main()
{
	int start=-1;
	int num;
	int k;
	scanf("%d",&start);
	scanf("%d",&num);
	scanf("%d",&k);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		node[temp].xb=temp;
		scanf("%d",&node[temp].data);
		scanf("%d",&node[temp].next);
		
	}
	int id=start;
	
	while(id!=-1)
	{
		if(node[id].data<0) v1.push_back(node[id]);
		else if(node[id].data>=0&&node[id].data<=k) v2.push_back(node[id]);
		else v3.push_back(node[id]);
		id=node[id].next;
	}
	for(int i=0;i<v1.size();i++)
	{
		seq.push_back(v1[i]);
	}
	for(int i=0;i<v2.size();i++)
	{
		seq.push_back(v2[i]);
	}
	for(int i=0;i<v3.size();i++)
	{
		seq.push_back(v3[i]);
	}
	if(num==1)
	{
		printf("%05d %d -1",seq[0].xb,seq[0].data);
	}
	else
	{
		for(int i=0;i<seq.size();i++)
		{
			printf("%05d %d",seq[i].xb,seq[i].data);
			if(i!=seq.size()-1) printf(" %05d\n",seq[i+1].xb);
			if(i==seq.size()-1) printf(" -1");
		}
	
	}

	
}
