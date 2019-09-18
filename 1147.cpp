#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
	int data;
	Node* leftchild;
	Node* rightchild;
};
int mycount=0;
int testnum;
int num;
Node* build(vector<int> seq,int i)
{
	if(i>=num) return NULL;
	Node* node=new Node;
	node->data=seq[i];
	node->leftchild=NULL;
	node->rightchild=NULL;
	node->leftchild=build(seq,2*i+1);
	node->rightchild=build(seq,2*i+2);
	return node;
	
}
int dfs1(vector<int> seq,int i,int mode)
{
	for(int i=0;i<num/2;i++)
	{
		if(mode==-1)
		{
			if(2*i+2<num)
			{
				if(seq[i]>seq[i*2+1]||seq[i]>seq[i*2+2]) return 0;	
			}
			else if(2*i+1<num&&2*i+2==num) 
			{
				if(seq[i]>seq[i*2+1]) return 0;	
			}  
		}
		if(mode==1)
		{
			if(2*i+2<num)
			{
				if(seq[i]<seq[i*2+1]||seq[i]<seq[i*2+2]) return 0;	
			}
			else if(2*i+1<num&&2*i+2==num) 
			{
				if(seq[i]<seq[i*2+1]) return 0;	
			}  			
		}
	}
	return mode;
	 
}
void dfs2(Node* root)
{
	if(root==NULL) return;
	dfs2(root->leftchild);
	dfs2(root->rightchild);
	if(mycount<num-1) 
	{
		printf("%d ",root->data); 
		mycount++;
	}
	else
	{
			printf("%d",root->data); 
	}
	
}
int main()
{

	scanf("%d %d",&testnum,&num);
	for(int i=0;i<testnum;i++)
	{
		vector<int> seq;
		int mode;
		for(int j=0;j<num;j++)
		{
			int temp;
			scanf("%d",&temp);
			seq.push_back(temp);
		}
		Node *root=build(seq,0);
		if(seq[0]>seq[1]) mode=1;
		else mode=-1; 
		int flag=dfs1(seq,0,mode);
		if(flag==0) printf("Not Heap\n");
		else if(flag==1) printf("Max Heap\n");
		else if(flag==-1) printf("Min Heap\n");
		dfs2(root);
		if(testnum-1!=i)printf("\n");
		mycount=0;
	}
}
