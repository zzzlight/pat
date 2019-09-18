#include<iostream>
#include<string>

using namespace std;

bool judge(string t)
{
	bool reflag=false;
	int dotloca=-1;
	for(int i=0;i<t.size();i++)
	{
		if((t[i]>='0'&&t[i]<='9')||t[i]=='.'||t[i]=='-')
		{
			if(t[i]=='-'&&i!=0) return false;
		//	if(t[i]=='.'&&i==0) return false;      //.在最前数据例子中暂无 
			if(t[i]=='.'&&dotloca!=-1) return false;     //.在最后算对 故不要排除 
			if(t[i]=='.'&&dotloca==-1) dotloca=i;
			if(dotloca!=-1&&i>dotloca+2) return false;
		} 
		else
		{
		 	return false;
		}
	
	}
	return true;
}
double intonum(string t)
{
	double result=0;
	double fh=1.0;
	int start=0;
	int dotwz=-1;
	if(t[0]=='-')  
	{
		fh=-1.0;	
		start=1;
	}
	for(int i=start;i<t.size();i++)
	{
		if(t[i]=='.') dotwz=i;
	}

	if(dotwz!=-1)
	{
		for(int j=start;j<dotwz;j++)
		{
				int n=t[j]-'0';
				result=result*10;
				result+=n;
		}
		double temp=0;
		for(int j=t.size()-1;j>=dotwz+1;j--)
		{
			int n=t[j]-'0';
			temp+=n;
			temp=temp*0.1;
		}
		result+=temp;
	}
	else
	{
		for(int j=start;j<t.size();j++)
		{
			int n=t[j]-'0';
			result=result*10;
			result+=n;
		}
	}
	return (result*fh);
}
int main()
{
	int num;
	cin>>num;
	int count=0;
	double sum=0;
	for(int i=0;i<num;i++)
	{
		string temp;
		cin>>temp;
		bool flag=judge(temp);
		if(flag==false)
		{
			cout<<"ERROR: "<<temp<<" is not a legal number"<<endl;
		}
		else
		{
			double mynum=intonum(temp);
			if(mynum<=1000&&mynum>=-1000)
			{
				sum+=mynum;
				count++;
			}
			else
			{
				cout<<"ERROR: "<<temp<<" is not a legal number"<<endl;
			}
			
		}
	}
	double result=sum/count;
	if(count==0) printf("The average of 0 numbers is Undefined");
	else if(count==1) printf("The average of %d number is %.2f",count,result); //注意s 
	else printf("The average of %d numbers is %.2f",count,result);
 } 
