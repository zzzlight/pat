#include<stdio.h>
#include<string.h>
struct person
{
	char id[20];
	char  intime[20];
	char  outtime[20];
}persons[1000];
int main()
{
	person minin;
	person maxout;
	int number;
	scanf("%d",&number);

	for(int i=0;i<number;i++)
	{
		scanf("%s %s %s",persons[i].id,persons[i].intime,persons[i].outtime);
		
	}
	minin=persons[0];
	maxout=persons[0];
	for(int j=0;j<number;j++)
	{
		if(strcmp(persons[j].intime,minin.intime)<0)
		minin=persons[j];
		
	}
		for(int j=0;j<number;j++)
	{
		if(strcmp(persons[j].outtime,maxout.outtime)>0)
		maxout=persons[j];
		
	}
	printf("%s %s",minin.id,maxout.id);
	
 } 
 
