#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<int,int> ii;

int n;
ii a[105],b[105],origin;

void operator -= (ii &a, ii b)
{
	a.first -= b.first;
	a.second -= b.second;
}

bool ccw(ii o, ii a, ii b)
{
	a -= o;
	b -= o;
	return a.first*b.second > a.second*b.first;
}

bool cmp(ii a, ii b)
{
	return ccw(origin,a,b);
}

double area(ii *p, int sz)
{
	double res=0;
	for(int i=0; i<sz; ++i) res += p[i].first * p[i+1].second;
	for(int i=0; i<sz; ++i) res -= p[i].second * p[i+1].first;
	return fabs(res)/2;
}

int main()
{
	int tc=1;
	while(cin>>n && n)
	{
		for(int i=0; i<n; ++i) cin>>a[i].first>>a[i].second;
		a[n]=a[0];
		double tile=area(a,n);
		
		sort(a, a+n);	// graham scan
		origin=a[0];
		sort(a+1, a+n, cmp);
		int m=0;
		for(int i=0; i<n; ++i)
		{
			while(m > 1 && !ccw(b[m-2], b[m-1], a[i])) m--;
			b[m++]=a[i];
		}

		b[m]=b[0];
		double packer=area(b,m);
		double ans=(1 - tile/packer)*100;
		printf("Tile #%d\n", tc++);
		printf("Wasted Space = %.2lf %%\n\n", ans);
	}
	return 0;
}
