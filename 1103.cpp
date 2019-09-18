#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>                  //用vector方便更新 
using namespace std;


int seq[500];
int num;
int p;
int k;
int i=0;
vector<int> temp;
vector<int>result;
int maxsum=-1;
void find(int index,int nowk,int sum,int seqsum)
{

	if(sum==num&&nowk==k)
	{
		if(seqsum>maxsum)
		{
			maxsum=seqsum;
			result=temp;
		}
		return; 
	 } 
	
	if(sum>num||nowk>k||index<1) 
	return;
	temp.push_back(index);
	find(index,nowk+1,sum+seq[index],seqsum+index);
	temp.pop_back();
	find(index-1,nowk,sum,seqsum);
	
	
}
int main()
{
	
	scanf("%d",&num);
	scanf("%d",&k);
	scanf("%d",&p);
	
	while(pow(i,p)<=num)   //等于num也要包含在内 
	{
		seq[i]=pow(i,p);
		i++;
	}
	find(i-1,0,0,0);
	int tempk=0;
	if(result.empty())
	{
		printf("Impossible");
	}
	else
	{
		while(result.size()!=tempk)
	{
		if(tempk==0)
		{
			printf("%d = %d^%d",num,result[tempk],p);
			tempk++;
		}
		else
		{
			printf(" + %d^%d",result[tempk],p);
			tempk++;	
		}
	
	}
	
	}

 } 

