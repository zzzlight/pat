#include<stdio.h>
#include<vector>

using namespace std;

int inputnum[1005];
vector<int> seq[1005];
vector<int> result;
int main()
{
	int vnum;
	int edgenum;
	scanf("%d %d",&vnum,&edgenum);
	for(int i=1;i<=edgenum;i++)
	{
		int id1;
		int id2;
		scanf("%d %d",&id1,&id2);
		inputnum[id2]++;
		seq[id1].push_back(id2);
	}
	int cxnum;
	scanf("%d",&cxnum);
	for(int i=0;i<cxnum;i++)
	{
		vector<int> cxseq;
		int tempinput[1005];
		bool flag=true;
		for(int x=0;x<1005;x++)
		{
			tempinput[x]=inputnum[x];
		}
		for(int j=1;j<=vnum;j++)
		{
			int temp;
			scanf("%d",&temp);
			cxseq.push_back(temp);
		}
		for(int t=0;t<cxseq.size();t++)
		{
			if(tempinput[cxseq[t]]==0)
			{
				for(int y=0;y<seq[cxseq[t]].size();y++)
				{
					tempinput[seq[cxseq[t]][y]]--;
				}
			}
			else
			{
				flag=false;
				break;
			}
		}
		if(flag==false) result.push_back(i);
	}
	for(int i=0;i<result.size();i++)
	{
		printf("%d",result[i]);
		if(i!=result.size()-1) printf(" ");
	}
}
