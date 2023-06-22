#include<iostream>
using namespace std;

int t,n,g,w[1010],v[1010],dp[35],mw;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>v[i]>>w[i];
		for(int i=0; i<=30; ++i) dp[i]=0;
		for(int i=0; i<n; ++i) for(int j=30; j>=w[i]; --j) if(j>=w[i]) dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
		cin>>g;
		int sum=0;
		while(g--)
		{
			cin>>mw;
			sum+=dp[mw];
		}
		cout<<sum<<endl;
	}
	return 0;
}


// top down approach

/*#include<iostream>
#include<cstring>
using namespace std;

int t,n,g,mw,w[1010],v[1010],dp[1010][35];

int dfs(int idx, int rem)
{
	int &memo=dp[idx][rem];
	if(memo!=-1) return memo;
	if(idx==n) return memo=0;
	if(rem-w[idx]>=0) memo=max(dfs(idx+1,rem-w[idx])+v[idx], dfs(idx+1,rem));
	else memo=dfs(idx+1,rem);
	return memo;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>v[i]>>w[i];
		for(int i=0; i<=n; ++i) for(int j=0; j<=30; ++j) dp[i][j]=-1;
		cin>>g;
		int sum=0;
		while(g--)
		{
			cin>>mw;
			sum+=dfs(0,mw);
		}
		cout<<sum<<endl;
	}
	return 0;
}*/