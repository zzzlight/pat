#include<stdio.h>



int main(){
	int num,exp;
	double coe[1010] = { 0 };
	double coe1[1010] = { 0 };
	
	
	
		scanf("%d ",&num);
		
		for (int j = 1; j <= num; j++)
		{
			
			if (j == num)
			{
				scanf("%d ", &exp);
				scanf("%lf \n", &coe[exp]);
				coe1[exp] += coe[exp];
			}
			else{
				scanf("%d ", &exp);
				scanf("%lf ", &coe[exp]);
				coe1[exp] += coe[exp];
			}
				
			
				
			
		}
		//****************输入第二行**********************
		
		scanf("%d ", &num);

		for (int j = 1; j <= num; j++)
		{

			if (j == num)
			{
				scanf("%d ", &exp);
				
				scanf("%lf", &coe[exp]);
				coe1[exp] += coe[exp];
			}
			else{
				scanf("%d ", &exp);
				scanf("%lf ", &coe[exp]);
				coe1[exp] += coe[exp];
			}




		}
		int sum = 0;
		for (int k = 0; k <=1000; k++)
		{
			if (coe1[k] >0.00000001 || coe1[k]<-0.00000001)
				 sum += 1;
				
			
		}
		printf("%d", sum);
	
		for (int n = 1000; n >=0; n--)
		{
			if (coe1[n] >0.00000001 || coe1[n]<-0.00000001)
			{
				
				printf(" %d %.1f", n, coe1[n]);
			

				
			}

			
		}

		
	
	
		return 0;


}