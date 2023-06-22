#include <iostream>
using namespace std;

const int INF=1e9;

int n,k,m,a[15][15][1005],dp[15][1005],tmp[1005];

int main()
{
	int tc=0;
	while(cin>>n>>k && n)
	{
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i != j)
		{
			cin>>m;
			for(int l=0; l<m; ++l) cin>>tmp[l];
			for(int l=0; l<k; ++l) a[i][j][l+1] = tmp[l%m];
		}
		for(int i=0; i<=n; ++i) for(int j=0; j<=k; ++j) dp[i][j]=INF;
		dp[1][0]=0;
		for(int l=1; l<=k; ++l) for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=n; ++j) if(i != j)
			{
				int cost=a[j][i][l];
				if(cost == 0) continue;
				dp[i][l]=min(dp[i][l], dp[j][l-1] + cost);
			}
		}
		printf("Scenario #%d\n", ++tc);
		if(dp[n][k] != INF) printf("The best flight costs %d.\n", dp[n][k]);
		else puts("No flight possible.");
		puts("");
	}
	return 0;
}
