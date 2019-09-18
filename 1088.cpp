#include<stdio.h>
#include<math.h>

struct Num
{
	long long  fz=0;
	long long  fm=0;
	long long  num=0;
};
long long  gcd(long long x,long long y)
{
	if(y!=0)
	{
		return gcd(y,x%y);
	}
	else return x;
}
Num huajian(Num a)
{
	
	if(abs(a.fz)/abs(a.fm)>=1) 
	{
		a.num=a.fz/a.fm;
		a.fz=a.fz-a.num*a.fm;
	}
	long long  gcd1=gcd(a.fz,a.fm);
	if(gcd1!=0)
	{
		a.fz=a.fz/gcd1;
		a.fm=a.fm/gcd1;       //注意一下几种  两个都是负数  第一个负  第二个负  三种情况 
	}
	
	return a;
}
void coutnum(Num a)
{
	bool flaga=true;
	if(a.num<0||(a.num==0&&a.fz<0&&a.fm>0)||(a.fm<0&&a.fz>0)) flaga=false;
	if(a.fz<0) a.fz=a.fz*(-1);
	if(a.fm<0) a.fm=a.fm*(-1);
	if(a.num<0) a.num=a.num*(-1);       //千万不能用abs  abs返回为float  格式转换与longlong会出错 
	if(flaga==true) 
	{
		if(a.fz!=0)
		{
			
			if(a.num==0) printf("%lld/%lld",a.fz,a.fm);
	 		else printf("%lld %lld/%lld",a.num,a.fz,a.fm);
		}
		else
		{
			if(a.num==0) printf("%lld",a.num);
	 		else printf("%lld",a.num);
		}	
	 
	 }
	 else 
	 {
	 	if(a.fz!=0)
	 	{
	 	 
			
	 		if(a.num==0) 
			printf("(-%lld/%lld)",a.fz,a.fm);
	 		else printf("(-%lld %lld/%lld)",a.num,a.fz,a.fm);
		 }
		 else
		 {
		 	
		 	if(a.num==0) printf("0");
	 		else if(a.num<0) printf("(-%lld)",a.num);
	 		else printf("(-%lld)",a.num);
		 }
	 
	 }
}
void plus(Num a,Num b)
{

	Num newa=huajian(a);
	Num newb=huajian(b);
 	coutnum(newa);
	 printf(" + ");
	 coutnum(newb);
	 printf(" = ");
	 Num result;
	 Num tempa;
	 Num tempb;
	 Num tempresult;
	 tempa.fm=a.fm*b.fm;
	 tempa.fz=a.fz*b.fm;
	 tempb.fm=b.fm*a.fm;
	 tempb.fz=b.fz*a.fm;
	 tempresult.fz=tempa.fz+tempb.fz;
	 tempresult.fm=tempa.fm;
	 result=huajian(tempresult);
	 coutnum(result);
	 printf("\n");
}
void cut(Num a,Num b)
{
	
	Num newa=huajian(a);
	Num newb=huajian(b);
 	coutnum(newa);
	 printf(" - ");
	 coutnum(newb);
	 printf(" = ");
	 Num result;
	 Num tempa;
	 Num tempb;
	 Num tempresult;
	 int t=a.fm;
	 tempa.fm=a.fm*b.fm;
	 tempa.fz=a.fz*b.fm;
	 tempb.fm=b.fm*t;
	 tempb.fz=b.fz*t;
	 tempresult.fz=tempa.fz-tempb.fz;
	 tempresult.fm=tempa.fm;
	 result=huajian(tempresult);
	 coutnum(result);
	 printf("\n");
}
void mul(Num a,Num b)
{
	Num newa=huajian(a);
	Num newb=huajian(b);
 	coutnum(newa);
	 printf(" * ");
	 coutnum(newb);
	 printf(" = ");
	 Num result;
	 Num temp;
	 temp.fz=a.fz*b.fz;
	 temp.fm=a.fm*b.fm;
	 result=huajian(temp);
	 coutnum(result);
	 printf("\n");
}
void chu(Num a,Num b)
{
	Num newa=huajian(a);
	Num newb=huajian(b);
 	coutnum(newa);
	 printf(" / ");
	 coutnum(newb);
	 printf(" = ");
	 Num result;
	 Num temp;
	 if((newb.num==0&&newb.fz==0))
	 {
	 	printf("Inf");
	 }
	 else
	 {
	 	 temp.fz=a.fz*b.fm;
		 temp.fm=a.fm*b.fz;
	 	result=huajian(temp);
	 	coutnum(result);
	 }
	
}
int main()
{
	Num num1;
	Num num2;
	scanf("%lld/%lld",&num1.fz,&num1.fm);
	scanf("%lld/%lld",&num2.fz,&num2.fm);
	
    plus(num1,num2);
    cut(num1,num2);
	mul(num1,num2);
	chu(num1,num2);
	
	
 } 
