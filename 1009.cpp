#include<stdio.h>


#define max 2010   //样例测试点有2个极点值在2000左右  开数组请保证大于 
#define maxn 110
 struct Poly{
 	int exp;
 	double coe;
 }poly[max]; 

int main(){
	double jieguo[max]={0};

	int num1=0;

	int num2=0;
	int count=0;
	int exp;
	double coe;

	//读入第一行 
	scanf("%d ",&num1);
	for(int i=0;i<num1;i++)
	{
		scanf("%d %lf",&poly[i].exp,&poly[i].coe);
	}

	//读入第二行
	scanf("%d",&num2);
	
	for(int j=0;j<num2;j++)
	{
		scanf("%d %lf",&exp,&coe);
		for(int p=0;p<num1;p++)
		{	
			jieguo[poly[p].exp+exp]+=poly[p].coe*coe;
		}
	
	}
	
	
		for(int m=0;m<max;m++){
			
			
			if(jieguo[m]!=0) count++;
			
		
		}
		printf("%d",count);
		for(int x=max-1;x>=0;x--)
		{
			if(jieguo[x]!=0)
			{
				printf(" %d %.1f",x,jieguo[x]);
			}
		 } 
	
	


	return 0;
}
