#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

char out[10010];
char in[10010];
char num[10000];
int elocation;
int potlocation;
int zflocation;
bool zf;
bool zf2;
int main()
{
	cin>>in;
	int length=strlen(in);	
	if(in[0]=='-')  zf=false;
	else zf=true;
	int i;
	int t=0;
	for(i=1;i<length;i++)
	{
			if(in[i]=='.') 
			{
				potlocation=i;
				continue;
			}
			if(in[i]=='E') 
			{
				elocation=i;
				continue;
			}
			if(in[i]=='+'||in[i]=='-')  
			{
				zflocation=i;
				if(in[i]=='+') zf2=true;
				else zf2=false;
				break;
			}
			num[t]=in[i];
		//	cout<<num[t]<<endl;
			t++;
 	}
 	int lengthnum=t;
 	
 	int exp=0;
 	int tt=0;
 	for(int j=length-1;j>i;j--)
 	{
 		exp+=(in[j]-'0')*pow(10,tt);
 		tt++;
	 }
	 //cout<<exp;
 	if(zf==false)  cout<<'-';
 	int yy=0;
 	int zy=0;
 	if(zf2==true)  
	 {
	 	yy=exp-(elocation-potlocation-1);
	 	if(yy>0)
	 	{
	 		cout<<num;
	 		for(int q=yy;q>0;q--)
	 		{
	 			cout<<'0';
			 }
		 }
		 else
		 {
		 	int q;
		 	for(q=0;q<lengthnum+yy;q++)
		 	{
		 		cout<<num[q];
			 }
			 if(q<lengthnum) cout<<'.';
			for(;q<lengthnum;q++)
			{
				cout<<num[q];
			}
		 }
	 }
 	if(zf2==false) 
	 {
	 	zy=exp-(potlocation-1);
	 	if(zy>=0)
	 	{
	 		cout<<'0';
	 		cout<<'.';
		 for(int i=0;i<abs(zy);i++)
		 {
		 	cout<<'0';
		 }
		 cout<<num;
		 }
		 else
		 {
		 	int newzy=abs(zy);
		 	int qq;
		 	for(qq=0;qq<newzy;qq++)
		 	{
		 		cout<<num[qq];
			 }
			 cout<<'.';
			 for(;qq<lengthnum;qq++)
			 {
			 	cout<<num[qq];
			 }
		 }
    	}
 	
 } 
