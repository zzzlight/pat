#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int seq[100050];
int main()
{
	int sum1;
	int sum2;
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+num,cmp);
	int maxcut=0;
	int becut=0;
	int n1;
	int n2;
	int cut;
	     //sort 就没了  偶数就一半  奇数就一半多一个 
	if(num%2==0) 
	{
		cut=0;
		for(int i=0;i<num/2;i++)
		{
			maxcut+=seq[i];
		}
		for(int i=num/2;i<num;i++)
		{
			becut+=seq[i];
		}
		maxcut-=becut;
	}
	else 
	{
		cut=1;
		for(int i=0;i<=num/2;i++)
		{
			maxcut+=seq[i];
		}
		for(int i=num/2+1;i<num;i++)
		{
			becut+=seq[i];
		}
		maxcut-=becut;
	}
	printf("%d %d",cut,maxcut);
}
