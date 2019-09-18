#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	Node* leftchild;
	Node* rightchild;
	int data;
};
vector<int> orgin;
vector<int> preorder;
vector<int> postorder;
vector<int> mirpreorder;
vector<int>mirpostorder;


void insert(Node* &root,int temp)           //传引用修改root值 
{
	if(root==NULL)
	{
		root=new Node;
		root->data=temp;	
		root->leftchild=NULL;
		root->rightchild=NULL;
		return;
	}
	if(temp<root->data)            //若非空到其子节点去 不断深搜直到为NULL处新建节点 
	{									 
		insert(root->leftchild,temp);
		
	}
	else
	{
		insert(root->rightchild,temp);
	}
	

}
void preorderfind(Node* root)
{
	if(root==NULL) return;
	preorder.push_back(root->data);
	if(root->leftchild!=NULL)
	{
		preorderfind(root->leftchild);
	}
	if(root->rightchild!=NULL)
	{
		preorderfind(root->rightchild);
	}
	
}
void mirpreorderfind(Node * root)
{
	if(root==NULL) return;
	mirpreorder.push_back(root->data);
	if(root->rightchild!=NULL)               //镜像的先序实际就是原树进行根右左 
	{
		mirpreorderfind(root->rightchild);
	}
	if(root->leftchild!=NULL)
	{
		mirpreorderfind(root->leftchild);
	}
	
	
}
void postorderfind(Node* root)
{
	if(root==NULL) return;
	if(root->leftchild!=NULL)
	{
		postorderfind(root->leftchild);
	}
	if(root->rightchild!=NULL)
	{
		postorderfind(root->rightchild);
	}
	postorder.push_back(root->data);
}
void mirpostorderfind(Node* root)
{
	if(root==NULL) return;
	if(root->rightchild!=NULL)
	{
		mirpostorderfind(root->rightchild);
	}
	if(root->leftchild!=NULL)
	{
		mirpostorderfind(root->leftchild);
	}
	
	mirpostorder.push_back(root->data);
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
		orgin.push_back(temp);
		insert(root,temp);  //第一次为用别名修改了root  后续循环由于root不为null，进入后面再深搜，都是用别名修改了root的后续子节点 
	}
	preorderfind(root);
	mirpreorderfind(root);
	if(orgin==preorder||orgin==mirpreorder) 
	{
		printf("YES\n");
		if(orgin==preorder)
		{
			postorderfind(root);
			auto x=postorder.begin();
			for(;x!=postorder.end()-1;x++)
			{
				printf("%d ",*x);
			}
			printf("%d",*x);
		}
		else
		{
			mirpostorderfind(root);
			auto x=mirpostorder.begin();
			for(;x!=mirpostorder.end()-1;x++)
			{
				printf("%d ",*x);
			}
			printf("%d",*x);
		}
	}
	else
	{
		printf("NO");
	}
	
 } 
