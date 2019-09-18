#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

bool isnormal(char a)
{
	if (a >= '0'&&a <= '9') return true;
	if (a >= 'a'&&a <= 'z') return true;
	if (a >= 'A'&&a <= 'Z') return true;
	
	return false;
}
int main()
{
	string in_put;
	map<string, int> amap;
	getline(cin,in_put);
	string::iterator ita=in_put.begin();
	transform(in_put.begin(),in_put.end(),in_put.begin(),::tolower);
	int alen=0;
	while (in_put.end()-ita>=alen)
	{
		string::iterator itb=in_put.begin()+alen;
		if (isnormal(*itb)== true)
		{
			int len = 0;
			while (isnormal(*(itb + len)))
			{
				len++;
				//cout<<len<<endl;
			}
		//	cout<<alen<<len<<endl;
			string word =in_put.substr(alen,len);
		//	cout<<word<<endl;
			if (amap[word]==1||amap[word]>1)
			{
				amap[word]++;
			}
			else
			{
				amap[word] = 1;
			}
			//in_put.erase(in_put.begin(), in_put.begin() + len);
			alen=alen+len;
		}
		else
		{
			alen++;
		}
	}
	int max = amap.begin()->second;
	string maxstr= amap.begin()->first;
	for (map<string, int>::iterator itmap = amap.begin(); itmap != amap.end(); itmap++)
	{
		if (itmap->second > max)
		{
			max = itmap->second;
			maxstr = itmap->first;
		}

	}
	cout << maxstr<<" "<<max;
}
