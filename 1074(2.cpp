#include<stdio.h>
#include<algorithm>
using namespace std;

struct Node
{
	int address;
	int date=100002;
	int order=100002;
	int next;
	
}node[100005];
bool cmp(Node a,Node b )
{
	return a.order<b.order;
	
}
int main()
{
	int num;
	int revnum;
	int orgin;
	scanf("%d",&orgin);
	scanf("%d",&num);
	scanf("%d",&revnum);
	for(int i=1;i<=num;i++)
	{
		int address;
		scanf("%d",&address);
		node[address].address=address;    
		scanf("%d",&node[address].date);
		scanf("%d",&node[address].next);
	}
	int id=orgin;
	int count1=0;
	while(id!=-1)
	{
		node[id].order=count1++;
		id=node[id].next;
	}
	num=count1;
	sort(node,node+100005,cmp);
	for(int i=0;i<num/revnum;i++)
	{
		for(int j=(i+1)*revnum-1;j>i*revnum;j--)  //>处不能取等号 取等号情况后面单独写  即将每个的最后一个都单独讨论 
		{
			printf("%05d %d %05d\n",node[j].address,node[j].date,node[j-1].address); 
		}
		if(i<num/revnum-1) printf("%05d %d %05d\n",node[i*revnum].address,node[i*revnum].date,node[(i+2)*revnum-1].address); //不是最后一组时，取(i+2)*revnum-1即下一行最后一个 
		else if(i==num/revnum-1&&num%revnum==0) printf("%05d %d -1\n",node[i*revnum].address,node[i*revnum].date);  //到了最后一组 ，整除则取-1 
		else if(i==num/revnum-1&&num%revnum!=0)  //不能整除则正向输出最后一组 
		{
			printf("%05d %d %05d\n",node[i*revnum].address,node[i*revnum].date,node[(i+1)*revnum].address);
			int j;
			for(j=num/revnum*revnum;j<num-1;j++)
			{
				printf("%05d %d %05d\n",node[j].address,node[j].date,node[j+1].address);
			}
			printf("%05d %d -1\n",node[j].address,node[j].date);
		}
	}
	
	
 } 

