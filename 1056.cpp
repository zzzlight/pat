#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int temp[1050];
int groupnum;
int num;
struct Mouse
{
	int rank;
	int weight;
}mouse[1050];
int main()
{
	
	queue<int> q;
	
	scanf("%d",&num);
	scanf("%d",&groupnum);
	for(int i=0;i<num;i++)
	{
		
		scanf("%d",&mouse[i].weight);
	}
	for(int i=0;i<num;i++)
	{
		int shunxu;
		scanf("%d",&shunxu);
		q.push(shunxu);
		
	}
	int block;
	
	while(q.size()!=1)
	{
		if(q.size()%groupnum==0)  block=q.size()/groupnum;
		else block=q.size()/groupnum+1;
		int temp=q.size();   //temp记录每次重新比赛时的总数 
		for(int x=0;x<block;x++)
		{
			int maxweightnum=q.front();
		
			for(int y=0;y<groupnum;y++)
			{
				if(x*groupnum+y>=temp) break;  //大于等于时说明最后一组的进行完毕，为了防止越界break 
				int front=q.front();
				q.pop();
				if(mouse[maxweightnum].weight<mouse[front].weight)
				{
					maxweightnum=front;
				}
				mouse[front].rank=block+1;
			
			}
			q.push(maxweightnum);
			
		}
	}
	if(q.size()==1)  mouse[q.front()].rank=1;
	for(int i=0;i<num;i++)
	{
		printf("%d",mouse[i].rank);
		if(i!=num-1) printf(" ");
	}
	
 } 
