#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Student
{
	int rank;
	double scoresum;
	string school;
	int studentnum;
};
vector<Student> seq;
map<string,int> mymap;
string intonew(string n)
{
	string t;
	int cut='A'-'a';
	for(int i=0;i<n.size();i++)
	{
		if(n[i]<='Z'&&n[i]>='A')
		{
			t.push_back(n[i]-cut);
		}
		else
		{
			t.push_back(n[i]);
		}
	}
	return t;
}
bool cmp(Student a,Student b)
{
	if(a.scoresum!=b.scoresum) return a.scoresum>b.scoresum;
	else if(a.studentnum!=b.studentnum) return a.studentnum<b.studentnum;
	else return a.school<b.school;	
}
int main()
{
	int num;
	scanf("%d",&num);
	int count=1;
	for(int i=0;i<num;i++)
	{
		string idtemp;
		string schooltemp;
		double scoretemp;
		Student student;
		cin>>idtemp>>scoretemp>>schooltemp;
		string newschool=intonew(schooltemp);
		if(mymap[newschool]==0)
		{	
			student.school=newschool;
			student.studentnum=1;
			if(idtemp[0]=='A') student.scoresum=scoretemp;
			else if(idtemp[0]=='B') student.scoresum=scoretemp/1.5;
			else if(idtemp[0]=='T') student.scoresum=scoretemp*1.5;
			seq.push_back(student);
			mymap[newschool]=count;
			count++;
			//cout<<mymap[newschool]<<endl;
		}
		else if(mymap[newschool]!=0)
		{
			if(idtemp[0]=='A') seq[mymap[newschool]-1].scoresum+=scoretemp;
			else if(idtemp[0]=='B') seq[mymap[newschool]-1].scoresum+=scoretemp/1.5;
			else if(idtemp[0]=='T') seq[mymap[newschool]-1].scoresum+=scoretemp*1.5;
			//cout<<seq[mymap[newschool]-1].scoresum<<seq[mymap[newschool]-1].school<<endl;
			seq[mymap[newschool]-1].studentnum++;
		}
	
	}
	for(int i=0;i<seq.size();i++)
	{
		seq[i].scoresum=(int)seq[i].scoresum;
	}
	sort(seq.begin(),seq.end(),cmp);
	int rankcount=2;
	seq[0].rank=1;
	
	for(int i=1;i<seq.size();i++)
	{
		if(seq[i].scoresum==seq[i-1].scoresum)
		{
			seq[i].rank=seq[i-1].rank;
		}
		else
		{
			seq[i].rank=rankcount;
		}
		rankcount++;
		
	}
	printf("%d\n",seq.size());
	for(int i=0;i<seq.size();i++)
	{
		printf("%d ",seq[i].rank);
		cout<<seq[i].school<<" ";
		printf("%d %d",(int)seq[i].scoresum,seq[i].studentnum);
		if(i!=seq.size()-1) printf("\n");
	}
	 
 } 
