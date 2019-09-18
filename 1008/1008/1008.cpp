#include<stdio.h>


int main()
{
	int num;
	scanf("%d", &num);
	int elevator[10000];
	elevator[0] = 0;
	int time;
	time = num * 5;
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &elevator[i]);
		if (elevator[i] - elevator[i - 1] >= 0)
			time += (elevator[i] - elevator[i - 1]) * 6;
		else
			time += (elevator[i - 1] - elevator[i]) * 4;
	}

	printf("%d", time);
	return 0;
	
}