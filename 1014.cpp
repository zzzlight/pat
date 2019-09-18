#include<stdio.h>
#include<queue>
#include<vector>


using namespace std;

int chaxun[2000];
queue<int> q;
queue<int> tt[50];
int winnum;
int capacity;
int numofpeople;
int numofquery;
int win[100];
int out[2000];
int pasttime[2000];

int main()
{
	for(int i=0;i<2000;i++)
	{
		out[i]=-1;
	}
	scanf("%d",&winnum);
	scanf("%d",&capacity);
	scanf("%d",&numofpeople);
	scanf("%d",&numofquery);
	for(int i=0;i<numofpeople;i++)
	{
		int temp;
		scanf("%d",&temp);
		q.push(temp);
		pasttime[i]=temp;
	}
	for(int t=0;t<numofquery;t++)
	{
		scanf("%d",&chaxun[t]);
	}
	int j;
	int guke;
	if(numofpeople<winnum*capacity)
	{
		guke=numofpeople;
	}
	else
	{
		guke=winnum*capacity;
	}
	for(j=0;j<guke;j++)
	{
		int temp=q.front();
		q.pop();
		win[j%winnum]+=temp;
		out[j]=win[j%winnum];
		tt[j%winnum].push(temp);
		
	}
	

	while(!q.empty())
	{
		int mytemp=q.front();
		q.pop();
		int min=2000;
		int minwin=0;
		for(int i=0;i<winnum;i++)
		{
			int qtemp;
			qtemp=tt[i].front();
			if(qtemp<min) 
			{
				min=qtemp;
				minwin=i;	
			}
		}
		tt[minwin].pop();
		win[minwin]+=mytemp;
		out[j++]=win[minwin];
		tt[minwin].push(mytemp);
	
	}
	for(int i=0;i<numofquery;i++)
	{
		int hour=8+out[chaxun[i]-1]/60;
		int min=out[chaxun[i]-1]%60;

			if((out[chaxun[i]-1]-pasttime[chaxun[i]-1])<540&&out[chaxun[i]-1]!=-1)
			{
			 printf("%02d:%02d", hour, min);
			}
			else printf("Sorry");

		if(i!=numofquery-1) printf("\n");
	}
 } 
