#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> preorder;
vector<int> inorder;
vector<int> result;
struct node
{
	node *leftchild;
	node *rightchild;
	int date;
};
node* create(int prel,int prer,int inl,int inr)
{
	if(prel>prer)
	{
		return NULL;
	}
	node* root=new node;
	root->date=preorder[prel];
	int k;
	for(k=inl;k<=inr;k++)
	{
		if(inorder[k]==preorder[prel])
		{
			break;
		}
	}
	int numleft=k-inl;
	root->leftchild=create(prel+1,prel+numleft,inl,k-1);
	root->rightchild=create(prel+numleft+1,prer,k+1,inr);
	return root;
}
void postorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	if(root->leftchild!=NULL)
	{
		postorder(root->leftchild);
	}
	if(root->rightchild!=NULL)
	{
		postorder(root->rightchild);
	}
	result.push_back(root->date);
}
int main()
{
	int num;
	stack<int> st;

	scanf("%d",&num);
	for(int i=0;i<2*num;i++)
	{
		string input;
		cin>>input;
		if(input=="Push")
		{
			int temp;
			cin>>temp;
			preorder.push_back(temp);
			st.push(temp);
		}
		else
		{
		int temp=st.top();
		inorder.push_back(temp);
		 st.pop();
		}
	}
	node* root=create(0,num-1,0,num-1);
	postorder(root);
	for(int i=0;i<num;i++)
	{
		if(i==0)
		{
			printf("%d",result[i]);
		}
		else
		{
			printf(" %d",result[i]);
		}
	}
}
