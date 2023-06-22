#include<iostream>
using namespace std;

int n,a[105],dp[105][105];

int main()
{
	while(cin>>n && n)
	{
		for(int i=1; i<=n; ++i)
		{
			cin>>a[i];
			a[i]+=a[i-1];
		}
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) dp[i][j]=0;
		for(int d=0; d<n; ++d) for(int i=1; i<=n-d; ++i)
		{
			int j=i+d;
			int best=-1e9;
			for(int k=i; k<=j; ++k)
			{
				best=max(best, a[k]-a[i-1]-dp[k+1][j]);
				best=max(best, a[j]-a[k-1]-dp[i][k-1]);
			}
			dp[i][j]=best;
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}


// top down approach, slower(0.02 vs 0.00 of bottom up approach)

/*#include<iostream>
using namespace std;

const int INF=1e9;

int n,a[105],dp[105][105];

int sum(int l, int r)
{
	return a[r]-a[l-1];
}

int dfs(int l, int r)
{
	if(l>r) return 0;
	if(l==r) return sum(l,r);
	int &res=dp[l][r];
	if(res) return res;
	res=-INF;
	for(int i=l; i<=r; ++i)
	{
		res=max(res, sum(l,i) - dfs(i+1,r));
		res=max(res, sum(i,r) - dfs(l,i-1));
	}
	return res;
}

int main()
{
	while(cin>>n && n)
	{
		for(int i=1; i<=n; ++i) 
		{
			cin>>a[i];
			a[i]+=a[i-1];
		}
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) dp[i][j]=0;
		cout<<dfs(1,n)<<endl;
	}
	return 0;
}*/