#include <iostream>
using namespace std;

int n,s,ne,k,a[105][105],dp[105][1005];

int main()
{
	while(cin>>n>>s>>ne>>k && n)
	{
		s--;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin>>a[i][j];
		for(int h=0; h<=k; ++h) for(int i=0; i<n; ++i) dp[i][h]=-1;
		dp[s][0]=0;
		for(int h=0; h<k; ++h) for(int i=0; i<n; ++i)
		{
			if(dp[i][h] == -1) continue;
			for(int j=0; j<n; ++j) if(i != j && a[i][j] != 0)
			{
				dp[j][h+1]=max(dp[j][h+1], dp[i][h] + a[i][j]);
			}
		}
		int ans=0;
		while(ne--)
		{
			int e; 
			cin>>e;
			e--;
			ans=max(ans, dp[e][k]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
