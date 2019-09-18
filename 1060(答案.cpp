#include<iostream>
#include<string>
using namespace std; 


int num;
string trans(string a,int& e)
{
	int k=0;
	while(a[0]=='0'&&a.length()>0)
	{
		a.erase(a.begin());
	 } 
	 if(a[0]=='.')
	{
		a.erase(a.begin());
		while(a[0]=='0'&&a.length()>0)
		{
			a.erase(a.begin());
			e--;
		}
	}    //说明是小于1 
	else    //大于1 
	{
		while(k<a.length()&&a[k]!='.')    //找大于1的小数点 
		{
			k++;
			e++;
		}
		if(k<a.length())
		{
			a.erase(a.begin()+k); 
		}    //否则说明此数无小数点 
	}
	if(a.length()==0)
	{
		e=0;
	}
	int n=0;
	k=0;
	string re;
	while(n<num)
	{
		if(k<a.length())
		{
			re+=a[k++];
		}
		else
		{
			re+='0';       //为0时 
		}
		n++;
	}
	return re;
}

int main()
{
	string a;
	string b;
	int m=0;
	int n=0;
	cin>>num>>a>>b;
	string transa=trans(a,m);
	string transb=trans(b,n);
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
