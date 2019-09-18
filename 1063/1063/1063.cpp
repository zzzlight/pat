#include<stdio.h>
#include<set>
using namespace std;
struct Setcoop
{
	set<int> aset;
}setcoop[100];

int main()
{
	Setcoop setcoop2[5];
	int n;
	scanf("%d", &n);
	int setnum;
	for (int i =1; i <=n; i++)
	{
		scanf("%d", &setnum);
		for (int j = 0; j < setnum; j++)
		{
			int inset;
			scanf("%d", &inset);
			setcoop[i].aset.insert(inset);
		}
	}
	int putoutnum;
	scanf("%d", &putoutnum);
	double baifenbi[2002];
	for (int x = 0; x < putoutnum; x++)
	{
		int set1;
		int set2;
		scanf("%d", &set1);
		scanf("%d", &set2);
		double qian = setcoop[set1].aset.size() + setcoop[set2].aset.size();
		setcoop2[0].aset.insert(setcoop[set1].aset.begin(), setcoop[set1].aset.end());   //vs坑爹不会补上begin等的括号注意
		setcoop2[0].aset.insert(setcoop[set1].aset.begin(), setcoop[set1].aset.end());		//insert方法为n  共n2，超时
		double hou = setcoop2[0].aset.size();
		baifenbi[x] = (qian-hou) / hou * 100;
		setcoop2[0].aset.clear();
	}
	for (int n = 0; n < putoutnum; n++)
	{
		if (n!=putoutnum-1)
		printf("%0.1lf%%\n", baifenbi[n]);
		else
		printf("%0.1lf%%", baifenbi[n]);
	}
	
}