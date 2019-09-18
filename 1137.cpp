#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
bool mark[15000];
map<string,bool> mymap1;
map<string,int> mymap2;
struct Student
{
	string name;
	int oj;
	int mid=-1;
	int final;
	int sum;
};
vector<Student> seq;
vector<Student> result;
bool cmp(Student a,Student b)
{
	if(a.sum!=b.sum) return a.sum>b.sum;
	else if(a.name!=b.name) return a.name<b.name;
}
int main()
{
	fill(mark,mark+15000,1);
	int numoj;
	int nummid;
	int numfin;
	cin>>numoj>>nummid>>numfin;
	int id=0;
	for(int i=0;i<numoj;i++)
	{
		string temp;
		int tempoj;
		cin>>temp>>tempoj;
		Student tempst;
		tempst.name=temp;
		tempst.oj=tempoj;
	
		if(tempoj>=200)
		{
			seq.push_back(tempst);
			mymap1[temp]=true;
			mymap2[temp]=id;
			id++;
		}

	
	}
	for(int i=0;i<nummid;i++)
	{
		string temp;
		int tempmid;
		cin>>temp>>tempmid;
		
		if(mymap1[temp]==true)
		{
			seq[mymap2[temp]].mid=tempmid;
		
		}
		
	}
	for(int i=0;i<numfin;i++)
	{
		string temp;
		int tempfin;
		cin>>temp>>tempfin;
		if(mymap1[temp]==true)
		{
			seq[mymap2[temp]].final=tempfin;
		}
	}
	for(int i=0;i<seq.size();i++)
	{
		if(seq[i].final!=0)
		{
			if(seq[i].final>seq[i].mid)
			{
				seq[i].sum=seq[i].final;
			}
			else
			{
				
				double tempsum=0.6*seq[i].final+0.4*seq[i].mid;
				seq[i].sum=int(tempsum+0.5);
			}
			if(seq[i].sum>=60&&seq[i].sum<=100) result.push_back(seq[i]); //测试点里有好几个神仙超过了100分 
		}
	}
	sort(result.begin(),result.end(),cmp);
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i].name<<" ";
		printf("%d %d %d %d",result[i].oj,result[i].mid,result[i].final,result[i].sum);
		if(i!=result.size()-1) printf("\n");
	}
}
