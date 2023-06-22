#include<iostream>
using namespace std;

int h,m,s,c;
char line[100];
int ansh,ansm,anss,ansc;

long num(char c) { return int(c-'0'); }

int main()
{
	double ratio=1e7/8640000;
	while(gets(line))
	{
		h=num(line[0])*10 + num(line[1]);
		m=num(line[2])*10 + num(line[3]);
		s=num(line[4])*10 + num(line[5]);
		c=num(line[6])*10 + num(line[7]);
		long long sum=0,cur=100*100*100;
		sum=h*3600*100 + m*60*100 + s*100 + c;
		double temp = (double)sum*ratio;
		sum=(long long)temp;
		ansh=sum/cur;
		sum%=cur;
		cur/=100;
		ansm=sum/cur;
		sum%=cur;
		cur/=100;
		anss=sum/cur;
		sum%=cur;
		cur/=100;
		ansc=sum;
		printf("%01d%02d%02d%02d\n",ansh,ansm,anss,ansc);
	}
	return 0;
}


// a shorter version using scanf, mult 10 to divide integer..cool!

/*#include<iostream>
using namespace std;

int h,m,s,c,sum;

int main()
{
	while(scanf("%2d%2d%2d%2d",&h,&m,&s,&c)==4)
	{
		sum=h*3600*1000 + m*60*1000 +s*1000 + c*10;
		h=sum/8640000;
		sum%=8640000;
		m=sum/86400;
		sum%=86400;
		s=sum/864;
		sum%=864;
		c=sum*100/864;
		printf("%01d%02d%02d%02d\n",h,m,s,c);
	}
	return 0;
}*/