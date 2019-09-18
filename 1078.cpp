#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
bool hashtable[25000];
int numtable[25000];
int result[25000];
vector<bool> numgang;
int main()
{
	bool flag=false;
	int hashkey;
	int newhashkey;
	int num;
	scanf("%d",&hashkey);
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&numtable[i]);
	}
	int i;
	for(i=2;i<hashkey;i++)
	{
		if(hashkey%i==0)
		break;
	}
	if(i!=hashkey) flag=true;
	//printf("%d",(hashkey));
	if(flag)
	{
		newhashkey=hashkey+1;
		while(1)
		{
			int t;
			for(t=2;t<newhashkey;t++)
			{
				if(newhashkey%t==0)
				break;
			}
			if(t==newhashkey) break;
			else
			{
				newhashkey++;
			}
		}
	}
	else
	{
		newhashkey=hashkey;
	}
	if(hashkey==2||hashkey==3)  newhashkey=hashkey;
	for(int j=0;j<num;j++)
	{
		if(hashtable[numtable[j]%newhashkey]==false)
		{
			hashtable[numtable[j]%newhashkey]=true;
			result[j]=numtable[j]%newhashkey;
			numgang.push_back(true);
		}
		else
		{
			int cao;
			for(cao=1;cao<num;cao++)
			{
				if(hashtable[(numtable[j]+cao*cao)%newhashkey]==false)     //还有平方探测法Quadratic probing 
				{
					hashtable[(numtable[j]+cao*cao)%newhashkey]=true;
					result[j]=(numtable[j]+cao*cao)%newhashkey;
					numgang.push_back(true);
					break;
				}
			}
			if(cao==num) numgang.push_back(false);
		}
	}
	for(int y=0;y<num;y++)
	{
		if(numgang[y]==true)
		{
			printf("%d",result[y]);
		}
		else
		{
			printf("-");
		}
		if(y!=num-1)  printf(" ");
	}
	
 } 
