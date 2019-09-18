#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

int last;	
bool result=false;
struct Tree
{
	int leftchild=-1;
	int rightchild=-1;
	int level=-1;
	int newtag; 
}node[500];
bool flag[500];
bool tagcx[500000];

void dfs(int root,int level,int newtag)
{
	if(node[root].level>4) 
	{
		result=true;
		return;
	}
	if(root==-1) return ;
	node[root].level=level;
	node[root].newtag=newtag;
	dfs(node[root].leftchild,level+1,newtag*2);
	dfs(node[root].rightchild,level+1,newtag*2+1);
	return ;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		string t1;
		string t2;
		cin>>t1>>t2;
		if(t1.size()==1)
		{
			if(t1[0]!='-') 
			{
				node[i].leftchild=t1[0]-'0';
				flag[t1[0]-'0']=true;
			}
		}
		else
		{
			node[i].leftchild=10*(t1[0]-'0')+t1[1]-'0';
			flag[node[i].leftchild]=true;
		}
		if(t2.size()==1)
		{
			if(t2[0]!='-')
			{
				node[i].rightchild=t2[0]-'0';
				flag[t2[0]-'0']=true;
			} 
		}
		else
		{
			node[i].rightchild=10*(t2[0]-'0')+t2[1]-'0';
			flag[node[i].rightchild]=true;
		}	
		
	}
	int root=-1;
	for(int i=0;i<num;i++)
	{
		if(flag[i]==false) root=i;
	}
	dfs(root,0,1);
	int maxnum=-1;
	for(int i=0;i<num;i++)
	{
		if(node[i].newtag>maxnum) maxnum=node[i].newtag;
		tagcx[node[i].newtag]=true;
	}
	int t;
	for(t=1;t<=num;t++)
	{
		if(tagcx[t]!=true) break;
	}
	if(maxnum>20||maxnum>num||t!=num+1) result=true;
	for(int i=0;i<num;i++)
	{
		if(node[i].newtag==maxnum) last=i;
	}

	if(result==true)
	{
		printf("NO %d",root);
	}
	else
	{
		printf("YES %d",last);
	}
}
/*#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

int last;	
bool result=false;
struct Tree
{
	int leftchild=-1;
	int rightchild=-1;
	int level=-1;
	int newtag; 
}node[500];
bool flag[500];


void dfs(int root,int level,int newtag)
{
	if(node[root].level>6) 
	{
		result=true;
		return;
	}
	if(root==-1) return ;
	node[root].level=level;
	node[root].newtag=newtag;
	dfs(node[root].leftchild,level+1,newtag*2+1);
	dfs(node[root].rightchild,level+1,newtag*2+2);
	return ;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		string t1;
		string t2;
		cin>>t1>>t2;
		if(t1.size()==1)
		{
			if(t1[0]!='-') 
			{
				node[i].leftchild=t1[0]-'0';
				flag[t1[0]-'0']=true;
			}
		}
		else
		{
			node[i].leftchild=10*(t1[0]-'0')+t1[1]-'0';
			flag[node[i].leftchild]=true;
		}
		if(t2.size()==1)
		{
			if(t2[0]!='-')
			{
				node[i].rightchild=t2[0]-'0';
				flag[t2[0]-'0']=true;
			} 
		}
		else
		{
			node[i].rightchild=10*(t2[0]-'0')+t2[1]-'0';
			flag[node[i].rightchild]=true;
		}	
		
	}
	int root=-1;
	for(int i=0;i<num;i++)
	{
		if(flag[i]==false) root=i;
	}
	dfs(root,0,0);
	int maxnum=-1;
	for(int i=0;i<num;i++)          //直接用是否最后一个等于堆值不对 因为可能前面有个没填满 而且下面还出现了子节点刚好又凑上了 
	{
		if(node[i].newtag>maxnum) maxnum=node[i].newtag;
	}
	if(maxnum>=num) result=true;
	last=maxnum;
	if(result==true)
	{
		printf("NO %d",root);
	}
	else
	{
		printf("YES %d",last);
	}
}
*/

