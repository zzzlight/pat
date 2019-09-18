#include<stdio.h>
#include<vector>

using namespace std; 

struct Node
{
	Node* leftchild;
	Node* rightchild;
	int value;
	int height;
};
Node * newnode(int v)
{
	Node * anode=new Node;
	anode->value=v;
	anode->leftchild=NULL;
	anode->rightchild=NULL;
	anode->height=1;
	return anode;
}
int getheight(Node *root)
{
	if(root==NULL) return 0;
	return root->height;
}
int getbalancefactor(Node *root)
{
	return getheight(root->leftchild)-getheight(root->rightchild);
}
void updateheight(Node *root)
{
	root->height=max(getheight(root->rightchild),getheight(root->leftchild))+1;   //stlº¯Êýmax 
}


void L(Node * &root)
{
	Node* temp=root->rightchild;
	root->rightchild=temp->leftchild;
	temp->leftchild=root;
	updateheight(root);
	updateheight(temp);
	root=temp;
}
void R(Node *&root)
{
	Node* temp=root->leftchild;
	root->leftchild=temp->rightchild;
	temp->rightchild=root;
	updateheight(root);
	updateheight(temp);
	root=temp;
}
void insert(Node* &root,int v)
{
	if(root==NULL)
	{
		root=newnode(v);
		return;
	}
	if(v<root->value)
	{
		insert(root->leftchild,v);
		updateheight(root);
		if(getbalancefactor(root)==2)
		{
			if(getbalancefactor(root->leftchild)==1)
			{
				R(root);
			}
			else if(getbalancefactor(root->leftchild)==-1)
			{
				L(root->leftchild);
				R(root);
			}
		}
		
	}
	else
	{
		insert(root->rightchild,v);
		updateheight(root);
		if(getbalancefactor(root)==-2)
		{
			if(getbalancefactor(root->rightchild)==-1)
			{
				L(root);
			}
			else if(getbalancefactor(root->rightchild)==1)
			{
				R(root->rightchild);
				L(root);
			}
		}
	}
}
int main()
{
	int num;
	Node *root=NULL;
	scanf("%d",&num);
	
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		insert(root,temp);
	}
	printf("%d",root->value);
 } 
