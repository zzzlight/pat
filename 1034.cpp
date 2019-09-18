#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;
struct gang
{
	int nodenum;
	string name;
};
vector<gang> out;

int k;
int numperson = 0;
int juzheng[2005][2005] = { 0 };
int weight[2005]={0};
map<string, int> strtoint;
map<int, string> inttostr;
bool flag[2005] = {false};

bool cmp(gang a, gang b)
{
	return a.name < b.name;
}
int tran(string str)
{
	if (strtoint.find(str)!=strtoint.end())
	{
		return strtoint[str];
	}
	else
	{
	
		strtoint[str] = numperson;
		inttostr[numperson] = str;
		return numperson++;
		
	}
}

void dfs(int node, int &membernum,int & totalweight,int &head)
{
	flag[node] = true;
	membernum++;
	if (weight[node] > weight[head])
	{
		head = node;
	}
	for (int i = 0; i < numperson; i++)
	{
		if (juzheng[node][i] > 0)
		{
			totalweight += juzheng[node][i];
			juzheng[node][i] = juzheng[i][node] = 0;
			if (flag[i] == false)
			{
				dfs(i, membernum, totalweight, head);
			}
		}
	}
	
}
void dfstravl()
{
	for (int i = 0; i < numperson; i++)
	{
		if (flag[i] == false)
		{
			int head = i;
			int totalweight = 0;
			int memnumber = 0;
			dfs(i, memnumber, totalweight, head);
			if (memnumber>2 && totalweight > k)
			{
				gang temp;
				temp.name=inttostr[head];
				temp.nodenum = memnumber;
				out.push_back(temp);
			}
		}
	}
}
int main()
{
	
	int num;
	cin >> num >> k;
	string str1;
	string str2;
	int w;
	for (int i = 0; i < num; i++)
	{
	
		
		cin >> str1 >> str2 >> w;
		int id1 = tran(str1);
		int id2 = tran(str2);
		
		juzheng[id1][id2] += w;
		weight[id1] += w;
		weight[id2] += w;
		juzheng[id2][id1] += w;
		
	}
	dfstravl();
	sort(out.begin(), out.end(), cmp);
	
	
		cout<<out.size()<<endl;
		
		
		for (auto it = out.begin(); it != out.end(); it++)
			{
				cout << (*it).name << " " << (*it).nodenum << endl;    //endl不用考虑最后一行的换行问题
			}
			
		
		
	
}
