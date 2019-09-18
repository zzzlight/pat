#include<stdio.h>
#include<vector>
#include<set>

using namespace std;

vector<int> seq[10005];
bool mark[10005];

vector<bool> result;
int main()
{
	int vertexnum;
	int edgenum;
	scanf("%d %d",&vertexnum,&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int id1;
		int id2;
		scanf("%d %d",&id1,&id2);
		seq[id1].push_back(i);
		seq[id2].push_back(i);
	}
	int cxnum;
	scanf("%d",&cxnum);
	for(int i=0;i<cxnum;i++)
	{
		int queuenum;
		scanf("%d",&queuenum);
		set<int> myset;
		for(int j=0;j<queuenum;j++)
		{
			int temp;
			scanf("%d",&temp);
			for(int t=0;t<seq[temp].size();t++)
			{
				myset.insert(seq[temp][t]);
			}
			
		}
		if(myset.size()==edgenum) result.push_back(true);
		else result.push_back(false);
		
		
	 } 
	 for(int i=0;i<result.size();i++)
	 {
	 	if(result[i]==true)
	 	{
	 		printf("Yes");
		 }
		 else
		 {
		 	printf("No");
		 }
		 if(i!=result.size()-1) printf("\n");
	 }
}
