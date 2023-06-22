#include<iostream>
using namespace std;

const int INF=1e9;

int t,M,n,v[105],dp[20020];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>M>>n;
		int mx;
		cin>>v[0];
		mx=v[0];
		for(int i=1; i<n; ++i) cin>>v[i], mx=max(mx,v[i]);
		int upper_bound=M+mx;
		dp[0]=0;
		for(int i=1; i<=upper_bound; ++i) dp[i]=INF;
		for(int i=0; i<n; ++i) for(int m=upper_bound; m>0; --m) if(m>=v[i]) dp[m]=min(dp[m],dp[m-v[i]]+1);
		int pay=M;
		while(dp[pay]==INF) pay++;
		cout<<pay<<" "<<dp[pay]<<endl;
	}
	return 0;
}