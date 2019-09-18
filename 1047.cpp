#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int tran(char * a);
 char* retran(int a);
bool cmp(int a,int b);
struct Course
{	
//	char[10] studentname;
	vector<int>out;

}courses[2600];
int main()
{

	int student;
	int course;
	scanf("%d %d",&student,&course);
	for(int i=0;i<student;i++)
	{
		char stuid[10];
		scanf("%s",stuid);
		int id=tran(stuid);
	
		int coursenum;
		scanf("%d",&coursenum);
		for(int j=0;j<coursenum;j++)
		{
			int coursenames;
			scanf("%d",&coursenames);
			courses[coursenames].out.push_back(id);
		}
			
	}
	for(int q=1;q<=course;q++)
	{
		sort(courses[q].out.begin(),courses[q].out.end(),cmp);
	}
	
	for(int m=1;m<=course;m++)
	{
		printf("%d %d\n",m,courses[m].out.size());
		for(int n=0;n<courses[m].out.size();n++)
		{
			char* rename=retran(courses[m].out[n]);
			if((m==course)&&(n==((courses[m].out.size())-1))) 
			{
			printf("%s",rename);
			}
			else	printf("%s\n",rename);
			
		//	else  printf("%s\n",rename);
		}
		//if(m==course) printf("\n");
	}
	

	
 } 
 bool cmp(int a,int b)
 {
 	return a<b;
 }
 char* retran(int a)
 {
 	static char b[10];   //设为静态 不然函数内存可能会被重新写  造成乱码 
 	b[3]=a%10+'0';
 	b[2]=a/10%26+'A';
 	b[1]=a/10/26%26+'A';
 	b[0]=a/10/26/26%26+'A';
 	b[4]='\0';
 	return b;
 }
 int tran(char * a)
 {
 	int num=0;
 	num=(a[0]-'A')*26*26*10+(a[1]-'A')*26*10+(a[2]-'A')*10+a[3]-'0';
 	return num;
 }
