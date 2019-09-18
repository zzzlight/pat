#include<stdio.h>
#include<algorithm>

using namespace std;

int seq[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+num,cmp);
	int out=0;
	for(int i=0;i<num;i++)   //必须从0 这时能判断第一个是否满足 即out=1才能判断 
	{								//否则out则是从0  到了2  中间1时是否正确无法判断 
		if(seq[i]>i+1)
		{
			out=i+1;   //每次判断下一位的情况  若下一位不满足(不能等号 因为是more than ) 直接break  防止有重复数的判断错误 
		}else
		{
			break;
		}
		
	}
	
	printf("%d",out);
	
 } 
