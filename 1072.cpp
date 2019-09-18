#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

int G[2000][2000];
int inf=10000000;
double mydistance[20];
double aveagedistance[20];
int d[2000];
bool visit[2000];
int routenum;
int range;
int housenum;
int gasnum;
int t=0;
int q=0;
struct PP
		{
			double p1=-1.0;
			int id=-1;
		}pp;
int stringtoint(string t)
{
	int result=0;
	for(int i=0;i<t.length();i++)
	{
		result=result*10;
		result+=t[i]-'0';
	}
	return result;
}
void dijkstra(int s)
{
	fill(d,d+2000,inf);
	memset(visit,0,sizeof(visit));
	d[s]=0;
	for(int i=0;i<housenum+gasnum;i++)
	{
		int u=-1;
		int MIN=inf;
		for(int j=1;j<=housenum+gasnum;j++)
		{
			if(visit[j]==false&&d[j]<MIN)
			{
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return ;
		visit[u]=true;
		for(int v=1;v<=housenum+gasnum;v++)
		{
			if(visit[v]==false&&G[u][v]!=inf)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
				}
			}
		}
	}
	double tempave=0.0;
	double tempmin=inf;
	bool flag=false;
	for(int i=1;i<=housenum;i++)
	{
		if(range<d[i]) flag=true;
		if(d[i]<tempmin) tempmin=d[i];
		tempave+=d[i];
	}
	if(flag==false)
	{
		mydistance[t++]=tempmin;
		aveagedistance[q++]=double(tempave)/double(housenum);
	}
	else
	{
		mydistance[t++]=-1;  //要取-1 这样不会影响后面最大的最小距离 
		aveagedistance[q++]=inf;
	}
}
bool cmp(PP a,PP b)
{
	if(a.p1!=b.p1) return a.p1<b.p1;
	else return a.id<b.id;
}
int main()
{
	fill(G[0],G[0]+2000*2000,inf);
	scanf("%d %d %d %d",&housenum,&gasnum,&routenum,&range);
	for(int i=0;i<routenum;i++)
	{
		string p1;
		string p2;
		int num1=0;
		int num2=0;
		int dist;
		cin>>p1>>p2;
		cin>>dist;
		if(p1[0]=='G'&&p2[0]=='G') 
		{
			p1.erase(p1.begin());
			num1=housenum+stringtoint(p1);
			p2.erase(p2.begin());
			num2=housenum+stringtoint(p2);
		}else if(p2[0]!='G'&&p1[0]=='G')
		{
			p1.erase(p1.begin());
			num2=stringtoint(p2);
			num1=housenum+stringtoint(p1);
		}else if(p1[0]!='G'&&p2[0]=='G')
		{
			p2.erase(p2.begin());
			num1=stringtoint(p1);
			num2=housenum+stringtoint(p2);
		}else 
		{
			num1=stringtoint(p1);
			num2=stringtoint(p2);
		}
		G[num1][num2]=dist;
		G[num2][num1]=dist;
	
	}
	for(int i=housenum+1;i<=housenum+gasnum;i++)
	{
		dijkstra(i);
	}
	int x;
	for(x=0;x<t;x++)
	{
		if(mydistance[x]!=-1) break;
	}
	if(x==t) printf("No Solution");
	else
	{
		double resultmax=-1;
		double resultave=double(inf);
		int gasresult=-1;
		for(int i=0;i<t;i++)
		{
			if(mydistance[i]>resultmax) resultmax=mydistance[i];
		}
		vector<PP> minave;
		int count=0;
		for(int i=0;i<t;i++)
		{
			if(resultmax==mydistance[i])
			{
				count++;
				pp.p1=aveagedistance[i];
				pp.id=i+1;
				minave.push_back(pp);
			}
		}
		sort(minave.begin(),minave.end(),cmp);
		

		gasresult=minave[0].id;
		resultave=minave[0].p1;
		printf("G%d\n",gasresult);
		printf("%0.1f %0.1lf",resultmax,resultave);
	}
 } 
