#include<stdio.h>
#include<vector>
#include<math.h> 
using namespace std;
int ranklist[10005];
bool ranklistflag[10005];
bool ranklistflag2[10005];
int seq[10005];
int result[10005];
bool isprime(int num)
{
	if(num==1||num==0) return false;
	for(int i=2;i<=(int)sqrt(num*1.0);i++)   //注意等于  注意0和1特殊值 
	{										//注意sqrt转换为int 且sqrt内num先*1.0转换为浮点数 
		if(num%i==0) return false;
	}
	return true;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		int temp;
		scanf("%d",&temp);
		ranklist[temp]=i;
		ranklistflag[temp]=true; //是否在 
	}
	int K;
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		int temp2;
		scanf("%d",&temp2);
		seq[i]=temp2;
		if(ranklistflag[temp2]==false)
		{
			result[i]=4;
		}
		else
		{
			if(ranklistflag2[temp2]==true) 
			{
				result[i]=5;
			}
			else
			{
				if(ranklist[temp2]==1) result[i]=1;
				else if(isprime(ranklist[temp2])==true)
				{
					
					result[i]=2;
				}
			}
		}
		
		ranklistflag2[temp2]=true;
	}
	
	for(int i=0;i<K;i++)
	{
		if(result[i]==0) result[i]=3;
	}
	
	for(int i=0;i<K;i++)
	{
		if(result[i]==1) printf("%04d: Mystery Award",seq[i]);
		else if(result[i]==2) printf("%04d: Minion",seq[i]);
		else if(result[i]==3) printf("%04d: Chocolate",seq[i]);
		else if(result[i]==4) printf("%04d: Are you kidding?",seq[i]);
		else printf("%04d: Checked",seq[i]);
		if(i!=K-1) printf("\n");
	}
 
 }
  
 
