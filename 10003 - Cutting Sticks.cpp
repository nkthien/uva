#include<iostream>
using namespace std;

int s,n,a[55],dp[55][55];

int cut(int l, int r)
{
	if(l+1==r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	int cost=1e9;
	for(int i=l+1; i<r; ++i) cost=min(cost, cut(l,i) + cut(i,r) + (a[r]-a[l]));
	return dp[l][r]=cost;
}

int main()
{
	while(cin>>s && s)
	{
		cin>>n;
		for(int i=1; i<=n; ++i) cin>>a[i];
		a[++n]=s;
		for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) dp[i][j]=-1;
		int ans=cut(0,n);
		printf("The minimum cutting is %d.\n", ans);
	}
	return 0;
}


// bottom up approach, faster than top down (0.03s vs 0.17s) --> has to find all sol anyway + overhead of recursion

/*#include<iostream>
using namespace std;

int L,n,a[55],dp[55][55];

int main()
{
	while(cin>>L && L)
	{
		cin>>n;
		for(int i=1; i<=n; ++i) cin>>a[i];
		a[(++n)++]=L;
		for(int j=1; j<n; ++j) for(int i=j-1; i>=0; --i)
		{
			if(i+1==j) dp[i][j]=0;
			else
			{
				int cost=1e9;
				for(int k=i+1; k<j; ++k) cost=min(cost, dp[i][k]+dp[k][j]);
				dp[i][j]=cost+a[j]-a[i];
			}
		}
		printf("The minimum cutting is %d.\n", dp[0][n-1]);
	}
	return 0;
}*/