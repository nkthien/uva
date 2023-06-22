#include <iostream>
#include <math.h>
using namespace std;

#define sq(x) (x)*(x)

int n,x[20],y[20];
double dp[1 << 16];
string name;

double dis(int a, int b)
{
	return sqrt(sq(x[a]-x[b]) + sq(y[a]-y[b]));
}

double match(int mask)
{
	if(dp[mask] > -0.5) return dp[mask];
	if(mask == (1 << 2*n) - 1) return dp[mask]=0;
	double res=1e9;
	for(int i=0; i<2*n; ++i) if(!(mask & (1 << i)))
	{
		for(int j=i+1; j<2*n; ++j) if(!(mask & (1 << j)))
		{
			res=min(res, dis(i,j) + match(mask | (1 << i) | (1 << j)));
		}
		break;
	}
	return dp[mask]=res;
}

int main()
{
	int tc=1;
	while(cin>>n && n)
	{
		for(int i=0; i<2*n; ++i) cin>>name>>x[i]>>y[i];
		for(int i=0; i<(1 << 2*n); ++i) dp[i]=-1;
		printf("Case %d: %.2lf\n", tc++, match(0));
	}
	return 0;
}
