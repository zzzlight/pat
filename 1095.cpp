#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
map<string,bool> mmap;
int carnum;
int cxquery;
int cxseq[90005];
int out[10005];
vector<string> outcarname;
char a[10];
struct Seq
{
	string name;
	int sum=0;
}seq[10005];
struct Car
{
	int time;
	int ptime=-1;
	bool flag;
	string carname;
	bool vaild;
	bool outvaild;
}car[10005];

bool cmp(Car car1,Car car2)
{
	if(car1.carname!=car2.carname)
	{
		return car1.carname<car2.carname;
	}
	else
	{
		return car1.time<car2.time;
	}
}
int trans(string temp)
{
	return temp[7]+temp[6]*10+(temp[3]*10+temp[4])*60+3600*(temp[0]*10+temp[1]);
}
bool cmp1(Car car1,Car car2)
{
	return car1.time<car2.time;
}
void transtostr(int time)
{

	int hour=time/3600;
	int min=(time-3600*hour)/60;
	int second=time%60;
	a[0]='0'+hour/10;
	a[1]='0'+hour%10;
	a[2]=':';
	a[3]='0'+min/10;
	a[4]='0'+min%10;
	a[5]=':';
	a[6]='0'+second/10;
	a[7]='0'+second%10;
	a[8]='\0';
	
}
int main()
{
	cin>>carnum;
	cin>>cxquery;
	for(int i=0;i<carnum;i++)
	{
		cin>>car[i].carname;
		mmap[car[i].carname]=false;
		string temp2;
		cin>>temp2;
		string temp3;
		cin>>temp3;
		if(temp3=="in")
		{
			car[i].flag=true;
			car[i].time=trans(temp2);
		}
		else
		{
			car[i].flag=false;
			car[i].time=trans(temp2);
		}
		
	}
	for(int i=0;i<cxquery;i++)
	{
		string temp;
		cin>>temp;
		cxseq[i]=trans(temp);
	}
	sort(car,car+carnum,cmp); 
	for(int i=0;i<carnum;i++)
	{
	
		if(car[i].flag==true)
		{
			int j;
			int temp=-1;
			for(j=i+1;j<carnum;j++)
			{
				if(car[j].flag==false&&car[j].carname==car[i].carname)
				{
					temp=j;
					car[i].vaild=true;
					car[j].outvaild=true;
					break;
				}
				else break;
			}
			if(temp!=-1)
			{
				car[temp].ptime=car[temp].time-car[i].time;
			}
		}
	}
	int max=-1;
	int t=0;
	for(int i=0;i<carnum;i++)
	{
		
		if(car[i].ptime!=-1)
		{
			seq[t].sum+=car[i].ptime;
			seq[t].name=car[i].carname;
		}
		if(car[i].carname!=car[i+1].carname||i==carnum-1)
		{
			t++;
		}
	}
	for(int i=0;i<t;i++)
	{
		if(seq[i].sum>max)
		{
			max=seq[i].sum;
		}
	}
	for(int i=0;i<t;i++)
	{
		if(seq[i].sum==max)
		{
			outcarname.push_back(seq[i].name);
		}
	}
	transtostr(max);
	int tt=0;
	int memory=0;
	sort(car,car+carnum,cmp1);
	int feiwu=0;
	int pair=0;
	for(int qt=0;qt<cxquery;qt++)
	{
		int i=memory;   //这里gcc能过 clang段错误 编译器问题导致rp好大数据点过了  
		for(;i<carnum;i++)
		{
		if(cxseq[qt]<car[i].time)
		{
			out[tt++]=feiwu-pair;
			break;     //找完停车场车数后需break否则会出错 ？？？ 
		}
		if(car[i].flag==true&&car[i].vaild==true)
		{
			feiwu++;
		}
	
		if(car[i].flag==false)
		{
			if(car[i].outvaild==true)
			{
				pair++;
			}
		}
		}
		
		if(car[i].time>cxseq[qt]&&car[i-1].time<=cxseq[qt]) memory=i;   //暴力会超时 这里优化为若有常规增序则 feiwu和pair继续用节约时间 
		else
		{
			memory=0;											//碰到用例中未知情况按暴力法重置 
			feiwu=0;
			pair=0;
		 } 
	}

	for(int i=0;i<cxquery;i++)
	{
		cout<<out[i];
	    cout<<endl;
	}
	for(int i=0;i<int(outcarname.size());i++)  //这里size返回为无符号 由于没有超过int的大数据 所以不影响  但还是强转一下 
	{
		cout<<outcarname[i]<<" ";
	}
	cout<<a;
} 
