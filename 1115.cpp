#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n1;
int n2;
int maxlevel=-1;
struct Node
{
	int level;
	int data=-1001;
	Node* leftchild;
	Node* rightchild;
}node; 
void insert(Node* &root,int data)
{
	if(root==NULL)
	{
		root=new Node;
		root->data=data;
		root->leftchild=NULL;
		root->rightchild=NULL;
		return ;
	}
	else
	{
		if(root->data<data)
		{
			insert(root->rightchild,data);
		}else
		{
			insert(root->leftchild,data);
		}
	}
	return ;
		
	
}
void dfs(int level,Node* &root)
{
	if(root==NULL)	return ;
	root->level=level;
	if(level>maxlevel) maxlevel=level;
	dfs(level+1,root->leftchild);
	 dfs(level+1,root->rightchild);
	return ;
}
void bfs(Node* &root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* t=q.front();
		q.pop();
		if(t->level==maxlevel-1) n2++;
		if(t->level==maxlevel) n1++;
		if(t->leftchild!=NULL) q.push(t->leftchild);
		if(t->rightchild!=NULL) q.push(t->rightchild);
	}
}
int main()
{
	int num;
	Node* root=NULL;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		insert(root,temp);
	}
	dfs(0,root);
	bfs(root);
	int sum=n1+n2;
	printf("%d + %d = %d",n1,n2,sum);
 } 
