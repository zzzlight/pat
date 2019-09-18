#include<stdio.h>

#include<string.h>


bool amap[10001];
int main()
{
		char orgin[100050];
		char sub[100050];
		fgets(orgin,100050,stdin);      //fgets   会包含最后输入结束时候的换行符 
		fgets(sub,100050,stdin);
		for(int j=0;j<strlen(sub);j++)     //此处strlen-1处的换行不影响 因为判断时候删除了  而且本题输入的不会含换行 
		{
			amap[sub[j]]=true;	
		}
		for(int i=0;i<strlen(orgin);i++)
		{
			if(amap[orgin[i]]==false) printf("%c",orgin[i]);
		}
		 
		
		
} 
/*
fgets(...)读入文本行时的两种情况。

 1.如果n大于一行的字符串长度，那么当读到字符串末尾的换行符时，fgets(..)会返回。并且在s的最后插入字符串结束标志'\0'。 而s缓冲区剩余的位置不会再填充。

example：

 123abc

fgets(s,10,fp);

此时，读入七个字符，123abc\n,实际上还有最后的'\0',所以，strlen(s)=7; 如果要去除末尾的\n，s[strlen(s)-1]='\0';便可。

2.如果n小于等于一行的字符串的长度，那么读入n-1个字符，此时并没有读入\n因为并没有到行尾 ，同样在最后会插入'\0'.

 example:
 123abc

 char s[5];

fgets(s,5,fp);

这时读入4个字符，123a,并没有换行符，所以strlen(s)=4.
--------------------- 

*/ 
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
		string orgin;
		vector<char> t;
		string tt;
		getline(cin,orgin);
		
	//	cout<<orgin<<endl;
		getline(cin,tt);
		
		for(auto it1=orgin.begin();it1!=orgin.end()-1;it1++)
		{
			for(auto it2=tt.begin();it2!=tt.end();it2++)
			{
				if((*it1)==(*it2))
				{
					orgin.erase(it1);
				}
			}
		}    //11112222   输入1  或者2  会出现
		
		cout<<orgin;
		
} */
