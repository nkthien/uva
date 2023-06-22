#include<iostream>
#include<algorithm>
using namespace std;

int n,m,a[20],res[20];

int main()
{
	int tc=1;
	while(cin>>n>>m)
	{
		for(int i=0; i<2*n; ++i) a[i]=0;
		double sum=0;
		for(int i=0; i<m; ++i) cin>>a[i], sum+=a[i];
		sort(a,a+2*n);
		double avg=sum/n, ans=0;
		for(int i=0; i<n; ++i) ans+=abs(avg-a[i]-a[2*n-1-i]);
		printf("Set #%d\n",tc++);
		for(int i=0; i<n; ++i)
		{
			printf(" %d:",i);
			if(a[i]!=0) printf(" %d",a[i]);
			if(a[2*n-1-i]!=0) printf(" %d",a[2*n-i-1]);
			puts("");
		}
		printf("IMBALANCE = %.5f\n",ans);
		puts("");
	}
	return 0;
}