#include<stdio.h>
#include<algorithm>
using namespace std;
struct Person{
		long long number;
		int virtue;
		int talent;
		int flag;
		
}a[105000];
bool cmp1(Person a,Person b){
	if (a.flag !=b.flag)return (a.flag>b.flag);
	else if ((a.virtue + a.talent) != (b.virtue + b.talent)) return ((a.virtue + a.talent) > (b.virtue + b.talent));
	else if (a.virtue != b.virtue)return (a.virtue > b.virtue);
	else return (a.number < b.number);
}
int N;
int H;

int main(){
	
	int count = 0;
	int num;
	int N;
	int H;
	scanf("%d %d %d", &num, &N, &H);
	for (int i = 0; i < num; i++)
	{
		scanf("%lld %d %d", &a[i].number,& a[i].virtue,& a[i].talent);
	}
	
	for (int i = 0; i < num; i++)
	{
		
		if (a[i].talent >= N&&a[i].virtue >= N)
		{
			if (a[i].virtue < H)
			{
				a[i].flag = 1;
			}
			if (a[i].virtue >=a[i].talent&&a[i].flag==1)
			{
				a[i].flag = 2;
			}
			
			if (a[i].virtue >= H)
			{
				if (a[i].virtue >= H && a[i].talent >= H)
				{
					a[i].flag = 4;
				}
				else a[i].flag = 3;
				
			}
			

		}
		else  a[i].flag = 0;
	}
	
	sort(a, a + num, cmp1);
	for (int i = 0; i < num; i++)
	{
		if (a[i].flag > 0)(count++);
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		
		printf("%lld %d %d\n", a[i].number, a[i].virtue, a[i].talent);
		//printf("%lld %d \n", a[i].number,a[i].flag);
	}
}