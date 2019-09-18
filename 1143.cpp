#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

struct Node
{
	int data;
	Node* leftchild;
	Node* rightchild;
};
vector<int> inorder;
vector<int> preorder;
bool flag;
Node* create(int prel,int prer,int inl,int inr)
{
	if(prel>prer) return NULL;
	Node* node=new Node;
	node->data=preorder[prel];
	node->leftchild=NULL;
	node->rightchild=NULL;
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
 void dfs1(Node* root,int data1,int data2)
 {
 	if(root==NULL) return;
 	if(root->data==data1)
 	{
 		printf("%d is an ancestor of %d.\n",data1,data2);
 		return ;
	 }
	 else if(root->data==data2)
	 {
	 	printf("%d is an ancestor of %d.\n",data2,data1);
	 	return ;
	 }
	 else if(root->data>data1&&root->data<data2)
	 {
	 	if(flag==true)
	 	{
	 		printf("LCA of %d and %d is %d.\n",data2,data1,root->data);
		 }
		 else
		 {
		 	printf("LCA of %d and %d is %d.\n",data1,data2,root->data);
		 }
		 return;
	 }
	 else if(root->data<data1&&root->data<data2) dfs1(root->rightchild,data1,data2);
	 else dfs1(root->leftchild,data1,data2);
	 
 }

int main()
{
	unordered_set<int> ss; //给的data不是从1到vnum 
	int testnum;
	int vnum;
	scanf("%d %d",&testnum,&vnum);
	for(int i=0;i<vnum;i++)
	{
		int temp;
		scanf("%d",&temp);
		preorder.push_back(temp);
		inorder.push_back(temp);
		ss.insert(temp);
	}
	sort(inorder.begin(),inorder.end());
	Node* root=create(0,vnum-1,0,vnum-1);
	for(int i=0;i<testnum;i++)
	{
		int test1;
		int test2;
		scanf("%d %d",&test1,&test2);
		if(ss.find(test1)==ss.end()&&ss.find(test2)==ss.end())
		{ 	 
			printf("ERROR: %d and %d are not found.\n",test1,test2);
		} 
		else if(ss.find(test1)==ss.end())
		{
			printf("ERROR: %d is not found.\n",test1);
		}
		else if(ss.find(test2)==ss.end())
		{
			printf("ERROR: %d is not found.\n",test2);
		}
		else
		{
			flag=false;
			if(test1>test2) 
			{
				swap(test1,test2);
				flag=true;
			}
			dfs1(root,test1,test2);
		}
	}
			
}
