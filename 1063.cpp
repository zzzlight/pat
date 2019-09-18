#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int input[2020];
int num;
struct Node
{
	int leftchild=-1;
	int rightchild=-1;
	int data;
}node[2020];
int t=0;
void inorder(int root)
{
	if(root>num)
	{
		return ;
	}
	inorder(node[root].leftchild);
	node[root].data=input[++t];
	inorder(node[root].rightchild);
}
int main()
{
	
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		scanf("%d",&input[i]);
		node[i].leftchild=2*i;
		node[i].rightchild=2*i+1;
	}
	sort(input+1,input+num+1);
	inorder(1);
	for(int i=1;i<=num;i++)
	{
		printf("%d",node[i].data);
		if(i!=num) printf(" ");
	}
}
