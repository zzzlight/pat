#include<iostream>
#include<math.h>
#include<string>
#include<map>

using namespace std;
long long inf = (llong long << 63) - 1;
map<char, int> mymap;
long long sumn1 = 0;
long long sumn2 = 0;
string n1;
string n2;
int tag;
int radix;

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
int to10rax(string num£¬int thisrax,int t)
{
	int sum = 0;
	for (int i = 0; i < num.length(); i++)
	{

	}
}
int main()
{

	cin >> n1;
	cin >> n2;
	cin >> tag >> radix;
	init();
	
}