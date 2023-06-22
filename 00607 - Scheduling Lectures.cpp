#include<iostream>
using namespace std;

const int INF=1e9;

int n,L,C,a[1010],dp[1010][1010],ans;

int cal(int x)
{
	if(x==0) return 0;
	if(x>0 && x<=10) return -C;
	return (x-10)*(x-10);
}

int main()
{
	int tc=0;
	while(cin>>n && n)
	{
		cin>>L>>C;
		for(int i=1; i<=n; ++i) cin>>a[i];
		for(int i=0; i<=n; ++i) for(int j=1; j<=n; ++j) dp[i][j]=INF;
		bool ok=false;
		for(int i=1; i<=n && !ok; ++i) for(int j=1; j<=n; ++j)
		{
			int sum=0;
			for(int k=j; k>=0; --k)
			{
				sum+=a[k];
				if(sum>L) break;
				if(dp[i-1][k-1]!=INF) dp[i][j]=min(dp[i][j], dp[i-1][k-1] + cal(L-sum));
			}
			if(j==n && dp[i][j]!=INF)
			{
				ans=i;
				ok=true;
			}
		}
		if(tc) cout<<endl;
		printf("Case %d:\n", ++tc);
		printf("Minimum number of lectures: %d\n", ans);
		printf("Total dissatisfaction index: %d\n", dp[ans][n]);
	}
	return 0;
}