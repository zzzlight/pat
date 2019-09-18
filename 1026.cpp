#include<stdio.h>
#include<iostream> 
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int num;	
int tablenum;
int viptablenum;
struct Player
{
	int time;
	int last;
	int tag;
}player;
struct Table
{
	int severnum=0;
	int isvip;
	int endtime=28800;
}table[150];
vector<Player> seq;
struct Result
{
	int arrivetime;
	int severtime;
};
vector<Result> output;
bool cmp1(Result a,Result b)
{
	return a.severtime<b.severtime;
}
int findnextvip(int start)
{
	for(int i=start+1;i<num;i++)
	{
		if(seq[i].tag==1) return i;
	}
}
void intprint(int time)
{
	int hour=time/3600;
	int min=(time-hour*3600)/60;
	int second=time%60;
	printf("%02d:%02d:%02d",hour,min,second);
}
bool cmp(Player a,Player b)
{
	return a.time<b.time;
}
void deal(int id,int i)
{
	Result tt;
	if(table[id].endtime<seq[i].time)
	{
		tt.arrivetime=seq[i].time; 
		tt.severtime=seq[i].time;
	}
	else
	{
		tt.arrivetime=seq[i].time;
		tt.severtime=table[id].endtime;	
	}
	table[id].endtime=tt.severtime+seq[i].last*60;
	table[id].severnum++;
	output.push_back(tt);
}
int main()
{

	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		Player temp;
		int hour;
		int min;
		int second;
		int temptime;
		scanf("%d:%d:%d %d %d\n",&hour,&min,&second,&temp.last,&temp.tag);
		if(temp.last>120) temp.last=120;
		temptime=hour*3600+min*60+second;
		temp.time=temptime;
		if(temptime>=75600) continue;
		seq.push_back(temp);
	}

	scanf("%d %d\n",&tablenum,&viptablenum);
	for(int i=0;i<viptablenum;i++)
	{
		int id;
		scanf("%d",&id);
		table[id].isvip=1;
	}
	sort(seq.begin(),seq.end(),cmp); 
	int i=0;
	int vipi=-1;
	vipi=findnextvip(vipi);
	while(i<seq.size())
	{
		int id=-1;
		int min=999999;
		for(int j=1;j<=tablenum;j++)
		{
			if(table[j].endtime<min)
			{
				min=table[j].endtime;
				id=j;
			 } 
		}
		if(table[id].endtime>=75600) break;
		//判断是否闭馆 
		if(seq[i].tag==1&&i<vipi)
		{
			i++;
			continue;
		 } 
		if(table[id].isvip==0&&seq[i].tag==0)
		{
			deal(id,i);
			i++;
			
		} 
		else if(table[id].isvip==1&&seq[i].tag==1)
		 {
		 	deal(id,i);
			if(vipi==i) vipi=findnextvip(vipi);
			i++;
		 }
		 else if(table[id].isvip==1&&seq[i].tag==0)
		 {
		 	if(vipi<seq.size()&&seq[vipi].time<=table[id].endtime)
		 	{
		 		deal(id,vipi);	
		 		vipi=findnextvip(vipi);
			}else
			{
				deal(id,i);
				i++;
			}
		 }
		 else if(table[id].isvip==0&&seq[i].tag==1)
		 {
		 	int vipmin=9999999;
		 	int vipid=-1;
		 	Result tt;
		 	for(int t=1;t<=tablenum;t++)
		 	{
		 		if(table[t].isvip==1&&table[t].endtime<vipmin)
				 {
				 	vipmin=table[t].endtime;
				 	vipid=t;
				  } 
			 }
			 if(vipid!=-1&&table[vipid].endtime<=seq[i].time)
			 {
			 	deal(vipid,i);
				if(vipi==i) vipi=findnextvip(vipi);
			 	i++;
			 	
			 }
			 else
			 {
				deal(id,i);
				if(vipi==i) vipi=findnextvip(vipi);
				i++;
			 }
		 }
	}
	sort(output.begin(),output.end(),cmp1);
	for(int i=0;i<output.size()&&output[i].severtime<75600;i++)
	{
		intprint(output[i].arrivetime);
		printf(" ");
		intprint(output[i].severtime);
		printf(" ");
		//int ttemp=output[i].severtime-output[i].arrivetime;
		//double ttemp=round(output[i].severtime-output[i].arrivetime)/60.0;
       
		printf("%d",(30+output[i].severtime-output[i].arrivetime)/60); //测评环境原因  只能用30s方式  用%.0f等皆错 此处测试数据有一定问题 
		printf("\n");                             //题中round to指四舍五入 
	}
	for(int i=1;i<=tablenum;i++)
	{
		printf("%d",table[i].severnum);
		if(i!=tablenum) printf(" ");
	}
 }
