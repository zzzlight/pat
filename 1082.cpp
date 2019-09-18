#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<string> out;
int main()
{
	string input;
	cin>>input;
	while(input[0]=='0') input.erase(input.begin());
	while(input[0]=='-'&&input[1]=='0') input.erase(input.begin()+1);
	string shuzi[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	string duyin[10] = {"*","Shi", "Bai", "Qian", "Wan","Shi", "Bai", "Qian","Yi"};
	string fu="Fu";
	int length;
	if(input[0]!='-') 
	{
		length=input.size();
	}
	else
	{
		length=input.size()-1;
	}
	for(int i=0;i<input.size();i++)
	{
		if(i==0&&input[i]=='-') out.push_back(fu);
		else 
		{
			if(input[i]!='0') 
			{
				out.push_back(shuzi[input[i]-'0']);
				if(input[0]=='-') out.push_back(duyin[length-i]);
				else out.push_back(duyin[length-1-i]);
			}
			else
			{
				if((input[i+1]!='0'&&i!=input.size()-1)||(i==input.size()-1&&input[i]!='0')) out.push_back(shuzi[input[i]-'0']);
				
				if(length>4) 
				{
					if(input[0]!='-')
					{
						if((length==9&&input[1]=='0'&&input[2]=='0'&&input[3]=='0'&&input[4]=='0')||(length==5&&input[0]=='0')||(length==6&&input[0]=='0'&&input[1]=='0')||(length==7&&input[0]=='0'&&input[1]=='0'&&input[2]=='0')||(length==8&&input[0]=='0'&&input[1]=='0'&&input[2]=='0'&&input[3]=='0'))
						{
						                      //万位全为0时不能有万 
						}
						else
						{
							if(duyin[length-1-i]=="Wan")out.push_back(duyin[length-1-i]);
						}	
					}
					else if(input[0]=='-')
					{
						if((length==9&&input[2]=='0'&&input[3]=='0'&&input[4]=='0'&&input[5]=='0')||(length==5&&input[1]=='0')||(length==6&&input[1]=='0'&&input[2]=='0')||(length==7&&input[1]=='0'&&input[2]=='0'&&input[3]=='0')||(length==8&&input[1]=='0'&&input[2]=='0'&&input[3]=='0'&&input[4]=='0'))
						{
						
						}
						else
						{
							if(input[0]=='-'&&duyin[length-i]=="Wan") out.push_back(duyin[length-i]);
						}
					}
				}
			
			}
		}
	}

	int temp=out.size();
	if(input.size()==0) cout<<"ling";
	else
	{
		if(out[temp-1]=="*") out.pop_back();   //注意个位给了个空格 
		for(int i=0;i<out.size();i++)
		{
			if(out[i]=="ling"&&out[i+1]=="Wan")
			{
				continue;  //万之前若有0不能是0万 
			}
			cout<<out[i];
			if(i!=out.size()-1) cout<<" ";
		}
	}
	
	
	
}
