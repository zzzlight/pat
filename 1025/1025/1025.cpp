#include<cstdio>
#include<algorithm>
using namespace std;

struct student{
	long long id;
	int score;
	int rank;
	int place;
	int placerank;
	int flag = 0;
}a[30500];
bool cmp1(student a, student b)
{
	if (a.place != b.place)return a.place < b.place;
	else return a.score > b.score;
	
}
bool cmp(student a, student b)
{
	if(a.score!=b.score) return a.score > b.score;
	else return a.id < b.id;
}
int main(){
	int num;
	int locationnum=0;
	int sum=0;
	int placenum=0;
	scanf("%d", &num);
	for (int i = 0; i <num; i++)
	{
		//sum += locationnum;
		scanf("%d", &locationnum);
		
		for (int j = 0; j <locationnum; j++)
		{
			scanf("%lld %d", &a[sum+j].id, &a[j+sum].score);
			a[j+sum].place = i+1;

		}
		sort(a+sum, a+sum + locationnum, cmp1);
		a[sum].placerank = 1;
		for (int m = 1; m < locationnum; m++)
		{
			
			if (a[m+sum].score == a[sum+m-1].score)
			{
				a[m+sum].placerank = a[sum+m - 1].placerank;
			}
			else
			{
				a[m + sum].placerank = m + 1;
			}
		}

		sum += locationnum;
		
	}
	/*sort(a, a + sum, cmp1);
	int k = 1;
	a[0].placerank = 1;
	
	for (int i = 1; i < sum; i++)
	{
		if (a[i].place == a[i - 1].place)
		{
				a[i].placerank = 1 + k;
				k++;
			
		}
		else {
			k = 1;
			a[i].placerank = k;
			}

	}
	for (int i = 1; i <sum ; i++)
	{
		if (a[i].score == a[i - 1].score)
		{
			a[i].placerank = a[i - 1].placerank;
		}
		
		
	}*/

	sort(a, a + sum, cmp);
	//a[0].rank = 1;
	for (int i = 0; i < sum; i++)
	{
		if (i>0&&a[i].score == a[i - 1].score){    //i>0与测试点三有关 应该是全0输入
			a[i].rank = a[i - 1].rank;
		}
		else a[i].rank = i+1;
	}

	printf("%d\n", sum);
	for (int i = 0; i < sum; i++)
	{
		printf("%013lld ", a[i].id);   //此处必须以13位输出
		printf("%d %d %d\n",  a[i].rank, a[i].place,a[i].placerank);
	}

}