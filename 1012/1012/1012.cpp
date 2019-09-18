#include<cstdio>
#include<algorithm>
using namespace std;
struct student{
	int stu;
	int clan;
	int math;
	int english;
	int ave;
	int rankc;
	int rankm;
	int rankeng;
	int rankave;
}a[2050];
bool cmp(student a, student b)
{
	
	return (a.english + a.math + a.clan) / 3>(b.english + b.math + b.clan)/3;
	

	
}
bool cmp1(student a, student b)
{
	return a.clan > b.clan;
}
bool cmp2(student a, student b)
{
	return a.math > b.math;
}
bool cmp3(student a, student b)
{
	return a.english > b.english;
}
int num;
int main(){
	int ran = 0;
	int b[2050];
	int num;
	int check;
	scanf("%d %d", &num, &check);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d %d\n",&a[i].stu,&a[i].clan,&a[i].math,&a[i].english);
	}
	for (int i = 0; i < check; i++)
	{
		scanf("%d",&b[i]);
	}
	sort(a, a + num, cmp);

	a[0].rankave = 1;
	a[0].ave = (a[0].english + a[0].math + a[0].clan) / 3;;   //注意ave问题，struct中无法除法得到ave（几个除数还未生成）
																		//故ave要自己计算
	for (int i = 1; i < num; i++)   //从1开始故前面还要手动算0的    其他数学成绩等不用如此麻烦
	{
		a[i].ave = (a[i].english + a[i].math + a[i].clan) / 3;
		
		if (a[i-1].ave == a[i].ave){ a[i].rankave = a[i-1].rankave; }    //排序中可能有值相同的但是rank序号不同，而题目要求数相同rank应该相等。rank总取第一个时候的rank
		else a[i].rankave = i + 1;
		
	}

	sort(a, a + num, cmp1);
	a[0].rankc = 1;
	for (int i = 0; i < num; i++)
	{
		if (a[i - 1].clan == a[i].clan){ a[i].rankc = a[i - 1].rankc; }
		else a[i].rankc = i + 1;
	}
	sort(a, a + num, cmp2);
	a[0].rankm = 1;
	for (int i = 0; i < num; i++)
	{
		if (a[i - 1].math == a[i].math){ a[i].rankm = a[i - 1].rankm; }
		else a[i].rankm = i + 1;
	}
	sort(a, a + num, cmp3);
	a[0].rankeng = 1;
	for (int i = 0; i < num; i++)
	{
		if (a[i - 1].english == a[i].english){ a[i].rankeng = a[i - 1].rankeng; }
		else a[i].rankeng = i + 1;
	}
													
	int temp=-1;
	for (int i = 0; i < check; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (b[i] == a[j].stu)
			{
				temp = j;
				break;
			}
			else temp = -1;
		}

		
		if (temp != -1)						
		{
			if (a[temp].rankave <= a[temp].rankc&&a[temp].rankave <= a[temp].rankm&&a[temp].rankave <= a[temp].rankeng)
				printf("%d A\n", a[temp].rankave);
			else if (a[temp].rankc <= a[temp].rankave&&a[temp].rankc <= a[temp].rankm&&a[temp].rankc <= a[temp].rankeng)
				printf("%d C\n", a[temp].rankc);
			else if (a[temp].rankm <= a[temp].rankc&&a[temp].rankm <= a[temp].rankave&&a[temp].rankm <= a[temp].rankeng)
				printf("%d M\n", a[temp].rankm);
			else if (a[temp].rankeng <= a[temp].rankc&&a[temp].rankeng <= a[temp].rankm&&a[temp].rankeng <= a[temp].rankave)
				printf("%d E\n", a[temp].rankeng);
		}
		if (temp == -1)printf("N/A\n");
		
	}
	
	
	
	
}