#include<stdio.h>
#include<algorithm>

using namespace std;


struct Station
{
	double price;
	double distance;
}station[505];
bool flag;   //final这个的下标也是范围内  start是当前位置 
int findminprice(int start,int final) //找出下一个的最近低于当前的 位置及价格 或者全大于时候找出第二小的站位置和价格 
{												 
	int ansid=0;
	int i;
	for(i=start+1;i<=final;i++)
	{
		if(station[i].price<station[start].price) 
		{
			return i;
		}
	}
	double secondmin=99999999;
	if(i==final+1)
	{
		for(int j=start+1;j<=final;j++)
		{
			if(station[j].price<secondmin) 
			{
				secondmin=station[j].price;
				ansid=j;
			}
		}
	 } 
	return ansid;
}
bool cmp(Station a,Station b)
{
	return a.distance<b.distance;
}
int main()
{
	bool mark=false; 
	double capacity;
	double distance;
	double price;
	int num;
	double nowcapacity=0;
	double nowdistance=0;
	double maxdistance;
	double cost=0;
	scanf("%lf %lf %lf %d",&capacity,&distance,&price,&num);
	for(int i=0;i<num;i++)
	{
		scanf("%lf",&station[i].price);
		scanf("%lf",&station[i].distance);
	}
	station[num].distance=distance;
	station[num].price=0;
	sort(station,station+num+1,cmp);
	num=num+1;
	if(station[0].distance!=0) 
	{
		printf("The maximum travel distance = 0.00");  
		mark=true;  //注意此处和最后要分开 否则是0.000.00了 
	}
	else
	{
		nowcapacity=0; 
		int nowstation=0;
		int maxreach=-1;
		while(1)
		{
			if(station[nowstation].distance==distance) break;
			int count=0;
			for(int x=nowstation+1;x<num;x++)
			{
				if(station[x].distance<=station[nowstation].distance+capacity*price) count++;
			}
			maxreach=nowstation+count;
			if(count==0) 
			{
				flag=true;
				maxdistance=station[nowstation].distance+capacity*price; 
				break;
			}
			int temp=findminprice(nowstation,maxreach);
			if(station[temp].price<station[nowstation].price)  //找得到低于当前的 
			{
				
				if(station[temp].distance<distance)   //判断是否到了最后点 
				{
					if(nowcapacity>(station[temp].distance-station[nowstation].distance)/price)
					{
						nowcapacity-=(station[temp].distance-station[nowstation].distance)/price;
						cost+=0;                
					}
					else
					{
						cost+=(station[temp].distance-nowcapacity*price-station[nowstation].distance)/price*station[nowstation].price;
						nowcapacity=0;          //cost是从nowstation点到下一个点的花费 注意：：：nowcapacity是到下一个点处时候的油量 
					}
				
					nowdistance=station[temp].distance;
					nowstation=temp;
				}
				else 
				{
					cost+=(station[temp].distance-nowcapacity*price-station[nowstation].distance)/price*station[nowstation].price;
					nowstation=temp;                            //到最后的点了 计算到终点的话费后 下次则直接判break 
				}
				
			}
			else //找不到低于当前的 
			{
				if(station[temp].distance<distance) 
				{
					if(nowcapacity>(station[temp].distance-station[nowstation].distance)/price)
					{
						cost+=(capacity-nowcapacity)*station[nowstation].price;
						nowcapacity=capacity-(station[temp].distance-station[nowstation].distance)/price;
					}
					else
					{
						cost+=(capacity-nowcapacity)*station[nowstation].price;
						nowcapacity=capacity-(station[temp].distance-station[nowstation].distance)/price;
					}
					
					nowstation=temp;
					nowdistance=station[temp].distance;	
				}
			
			
			}
			
		}
	}
	if(mark==false)
	{
			if(flag==true) printf("The maximum travel distance = %0.2lf",maxdistance);
		else
		{
			printf("%0.2lf",cost);
		}
	}

 } 
