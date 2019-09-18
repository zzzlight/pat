#include<stdio.h>
#include<map>
using namespace std;


int main()
{
	int num1;
	int num2;
	scanf("%d", &num1);
	scanf("%d", &num2);
	map<int, int> amap;
	int sum = num1*num2;
	for (int i = 0; i < sum; i++)
	{
		int num3;
		scanf("%d", &num3);
		if (amap.empty())
		{
			amap[num3] = 1;
		}
		else
		{
			amap[num3]++;
		}
		
	}
	map<int, int>::iterator ita;
	int max = amap.begin()->second;
	int maxfirst = amap.begin()->first;
	for (ita = amap.begin(); ita != amap.end(); ita++)
	{
		
		if (ita->second > max)
		{
			maxfirst = ita->first;
			max = ita->second;
		}
	}
	printf("%d", maxfirst);
	
	

}