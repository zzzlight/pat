#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set> 
using namespace std;

vector<int> seq[10005];
int potid[10005];
set<int> special;
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
	}
	int testnum;
	scanf("%d",&testnum);
	for(int i=0;i<testnum;i++)
	{
		fill(potid,potid+10005,0);
		special.clear();
		int count=0;
		bool flag=false;
		for(int j=0;j<vnum;j++)
		{
			int temp;
			scanf("%d",&temp);
			special.insert(temp);
			
			potid[j]=temp;
		}
		count=special.size();  //ÓÃset¼ÆÊý 
		for(int t=0;t<vnum;t++)
		{
			for(int x=0;x<seq[t].size();x++)
			{
				if(potid[seq[t][x]]==potid[t]) flag=true;
			}
		}
		if(flag==true) printf("No");
		else printf("%d-coloring",count);
		if(i!=testnum-1) printf("\n");
	
	}
}
