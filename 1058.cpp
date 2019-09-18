#include<stdio.h>

struct score
{
	int galleon;
	int sickle;
	int knut;
};
int main()
{
	score num1;
	score num2;
	scanf("%d.%d.%d",&num1.galleon,&num1.sickle,&num1.knut);
	scanf("%d.%d.%d",&num2.galleon,&num2.sickle,&num2.knut);
	score result;
	result.knut=(num1.knut+num2.knut)%29;
	int temp=(num1.knut+num2.knut)/29;
	result.sickle=(temp+num1.sickle+num2.sickle)%17;
	int temp2=(temp+num1.sickle+num2.sickle)/17;
	result.galleon=temp2+num1.galleon+num2.galleon;
	
	printf("%d.%d.%d",result.galleon,result.sickle,result.knut); 
	
 } 
