#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> seq[500]; 
bool G[500][500];
vector<int> ans;
int main()
{
	int vnum;
	int edgenum;
	scanf("%d %d",&vnum,&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int id1;
		int id2;
		scanf("%d %d",&id1,&id2);
		seq[id1].push_back(id2);
		seq[id2].push_back(id1);
		G[id1][id2]=true;
		G[id2][id1]=true;
		
	}
	int cxnum;
	scanf("%d",&cxnum);
	for(int i=0;i<cxnum;i++)
	{
		int potnum;
		vector<int> cxseq; 
		int mark[500];
		fill(mark,mark+500,0);
		int flag=0;
		scanf("%d",&potnum);

		for(int j=0;j<potnum;j++)
		{
			int temp;
			scanf("%d",&temp);
			cxseq.push_back(temp);
		}
		for(int j=0;j<potnum;j++)
		{
			for(int t=j+1;t<potnum;t++)
			{
				if(G[cxseq[j]][cxseq[t]]==false)
				{
					flag=-1;
					break;
				}
			}
			if(flag==-1) break;
		}
		if(flag!=-1)
		{
			for(int t=0;t<potnum;t++)
			{
				for(int k=0;k<seq[cxseq[t]].size();k++)
				{
					mark[seq[cxseq[t]][k]]++;
				}
			}
			
			vector<int> waitcx;
			for(int z=1;z<=vnum;z++)
			{
				if(mark[z]==potnum) 
				{
					waitcx.push_back(z);     //若这一点被其他几个点全连接了（包括原先里面的），全加进队在判断是否全互相联通 
					flag=1;                  //判全联通时候自动也判了1个点情况 
				}
			}
			for(int z=0;z<waitcx.size();z++)
			{
				for(int y=z+1;y<waitcx.size();y++)
				{
					if(G[waitcx[z]][waitcx[y]]!=true)
					{
						flag=0;
					}
				}
			}
		}
		 
		ans.push_back(flag);
	
	}
	for(int i=0;i<cxnum;i++)
	{
		if(ans[i]==-1) printf("Not a Clique");
		else if(ans[i]==1) printf("Not Maximal");
		else printf("Yes");
		if(i!=cxnum-1) printf("\n");
	}
}
