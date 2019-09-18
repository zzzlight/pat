#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int flag=true;
vector<int> result;
int num;
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
	root->height=max(getheight(root->rightchild),getheight(root->leftchild))+1;   //stl函数max 
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
		root=newnode(v);  //必须要新建另一个再赋值  不能用root进行new 
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
void bfs(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node* t=q.front();
		q.pop();
		result.push_back(t->value);
		if(t->leftchild!=NULL) q.push(t->leftchild);
		if(t->rightchild!=NULL) q.push(t->rightchild);
		
	}
}
void bfs2(Node* root)
{
	queue<Node*> q;
	q.push(root);
	bool leaf=false;
	while(!q.empty())
	{
		Node* t=q.front();
		q.pop();
		if(t->rightchild!=NULL&&t->leftchild==NULL) flag=false;   //当前结点有右孩子无左孩子
		if(leaf&&(t->leftchild!=NULL||t->rightchild!=NULL)) flag=false;  //当前结点不是叶子结点且之前结点有叶子结点 
		if(t->leftchild!=NULL) q.push(t->leftchild);
		if(t->rightchild!=NULL) q.push(t->rightchild);
		if(t->leftchild==NULL||t->rightchild==NULL) leaf=true; //记录之前有没有存在叶子节点 
	}
}
int main()
{
	Node *root=NULL;

	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int temp;
		scanf("%d",&temp);
		insert(root,temp);
	}
	//printf("%d*",root->value);
	bfs(root);
	for(int i=0;i<result.size();i++)
	{
		printf("%d",result[i]);
		if(i!=result.size()-1) printf(" "); 
	}
	bfs2(root); 
	printf("\n");
	if(flag==false) printf("NO\n");
	else printf("YES\n");
}
