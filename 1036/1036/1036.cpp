#include<cstdio>
#include<algorithm>
using namespace std;
#define max 100
struct Student
{
	int score;
	char ID[15];
	char name[15];
	char gender;
}student[max];
bool cmp(Student a, Student b)
{
	return a.score > b.score;
}
int main(){


	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%s %c %s %d", &student[i].name, &student[i].gender, &student[i].ID, &student[i].score);


	}
	int male=-1;
	int female = -1;

	sort(student, student + num, cmp);
	for (int i = 0; i < num; i++)
	{
		if (student[i].gender == 'F')
		{
			printf("%s %s\n", student[i].name, student[i].ID);
			female = student[i].score;
			break;
		}
		 if(i==num-1)printf("Absent\n");
	}
	for (int i = (num - 1); i >= 0; i--)
	{
		if (student[i].gender == 'M')
		{
			printf("%s %s\n", student[i].name, student[i].ID);
			male = student[i].score;
			break;
		}
		if(i==0)  printf("Absent\n");
	}
	if (female != -1 && male != -1)
	{
		printf("%d", female - male);
	}
	else printf("NA");
	return 0;


}
