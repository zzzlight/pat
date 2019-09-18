#include<stdio.h>
#include<algorithm>
using namespace std;
struct Mooncake
{
	double type;
	double price=0;
	double eachprice=0;	
}mooncake[1500];

bool cmp(Mooncake a,Mooncake b)
{
	return b.eachprice<a.eachprice;
}
int main()
{
	
	int num;
	int amount;
	double profit=0.0;
	scanf("%d",&num);
	scanf("%d",&amount);
	for(int i=0;i<num;i++)
	{
		
		scanf("%lf",&mooncake[i].type);
	}
	for(int j=0;j<num;j++)
	{
		scanf("%lf",&mooncake[j].price);
		mooncake[j].eachprice=mooncake[j].price/mooncake[j].type;
	}
	sort(mooncake,mooncake+num,cmp);
	for(int i=0;i<num;i++)
	{
		if(amount==0) break;
		if(amount>0) 
		{
			if(amount>mooncake[i].type)
			{
				amount=amount-mooncake[i].type;
				profit+=mooncake[i].price;	
			}
			else
			{
				profit+=amount*mooncake[i].eachprice;
				amount=0;
			}
		}

		
	
	}
	printf("%0.2lf",profit);
 } 
