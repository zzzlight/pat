#include<stdio.h>
#include<vector>
#include<math.h>
#include<string.h> 
using namespace std;
int chongfu[100000];
struct Node
{
	int address;
	int date;
	int next;
}node[100001];
bool judge(int a)
{
	int b=abs(a);
	if(chongfu[b]==1)return false;
	else return true;
}
int main()
{
	vector<Node> list;
	vector<Node> removelist;
	int orgin;
	int num;
	scanf("%d",&orgin);	
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int address;
		scanf("%d",&address);
		node[address].address=address;
		scanf("%d %d",&node[address].date,&node[address].next);
	}
	int temp=orgin;
	int mytemp=orgin;
	while(temp!=-1)
	{
		if(judge(node[temp].date))
		{
			list.push_back(node[temp]);
			int atemp=abs(node[temp].date);
			chongfu[atemp]=1;
			mytemp=node[temp].address;
			temp=node[temp].next;
			
		}
		else
		{
			removelist.push_back(node[temp]);
			temp=node[temp].next;
			node[mytemp].next=temp;
		}
	}
	auto it=list.begin();
	for(;it!=list.end()-1;it++)
	{
		printf("%05d %d %05d\n",(*it).address,(*it).date,(*(it+1)).address);
	}
	if(list.size()<num)
	{
		printf("%05d %d -1\n",(*it).address,(*it).date);
		auto it1=removelist.begin();
			for(;it1!=removelist.end()-1;it1++)
				{
					printf("%05d %d %05d\n",(*it1).address,(*it1).date,(*(it1+1)).address);
				}
				printf("%05d %d -1",(*it1).address,(*it1).date);
	}	
	else
	{
			printf("%05d %d -1",(*it).address,(*it).date);
	}
	
 } 
