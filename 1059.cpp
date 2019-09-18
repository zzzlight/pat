#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	long int num;
	long int mynum;
	scanf("%ld",&num);
	mynum=num;
	int printout[1000];
	int j=0;
	int i=2;
	while(1)
	{
	
		if(i>sqrt(mynum)) break;
			if(num%i==0)
		{
			num=num/i;
			printout[j]=i;
			j++;
			i=2;
			continue;
		}
		i++;
	}
	
	sort(printout,printout+j);
/*	for(int k=0;k<j;k++)
	{
		printf("%d  ",printout[k]);	
	}*/
	int count=1;
	printf("%d=",mynum);
	for(int x=0;x<j;x++)
	{
		if(printout[x]==printout[x+1])
		{
			count++;
			continue;
		}
		if(count==1)
		{
			printf("%d",printout[x]);
		}
		if(count>1)
		{
			printf("%d^%d",printout[x],count);
			count=1;
		}
		if(x!=j-1)printf("*");
	}
	if(mynum==num) printf("%d",num);    //本身为质数时 
	
} 
