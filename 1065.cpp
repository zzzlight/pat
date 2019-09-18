#include<stdio.h>
 
 int main(){
 	int num;
 	long long a,b,c=0;
 	long long sum=0;
 	int result[15]={0};
 	scanf("%d",&num);
 	for(int i=1;i<=num;i++)
	 {
 		
 		scanf("%lld %lld %lld",&a,&b,&c);
 		sum=a+b;
		 
		 
		 if (sum>c)
		 {
		 	if(a<0&&b<0&&sum>=0)
		 	{
		 	result[i]=0;
		 
		 	}else result[i]=1;
		 	
		 
		 }
		 else if(sum<=c)
		 {
		 	if(a>0&&b>0&&sum<=0)
		 	{
		 	result[i]=1;
		 
		 	}else result[i]=0;
		 
		 }
		 
	 }
	 for(int j=1;j<=num;j++)
	 {
	 	if(result[j]==0)
		 printf("Case #%d: false\n",j);
 		else if(result[j]==1)
		 printf("Case #%d: true\n",j);
	 }
	   
	
 } 
