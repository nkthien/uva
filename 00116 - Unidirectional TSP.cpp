#include<iostream>
using namespace std;

int n,m,a[15][105],dp[15][105],path[15][105];

int main()
{
	while(cin>>n>>m)
	{
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>a[i][j];
		for(int i=0; i<n; ++i) dp[i][m-1]=a[i][m-1];
		for(int j=m-2; j>=0; --j) for(int i=0; i<n; ++i)
		{
			int cur=2e9, save;
			for(int k=-1; k<=1; ++k)
			{
				int idx=(i+n+k)%n;
				int test=dp[idx][j+1];
				if(cur>test || (cur==test && idx<save))
				{
					cur=test;
					save=idx;
				}
			}
			dp[i][j]=cur+a[i][j];
			path[i][j]=save;
		}	
		int ans=2e9, x;
		for(int i=0; i<n; ++i) if(ans>dp[i][0]) ans=dp[i][0], x=i;
		cout<<x+1;
		for(int i=0; i<m-1; ++i)
		{
			x=path[x][i];
			cout<<" "<<x+1;
		}
		cout<<endl<<ans<<endl;	
	}
	return 0;
}