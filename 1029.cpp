#include<stdio.h>
#include<algorithm>

using namespace std;

int seq1[200005];
short int seq2[200005];

int main()
{
	long long int num;
	long long int n;
	scanf("%lld",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&seq1[i]);
	
	 } 
	 sort(seq1,seq1+num);
	 scanf("%lld",&n);
	 long long int mid=(n+num-1)/2; 
	 long long int count=0;
	 for(int j=0;j<n;j++)
	 {
	 	scanf("%hd",&seq2[j]);
	 	
	  } 
	  sort(seq2,seq2+n);
	  seq2[n]=0x3fff;
	  seq1[num]=0x3fffff;
	  int wz1=0;
	  int wz2=0;
	  while(count!=mid)
	  {
		
			if(seq1[wz1]<seq2[wz2])
			{
				wz1++;
				count++;
			}
			else
			{
				wz2++;
				count++;
			}
		
	
	  	
	  	
		
	  }
	  int result;
	  if(seq1[wz1]<seq2[wz2]) result=seq1[wz1];
	  else result=seq2[wz2];
	
	  
	  
	  
	  printf("%d",result);
	  
}
