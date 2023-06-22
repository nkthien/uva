#include<iostream>
#include<vector>
using namespace std;

int t,w,n,d[35],v[35],dp[35][1010];

int main()
{
	bool first=true;
	while(cin>>t>>w)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>d[i]>>v[i];
		for(int i=0; i<=n; ++i) for(int j=0; j<=t; ++j) dp[i][j]=0;
		for(int i=1; i<=n; ++i) for(int j=t; j>=0; --j)
		{
			dp[i][j]=dp[i-1][j];
			int cost=3*w*d[i-1];
			if(j>=cost) dp[i][j]=max(dp[i][j], dp[i-1][j-cost]+v[i-1]);
		}
		if(!first) cout<<endl;
		else first=false;
		cout<<dp[n][t]<<endl;
		vector<int> res;
		int cur=t;
		for(int i=n; i>0; --i) if(dp[i][cur]!=dp[i-1][cur])
		{
			res.push_back(i-1);
			cur-=3*w*d[i-1];
		}
		cout<<res.size()<<endl;
		for(int i=res.size()-1; i>=0; --i) cout<<d[res[i]]<<" "<<v[res[i]]<<endl;
	}
	return 0;
}