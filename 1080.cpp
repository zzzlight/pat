#include<stdio.h>
#include<algorithm>
#include<vector> 
using namespace std;

struct Student
{
	int id;
	int grade1;
	int grade2;
	double avegrade=0;
	vector<int> studentchoice;
}student[50000];
vector<int> schoolreceive[105];
int schoolreceivenum[105]; 
int nowreceive[105];
bool cmp1(Student a,Student b)
{
	if(a.avegrade!=b.avegrade) return a.avegrade>b.avegrade;
	else return a.grade1>b.grade1;
}
bool researchsamerank(int id,int school)
{
	bool flag=false;
	int grade1=student[id].grade1;
	int grade2=student[id].grade2;
	for(int i=0;i<schoolreceive[school].size();i++)
	{
		if(student[schoolreceive[school][i]].grade1==grade1&&grade2==student[schoolreceive[school][i]].grade2)
		{
			flag=true;
			break;
		}
	}
	return flag;
}
int main()
{
	int num;
	int schoolnum;
	int choicenum;
	scanf("%d %d %d\n",&num,&schoolnum,&choicenum);
	for(int i=0;i<schoolnum;i++)
	{
		scanf("%d",&schoolreceivenum[i]);
	}
	for(int i=0;i<num;i++)
	{
		scanf("%d",&student[i].grade1);
		scanf("%d",&student[i].grade2);
		student[i].id=i;
		student[i].avegrade=(double(student[i].grade1)+student[i].grade2)/2;
		for(int j=0;j<choicenum;j++)
		{
			int temp;
			scanf("%d",&temp);
			student[i].studentchoice.push_back(temp);
		}
	}
	sort(student,student+num,cmp1);
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<choicenum;j++)
		{
			bool flag=researchsamerank(student[i].id,student[i].studentchoice[j]);
			if(nowreceive[student[i].studentchoice[j]]<schoolreceivenum[student[i].studentchoice[j]]||flag==true)
			{
				schoolreceive[student[i].studentchoice[j]].push_back(student[i].id);
				nowreceive[student[i].studentchoice[j]]++;
				break;
			}
			
		}
			
		
	}
	
	for(int i=0;i<schoolnum;i++)
	{
		sort(schoolreceive[i].begin(),schoolreceive[i].end());
		for(int j=0;j<schoolreceive[i].size();j++)
		{
			printf("%d",schoolreceive[i][j]);
			if(j!=schoolreceive[i].size()-1) printf(" ");
		}
		 printf("\n");
	}
 } 
