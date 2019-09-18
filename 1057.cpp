#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;
    //理解错误  理解为在栈中的排列顺序的中间
	//实际中位数指第n大的，不与栈中顺序相关的大小排列 
	//分块思想 
int block[501];
int table[100500]; 
int findposition(int position)
{
/*	int sum=0;
	int idx=0;
	while(sum+block[idx]<position)
	{
		sum+=block[idx];
		idx++;
	}
	int num=idx*200;
	while(sum+table[num]<position)
	{
		sum+=table[num++]; 
	}
	return num;*/
	
	int pos=0;
	int i=0;
	while(pos+block[i]<position)
	{
		pos+=block[i];
		i++;
	}
	int j;
	for(j=i*200;j<(i+1)*200;j++)
	{
		if(pos+table[j]<position)
		{
			pos+=table[j];
		}
		else break;
	}
	return j;
	
	
	
}
int main()
{
	int flag=0;
	int num;
	stack<int> st;
	vector<int> out;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		string temp;
		cin>>temp;
	
		if(temp=="Push")
		{
			int tempst;
			cin>>tempst;
			block[tempst/200]++;
			table[tempst]++;
			st.push(tempst);
		
		//	printf("%d---\n",st.top());
		}
		if(temp=="Pop"||temp=="PeekMedian")
		{
			if(st.empty())
			{
				out.push_back(-1);	
			}
			else
			{
				if(temp=="Pop")
				{
				 	int top=st.top();
				 	out.push_back(top);
				 	block[top/200]--;
				 	table[top]--;
				 	st.pop();
				}
				else
				{
					int n=st.size();
					int newa;
						if(n%2==1)
						{
							newa=(n+1)/2;
						}
						else
						{
							newa=n/2;
						}
					
					int x=findposition(newa);
					out.push_back(x);
					
				}
			}
		
		}
		
	}
	int j=0;
	for(;j<out.size()-1;j++)
	{
		if(out[j]==-1)
		{
			printf("Invalid\n");
		}
		else
		{
			printf("%d\n",out[j]);
		}
	}
	if(out[j]==-1)
	{
		printf("Invalid");
	}
	else
	{
		printf("%d",out[j]);
	}
 } 
