#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
long long inf = 0x7FFFFFFFFFFFFFFF;
map<char, int> mymap;
long long sumn1 = 0;
long long sumn2 = 0;
string n1;
string n2;
long long tag;
long long radix;

void init()
{
	for (char i = '0'; i <= '9'; i++)
	{
		mymap[i] = i - '0';
	}
	for (char i = 'a'; i <= 'z'; i++)
	{
		mymap[i] = 10 + (i - 'a');
	}
}

long long totherax(string num,long long rax,long long t)
{
	long long sum = 0;
	for (long long i = 0; i < num.length(); i++)
	{
		sum=mymap[num[i]]+rax*sum;
		if(sum<0||sum>t) return -1; //暗藏给定进制那个并不会发生溢出 故这里小于0专门用来cmp里n2判溢出的 
	}
	return sum;
}
int cmp(string n2,long long rax,long long t)  //t即n1的十进制 
{
	long long num=totherax(n2,rax,t);
	if(num<0) return 1;  //发生溢出 说明n2必大于n1
	if(t==num)  return 0;
	else if(t>num) return -1; //n1大于n2  说明设定的radix较小了 
	else return 1;  //正常判大小  n1小于n2  设定radix过大 
}
long long binarysearch(string n2,long long left,long long right,long long t)
{
	long long mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		int flag=cmp(n2,mid,t);
		if(flag==0) return mid;
		if(flag==-1) left=mid+1;
		else right=mid-1;
	}
	return -1;
}
int main()
{

	cin >> n1;
	cin >> n2;
	cin >> tag >> radix;
	init();
	if(tag==2)
	{
		swap(n1,n2); //保证n1总是已知进制的 
	}
	long long n1flag=totherax(n1,radix,inf);
	long long mymax=-1;
	for(long long i=0;i<n2.length();i++)
	{
		if(mymax<mymap[n2[i]]) mymax=mymap[n2[i]];
	}
	long long low=mymax+1; //即n2的最大数字加一 是最小可能的进制

	long long high ;//n1成为十进制后的 
	if(low>n1flag) high=low+1;
	else high=n1flag+1;
	long long  result=binarysearch(n2,low,high,n1flag);
	if(result==-1) cout<<"Impossible";
	else cout<<result;
}
