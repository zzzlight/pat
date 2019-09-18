#include<stdio.h>
#include<string.h>
int main()
{
	char first[80];
	char second[80];
	char third[80];
	char four[80];
	scanf("%s",first);
	scanf("%s",second);
	scanf("%s",third);
	scanf("%s",four);
	int min1=strlen(first);
	char common1;
	char common2;
	int common3;
	int firstflag;
	if(strlen(second)<strlen(first)) min1=strlen(second);
	for(int i=0;i<min1;i++)
	{
		if(first[i]==second[i]&&first[i]>='A'&&first[i]<='G')     //第一对是A到G   注意范围 否则点4报错 
		{														//下面范围同样注意 
			common1=first[i];
			firstflag=i;
			break;
		}
	}
	for(int i=firstflag+1;i<min1;i++)
	{
		if(first[i]==second[i])
		{
			if((first[i]>='A'&&first[i]<='N')||(first[i]>='0'&&first[i]<='9'))
			
			{
				common2=first[i];
				break;
			}
	
		
		}
	}
	int min2=strlen(third);
	if(strlen(four)<strlen(third))  min2=strlen(four);
	for(int j=0;j<min2;j++)
	{
		if(third[j]==four[j])
		{
			if((third[j]<='z'&&third[j]>='a')||(third[j]>='A'&&third[j]<='Z'))
			{
			common3=j;
			break;
			}
		
		}
	}
//	char time[5];
	int flag1=common1-'A'+1;
	int flag2;
	if(common2<='9'&&common2>='0')
	{
		flag2=common2-'0';
		
	}

	if(common2<='N'&&common2>='A')
	{
		flag2=common2-'A'+10;
	}
	int flag3=common3;
	switch (flag1)
	{

		case 1:{char time[5]="MON";	printf("%s %02d:%02d",time,flag2,flag3);break;}
		case 2:{char time[5]="TUE";	printf("%s %02d:%02d",time,flag2,flag3);break;}
		case 3:{char time[5]="WED";	printf("%s %02d:%02d",time,flag2,flag3);break;}
		case 4:{char time[5]="THU";	printf("%s %02d:%02d",time,flag2,flag3);break;}
		case 5:{char time[5]="FRI";	printf("%s %02d:%02d",time,flag2,flag3);break;}
		case 6:{char time[5]="SAT";	printf("%s %02d:%02d",time,flag2,flag3);break;}
		case 7:{char time[5]="SUN";	printf("%s %02d:%02d",time,flag2,flag3);break;}
	}	

 } 
