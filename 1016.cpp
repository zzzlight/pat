#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct User
{
	string name;
	string time;
	string state;
	
}user[1005];
int rate[24];
struct Out
{
	int month;
	string name;
	string starttime;
	string overtime;
	int min;
	double price;
	double amountprice=0;
}out[1005];
bool flag[1005];
int num;
bool cmp(User a,User c)
{
	if(a.name!=c.name)
	{
		return a.name<c.name;
	}
	else return a.time<c.time;
	
	
}
int counttime(string start,string over)
{
	string mm=start.substr(0,2);
	int mmint=(mm[0]-'0')*10+(mm[1]-'0');
	string dd=start.substr(3,2);
	int ddint=(dd[0]-'0')*10+(dd[1]-'0');
	string hh=start.substr(6,2);
	int hhint=(hh[0]-'0')*10+(hh[1]-'0');
	string minmin=start.substr(9,2);
	int minminint=(minmin[0]-'0')*10+(minmin[1]-'0');
	string mm2=over.substr(0,2);
	int mmint2=(mm2[0]-'0')*10+(mm2[1]-'0');;
	string dd2=over.substr(3,2);
	int ddint2=(dd2[0]-'0')*10+(dd2[1]-'0');
	string hh2=over.substr(6,2);
	int hhint2=(hh2[0]-'0')*10+(hh2[1]-'0');
	string minmin2=over.substr(9,2);
	int minminint2=(minmin2[0]-'0')*10+(minmin2[1]-'0');
	int out=(minminint2-minminint)+(hhint2-hhint)*60+(ddint2-ddint)*24*60+(mmint2-mmint)*30*24*60;
	return out;
	
}
double countprice(string start,string over)
{
	double out=0;
	string mm=start.substr(0,2);
	int mmint=(mm[0]-'0')*10+(mm[1]-'0');
	string dd=start.substr(3,2);
	int ddint=(dd[0]-'0')*10+(dd[1]-'0');
	string hh=start.substr(6,2);
	int hhint=(hh[0]-'0')*10+(hh[1]-'0');
	string minmin=start.substr(9,2);
	int minminint=(minmin[0]-'0')*10+(minmin[1]-'0');
	string mm2=over.substr(0,2);
	int mmint2=(mm2[0]-'0')*10+(mm2[1]-'0');;
	string dd2=over.substr(3,2);
	int ddint2=(dd2[0]-'0')*10+(dd2[1]-'0');
	string hh2=over.substr(6,2);
	int hhint2=(hh2[0]-'0')*10+(hh2[1]-'0');
	string minmin2=over.substr(9,2);
	int minminint2=(minmin2[0]-'0')*10+(minmin2[1]-'0');
    while(ddint<ddint2||hhint<hhint2||minminint<minminint2)
    {
    	out+=rate[hhint];
    	minminint++;
    	if(minminint>=60)
    	{
    		hhint++;
    		minminint=0;
		}
		if(hhint>=24)
		{
			ddint++;
			hhint=0;
		}
	}
	return out;
};
bool cmp1(Out a,Out c)
{
	if(a.name!=c.name)
	{
		return a.name<c.name;
	}
	else return a.starttime<c.starttime;
	
	
}
int main()
{
	for(int i=0;i<24;i++)
	{
		cin>>rate[i];
	}
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>user[i].name;
		cin>>user[i].time;
		cin>>user[i].state;

	}
	sort(user,user+num,cmp);
	int i;
	int count=0;
	for(i=0;i<num;i++)
	{
		for(int j=i+1;j<num;j++)
		{
			if(flag[j]==true||flag[i]==true) continue;
			if(user[j].name!=user[i].name) break;
			if(user[j].name==user[i].name&&user[i].state=="on-line"&&user[j].state=="on-line") 
			{
				
				break;
			}
			if(user[i].name==user[j].name&&user[i].state=="on-line"&&user[j].state=="off-line")
			{
				flag[j]=true;
				flag[i]=true;
				string tempmonth=user[j].time.substr(0,2);
				out[count].month=(tempmonth[0]-'0')*10+(tempmonth[1]-'0');
				out[count].name=user[i].name;
				out[count].starttime=user[i].time;
				out[count].overtime=user[j].time;
				int tempmin=counttime(user[i].time,user[j].time);
				out[count].min=tempmin;
				double tempprice=countprice(user[i].time,user[j].time);
				out[count].price=tempprice;
				count++;
			}
		}
	
	}
	sort(out,out+count,cmp1);
	for(int t=0;t<count;t++)
	{
		double amount;
		if(t==0||out[t].name!=out[t-1].name||(out[t].name==out[t-1].name&&out[t].month!=out[t-1].month))
		{
			cout<<out[t].name<<" ";
			printf("%02d\n",out[t].month);
			amount=0;
		}
		string starttemp=out[t].starttime.substr(3,8);
		string overtemp=out[t].overtime.substr(3,8);
		cout<<starttemp<<" ";
		cout<<overtemp<<" ";
		cout<<out[t].min<<" ";
		printf("$%.02lf\n",(out[t].price/100));
		amount+=out[t].price/100;
		if(out[t].name!=out[t+1].name||(out[t].name==out[t+1].name&&out[t].month!=out[t+1].month)||t==count-1)
		{
			printf("Total amount: $%.02lf",amount);
			amount=0;
			if(t!=count-1) printf("\n");
		}
	}
	
	
}
 
