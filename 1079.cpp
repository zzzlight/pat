#include<stdio.h>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

struct Node{
	int level=0; //离根节点距离 
	vector<int> child;
	int father=-1;
	int data;
	int num=0;   //商品数量 
}node[100000];
vector<int> result;
vector<int> leaf;
int create(int i)
{
	int t=i;
	while(node[t].father!=-1)
	{
		t=node[t].father;
	}
	node[t].level=0;
	return t;
 } 
 void createlel(int root)
 {
 	int mark=0;
 	int flag;
 	int count=0;
 	queue<Node> q;
 	q.push(node[root]);
 	while(!q.empty())
 	{
 		Node now=q.front();
 		q.pop();
 		//count++;
 		if(now.child.empty())
 		{
 			result.push_back(now.data);
		}
		for(auto x=now.child.begin();x!=now.child.end();x++)
		{
			node[*x].level=now.level+1;   //每一层等于上一层加一 
			Node nowtemp=node[*x];
			q.push(nowtemp);
			flag=nowtemp.data;
		}
	
 		
 		
	 }
 }
int main()
{
	
	int num;
	double price;
	double rate;
	scanf("%d",&num);
	scanf("%lf",&price);
	scanf("%lf",&rate);
	for(int i=0;i<num;i++)
	{
		int childnum;
		scanf("%d",&childnum);
		if(childnum!=0)
		{
			while(childnum!=0)
			{
				int tempnum;
				scanf("%d",&tempnum);
				node[i].child.push_back(tempnum);
				node[tempnum].father=i;
				childnum--;
				node[i].data=i;
			}
		}
		else
		{
			int temp;
			scanf("%d",&temp);
			node[i].num=temp;
			node[i].data=i;
		}
	 } 
	 int root;
	 root=create(0);
	 createlel(root);  //找根没问题 
//	printf("%d--",node[4].level); 
	 double sum=0;
	 for(int y=0;y<result.size();y++)
	 {
	 	sum+=price*node[result[y]].num*pow(1.0+(rate/100.0),node[result[y]].level);
	 }
	 printf("%0.1lf",sum);
 } 
