#include<iostream>
using namespace std;

double h,u,d,f;

int main()
{
	while(1)
	{
		cin>>h>>u>>d>>f;
		if(h==0) break;
		double nh=0,nu=u;
		f/=100;
		int day;
		bool ok;
		for(int i=1;; ++i)
		{
			nh += nu;
			if(nh > h)
			{ 
				ok=1;
				day=i;
				break;
			}
			nu -= u*f;
			if(nu<0) nu=0;
			nh -= d;
			if(nh < 0)
			{
				ok=0;
				day=i;
				break;
			}
		}
		if(ok) printf("success on day %d\n",day);
		else printf("failure on day %d\n",day);
	}
	return 0;
}