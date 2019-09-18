#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;

bool isprime(int n)
{
	
	if(n==1||n==0) return false;
	for(int i=2;i<=(int)sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
bool flag;
int main()
{
	int num;
	int primenum;
	scanf("%d",&num);
	scanf("%d",&primenum);
	string seq;
	cin>>seq;
	while(seq[0]=='0') seq.erase(seq.begin());
	int i;
	for(i=0;i<num;i++)
	{
		int start=i;
		char temp[20];
		int t=0;
		if(num-i<primenum) break;
		for(int j=i;j<i+primenum;j++)
		{
			temp[t++]=seq[j];
		}
		int newnum;
		sscanf(temp,"%d",&newnum);
        temp[t]='\0';  //封好最后一位的后一位便于cout输出 否则会出错 
		if(isprime(newnum)) 
		{
			cout<<temp;   //最好输出原来的string部分  因为可能是中间部分有0的数 转成int前面0会消失  要补够0 
			flag=true;
			return 0;
		}
	}
	if(i==num-primenum+1) printf("404\n");
}
/*
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;

bool isprime(int num)
{
	
	if(num==1||num==0) return false;
	for(int i=2;i<=(int)sqrt(num);i++)
	{
		if(num%i==0) return false;
	}
	return true;
}
bool flag;
int main()
{
	int num;
	int primenum;
	scanf("%d",&num);
	scanf("%d",&primenum);
	string seq;
	cin>>seq;
	while(seq[0]=='0') seq.erase(seq.begin());
	int i;
	for(i=0;i<=num-primenum;i++)
	{
		int newnum;
		string t=seq.substr(i,primenum);
		newnum=stoi(t);
		if(isprime(newnum)) 
		{
			cout<<t;   //要输出为k位置的 故要是输出数字要补0  否则最好就输出原来的string 
			flag=true;
			break;
		}
	}
	if(i==num-primenum+1) printf("404");
}*/ 
