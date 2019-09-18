#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int numout[105];
string gewei[13]={"tret","jan","feb","mar","apr", "may","jun","jly","aug","sep","oct","nov","dec"};
string shiwei[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
bool flag[105];
int main()
{
	int num;
	string input;
	cin>>num;
	getchar();
	for(int i=0;i<num;i++)
	{
		getline(cin,input);
		if(input[0]>='0'&&input[0]<='9')
		{
			int ttempnum=0;
			int qqq=0;
			for(int qq=input.length()-1;qq>=0;qq--)
			{
				ttempnum+=(input[qq]-'0')*int(pow(10.0,qqq));
				qqq++;
			}
			numout[i]=ttempnum;
			flag[i]=true;
		}
		else
		{
			int ttemp=0;
			if(input.length()>3)
			{
				string temp1=input.substr(0,3);
				string temp2=input.substr(4,3);
				for(int i=0;i<13;i++)
				{
				if(temp2==gewei[i])
				{
					ttemp+=i;
				}
				}
				for(int i=0;i<13;i++)
				{
				if(temp1==shiwei[i])
				{
					ttemp+=i*13;
				}
				}
			}
			else
			{
				string temp1=input.substr(0,3);
				int a;
				for(a=0;a<13;a++)
				{
				if(temp1==gewei[a])
				{
					ttemp=a;
				}
				}
				if(a>12)                       //注意单个情况中 可能有13整倍数也为单个  此时数字转字母还是字母转数字都要注意 
				{
					for(int b=0;b<13;b++)
					{
						if(shiwei[b]==temp1) ttemp=b*13;
					}
				}
				
			}
			numout[i]=ttemp;
			flag[i]=false;
		}
	}
	for(int i=0;i<num;i++)
	{
		if(flag[i]==false)
		{
			cout<<numout[i];
		}
		else
		{
			if(numout[i]>13&&numout[i]%13!=0)
			{
				cout<<shiwei[numout[i]/13];
				cout<<" ";
			    cout<<gewei[numout[i]%13];
			}
			else if(numout[i]%13==0)
			{
				string outs=shiwei[numout[i]/13];
				cout<<outs;
			
			}
			else
			{
					cout<<gewei[numout[i]%13];
			}
		}
		if(i!=num-1) cout<<endl;
	}
	
}
