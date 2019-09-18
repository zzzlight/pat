#include<stdio.h>
#include<string.h>

int main()
{
	int times;
	int number[102000];
	int map[10200];
	int mark=-1;
	memset(number,-1,sizeof(number));
	memset(map,0,sizeof(map)); 
	scanf("%d",&times);
	for(int i=0;i<times;i++)
	{
		scanf("%d",&number[i]);
		map[number[i]]++;
	}
	int j=0;
	while(number[j]!=-1)
	{
		if(map[number[j]]==1) 
		{
			mark=number[j];	
			break;	
		}
		j++;
		
	}
	if(mark!=-1)printf("%d",mark);
	else printf("None");
}
