#include<cstdio>
#include<string.h>
struct bign
{
	int d[30];
	int len=0;
	bign()
	{
		memset(d,0,sizeof(d));
		}	
};
bign multi(bign a);
 int judge(bign a,bign b);
int main()
{
	
	bign num1;
    bign num2;
	char num[30];
	int j=0;
	int numlen;
	
	scanf("%s",num);
		
	num1.len=strlen(num);
	
	for(int i=num1.len-1;i>=0;i--)
	{
		num1.d[j]=num[i]-'0';
		j++;
	}
	num2=multi(num1);//乘2模块

	int judgemod=judge(num1,num2);	//比较模块
	if(judgemod)
	{
		printf("Yes\n");
	 }
	 else 
	 {
	 	printf("No\n");
	  } 
	  for(int k=num2.len-1;k>=0;k--)
	{
		printf("%d",num2.d[k]);
	}
 } 

bign multi(bign a)
 {
 	bign c;
 	int carry=0;
 	for(int i=0;i<a.len;i++)
 	{
 		int temp=a.d[i]*2+carry;
 		c.d[c.len++]=temp%10;
 		carry=temp/10;
 		
 		//a[i+1]=a[i+1]+carry;
	 }
	 while(carry!=0)
	 {
	 	c.d[c.len++]=carry%10;
	 	carry=carry/10;
	 }
	 
	 return c;
 }
 
 int judge(bign a,bign b)
 {
 	int flag[10];
 	memset(flag,-1,sizeof(flag));
 
	for(int j=0;j<a.len;j++)
	 {
	 	flag[a.d[j]]++;
	 }
	for(int i=0;i<b.len;i++)
 	{
 		flag[b.d[i]]--;	        //0到9数字表记录  若加加减减后还为初始值说明完全一样 
	 }
	int k;
 	for(k=0;k<10;k++)
 	{
 		if(flag[k]!=-1)
 		return 0;
 	
	 }
	if(k==10) return 1;
 }
 
 
 
