#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> mark[100005];
vector<bool> result;
int main()
{
	int pairnum;
	int cxnum;
	scanf("%d %d",&pairnum,&cxnum);
	for(int i=0;i<pairnum;i++)
	{
		int temp1;
		int temp2;
		scanf("%d %d",&temp1,&temp2);
		mark[temp1].push_back(temp2);
		mark[temp2].push_back(temp1);
	}
	for(int j=0;j<cxnum;j++)
	{
		int potnum;
		scanf("%d",&potnum);
		vector<int> compare;
		bool flag=true;
		for(int i=0;i<potnum;i++)
		{
			
			int temp;
			scanf("%d",&temp);
			if(mark[temp].size()!=0)
			{
				for(int k=0;k<mark[temp].size()-1;k++)
				{
					compare.push_back(mark[temp][k]);
				}
			}
			if(compare.size()!=0)
			{
				for(int t=0;t<compare.size()-1;t++)
				{
					if(temp==compare[t]) 
					{
						flag=false;
					}
				}				
			}

		}
		result.push_back(flag);
	}
	for(int i=0;i<result.size();i++)
	{
		if(result[i]==true) printf("Yes");
		else printf("No"); 
		if(i!=result.size()-1) printf("\n");
	}
}
