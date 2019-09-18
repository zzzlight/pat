#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct Student
{
	int height;
	string name;
		
};
int line;
vector<Student> seq;
Student xxseq[15][10005];;
bool cmp(Student a,Student b)
{
	if(a.height!=b.height) return a.height>b.height;
	else return a.name<b.name;
}

int main()
{
	int num;
	cin>>num;
	
	cin>>line;
	for(int i=0;i<num;i++)
	{
		string temp;
		cin>>temp;
		int height;
		cin>>height;
		Student t;
		t.height=height;
		t.name=temp;
		seq.push_back(t);
	}
	sort(seq.begin(),seq.end(),cmp);
	int eachline=num/line;
	int firstline=num-eachline*(line-1);
//	printf("%d",firstline);
	//第一行
	int m=firstline/2+1;
	int n=firstline/2-1;
	int t=0;
	for(int i=0;i<firstline;i++)
	{
		if(i==0) xxseq[0][firstline/2+1-1]=seq[t++];
		else if(i%2==1)	xxseq[0][n--]=seq[t++];
		else  xxseq[0][m++]=seq[t++];
	}
	//后面行
	for(int i=1;i<line;i++)
	{
		int p=eachline/2+1;
		int q=eachline/2-1;
		for(int j=0;j<eachline;j++)
		{
			if(j==0) xxseq[i][eachline/2+1-1]=seq[t++];
			else if(j%2==1) xxseq[i][q--]=seq[t++];
			else  xxseq[i][p++]=seq[t++]; 
		//	cout<<q<<" ";
		}
		//cout<<endl;
	 } 
	 for(int i=0;i<firstline;i++)
	 {
	 	cout<<xxseq[0][i].name;
	 	if(i!=firstline-1) cout<<" ";
	 }
	 cout<<endl;
	for(int i=1;i<line;i++)
	{
		for(int j=0;j<eachline;j++)
		{
			cout<<xxseq[i][j].name;
			if(j!=eachline-1) cout<<" ";
		}
		if(i!=line-1) cout<<endl; 
	}
}
