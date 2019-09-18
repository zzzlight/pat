#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int level;
int num;

vector<int> point[1001];
vector<int> result;
vector<int> test;
struct Node
{
	int num;
	int lel=1;
};
void bfs(int root)
{
	
	int lel=level;
	bool flag[1001];
	int count=0;
	memset(flag,0,sizeof(flag));
	Node myroot;
	myroot.num=root;
	queue<Node> q;
	q.push(myroot);
	flag[root]=true;
	while((!q.empty()))
	{
		Node newq=q.front();
		q.pop();
		flag[newq.num]==true;
		if(newq.lel>level) break;
		
		for(auto it1=point[newq.num].begin();it1!=point[newq.num].end();it1++)
		{
			
			if(flag[*it1]==false)
			{
				Node tempnode;
				tempnode.num=*it1;
				tempnode.lel=newq.lel+1;
				q.push(tempnode);
				count++;
				
			}
			
			flag[*it1]=true;
		
		}
		
		
		
		
		
	}
	result.push_back(count);
	
}
int main()
{
	
	scanf("%d",&num);
	scanf("%d",&level);
	
	for(int i=1;i<=num;i++)
	{
		int tempnum;
		scanf("%d",&tempnum);
		for(int j=0;j<tempnum;j++)
		{
			int temp;
			scanf("%d",&temp);
			point[temp].push_back(i);
		 } 
	}
	int testnum;
	scanf("%d",&testnum);
	for(int i=0;i<testnum;i++)
	{
		int a;
		scanf("%d",&a);
		test.push_back(a);
	}
	for(auto t=test.begin();t!=test.end();t++)
	{
		bfs(*t);
		
	}
	for(auto x=result.begin();x!=result.end();x++)
	{
		printf("%d",*x);
		if(x!=result.end()-1)
		{
			printf("\n");
		}
	}
	
 } 
