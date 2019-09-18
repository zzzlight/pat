#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>


using namespace std;
const int inf=10000000;
struct Node
{
	int happiness;
	string name;
	int level;
}node[400];
map<int,string> stringtoint;
map<string,int> inttostring;
int G[205][205];
int d[205];
bool vis[205];
int numofpath;
int maxcost;
int finalhappiness;
double avehappiness;
int potnum;
int roadnum;
vector<int> out,tempout;
vector<int> pre[205];
void  dfs(int final)   //沿pre数组dfs->即倒着深搜到出发地 
{
	if(final==0)
	{
		tempout.push_back(final);
		numofpath++;
		int costtemp=0;
		for(int i=tempout.size()-1;i>=0;i--)  //-2也可 由于0处的happiness初始化为0 无影响 
		{
			costtemp+=node[tempout[i]].happiness;
		}
		double tempavehappiness=costtemp*1.0/(tempout.size()-1);
		if(costtemp>maxcost)
		{
			maxcost=costtemp;
			avehappiness=tempavehappiness;
			out=tempout;
		}
		else if(costtemp==maxcost&&tempavehappiness>avehappiness)
		{
			avehappiness=tempavehappiness;
			out=tempout;
		}
		tempout.pop_back();
		
		return ;
		
	}
	tempout.push_back(final);
	 for(int i=0;i<pre[final].size();i++)
	 {
	 	dfs(pre[final][i]);
	 }
	 tempout.pop_back();
	 return ;
}
void dijkstra(int start)
{
	fill(d,d+205,inf);
	d[start]=0;
	for(int i=0;i<potnum;i++)
	{
		int u=-1;
		int min=inf;
		for(int j=0;j<potnum;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;min=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<potnum;v++)
		{
			if(vis[v]==false&&G[u][v]!=inf)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[u]+G[u][v]==d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}

int main()
{
	fill(G[0],G[0]+205*205,inf);
	string start;
	cin>>potnum>>roadnum>>start;
	node[0].name=start;
	for(int i=1;i<potnum;i++)
	{
		cin>>node[i].name>>node[i].happiness;
		inttostring[node[i].name]=i;
		stringtoint[i]=node[i].name;
	} 
	for(int j=0;j<roadnum;j++)
	{
		string temp1;
		string temp2;
		cin>>temp1>>temp2;
		int cost;
		cin>>cost;
		G[inttostring[temp1]][inttostring[temp2]]=cost;
		G[inttostring[temp2]][inttostring[temp1]]=cost;
	}
	dijkstra(0);
	int final=inttostring["ROM"];
	dfs(final);
	printf("%d %d %d %d\n",numofpath,d[final],maxcost,int(avehappiness));  //取整用强转吧 
	cout<<node[0].name<<"->";
	for(int i=out.size()-2;i>=0;i--)  //-2是由于-1处的最后出发点已在dfs的=0判定中被pop 
	{
		cout<<stringtoint[out[i]];
		if(i!=0) cout<<"->";
	}
 } 
