#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int seq[1005];
vector<int> result[1005];
vector<int> temp;
int num;
int c;
void dfs(int root)
{
	if(root*2+1>num) 
	{
		temp.push_back(seq[root]);
		result[c]=temp;
		c++;
		temp.pop_back();
		return ;
	}
	temp.push_back(seq[root]);
	if(root*2+2<num) dfs(root*2+2);
	if(root*2+1<num) dfs(root*2+1);
	temp.pop_back();
	return ;
}
int mark;
bool flag;
int main()
{
	
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&seq[i]);
	}
	dfs(0);
	if(seq[0]<seq[1]) mark=-1;  //minheap
	else mark=1; //maxheap
	for(int i=0;i<c;i++)
	{
		for(int t=0;t<result[i].size();t++)
		{
			if(t!=0)
			{
				if(mark==1)
				{
					if(result[i][t]>result[i][t-1]) flag=true;
				}
				else if(mark==-1)
				{
					if(result[i][t]<result[i][t-1]) flag=true;
				}
			}
			printf("%d",result[i][t]);
			if(t!=result[i].size()-1) printf(" ");
		}
		printf("\n"); 
	}
	if(flag==true)
	{
		printf("Not Heap");
	}
	else
	{
		if(mark==1) printf("Max Heap");
		else printf("Min Heap");
	}
	
}
