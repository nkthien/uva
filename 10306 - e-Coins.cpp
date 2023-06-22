#include<iostream>
using namespace std;

const int INF=1e9;

int t,m,s,x,y,dp[305][305];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>s;
		for(int i=0; i<=s; ++i) for(int j=0; j<=s; ++j) dp[i][j]=INF;
		dp[0][0]=0;
		while(m--)
		{
			cin>>x>>y;
			for(int i=x; i<=s; ++i) for(int j=y; j<=s; ++j) dp[i][j]=min(dp[i][j],dp[i-x][j-y]+1);			
		}
		int ans=INF;
		for(int i=0; i<=s; ++i) for(int j=0; j<=s; ++j) if(i*i+j*j==s*s) ans=min(ans,dp[i][j]);
		if(ans==INF) cout<<"not possible\n";
		else cout<<ans<<endl;	
	}
	return 0;
}