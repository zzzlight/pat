#include<stdio.h>
#include<string.h>
bool hashmap[200] = {false};


int main()
{
	for (int i = 0; i < 200; i++)
	{
		hashmap[i] = false;
	}
	char str1[120];
	char str2[120];
	scanf("%s", &str1);
	scanf("%s", &str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1; i++)
	{
		char c1;
		char c2;
		int j;
		for (j = 0; j < len2; j++)
		{
			c1 = str1[i];
			c2 = str2[j];
			if (c1 >= 'a'&&c1 <= 'z')  { c1 = c1 - 32; }
			if (c2 >= 'a'&&c2 <= 'z')  { c2 = c2 - 32; }
			if (c1 == c2) {
				//hashmap[c1] = true;
				break;
			}
		}
		if (j == len2&&hashmap[c1] == false)
		{
			printf("%c", c1);
			//hashmap[c1] = true;
		}
		
	}
}