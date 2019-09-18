#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int final;
vector<int> seq[10005];
vector<int> temp;
bool visit[10005];
bool mark[10005];  //女为true 

struct Pair
{
	int man;
	int woman;
};
int stringtoint(string t)
{
	int sum=0;
	for(int i=0;i<t.size();i++)
	{
		if(t[i]=='-') continue;
		int n=t[i]-'0';
		sum+=n;
		if(i!=t.size()-1) sum=sum*10;
		
	}
	return sum;
}
bool cmp1(Pair a,Pair b)
{
	if(a.woman!=b.woman) return a.woman<b.woman;
	else return a.man<b.man;
}
bool cmp2(Pair a,Pair b)
{
	if(a.man!=b.man) return a.man<b.man;
	else return a.woman<b.woman;
}
int main()
{
	int num;
	int edgenum;
	scanf("%d %d",&num,&edgenum);
	for(int i=0;i<edgenum;i++)
	{
		int id1;
		int id2;
		string idc1;
		string idc2;
		cin>>idc1>>idc2;
		id1=stringtoint(idc1);
		id2=stringtoint(idc2);
		if(idc1[0]=='-') mark[abs(id1)]=true;	
		if(idc2[0]=='-')  mark[abs(id2)]=true;
		seq[abs(id1)].push_back(abs(id2));
		seq[abs(id2)].push_back(abs(id1));
	}
	int cxnum;
	scanf("%d",&cxnum);
	for(int i=0;i<cxnum;i++)
	{
		vector<int> result;
		int cxid1;
		int cxid2;
		string charcxid1;
		string charcxid2;
		cin>>charcxid1>>charcxid2;
		cxid1=stringtoint(charcxid1);
		cxid2=stringtoint(charcxid2);
		int absid1=abs(cxid1);
		int absid2=abs(cxid2);
		vector<int> thistemp;
		vector<int> thistemp4;
		for(int j=0;j<seq[absid1].size();j++)
		{
			if(mark[seq[absid1][j]]==mark[absid1]&&seq[absid1][j]!=absid2) thistemp.push_back(seq[absid1][j]);
		}
		for(int j=0;j<seq[absid2].size();j++)
		{
			if(mark[seq[absid2][j]]==mark[absid2]&&seq[absid2][j]!=absid1) thistemp4.push_back(seq[absid2][j]);
		}                                          //注意把直接认识的排除掉 
		if(thistemp.size()!=0)
		{
			for(int t=0;t<thistemp.size();t++)
			{
				for(int k=0;k<thistemp4.size();k++)
				{
					for(int q=0;q<seq[thistemp[t]].size();q++)
					{
						if(seq[thistemp[t]][q]==thistemp4[k])
						{
						//	if(thistemp[t]==thistemp4[k]) continue;  不会出现自己和自己是朋友的情况 
							result.push_back(thistemp[t]);
							result.push_back(thistemp4[k]);		
						}
					}
				
				}
			}
		vector<Pair> output;
		for(int x=0;x<result.size();)
		{
			Pair temppair;
			if(mark[result[x]]==true)
			{
				temppair.woman=result[x];
				temppair.man=result[x+1];
			 } 
			 else
			 {
			 	temppair.man=result[x];
			 	temppair.woman=result[x+1];
			 }
			 output.push_back(temppair);
			 x=x+2;
		}
		printf("%d\n",output.size());
		if(mark[absid1]==true)
		{
			sort(output.begin(),output.end(),cmp1);
			for(int x=0;x<output.size();x++)
			{
				printf("%04d %04d\n",output[x].woman,output[x].man);
			}
		}
		else
		{
			sort(output.begin(),output.end(),cmp2);
			for(int x=0;x<output.size();x++)
			{
				printf("%04d %04d\n",output[x].man,output[x].woman);
			}
		}
		
		}
		else
		{
			if(i!=cxnum-1) printf("0\n");
			else printf("0");
		}   //最后一行得有一个多的换行   这里碰巧样例中0应该不是最后一个 所以else处没换行也ac了 
		/*
		else
		{
			printf("0\n");
			//排查发现应该是最后一行得有一个多的换行  这里这样更符合意思 也能ac 
		}
		*/
	}
}
