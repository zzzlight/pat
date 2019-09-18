#include<stdio.h>
#include<algorithm>
using namespace std;
struct Stationinfo
{
	double price;
	double loc;
	
}stationinfo[30010];

	Stationinfo findmin(Stationinfo nowsta);
	Stationinfo findsecondmin(Stationinfo nowsta);
	int station;
	double perdis;
	double capacity;
int main()
{

	double distance;
	

	scanf("%lf %lf %lf %d",&capacity,&distance,&perdis,&station);
	for(int i=0;i<station;i++)
	{
		scanf("%lf %lf",&stationinfo[i].price,&stationinfo[i].loc);
	}
		
	
	double sum=0;
	Stationinfo nowsta;
	nowsta.price=-1;
	int j;
	for(j=0;j<station;j++)
	{
		if(stationinfo[j].loc==0&&stationinfo[j].price>nowsta.price)
		{
			nowsta=stationinfo[j];
		}
		
	}
	if(j==station&&nowsta.price==-1) printf("The maximum travel distance = 0.00");
	/*  此处前无问题*/ 
	double nowgas=0;
//	stationinfo[station].loc=distance;
//	stationinfo[station].price=0;
/*	while(nowsta.loc!=1250)
	{
		Stationinfo minsta=findmin(nowsta);

	if(minsta.loc>nowsta.loc)     //策略一  后续有较小时 
	{
		Stationinfo secondmin=findsecondmin(minsta);
		if(nowgas>0)
		{
			
			sum+=(secondmin.loc-perdis*(nowgas-(minsta.loc-nowsta.loc)/perdis))*nowsta.price;
			
		}
		else
		{
			sum+=((minsta.loc-nowsta.loc)/perdis)*nowsta.price;
		}
	
		
		nowsta=minsta;
		nowgas=0;
	}
	if(minsta.loc==nowsta.loc)										//策略二 本个最小  后续找第二小 
	{
		
		sum+=(capacity-nowgas)*minsta.price;
		
		nowsta=findsecondmin(minsta);
		nowgas=capacity-(nowsta.loc-minsta.loc)/perdis;
	}
	}
	
	printf("%lf",sum);*/
}
Stationinfo findmin(Stationinfo nowsta)
{
	Stationinfo minsta=nowsta;
	for(int i=0;i<station;i++)
	{
		
		if((nowsta.loc+capacity*perdis)>stationinfo[i].loc&&nowsta.price>stationinfo[i].price)
		{
			minsta=stationinfo[i];
		}
		
		
	}
	return minsta;
}
Stationinfo findsecondmin(Stationinfo nowsta)
{
	Stationinfo min=nowsta;
	Stationinfo secondminsta;
	for(int i=0;i<station;i++)
	{
		if(stationinfo[i].price>min.price) 
		{
		secondminsta=stationinfo[i]; 
		break;
		}	
	}

	for(int i=0;i<station;i++)
	{
		
		if((nowsta.loc+capacity*perdis)>stationinfo[i].loc&&min.price<secondminsta.price&&secondminsta.price<stationinfo[i].price)
		{
			secondminsta=stationinfo[i];
		}
		
		
	}
	return secondminsta;
}
