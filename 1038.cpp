#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<string> seq;
bool cmp1(string a,string b)
{
	if(a+b<b+a) return true;
	else return false;
}
int main()
{
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		string temp;
		cin>>temp;
		seq.push_back(temp);
	}
	sort(seq.begin(),seq.end(),cmp1);
	string out;
	for(int i=0;i<seq.size();i++)
	{
		out+=seq[i];
	}
	while(out[0]=='0')
	{
		out.erase(out.begin());  
	}
	if(out.size()==0) cout<<0;  //注意全0情况 
	else cout<<out;
 } 
