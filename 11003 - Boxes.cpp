#include<iostream>
#include<cstring>
using namespace std;

int n,w[1010],l[1010],dp[1010][6060];

int dfs(int idx, int rem)
{
	if(dp[idx][rem]!=-1) return dp[idx][rem];
	if(idx==n) return 0;
	// capacity always gets smaller in later turn!!!
	if(rem>=w[idx]) dp[idx][rem]=max(dfs(idx+1,min(rem-w[idx], l[idx]))+1, dfs(idx+1,rem));
	else dp[idx][rem]=dfs(idx+1,rem);
	return dp[idx][rem];
}
int main()
{
	while(cin>>n && n)
	{
		for(int i=0; i<n; ++i) cin>>w[i]>>l[i];
		memset(dp,-1,sizeof(dp));
		cout<<dfs(0,6000)<<endl;
	}
	return 0;
}