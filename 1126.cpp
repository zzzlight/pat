#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int oddnum=0;
bool mark[550];
vector<int> t[550];
bool semiflag;
bool flag=true;
int degree[550];
void dfs(int start)
{
	mark[start]=true;
	for(int i=0;i<t[start].size();i++)
	{
		if(mark[t[start][i]]==false)
		dfs(t[start][i]);
	}
}
int main()
{
	int vertexnum;
	int edgenum;
	scanf("%d",&vertexnum);
	scanf("%d",&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int id1;
		int id2;
		scanf("%d %d",&id1,&id2);
		t[id1].push_back(id2);
		t[id2].push_back(id1);
		degree[id1]++;
		degree[id2]++;
	}
	dfs(1);
	
	for(int i=1;i<=vertexnum;i++)
	{
		if(degree[i]%2==1) flag=false;   //为全偶数且全联通必然满足Eulerian 
	}
	for(int i=1;i<=vertexnum;i++)
	{
		if(degree[i]%2==1) oddnum++;
		printf("%d",degree[i]);
		if(i!=vertexnum) printf(" ");
		else printf("\n");
	}
	if(oddnum==2) semiflag=true;
	for(int i=1;i<=vertexnum;i++)
	{
		if(mark[i]==false)
		{
			flag=false;
			semiflag=false;
		}
	}    //图未联通 
	if(semiflag==true&&flag==false)
	{
		printf("Semi-Eulerian");
	}
	else if(semiflag==false&&flag==true)
	{
		printf("Eulerian");
	}
	else printf("Non-Eulerian");
}
