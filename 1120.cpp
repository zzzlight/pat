#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> seq;
bool hashtable[10005];
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		string temp;
		cin>>temp;
		int tempnum=0;
		for(int j=0;j<temp.size();j++)
		{
			tempnum+=temp[j]-'0';
			
		}
		if(hashtable[tempnum]==false) seq.push_back(tempnum);
		hashtable[tempnum]=true;
	}
	sort(seq.begin(),seq.end());
	printf("%d\n",seq.size());
	for(int i=0;i<seq.size();i++)
	{
		printf("%d",seq[i]);
		if(i!=seq.size()-1) printf(" ");
	}
 } 
