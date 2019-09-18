#include<stdio.h>
#include<math.h>
#include<vector>


using namespace std;


int seq[150];
int num;
int record1;
int record2;
bool judge(int a,int b)
{
	int liahumannum=0;
	int liawolfnum=0;
	for(int i=1;i<=num;i++)
	{
		if(liahumannum>1||liawolfnum>1)
		{
			return false;  //通过判断说假话的人狼数量判定是否合理 
		}
		if(seq[i]>0)
		{
			if(seq[i]==a||seq[i]==b)
			{
				if(i==a||i==b)  //下判定的自己是狼 
				{
					liawolfnum++;
				}
				else  //否则是人说谎 
				{
					liahumannum++;
				}
			}
			//否则则说了真话  算了     
		}
		else
		{
			if(abs(seq[i])!=a&&abs(seq[i])!=b)
			{
				if(i==a||i==b)
				{
					liawolfnum++;
				}
				else
				{
					liahumannum++;
				}
			}	
		}
		
	}
	if(liawolfnum==1&&liahumannum==1)return true;
	else return false;
}
int main()
{

	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
		scanf("%d",&seq[i]);
	}
	int flag=false;
	for(int i=1;i<=num;i++)
	{
		for(int j=i+1;j<=num;j++)
		{
			if(judge(i,j))
			{
				record1=i;
				record2=j;
				flag=true;
				break;
			}
		}
		if(flag==true) break;
	}
	if(flag==true) printf("%d %d",record1,record2);
	else printf("No Solution");
}
