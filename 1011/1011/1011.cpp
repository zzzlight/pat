#include<cstdio>
#include<algorithm>
using namespace std;
#define num 0.00001;
int main(){
	double first[5][5] = { 0 };
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			scanf("%lf", &first[j][i]);
		}

	}
	double w1 = 0;
	double w2 = 0;
	double	w3 = 0;
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	char result1;
	char result2;
	char result3;
		
	w1=max(max(first[0][0], first[0][1]),first[0][2]);
	w2 = max(max(first[1][0], first[1][1]), first[1][2]);
	w3 = max(max(first[2][0], first[2][1]), first[2][2]);
	
		for (int i = 0; i < 3; i++)
		{
			if (w1==first[0][i])a1 = i;
			if (w2==first[1][i])a2 = i;
			if (w3==first[2][i])a3 = i;

		}
		
		switch (a1)
		{
			case 0:result1 = 'W'; break;
			case 1:result1 = 'T'; break;
			case 2:result1 = 'L'; break;
		}
	
		switch (a2)
		{
		case 0:result2 = 'W'; break;
		case 1:result2 = 'T'; break;
		case 2:result2 = 'L'; break;
		}
		switch (a3)
		{
		case 0:result3 = 'W'; break;
		case 1:result3 = 'T'; break;
		case 2:result3 = 'L'; break;
		}
	
		double profit = (w1*w2*w3*0.65 - 1) * 2;
		printf("%c %c %c %.2f", result1, result2, result3, profit);

}