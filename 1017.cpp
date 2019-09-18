#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Customer
{
	int time;
	int last;
	//int lastfinaltime=28800;
};
vector<Customer> time;
int window[200];
bool cmp(Customer a,Customer b)
{
	return a.time<b.time;
}
int main()
{
	int sumtime=0;
	int num;
	int queuenum;
	scanf("%d",&num);
	scanf("%d",&queuenum);
	for(int i=0;i<queuenum;i++)
	{
		window[i]=28800;
	}
	queue<Customer> q[queuenum];
	for(int i=0;i<num;i++)
	{
		int hour,min,second,waitime;
		Customer temp;
		scanf("%d:%d:%d %d",&hour,&min,&second,&waitime);
		temp.time=second+min*60+hour*3600;
		temp.last=waitime;
		if(temp.time<=61200) time.push_back(temp);
	}
	sort(time.begin(),time.end(),cmp);

	                             
	int count=queuenum;
	if(time.size()>0)
	{

//	printf("%d ",sumtime);                
	for(int j=0;j<time.size();j++)            //只要将初始设置为8点最低 就不用单独讨论 否则会有特殊情况（估计是time.size小于了queuenum）(测试点2）导致错误 
	{										
		//if(count==time.size()) break;
		int min=999999;
		int minid=0;
		for(int i=0;i<queuenum;i++)
		{
			
			if(window[i]<min)
			{
				min=window[i];
				minid=i;
			}
		}
		if(window[minid]>time[j].time)
		{
				sumtime+=window[minid]-time[j].time;
				window[minid]=window[minid]+60*time[j].last;
		}
		else
		{
			window[minid]=time[j].time+60*time[j].last;       //此处第一次时写错了 注意逻辑 
		 } 
	//	printf("\n%d ",time[count].lastfinaltime);
		q[minid].pop();
		q[minid].push(time[j]);
	//	count++;
	}
	}
	else
	{
		sumtime=0;
	}
	
	double aveans=sumtime/60.0/(double)(time.size());
	if(sumtime!=0) printf("%.1f",aveans);
	else printf("0.0");
 } 
