#include<iostream>
using namespace std;

int tc,n,t,m,a[1000],dp[1000][200][200];

int main()
{
	cin>>tc;
	while(tc--)
	{
		cin>>n>>t>>m;
		cin>>a[1];
		for(int i=2; i<=n; ++i) scanf(", %d",a+i);
		
		for(int k=1; k<=m; ++k) 
		for(int j=0; j<=t; ++j)
		for(int i=1; i<=n; ++i) dp[i][j][k]=0;
		
		for(int k=1; k<=m; ++k)
		for(int j=0; j<=t; ++j)
		for(int i=1; i<=n; ++i)
		{
			// update base case = maximum of previous disk
			if(j==0) dp[i][j][k]=dp[i][t][k-1];
			// normal knapsack
			else if(j>=a[i]) dp[i][j][k]=max(dp[i-1][j][k], dp[i-1][j-a[i]][k] + 1);
			// maximum from previous disk or current max
			else if(j<a[i])  dp[i][j][k]=max(dp[i-1][j][k], dp[i][t][k-1]);
		}
		cout<<dp[n][t][m]<<endl;
		if(tc) cout<<endl;
	}
	return 0;
}