#include<cstdio>
#include<algorithm>
using namespace std;
#define max 100001
struct Node{
	int address;
	int data;
	int next;
	bool flag;
}node[max];
bool cmp(Node a,Node b)
	{
	if(a.flag==false||b.flag==false)
	{
		
		return a.flag>b.flag;						//sort的cmp此处将无效点（flag为0）放在后面，再将前面的有效点进行了排序 
		
	}		
	else return a.data<b.data; 
	}
 
int main()
{
	int num,data,next,s1,address;
	int count=0;
	scanf("%d %d",&num,&s1);
	for(int x=0;x<max;x++)
{
	node[x].flag=0;
}
	for(int i=0;i<num;i++)
	{
		scanf("%d %d %d",&address,&data,&next);
		node[address].address=address;
		node[address].data=data;
		node[address].next=next;
	}
	for(int j=s1;j!=-1;j=node[j].next)
	{
		node[j].flag=1;
		count++;
	}
	if(count==0)
	printf("0 -1");
	else{

	sort(node,node+max,cmp);
	
	for(int z=0;z<count;z++)
 	{
 		if(z!=count-1)
 		node[z].next=node[z+1].address;
 		else node[z].next=-1;
	 }
	printf("%d %05d\n",count,node[0].address);
	
												//本题注意问题1.sort只按数据排了记得排address
													//		  2.注意最后一位-1的输出
													//		  3.了解sort的使用以及std
															   
	
	
	
	for(int y=0;y<count;y++)
	{
		if(y==count-1)
		printf("%05d %d %d\n",node[y].address,node[y].data,node[y].next);
		else printf("%05d %d %05d\n",node[y].address,node[y].data,node[y].next);
		 
	}
	
		}
	
	return 0;
}    
