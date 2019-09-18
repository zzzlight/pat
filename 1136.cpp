#include<iostream>
#include<string>
#include<algorithm>
//ûac 
using namespace std;
bool flag;
long long stringtoint(string t)
{
	long long sum=0;
	for(int i=0;i<t.size();i++)
	{
		
		long long n=t[i]-'0';
		sum+=n;
		if(i!=t.size()-1) sum=sum*10;
		
	}
	return sum;
}

string reverse(string t)
{
	string temp;
	for(int i=t.size()-1;i>=0;i--)
	{
		temp.push_back(t[i]);
	}
	return temp;
}
string inttostring(long long t)
{
	string temp;
	while(t>0)
	{
		int tt=t%10;
		temp.push_back(tt+'0');
		t=t/10;
	}
	return reverse(temp);
}
int count1=0;
int main()
{
	string name;
	cin>>name;
	string temp=name;
	if(name.size()>25)
	{
		flag=false;
		count1=10;
	}
	while(1)
	{
		if(count1>9) 
		{
			flag=true;
			break;
		}
		count1++;
		string res=reverse(temp);
		if(temp==res)
		{
			break;
		 } 

		long long num1=stringtoint(res);
		long long num2=stringtoint(temp);
		long long num3=num1+num2;
		cout<<temp;
		printf(" + ");
		cout<<res;
		printf(" = ");
		temp=inttostring(num3);
		cout<<temp<<endl;
	
	}
	
	if(flag==true)
	{
		printf("Not found in 10 iterations."); 
	}
	else
	{
		cout<<temp;
		printf(" is a palindromic number.");
	}
 } 
