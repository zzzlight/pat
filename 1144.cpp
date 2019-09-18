#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> seq;
bool mark[100050];
 int main()
 {
 	int num;
 	scanf("%d",&num);
 	for(int i=0;i<num;i++)
 	{
 		int temp;
 		scanf("%d",&temp);
 		seq.push_back(temp); 
		 if(temp>0&&temp<100050)mark[temp]=true;		
	 }
	// sort(seq.begin(),seq.end());
	 for(int i=1;i<100005;i++)
	 {
	 	if(mark[i]==false) 
	 	{
	 		printf("%d",i);
	 		break;
		 }
	 }
 }
