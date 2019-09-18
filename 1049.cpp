#include<stdio.h>
#include<math.h>

int main()
{
	int num;
	int count=0;
	scanf("%d",&num);
	int temp=num;
	int len=0;
	int left;
	int right;
	while(num!=0)
	{
		
		
		if(num%10==0)
		{
			left=num/10;
			count+=left*pow(10,len);
		}
		if(num%10==1)							//分为大于1 等于1和0 讨论 
		{										//固定某一位 判断其他位的变化次数。
												//大于1则算入在该位时10的次方次。等于0只算左边全部 各种变时该位固定为1；为1算入该一次 
			left=num/10;																					//并加上右侧的数（右侧变化n次由于此为1总数也加次数n） 
			right=(int(temp-left*pow(10,len))%int(pow(10,len)));
			count+=left*pow(10,len)+right+1;
		 } 
		 if(num%10>1)
		 {
		 	left=num/10;
		 	right=temp-left*pow(10,len);
		 	count+=(left+1)*pow(10,len);
		 }
		num=num/10;
		len++;
	}


	printf("%d",count);
	
 } 

