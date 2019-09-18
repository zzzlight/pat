#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string create(string t)
{
	string s;
	int i=0;
	int count=1;
	if(t.size()==1)
	{
		s.push_back(t[i]);
		s.push_back('1');
	}
	else
	{
		while(i<t.size())
		{
			if(i!=t.size()-1)
			{
				if(t[i]==t[i+1])
				{
					count++;
				}
				else
				{
					s.push_back(t[i]);
					s.push_back(count+'0');
					count=1;
				}
			}
			else
			{
				s.push_back(t[i]);
				s.push_back(count+'0');
				
			}
			
		i++;
		}	
	}


	return s;
}
int main()
{
	string first;
	int seqnum;
	cin>>first;
	cin>>seqnum;
	int count=1;
	string temp=first;
	while(count<seqnum)
	{
		string news=create(temp);
		temp=news;
		count++;
	}
	cout<<temp;
}
