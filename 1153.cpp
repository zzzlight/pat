#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

int fuck[1005];
struct Student
{
	int score;
	string id;
};
struct part
{
	int count=1;
	int id;	
};
vector<Student> seq;
bool cmp(Student a,Student b)
{
	if(a.score!=b.score) return a.score>b.score;
	else return a.id<b.id;
	
}
bool cmp1(part a,part b)
{
	if(a.count!=b.count) return a.count>b.count;
	else return a.id<b.id;
}
int main()
{
	int seqnum;
	int cxnum;
	scanf("%d %d",&seqnum,&cxnum);
	for(int i=0;i<seqnum;i++)
	{
		Student temp;
		cin>>temp.id;
		cin>>temp.score;
		seq.push_back(temp);
	}
	for(int i=1;i<=cxnum;i++)
	{
		vector<Student> result;
		int mode;
		string cxid;
		scanf("%d",&mode);
		cin>>cxid;
		if(mode==2)
		{
			int sum=0;
			int count=0;
			for(int j=0;j<seq.size();j++)
			{
				string ttemp;
				for(int t=1;t<4;t++)
				{
					ttemp.push_back(seq[j].id[t]);
				}
				if(ttemp==cxid) 
				{
					sum+=seq[j].score;
					count++;
				}
				
			}
			printf("Case %d: %d ",i,mode);
			cout<<cxid<<endl;
			if(count!=0) printf("%d %d",count,sum);
			else printf("NA");
		}
		if(mode==1)
		{
			vector<Student> result;
			for(int j=0;j<seq.size();j++)
			{
				if(seq[j].id[0]==cxid[0])
				{
					result.push_back(seq[j]);
				}
			}
			sort(result.begin(),result.end(),cmp);
			printf("Case %d: %d ",i,mode);
			cout<<cxid<<endl;
			if(result.size()!=0)
			{
				for(int j=0;j<result.size();j++)
				{
					cout<<result[j].id;
					printf(" %d",result[j].score);
					if(j!=result.size()-1) printf("\n");
				} 
			}
			else
			{
				printf("NA");
			}
		}
		if(mode==3)
		{
			fill(fuck,fuck+1005,0);
			bool flag=false;
			for(int j=0;j<seq.size();j++)
			{

				int xx=0;
				int tt;
				for(tt=4;tt<10;tt++)
				{
					if(cxid[xx++]!=seq[j].id[tt]) break;
				}
				if(tt==10)
				{
					flag=true;
					char a[10];
					int acount=0;
					int fucku;
					for(int mm=1;mm<4;mm++)
					{
						a[acount++]=seq[j].id[mm];
					}
					sscanf(a,"%d",&fucku);
					
					fuck[fucku]++;		
				}
			}
			printf("Case %d: %d ",i,mode);
			cout<<cxid<<endl;
			if(flag)
			{
				vector<part> aseq;
				for(int y=0;y<1005;y++)
				{
					if(fuck[y]!=0)
					{
						part tpart;
						tpart.count=fuck[y];
						tpart.id=y;
						aseq.push_back(tpart);
					}
				}
				sort(aseq.begin(),aseq.end(),cmp1);
				for(int t=0;t<aseq.size();t++)
				{
					printf("%d %d",aseq[t].id,aseq[t].count);
					if(t!=aseq.size()-1) printf("\n");
				}
				
			}
			else
			{
				printf("NA");
			}

		}
		if(i!=cxnum) printf("\n");
	}
}
