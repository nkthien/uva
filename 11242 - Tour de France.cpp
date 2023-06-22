#include<iostream>
#include<algorithm>
using namespace std;

int nf,nr,af[15],ar[15];
double res[150];

int main()
{
	while(cin>>nf>>nr, nf)
	{
		for(int i=0; i<nf; ++i) cin>>af[i];
		for(int i=0; i<nr; ++i) cin>>ar[i];
		int cnt=0;
		for(int i=0; i<nf; ++i) for(int j=0; j<nr; ++j) res[cnt++]=af[i]*1.0/ar[j];
		sort(res,res+cnt);
		double ans=0;
		for(int i=1; i<cnt; ++i) ans=max(ans,res[i]/res[i-1]);
		printf("%.2f\n",ans);	
	}
	return 0;
}