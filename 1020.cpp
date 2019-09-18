#include<stdio.h>
#include<queue>
using namespace std;
int num;
int postorder[50];
int inorder[50];
struct Tree
{
	Tree * leftchild;
	Tree * rightchild;
	int date;
};
queue<int> out;
Tree * findtree(int postL,int postR,int inL,int inR)
{
	if(postL>postR)   //postl=postr说明还有一个单个的 
	{
		return NULL;
	}
	Tree *root=new Tree;
	root->date=postorder[postR];
	int k;
	for(k=inL;k<inR;k++)
	{
		if(inorder[k]==postorder[postR])
		{
			break;
		}
	}
	int numLeft=k-inL;
	root->leftchild=findtree(postL,postL+numLeft-1,inL,k-1);
	root->rightchild=findtree(postL+numLeft,postR-1,k+1,inR);    //postr位为根 
	return root;
}

int n=0; 
void bfs(Tree* root)
{
	queue<Tree*> q;
	q.push(root);
	while(!q.empty())
	{
		Tree * now=q.front();
		q.pop();
		if(n!=num-1)
		{
		printf("%d ",now->date);
		n++;
		}
		else
		{
			printf("%d",now->date);
		}
		if(now->leftchild!=NULL)
		{
			q.push(now->leftchild);
				
		}
		if(now->rightchild!=NULL)
		{
			q.push(now->rightchild);
		}
	}

	
	
}
int main()
{

	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&postorder[i]);
	}
	for(int i=0;i<num;i++)
	{
		scanf("%d",&inorder[i]);
	}
	Tree * root=findtree(0,num-1,0,num-1);
	bfs(root);
}
