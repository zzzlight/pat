#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
vector<int> result[50];
int inorder[50];
int postorder[50];
int num;
int maxlevel=-1;
struct Node
{
	int level=-1;
	int date;
	Node* rightchild;
	Node* leftchild;
};


Node* create(int postl,int postr,int inl,int inr)
{
	if(postl>postr) return NULL;
	Node* node=new Node;
	node->date=postorder[postr];
	node->rightchild=NULL;
	node->leftchild=NULL;
	int i;
	for(i=inl;i<=inr;i++)
	{
		if(postorder[postr]==inorder[i]) break;
	}
	int k=i-inl;
	node->leftchild=create(postl,postl+k-1,inl,i-1);
	node->rightchild=create(postl+k,postr-1,i+1,inr);
	return node;
}
void dfs(Node* root,int level)
{
	if(root==NULL) return;
	root->level=level;
	if(level>maxlevel) maxlevel=level;
	if(root->leftchild!=NULL) dfs(root->leftchild,level+1);
	if(root->rightchild!=NULL) dfs(root->rightchild,level+1);
	return ;
}
void bfs(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* n=q.front();
		q.pop();	
		result[n->level].push_back(n->date);
		if(n->leftchild!=NULL)
		{
			q.push(n->leftchild);
		}
		if(n->rightchild)
		{
			q.push(n->rightchild);
		}
		
		
	}
}
int main()
{
	
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		inorder[i]=temp;
	}
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		postorder[i]=temp;
	}
	Node* root=create(0,num-1,0,num-1);
	dfs(root,0);
	bfs(root);
	for(int i=0;i<=maxlevel;i++)
	{
			if(i%2==0)
			{
				for(int j=result[i].size()-1;j>=0;j--)
				{
					printf("%d",result[i][j]);
					if(i==maxlevel&&j==0) 
					{
						
					}
					else printf(" ");
						
				}	
			}
			else
			{
				for(int j=0;j<result[i].size();j++)
				{
					printf("%d",result[i][j]);
					if(i==maxlevel&&j==result[i].size()-1) 
					{
						
					}
					else printf(" ");
				}
			}
		

	}
}
