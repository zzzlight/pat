#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<map>
using namespace std;

struct Node
{
	int data;
	Node *parent; 
	Node* leftchild;
	Node* rightchild;
};
vector<int> inorder;
vector<int> preorder;
map<int,Node*> mymap;
bool flag;
Node* create(int prel,int prer,int inl,int inr,Node *pa)
{
	if(prel>prer) return NULL;
	Node* node=new Node;
	node->data=preorder[prel];
	node->parent=pa;
	mymap[node->data]=node;
	node->leftchild=NULL;
	node->rightchild=NULL;
	int i;
	for(i=inl;i<inr;i++)
	{
		if(preorder[prel]==inorder[i]) break;
	}
	int numl=i-inl;
	node->leftchild=create(prel+1,prel+numl,inl,i-1,node);
	node->rightchild=create(prel+numl+1,prer,i+1,inr,node);
	return node;
 } 
 void check(Node* root,int data1,int data2)
 {
 	vector<int> seq1;
    vector<int> seq2;	
    Node* temp1=mymap[data1];
    Node* temp2=mymap[data2];
 	while(temp1!=NULL)
 	{
 		seq1.push_back(temp1->data);
 		temp1=temp1->parent;
	 }
	 while(temp2!=NULL)
	 {
	 	seq2.push_back(temp2->data);
	 	temp2=temp2->parent;
	 }
	 int mark=-1;
     int k=seq1.size()-1;
	 for(int t=seq2.size()-1;t>=0;t--)
	 {
	 	if(seq2[t]==seq1[k])      //从根到最近公共节点这一段 seq1,seq2两者必然是相同的 
	 	{
	 		mark=seq1[k];
	 		k--;
		 }
	}
	if(mark!=data1&&mark!=data2) printf("LCA of %d and %d is %d.\n",data1,data2,mark);
	else if(mark==data1) printf("%d is an ancestor of %d.\n",data1,data2);
	else if(mark==data2) printf("%d is an ancestor of %d.\n",data2,data1);
	 
 }

int main()
{
	unordered_set<int> ss;
	int testnum;
	int vnum;
	scanf("%d %d",&testnum,&vnum);
	for(int i=0;i<vnum;i++)
	{
		int temp;
		scanf("%d",&temp);
		inorder.push_back(temp);
		ss.insert(temp);
	}
	for(int i=0;i<vnum;i++)
	{
		int temp;
		scanf("%d",&temp);
		preorder.push_back(temp);
	} 
	Node* root=create(0,vnum-1,0,vnum-1,NULL);
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
			check(root,test1,test2);
		}
	}
			
}
