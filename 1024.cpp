#include<cstdio>
#include<string.h>

struct bign
{
	int d[500];
	int len=0;
	bign()
	{
		memset(d,0,sizeof(d));
		}	
};
bign add(bign a);
int judgehw(bign a);
int main()
{
	char num[500];
	bign num1;
	bign num2;
	
	int times;
	int judge=0;
	scanf("%s",num);
	scanf("%d",&times);
		
	num1.len=strlen(num);
	int j;
	for(int i=num1.len-1;i>=0;i--)
	{
		num1.d[j]=num[i]-'0';
		j++;
	}
	int k;
//	int flag=1;
	if(judgehw(num1))
	{
		for(int m=num1.len-1;m>=0;m--)
		{
			printf("%d",num1.d[m]);
		}
	printf("\n%d",0);
		
	}
	else
	{
		
	for(k=0;k<times;k++)
	{
	
		num1=add(num1);
	
		if(judgehw(num1)&&k<times)
		{
			for(int m=num1.len-1;m>=0;m--)
			{
				printf("%d",num1.d[m]);
			}
			printf("\n%d",k+1);
		//	flag=0;
			break;
		}
	}
  	if(k==times)
  	{
  		for(int m=num1.len-1;m>=0;m--)
			{
				printf("%d",num1.d[m]);
			}
  			printf("\n%d",times);
	  }
	}
}
int judgehw(bign a)
{
	for(int i=0;i<=a.len;i++)
	{
		if(a.d[i]!=a.d[a.len-1-i])
		return 0;
		
	}
	return 1;
	/*
	bign b;
	int alen=a.len-1;
	for(int i=0;i<a.len;i++)
	{
	b.d[alen--]=a.d[i];
	}
	for(int i=0;i<a.len;i++)
	{
		if(a.d[i]!=b.d[i])
		return 0;
		else return 1;
	}*/
}
bign add(bign a)
{
	bign c;
	bign b;
	int carry=0;
	int alen=a.len-1;
	for(int j=0;j<a.len;j++)
	{
		b.d[j]=a.d[alen--];
	}
	
	for(int i=0;i<a.len;i++)
	{
		int temp=b.d[i]+a.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
		
	}
	while(carry!=0)
	{
		c.d[c.len++]=carry%10;
		carry=carry/10;
	}
	return c;
}
