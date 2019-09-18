#include<stdio.h>
#include<algorithm>
                        //并查集   未完全弄懂！！！！！！！ 
using namespace std;

struct Family
{
	int id=-1;
	int estate;
	int area;
	int num;
	double avearea;
	double aveestate;
}family[10005];
int estate[10005];
int area[10005];
int father[10005];
int findfather(int x)
{

	if(x==father[x]) return x;
	else 
	{
		int F=findfather(father[x]);
		father[x]=F;
		return F;
	}
}
void myunion(int a,int b)
{
	int faA=findfather(a);
	int faB=findfather(b);
	if(faA!=faB)
	{
		father[max(faA,faB)]=min(faA,faB);  //ID总是选到最小处 
	}
}
bool cmp(Family a,Family b)
{
	if(a.avearea!=b.avearea) return a.avearea>b.avearea;
	else return a.id<b.id;
}
int main()
{
	
	int num;
	scanf("%d",&num);
	for(int i=0;i<10005;i++)
	{
		father[i]=-1;  //
	}
	for(int i=0;i<num;i++)
	{
		int id;
		int Father;
		int Mother;
		scanf("%d %d %d",&id,&Father,&Mother);
		if(father[id]==-1) father[id]=id;  // 
		if(Father!=-1) 
		{
			if(father[Father]==-1) father[Father]=Father;
			myunion(id,Father);
		}
		if(Mother!=-1) 
		{
			if(father[Mother]==-1) father[Mother]=Mother;
			myunion(id,Mother);
		}
		int childnum;
		scanf("%d",&childnum);
		for(int j=0;j<childnum;j++)
		{
			int child;
			scanf("%d",&child);
			if(father[child]==-1) father[child]=child;
			myunion(id,child);
		 } 
		 int temp1;
		 int temp2;
		 scanf("%d %d",&estate[id],&area[id]);
	}
	for(int i=0;i<10005;i++)
	{
		if(father[i]!=-1)  //不是没包含的点  -1即没包括的点 
		{
			int t=findfather(i);  //全弄到根节点 
			family[t].id=t; //只在根节点上记录了id 
			family[t].area+=area[i];
			family[t].estate+=estate[i];
			family[t].num++;
		}
	}
	for(int i=0;i<10005;i++)
	{
		if(family[i].id!=-1)
		{
			family[i].aveestate=1.0*family[i].estate/family[i].num;
			family[i].avearea=1.0*family[i].area/family[i].num;
		}

	}
	sort(family,family+10005,cmp);
	int block=0;
	for(int i=0;i<10005;i++)
	{
		if(family[i].id!=-1)
		{
			block++;
		}
	}
	printf("%d",block);
	for(int i=0;i<10005;i++)
	{
		if(family[i].id!=-1)
		{
			printf("\n%04d %d %0.3f %0.3f",family[i].id,family[i].num,family[i].aveestate,family[i].avearea);
			
		}
	}
}
