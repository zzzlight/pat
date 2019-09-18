#include<stdio.h>
#include<string.h>
struct bead
{
	char beads[1010];
	int flag[1010];
	bead()
	{
		memset(flag,0,sizeof(flag));
	}
};

int main()
{
	bead shop;
	bead eva;
	
	scanf("%s",shop.beads);
	scanf("%s",eva.beads);
	
	for(int j=0;j<strlen(eva.beads);j++)
	{
		for(int i=0;i<strlen(shop.beads);i++)
		{
			if(eva.beads[j]==shop.beads[i]&&shop.flag[i]!=1)
			{
				shop.flag[i]=1;
				break;
			}
		}
	}
	int count=0;

	for(int i=0;i<strlen(shop.beads);i++)
	{
		if(shop.flag[i]==1)
		{
			count++;
		}
		
	}
	
	if(count==strlen(eva.beads))
	{
		printf("Yes %d",strlen(shop.beads)-count);
	}
	else 
	{
		printf("No %d",strlen(eva.beads)-count);
	}
	
 } 
