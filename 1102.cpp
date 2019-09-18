#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> inorder;
vector<int>levelorder;
struct node
{
	int leftchild=-1;
	int rightchild=-1;
	int father=-1;
}Node[15];
void myinorder(int root)
{
	if(root==-1)return;
	myinorder(Node[root].leftchild);
	inorder.push_back(root);
	myinorder(Node[root].rightchild);
}
void layerorder(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		levelorder.push_back(now);
		if(Node[now].leftchild!=-1) q.push(Node[now].leftchild);
		if(Node[now].rightchild!=-1) q.push(Node[now].rightchild);
	}
}
int main()
{
	int num;
	char temp;
//	scanf("%d",&num);
	cin>>num;	
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<2;j++)
		{
		cin>>temp;
		//	scanf("%c",&temp);
			if(temp!='-' )
			{
				if(j==1)
				{
					Node[i].leftchild=temp-'0';     //题目没说是先右孩子后左  但例子给出的是先右后左 
					Node[(temp-'0')].father=i;
				}
				else
				{
					Node[i].rightchild=temp-'0';
					Node[(temp-'0')].father=i;
				}
			
			}
			
		}
	
	}
	int flag=0;
	while(Node[flag].father!=-1)
	{
		flag=Node[flag].father;
	}
	myinorder(flag);
	layerorder(flag);
	int countlay=0;
	while(countlay!=num)
	{
		if(countlay==0)
		{
			printf("%d",levelorder[countlay]);
		}
		else
		{
			printf(" %d",levelorder[countlay]);
		}
		countlay++;	
	}
	printf("\n");
	int count=0;
	while(count!=num)
	{
		if(count==0)
		{
			printf("%d",inorder[count]);
		}
		else
		{
			printf(" %d",inorder[count]);
		}
		count++;	
	}
	
 } 
