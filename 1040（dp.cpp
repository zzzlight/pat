#include<stdio.h>
#include<string.h>

int dp[1005][1005];

int main()
{
	int max=1;
	char input[1005];
	char c;
	int t=0;
	while((c=getchar())!='\n')
	{
		if(c==' ') 
		{
		input[t]=' ';
		t++;
		}
		else
		{
			input[t]=c;
			t++;	
		}
		
	}
	int length=strlen(input);
	//chushihua
	for(int i=0;i<length;i++)
	{
		dp[i][i]=1;
		//ÆæÊý
		if(i<length-1)
		{
			if(input[i]==input[i+1])
			{
				dp[i][i+1]=1;
				max=2;   //Å¼Êý 
			}
		 } 
	}
	for(int i=3;i<=length;i++)
	{
		for(int j=0;(j+i-1)<length;j++)
		{
			int right=j+i-1;
			if(input[j]==input[right]&&dp[j+1][right-1]==1)
			{
				dp[j][right]=1;
				max=i;
			}
		}
	}
	printf("%d",max);
}
