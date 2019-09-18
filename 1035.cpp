#include<stdio.h>
#include<string.h>
struct password
{
	char a[50];
	char b[50];
	password()
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	 } 
	int flag=0;
}pw[4000];
int main()
{
	int num;


	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%s %s",pw[i].a,pw[i].b);
		int len=strlen(pw[i].b);
	
	for(int j=0;j<len;j++)
	{
		switch(pw[i].b[j])
		{
		case '1':{pw[i].b[j]='@'; pw[i].flag++; break;}
		case '0':{pw[i].b[j]='%';pw[i].flag++;break;}
		case 'l':{pw[i].b[j]='L';pw[i].flag++;break;}
		case 'O':{pw[i].b[j]='o';pw[i].flag++;break;}
		}	
	}
	}

	
	
	int sum=0;
	
	for(int i=0;i<num;i++)
	{
		if(pw[i].flag>0)
	{
		sum++;
	}
	}
	if(sum>0) printf("%d",sum);
	 for(int i=0;i<num;i++)
	 {
	 	if(pw[i].flag>0)
	 	{
	 		printf("\n%s %s",pw[i].a,pw[i].b);
		 }
	 }
	if(sum==0&&num>1) printf("There are %d accounts and no account is modified",num);
	if(sum==0&&num==1) printf("There is %d account and no account is modified",num);
 } 
