#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<double> seq;

int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		double temp;             
		scanf("%lf",&temp);
		seq.push_back(temp);
	}
	sort(seq.begin(),seq.end());
	double sum=seq[0];
	for(int i=1;i<num;i++)
	{
		sum=sum/2+seq[i]/2;    //从最小到最大折半串联实现损失最小 
	}
	printf("%d",(int)sum); //用截断实现向下取整  double转int会发生截断 
 } 
