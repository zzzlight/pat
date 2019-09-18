#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int tran(char * a);
bool cmp(int a,int b);
struct Student 
{
	char studentname[10];
	vector<int>out;

}students[180000];
int main()
{

	int student;
	int course;
	scanf("%d %d",&student,&course);
	for(int i=0;i<course;i++)
	{
		
		int coursestu;
		int courseid;
		scanf("%d %d",&courseid,&coursestu);
		for(int j=0;j<coursestu;j++)
		{
			char stuid[10];
			scanf("%s",stuid);
			
			int id=tran(stuid);
			for(int n=0;n<4;n++)
			{
					students[id].studentname[n]=stuid[n];
			}
		
			students[id].out.push_back(courseid);
		}
	}
	int output[180000];
	for(int k=0;k<student;k++)
	{
			char record[10];
			scanf("%s",record);
			output[k]=tran(record);
			if(students[output[k]].out.size()==0)
			{
				for(int x=0;x<4;x++)
				students[output[k]].studentname[x]=record[x];
			}
			
	}
	for(int k=0;k<student;k++)
	{
			printf("%s %d",students[output[k]].studentname,students[output[k]].out.size());
			sort(students[output[k]].out.begin(),students[output[k]].out.end(),cmp);
			for(int m=0;m<students[output[k]].out.size();m++)
			{
				printf(" %d",students[output[k]].out[m]);
			}
			if(k!=student-1)printf("\n");
	}


	
	
 } 
 bool cmp(int a,int b)
 {
 	return a<b;
 }
 int tran(char * a)
 {
 	int num=0;
 	num=(a[0]-'A')*26*26*10+(a[1]-'A')*26*10+(a[2]-'A')*10+a[3]-'0';
 	return num;
 }
