#include<stdio.h>
#include<algorithm>

using namespace std;

int seq[10005];
bool seqbool[105][105];
int out[105][105];

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+num,cmp);
	int min=num;
	int m=num;
	int n=1;
	for(int i=1;i<=num;i++)  //i为行 
	{
		if(num%i==0)
		{
			int j=num/i;
			if(i>=j&&((i-j)<=min))
			{
				m=i;
				n=j;
				min=i-j;
			}
		}
	}
	int tempm=0;
	int tempn=0;
	int i=0;
	int prority=1;
	while(1)
	{
		if(seqbool[tempm][tempn]!=true)
		{
			out[tempm][tempn]=seq[i];
			i++;
			seqbool[tempm][tempn]=true;
		
		}
		else
		{
			
			if(tempn!=n-1&&seqbool[tempm][tempn+1]==false) 
			{
				if(prority!=1)
				{
					if(prority==2)
					{
						if(tempm!=m-1&&seqbool[tempm+1][tempn]==false) 
						{
							tempm++;
							prority==2;
						}
						else
						{
						tempn++;
						prority=1;
						}
					}
					if(prority==3)
					{
						if(tempn!=0&&seqbool[tempm][tempn-1]==false) 
						{
							tempn--;
							prority=3;
						}
						else
						{
						tempn++;
						prority=1;
						}
					}
					if(prority==4)
					{
						if(tempm!=0&&seqbool[tempm-1][tempn]==false)
						{
							tempm--;
							prority=4;
						}
						else
						{
							tempn++;
							prority=1;
						}
					}
				}
				else
				{
					tempn++;
					prority=1;
				}
			
			}
			else if(tempm!=m-1&&seqbool[tempm+1][tempn]==false)
			{
					if(prority!=2)
				{
					if(prority==1)
					{
						if(tempn!=n-1&&seqbool[tempm][tempn+1]==false) 
						{
								tempn++;
								prority=1;
						}
						else
						{
								tempm++;
								prority=2;
						}
					}
					if(prority==3)
					{
						if(tempn!=0&&seqbool[tempm][tempn-1]==false) 
						{
							tempn--;
							prority=3;
						}
						else
						{
							tempm++;
							prority=2;
						}
					}
					if(prority==4)
					{
						if(tempm!=0&&seqbool[tempm-1][tempn]==false)
						{
							tempm--;
							prority=4;
						}
						else
						{
							tempm++;
							prority=2;
						}
					}
				}
				else
				{
					tempm++;
				prority=2;
				}
				
			}
			else if(tempn!=0&&seqbool[tempm][tempn-1]==false)
			{
					if(prority!=3)
				{
					if(prority==1)
					{
						if(tempn!=n-1&&seqbool[tempm][tempn+1]==false) 
						{
								tempn++;
								prority=1;
						}
						else
						{
								tempn--;
								prority=3;
						}
					}
					if(prority==2)
					{
						if(tempm!=m-1&&seqbool[tempm+1][tempn]==false) 
						{
							tempm++;
							prority=2;
						}
						else
						{
							tempn--;
							prority=3;
						}
					}
					if(prority==4)
					{
						if(tempm!=0&&seqbool[tempm-1][tempn]==false)
						{
							tempm--;
							prority=4;
						}
						else
						{
								tempn--;
								prority=3;
						}
					}
				}
				else
				{
					
						tempn--;
						prority=3;
				}
			
				
			}
			else if(tempm!=0&&seqbool[tempm-1][tempn]==false)
			{
				
				tempm--;
				prority=4;
			}
			
		
		}
		if(i==num) break;
	}
	for(int t=0;t<m;t++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d",out[t][j]);
			if(j!=n-1) printf(" ");
		}
		if(t!=m-1) printf("\n");
	}
}
//第四个优先级最低了 不用再判断  实际上本题的样例写前两优先级的判断即可ac 
