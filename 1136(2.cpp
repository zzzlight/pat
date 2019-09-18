#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string add(string a,string b)
{
	string c;
	int length=a.size();
	char t[length+5];
	int jw=0;
	for(int i=length-1;i>=0;i--)
	{
			int temp=(a[i]-'0')+(b[i]-'0')+jw;	
			if(temp>=10) 
			{
				int temp1=temp%10;
				jw=temp/10;
				t[i]=temp1+'0';
			}
			else
			{
				t[i]=temp+'0';
				jw=0;
			}
	}
	if(jw!=0) c.push_back(jw+'0');
	for(int i=0;i<length;i++)
	{
		c.push_back(t[i]);
	}
	cout<<a;
	printf(" + ");
	cout<<b;
	printf(" = ");
	cout<<c<<endl;
	return c;
}
int main()
{
	string a;
	cin>>a;
	string b=a;
	reverse(b.begin(),b.end());
	int count=0;
	while(count<10)
	{
		if(a==b) 
		{
			cout<<a;
			printf(" is a palindromic number.");   //判定第一组 
			break;
		}
		count++; 
		a=add(a,b);
		b=a;
		reverse(b.begin(),b.end());
		
	}
	if(count==10)
	{
		printf("Not found in 10 iterations.");
	}
	
}
