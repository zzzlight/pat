#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int hobby[1001];
int father[1001];
int isroot[1001];
bool cmp(int a,int b)
{
	return a>b;
}
void orgin(int num)
{
	for(int i=1;i<=num;i++)   //初始化最好初始化为人数的 后续不用初始 
	{
		father[i]=i;
		isroot[i]=false;
	}
}
int findfather(int x)
{
	int a=x;
	while(father[x]!=x)
	{
		x=father[x];
	}
	while(a!=father[a])   //路径压缩 
	{
		int z=a;
		a=father[a];
		father[z]=x;
		
	}
	return x;
}
 void unionab(int a,int b)
 {
 	int fathera=findfather(a);
 	int fatherb=findfather(b);
 	if(fathera!=fatherb)
 	{
 		father[fathera]=fatherb;
	 }
  } 
int main()
{
	 vector<int> out;

	int  num;
	int t=0;
	scanf("%d",&num);
		orgin(num);
	for(int i=1;i<=num;i++) 
	{
		int tempnum;
		scanf("%d:",&tempnum);
		int flag;
		for(int j=1;j<=tempnum;j++)
		{
			int tempj;
		
			scanf("%d",&tempj);
			if(hobby[tempj]==0)    
			{
				hobby[tempj]=i;     //第一次则记录下有这个爱好的人id 
			}
			
			
			unionab(findfather(hobby[tempj]),i); 	
			
		
			
		 } 
		
	 } 
	 
	for(int t=1;t<=num;t++)    //表示人的id是从1一直到n 故若是一个人是一组时，直接在此处就为1（因为一开始都初始化为自身） 
	{                              //原理即是重复的就用并查集合并，没重复的默认为1       
		isroot[findfather(t)]++;
	}
	int mycount=0;
	for(int x=1;x<=num;x++)
	{
		if(isroot[x]>0)
		{
			mycount++;
			out.push_back(isroot[x]);
		}
		
	 } 
	sort(out.begin(),out.end(),cmp);
	
	 printf("%d\n",mycount);
	 
	 if(mycount>1)
	 {
	 	auto it=out.begin();
	 	 for(;it!=out.end()-1;it++)
	 	{
	 		printf("%d ",*it);
	 	}
	 	printf("%d",*it);
	 }
	 else
	 {
	 	printf("%d",out[0]);
	 }
	
	 
	 
 } 
