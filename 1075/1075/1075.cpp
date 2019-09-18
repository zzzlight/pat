#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct student{
	int id;
	int prefect;   //初始化0
	int sum;
	int score[6];   //初始化-1        //该点有一个测试点2，若为5不可以.
	bool flag;	   //初始化false

}pater[15000];

int user;
int problem;
int sub;
int maxpoint[6];
bool cmp(student a, student b)
{
	if (a.sum != b.sum)return a.sum > b.sum;
	else if (a.prefect != b.prefect)return a.prefect > b.prefect;
	else if(a.id!=b.id)return a.id < b.id;
	
}
void mem(){
	for (int i=1; i <= user; i++)
	{
		pater[i].id = i;
		pater[i].sum = 0;
		pater[i].flag = false;
		pater[i].prefect=0;
		memset(pater[i].score, -1, sizeof(pater[i].score));
	}
}

int main(){
	
	scanf("%d %d %d", &user, &problem, &sub);
	mem();
	
	for (int i = 1; i <= problem; i++)
	{
		scanf("%d",&maxpoint[i]);

	}
	int proid;
	int score;
	int id;
	for (int i = 0; i < sub; i++)
	{
		
		scanf("%d %d %d", &id, &proid, &score);
		
		
		if (score != -1)
		{
			pater[id].flag = true;
		}
		if (score == -1&&pater[id].score[proid]==-1)
		{
			pater[id].score[proid] = 0;
		}
		if (pater[id].score[proid] < maxpoint[proid]&&score==maxpoint[proid])   //第一次获得满分才可，不然可能有重复计数
		{
			pater[id].prefect = pater[id].prefect + 1;     //故该判断要在值更新之前 便于判断之前并不是满分，此时为第一次满分
		}
		if (pater[id].score[proid] < score)
		{

			pater[id].score[proid] = score;
		}

		            
	}
	for (int i = 1; i <=user; i++)
	{
		
			for (int j = 1; j <= problem; j++)
			{
				if (pater[i].score[j] != -1)
				{
					pater[i].sum += pater[i].score[j];
				}
				
			}
		
	}
	sort(pater+1, pater +user+1, cmp);
	int rank = 0;
	
	for (int i = 1; i <=user; i++)
	{
		
		if (pater[i].flag == true)
		{
			if (pater[i].sum == pater[i-1].sum&&i>1)
			{
				printf("%d ", rank);
				
				
			}
			else
			{
				printf("%d ", i);
				rank++;
			}
			
			printf("%05d", pater[i].id);
			printf(" %d", pater[i].sum);
			for (int j = 1; j <= problem; j++)
			{
				if (pater[i].score[j] >=0)
				{
					printf(" %d", pater[i].score[j]);
				}
				else printf(" -");
				
			}
			printf("\n");

		}
	
	}
	
	
	
}
	