#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int preorder[100];
int postorder[100];
bool flag=true;
vector<int> result;
struct Node
{
	int data;
	Node* leftchild;
	Node* rightchild;
};

Node* create(int prel,int prer,int postl,int postr)
{
	//if(prel>prer) return NULL; 由于在到节点后就进行了判定 此处就不需要   此语句是在到了子节点不存在的下一个时候再返回用的  前中 后中 写法用的此方法 
	Node* node=new Node;
	node->data=preorder[prel];
	node->leftchild=NULL;
	node->rightchild=NULL;
	if(prel==prer) 	return node;
	 //用于节点到达末端(所有末端)时候的判定 
	int k=0;
	for(k=prel+1;k<=prer;k++)
	{
		if(preorder[k]==postorder[postr-1]) break;  //后序中根的前一个即右节点  在先序中找到该点位置  每次都是递归找该点 
	}
	if(k-prel>1) 
	{                    //postl+k-prel-2即postl+（k-1-（prel+1）） 
		node->leftchild=create(prel+1,k-1,postl,postl+k-prel-2);  //找到该点后 该点前面部分为左子树  该点及其右边为右子树  并总是将先序第一个和后序最后一个踢出（即找到的填入根节点） 
		node->rightchild=create(k,prer,postl+k-prel-1,postr-1);
	}
	else
	{
		flag=false;    //单节点时，随便选一个 
		node->rightchild=create(k,prer,postl+k-prel-1,postr-1);  
	}
	return node;
 } 
 void inorder(Node* root)
 {
 	if(root==NULL) return;
    inorder(root->leftchild);
 	result.push_back(root->data);
 	inorder(root->rightchild);
 	return ;
 	
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
		scanf("%d",&postorder[i]);
	}

	Node* root=create(0,num-1,0,num-1);
	inorder(root);
	
	if(flag==true) printf("Yes\n");
	else
	{
		printf("No\n");
	}
	for(int i=0;i<result.size();i++)
	{
		printf("%d",result[i]);
		if(i!=result.size()-1) printf(" ");
	}
	printf("\n"); //测试数据所有全部要最后一个换行 否则格式错误 
}


