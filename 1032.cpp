#include<cstdio>
#include<cstring>
 
#define  max 100001
 struct node{
 	char data;
 	int next;
 	bool flag;
 }node[max];
 
 int main(){
	int s1,s2,num;
   for(int i=0;i<max;i++)    //flag初始化为0（未遍历） 
 	{
 		node[i].flag=false; 
	}
	 scanf("%d %d %d",&s1,&s2,&num);
	 int address,next,common;
	 char data;
	 
	 for(int j=0;j<num;j++)
	 {
	 	scanf("%d %c %d",&address,&data,&next);
	 	node[address].data=data;
	 	node[address].next=next;
	 }
	 for(int x=s1;x!=-1;x=node[x].next)
	 {
		node[x].flag=true;
	 }
	 int y;
	for(y=s2;y!=-1;y=node[y].next)
	{
		if(node[y].flag==true)
		{
			common=y;
			break;
		}
	}
	if(y==-1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%05d\n",common);
	}
	
	return 0;
 }
