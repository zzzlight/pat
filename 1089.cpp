#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int num;
int initseq[105];
int initseq2[105];
int initseq3[105];
int insertseq[105];
int mergeseq[105];
int final[105]; 
int nextseq[105];
bool flag;
int cot=0;
int record;
void mergesort(int a[])
{
	int cut=2;
	for(int cut=2;cut<2*num;cut=cut*2)
	{
		for(int i=0;i<num;i+=cut)
		{
			if(i+cut<num)
			{
				sort(a+i,a+i+cut);	
			}
			else
			{
				sort(a+i,a+num);
			}
			
		}
		int j;
		for(j=0;j<num;j++)
		{
			if(a[j]!=final[j]) break;
		}
		if(flag==true&&cot==0)
		{
			for(int t=0;t<num;t++)
			{
				nextseq[t]=a[t];
			 } 
			cot=1;
		}
		if(j==num) 	flag=true;
	}

	
}
void insertsort(int a[])
{
	for(int i=1;i<num;i++)
	{
		sort(a,a+i);
		int t;
		for(t=0;t<num;t++)
		{
			if(a[t]!=final[t]) break;
		}
		if(t==num)  record=i+1;
	}
}
int main()
{

	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&initseq[i]);
		initseq2[i]=initseq[i];
		initseq3[i]=initseq[i];
		insertseq[i]=initseq[i];
		mergeseq[i]=initseq[i];
	}
	for(int i=0;i<num;i++)
	{
		scanf("%d",&final[i]);
	}
	mergesort(initseq);
	insertsort(initseq2);
	if(flag==true) 
	{
		printf("Merge Sort\n");
		for(int t=0;t<num;t++)
		{
			printf("%d",nextseq[t]);
			if(t!=num-1) printf(" ");
		}
	}
	else
	{
		printf("Insertion Sort\n");          //压根不是插入和归并  用快排模拟其思路即可 
		sort(initseq3,initseq3+record);
		for(int t=0;t<num;t++)
		{
			printf("%d",initseq3[t]);
			if(t!=num-1) printf(" ");
		}
	}
 } 
