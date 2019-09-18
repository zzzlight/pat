#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

bool mark[1500];
vector<bool> result;
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		int problem;
		scanf("%d",&problem);
		int seq[problem+1];
		bool flag=true;
		fill(mark,mark+1500,0);
		for(int j=1;j<=problem;j++)
		{
			int temp;
			scanf("%d",&temp);
			if(mark[temp]==false) 
			{
				seq[j]=temp;
				mark[temp]=true;
			}
			else 
			{
				flag=false;
			}
			for(int t=1;t<j;t++)        //判断之前斜对角上（全部的都要 
			{
				if(abs(seq[j]-seq[t])==abs(t-j))
				{
					flag=false;
					break;
				}
			}
			
				
			
		}
		
		if(flag==false)
		{
			result.push_back(false);
		}
		else
		{
			result.push_back(true);
		}
		
	}
	for(int i=0;i<num;i++)
	{
		if(result[i]==true) printf("YES");
		else printf("NO");
		if(i!=num-1) printf("\n");
	}
}
