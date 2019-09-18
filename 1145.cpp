#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int seq[100010];
int sum=0;
bool isprime(int n)
{
	for(int i=2;i<=(int)sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int findprime(int n)
{
	if(n==2||n==1) return n;
	for(int t=n;t<100010;t++)
	{
		if(isprime(t)) return t;
	}
}
int main()
{
	int size;
	int insertnum;
	int cxnum;
	scanf("%d %d %d",&size,&insertnum,&cxnum);
	int nsize=findprime(size);
	for(int i=0;i<insertnum;i++)
	{
		int temp;
		scanf("%d",&temp);
		int j=0;
		while(seq[(temp+j*j)%nsize]!=0)
		{
			
			j++;
			if(j>=nsize) break;
		}
		if(j<=nsize-1)
		{
			int wz=(temp+j*j)%nsize;
			seq[wz]=temp;			
		}
		else
		{
			printf("%d cannot be inserted.\n",temp);
		 }
	}
	for(int i=0;i<cxnum;i++)
	{
		int temp;
		scanf("%d",&temp);
		int j=0;
		while(1)
		{
			if(seq[(temp+j*j)%nsize]==0||seq[(temp+j*j)%nsize]==temp) break;
			j++;
			if(j>=nsize) break;
		}
		if(j<=nsize-1) sum+=j+1;
		else sum+=nsize+1;
	}
	double output=1.0*sum/(1.0*cxnum);
	printf("%.1lf",output);
}
