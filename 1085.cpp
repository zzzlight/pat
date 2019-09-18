#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> seq;
int main()
{
    //要让序列最长  max并不一定是sort后最后一位 
	int num;
	long long p;
	scanf("%d",&num);
	scanf("%lld",&p);
	for(int i=0;i<num;i++)
	{
		long long temp;
		scanf("%lld",&temp);
		seq.push_back(temp);
	}

	sort(seq.begin(),seq.end());
	int result=0;
	
		for(int j=0;j<num;j++)
		{
				long long sum=seq[j]*p;
				int x=upper_bound(seq.begin(),seq.end(),sum)-seq.begin()-1;   //upper_bound返回为比m*p刚刚大的地址（故要减begin（）得到int），前一位即为等于或小于 ，求序列长要用前一位的 
			
				if(x+1-j>result)  //vector从0开始故又要加一 
				{
					result=x+1-j;
				}
			
			
		}	
	
	

	printf("%d",result);
 } 
