#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;

string trans(string a,int& count,int num)
{
	string re;
	
	 if((atoi(a.c_str()))>0||(strlen(a.c_str())&&a.c_str()[0]>0))
	 {
	 	
	 while(a[0]=='0')
	{
		a.erase(a.begin());
	 } 
	 if(a[0]!=0&&a.length()>0)
	{
		while(count<num&&a[count]!='.'&&count<a.length())
		{
			
			re+=a[count];
			count++;
		}
		for(int i=0;i<a.length();i++)
		{
			if(a[i]!='.'&&count==num&&count<a.length())
				count=a.length();
		}
		
		
	
		if(count>=a.length())
		{
			for(int k=count;k<num;k++)
			{
				re+='0';
			}
		}
		if(a[count]=='.')
		{
			int x=count;
			a.erase(a.begin()+count);
			while(x<num)
			{
				re+=a[x];
				x++;
			}
		
		}
		//cout<<re<<endl;
	}
	}
	else
	{
	while(a[0]=='0')
	{
		a.erase(a.begin());
	 } 
	if(a[0]=='.')
	{
		a.erase(a.begin());
		while(a[0]=='0'&&a.length()>0)
		{
			a.erase(a.begin());
			count--;
		}
		int y=0;
		while(a[0]!='0'&&y<num&&y<a.length())
		{
			re+=a[y];
			y++;
			
		//	count--;
		}
		if(y!=num)
		{
			for(int k=y;k<num;k++)
			{
				re+='0';
			}
		}
	} 

	 if(atoi(a.c_str())==0)
	 {
		count=0;
		re.clear();
		for(int i=0;i<num;i++)
		{
			re+='0';
		}
	 }
	 
	}
	return re;
}
int main()
{
	string a;
	string b;
	int num;
	int m=0;
	int n=0;
	cin>>num>>a>>b;
	string transa=trans(a,m,num);
	string transb=trans(b,n,num);
	if(transa==transb&&m==n)
	{
		cout<<"YES ";
		cout<<"0."<<transa<<"*10^"<<m;
	}
	else
	{
		cout<<"NO ";
		cout<<"0."<<transa<<"*10^"<<m<<" "<<"0."<<transb<<"*10^"<<n;
	}
	
 } 
