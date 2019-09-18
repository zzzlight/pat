#include<stdio.h>
#define max 100010

int main(){
	char zimu[max];
	int leftp[max]={0};
	int rightt=0;
	

	int num=0;

	scanf("%s",zimu);
	

	for(int i=0;i<max;i++)
	{
		if(i>0) leftp[i]=leftp[i-1];    //用数组保存左边部分p的个数，且若是该点不是P则数值不变，为p该点数值加一 
		if(zimu[i]=='P') 
		{
			 
			leftp[i]=leftp[i-1]+1;
		}
	
	}
	for(int j=max;j>=0;j--)				//从右往左遍历得在A右边T的数量，且将其与该A右边P数量相乘得到该处A的PAT数量。  并继续向左找下一个A。 
	{									//相当于一次遍历既当了寻找A用也用于寻找T，降低复杂度 
		if(zimu[j]=='T') 
		{
			rightt=rightt+1;
			
		}
		else if(zimu[j]=='A')
		num=(num+rightt*leftp[j])%1000000007;
	}



	printf("%d\n",num);
	
	return 0;
} 
