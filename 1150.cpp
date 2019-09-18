#include<stdio.h>
#include<algorithm>

using namespace std;


int inf=9999999;
int G[500][500];

int main()
{
	fill(G[0],G[0]+500*500,inf);
	int vnum;
	int edgenum;
	scanf("%d %d",&vnum,&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int id1,id2;
		scanf("%d %d",&id1,&id2);
		scanf("%d",&G[id1][id2]);
		G[id2][id1]=G[id1][id2];
	}
	int checknum;
	scanf("%d",&checknum);
	int min=2*inf;
	int minid=-1;
	for(int i=0;i<checknum;i++)
	{
		int potnum;
		scanf("%d",&potnum);
		int seq[potnum];
		int dis=0;
		bool mark[1000];
		fill(mark,mark+1000,0);
		for(int j=0;j<potnum;j++)
		{
			scanf("%d",&seq[j]);
			mark[seq[j]]=true;
			if(j!=0) dis+=G[seq[j-1]][seq[j]];
		}
		if(dis>=inf) printf("Path %d: NA (Not a TS cycle)\n",i+1);
		else if(seq[0]!=seq[potnum-1]||potnum<vnum+1) printf("Path %d: %d (Not a TS cycle)\n",i+1,dis);
		else if(potnum>vnum+1)
		{
			int t;
			for(t=1;t<=vnum;t++)
			{
				if(mark[t]==false) break;
			}
			if(t>vnum) 
			{
				printf("Path %d: %d (TS cycle)\n",i+1,dis);
				if(min>dis) 
				{
					min=dis;
					minid=i+1;	
				}
			}
			else printf("Path %d: %d (Not a TS cycle)\n",i+1,dis);
		}
		else if(seq[0]==seq[potnum-1])
		{
			int t;
			for(t=1;t<=vnum;t++)
			{
				if(mark[t]==false) break;
			}
			if(t>vnum)
			{
				printf("Path %d: %d (TS simple cycle)\n",i+1,dis);
				if(min>dis) 
				{
					min=dis;
					minid=i+1;	
				}				
			}
			else
			{
				printf("Path %d: %d (Not a TS cycle)\n",i+1,dis);
			}
			
		}
		
	}
	printf("Shortest Dist(%d) = %d",minid,min);

}
