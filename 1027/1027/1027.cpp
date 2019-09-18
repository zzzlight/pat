#include<stdio.h>

int main(){
	int a;
	int b;
	int c;
	int d[10];
	int num=0;
	int x[5];
	scanf("%d %d %d", &a, &b, &c);
	
		
		do{
			d[num++] = a % 13;
			a = a / 13;

		} while (a != 0);  //用do  使循环至少执行一次 num为1便于后面判断只有一位
		printf("#");
		for (int j = num-1; j >= 0; j--)
		{
			
			if (num == 1)
			{
				
				 printf("0");
			}


			if (d[j] < 10 && d[j] >= 0)
				printf("%d", d[j]);
			else{
				switch (d[j])
				{
				case 10:printf("A"); break;
				case 11:printf("B"); break;
				case 12:printf("C"); break;

				}
			}
		}
			num = 0;
			do{
				d[num++] = b % 13;
				b= b / 13;

			} while (b != 0);
		
			for (int j = num-1; j >= 0; j--)
			{
				
				if (num == 1)
				{
					
					 printf("0");
				}
				
				
				
				if (d[j] < 10 && d[j] >=0)
					printf("%d", d[j]);
				else{
					switch (d[j])
					{
					case 10:printf("A"); break;
					case 11:printf("B"); break;
					case 12:printf("C"); break;

					}
				}
			}
			num = 0;
			do{
				d[num++] = c % 13;
				c = c / 13;

			} while (c != 0);

			for (int j = num-1; j >= 0; j--)
			{
			
				if (num == 1)
				{
					
				 printf("0");
				}


				if (d[j] < 10 && d[j] >=0)
					printf("%d", d[j]);
				else{
					switch (d[j])
					{
					case 10:printf("A"); break;
					case 11:printf("B"); break;
					case 12:printf("C"); break;

					}
				}
			}
	
}