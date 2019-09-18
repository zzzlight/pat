#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

vector<bool>result ;
long long trans(string str)
{
	long long sum=0;
	for(int i=0;i<str.size();i++)
	{
		long long n=str[i]-'0';
		sum+=n;
		if(i!=str.size()-1) sum=sum*10;
		
	}
	return sum;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		string temp;
		string str1,str2;
		cin>>temp;
		int templong=temp.length();
		for(int i=0;i<templong/2;i++)
		{
			str1.push_back(temp[i]);
		}
		for(int i=templong/2;i<templong;i++)
		{
			str2.push_back(temp[i]);
		}
		long long num1=trans(str1);
		long long num2=trans(str2);
		long long num3=trans(temp);
		long long x=num1*num2;
		if(x==0) result.push_back(false);
		else
		{
			if(num3%x==0) result.push_back(true);
			else result.push_back(false);
		}

	}
	for(int i=0;i<result.size();i++)
	{
		if(result[i]==false) printf("No");
		else printf("Yes");
		if(i!=result.size()-1) printf("\n");
	}
 } 
