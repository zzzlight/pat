#include<stdio.h>
#include<string.h>


int main()
{
	int max=0;
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
	int begin=0;
	int endnum=strlen(input);
	for(int i=0;i<endnum;i++)
	{
		for(int j=endnum-1;j>i;j--)
		{
		
			if(input[i]==input[j])
			{
				int tempb=i;
				int tempe=j;
				if((j-i+1)>max)
				{
					while(tempb<=tempe)
					{
					
					if(input[tempb]==input[tempe])
					{
						tempb++;
						tempe--;
					}
					else break;	
					}
				}
				
				if(tempb>=tempe&&(j-i+1)>max) 
				{
					max=j-i+1;
				}
			}
		}
	}
	printf("%d",max);
}
