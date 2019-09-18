#include<stdio.h>
#include<algorithm>
using namespace std;

struct Node
{
	int address;
	int date=100002;
	int next;
	
}node[100001];
bool cmp(Node a,Node b )
{
	return a.date<b.date;          //问题在于按date进行了从小到大排序
												//但若输入地址不是按从小到大顺序而是从大到小则必然出错
												//解决办法：不要用数组和sort关于值排序  直接用vector 
	
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
	int j=orgin;
	int address[100001];
	int i=0;
	while(1)
	{
		address[i]=j;
		++i; 
		if(node[j].next==-1)
		{
			break;
		}
		else
		j=node[j].next;
		
	}
	num=i;
	sort(node,node+100001,cmp);
	int duan=num%revnum;
	int temp=-1;
	if(duan==0)
	{
			temp+=revnum;
			while(temp<num-revnum)
			{	
			int count=0;
			while(count!=revnum)
			{	
				if(count!=revnum-1)
				{
					printf("%05d %d %05d\n",node[temp-count].address,node[temp-count].date,node[temp-count-1].address);	
				}
				else
				{
					printf("%05d %d %05d\n",node[temp-count].address,node[temp-count].date,node[temp+revnum].address);
				}

				
				count++;
				
			
			}
			temp+=revnum;
		  	}
		  for(int y=temp;y<num;y++)
		  {
		  		int count=0;
			while(count!=revnum)
			{	
				if(count!=revnum-1)
				{
					printf("%05d %d %05d\n",node[y-count].address,node[y-count].date,node[y-count-1].address);	
				}
				else
				{
					printf("%05d %d -1",node[temp-count].address,node[temp-count].date);
				}

				
				count++;
				
			
			}
		  }
		  	
		  	
	}
	else
	{
		if(num<revnum)
		{
			int x;
			for(x=num-1;x>0;x--)
			{
				printf("%05d %d %05d\n",node[x].address,node[x].date,node[x-1].address);	
			}
			printf("%05d %d -1",node[x].address,node[x].date);	
		}
		else
		{
	
			temp+=revnum;
			while(temp<num-duan)
			{
		
			int count=0;
			while(count!=revnum)
			{
			
				
				if(count!=revnum-1)
				printf("%05d %d %05d\n",node[temp-count].address,node[temp-count].date,node[temp-count-1].address);	
				if(count==revnum-1&&temp+revnum<num)
				printf("%05d %d %05d\n",node[temp-count].address,node[temp-count].date,node[temp+revnum].address);
				if(count==revnum-1&&temp+revnum>num)
				{
					printf("%05d %d %05d\n",node[temp-count].address,node[temp-count].date,node[num-duan].address);
				}
				
				
				
				count++;

			}
			temp+=revnum;
		  	}
		  	for(int x=num-duan;x<num;x++)
		  	{
		  		if(x!=num-1)
		  		printf("%05d %d %05d\n",node[x].address,node[x].date,node[x].next);
		  		else
		  		printf("%05d %d -1",node[x].address,node[x].date);
			  }
		}
	}
	
	
 } 
