#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;

bool flag;
vector<string> nameseq;
map<string,bool> mymap;
vector<string> result;
int main()
{
	int num;
	int cut;
	int startid;
	cin>>num>>cut>>startid;
	if(startid>num) flag=true;
	nameseq.push_back("zhanwei");
	for(int i=1;i<=num;i++)
	{
		string temp;
		cin>>temp;
		nameseq.push_back(temp);
	}
	int id=startid;
	while(1)
	{
		if(id>=nameseq.size()) break;  //size获得的 比实际num大1 
		if(mymap[nameseq[id]]==false)
		{
			result.push_back(nameseq[id]);
			mymap[nameseq[id]]=true;
			id+=cut;
		}
		else
		{
			id++;
		}
	}
	if(flag==false)
	{
		for(int i=0;i<result.size();i++)
		{
		cout<<result[i];
		if(i!=result.size()-1) cout<<endl;
		}
	}
	else
	{
		cout<<"Keep going...";
	}

}
