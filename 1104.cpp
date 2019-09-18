#include<stdio.h>

double seq[100005];
int count[100005];

int main()
{
	double sum=0;
	long long  num;
	scanf("%lld",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lf",&seq[i]);
		sum+=(i+1)*(num-i)*seq[i];   //i+1与num-i若用int乘法的结果会超过上限 用longlong会转换成longlong
		//或者sum+=(double)(i+1)*(double)(num-i)*seq[i];  则可以用int 
	 } 

	 printf("%.2f",sum);
 } 
 //int 会超过int范围 用longlong 
