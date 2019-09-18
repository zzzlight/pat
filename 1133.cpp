#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
          //倒数第二个测试点错误  while处还是seq进队时候 有特殊数据影响  
struct Node
{
	int xb;
	int data;
	int next;
}node[100005];
Node newnode[100005];
bool mark[100005];
vector<Node> seq; 
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
	int t=0;
	while(id!=-1)
	{
		newnode[t].xb=id;
		newnode[t].data=node[id].data;
		t++;
		id=node[id].next;
	}
	for(int i=0;i<num;i++)
	{
		if(newnode[i].data<0) seq.push_back(newnode[i]);
	}
	for(int i=0;i<num;i++)
	{
		if(newnode[i].data>=0&&newnode[i].data<=k) seq.push_back(newnode[i]);
	}
	for(int i=0;i<num;i++)
	{
		if(newnode[i].data>k) seq.push_back(newnode[i]);
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
