#include<iostream>
#include<math.h>
using namespace std;

const double eps=1e-7;

int p,q,r,s,t,u;

double f(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double bisection(double l, double r)
{
	double m=(l+r)/2;
	if(abs(f(m))<=eps) return m;
	if(f(m)<0) return bisection(l,m);
	else return bisection(m,r);
}

int main()
{
	while(cin>>p>>q>>r>>s>>t>>u)
	{
		if(f(0)*f(1)>0) printf("No solution\n");
		else printf("%.4f\n",bisection(0,1));
	}
	return 0;
}