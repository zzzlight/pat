#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> seq;
int hashmap[100005];
int coupleA[100005];
int coupleB[100005];
int input[100005];
int main()
{
	fill(coupleA,coupleA+100005,-1);
	fill(coupleB,coupleB+100005,-1);
	int couplenum;
	scanf("%d",&couplenum);
	for(int i=0;i<couplenum;i++)
	{
		int temp1,temp2;
		scanf("%d %d",&temp1,&temp2);
		coupleA[temp1]=temp2;
		coupleB[temp2]=temp1;
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int temp;
		scanf("%d",&temp);
		input[i]=temp;
		hashmap[temp]=true;
	}
	for(int i=0;i<M;i++)
	{
		if(coupleA[input[i]]==-1&&coupleB[input[i]]==-1)  //从0到99999  不能用0  用-1 
		{
			seq.push_back(input[i]);
		}
		else if(coupleA[input[i]]!=-1&&coupleB[input[i]]==-1)
		{
			if(hashmap[coupleA[input[i]]]==false)
			{
				seq.push_back(input[i]);
			}
		}
		else if(coupleB[input[i]]!=-1&&coupleA[input[i]]==-1)	
		{
			if(hashmap[coupleB[input[i]]]==false)
			{
				seq.push_back(input[i]);
			}
		}
		
	}
	sort(seq.begin(),seq.end());
	printf("%d\n",seq.size());
	for(int i=0;i<seq.size();i++)
	{
		printf("%05d",seq[i]);
		if(i!=seq.size()-1) printf(" ");
	}
}
