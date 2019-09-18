#include<stdio.h>

struct Node
{
	int data;
	Node* leftchild;
	Node* rightchild;
};
int preorder[50050];
int inorder[50050];
int postfirst=-1;

Node* create(int prel,int prer,int inl,int inr)
{
	if(prel>prer) return NULL;
	Node* node=new Node;
	node->data=preorder[prel];
	node->rightchild=NULL;
	node->leftchild=NULL;
	int i;
	for(i=inl;i<inr;i++)
	{
		if(preorder[prel]==inorder[i]) break;
	}
	int numl=i-inl;
	node->leftchild=create(prel+1,prel+numl,inl,i-1);
	node->rightchild=create(prel+numl+1,prer,i+1,inr);
	return node; 
}
void dfs(Node* root)
{
	if(root==NULL) return ;
	dfs(root->leftchild);
	dfs(root->rightchild);
	if(postfirst==-1) 
	{
		postfirst=root->data;
	}
	return;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&preorder[i]);
	}
	for(int i=0;i<num;i++)
	{
		scanf("%d",&inorder[i]);
	}
	Node* root=create(0,num-1,0,num-1);
	dfs(root);
	printf("%d",postfirst);
}
