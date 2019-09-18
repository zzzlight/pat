#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int start;
struct Node
{
	string data;
	int leftchild=-1;
	int rightchild=-1;
}node[1000];
string seq;
bool mark[1000];
void tra(int root)
{
	if(root==-1) return ;
	if(root!=start)
	{
		if(node[root].leftchild!=-1||node[root].rightchild!=-1)
		{
			seq.push_back('(');  //²»Ö¹¼Ó¼õ³Ë³ý 
		}

	}

	tra(node[root].leftchild);
	for(int i=0;i<node[root].data.size();i++)
	{
		seq.push_back(node[root].data[i]);
	}
	
	tra(node[root].rightchild);
	if(root!=start)
	{
		if(node[root].leftchild!=-1||node[root].rightchild!=-1)
		{
			 seq.push_back(')');
		}

	}

}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		string temp;
		int templ;
		int tempr;
		cin>>temp>>templ>>tempr;
		node[i].data=temp;
		node[i].leftchild=templ;
		node[i].rightchild=tempr;
		if(templ!=-1) mark[templ]=true;
		if(tempr!=-1) mark[tempr]=true;
	}
	int root;
	for(int i=1;i<=num;i++)
	{
		if(mark[i]==false) root=i;
	}
	start=root;
	tra(root);
	cout<<seq;
}
