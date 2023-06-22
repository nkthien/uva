#include <iostream>
using namespace std;

int t,n,L,a[25],dp[5][1 << 20];

int check(int k, int mask, int sum)
{
	if(k == 3) return 1;
	if(sum == L) return check(k+1, mask, 0);
	if(dp[k][mask] != -1) return dp[k][mask];
	int ans=0;
	for(int i=0; i<n && !ans; ++i) if(!(mask & (1 << i)))
	{
		if(sum+a[i] <= L) ans |= check(k, mask | (1 << i), sum+a[i]);
	}
	return dp[k][mask]=ans;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>a[i];
		int sum=0;
		for(int i=0; i<n; ++i) sum+=a[i];
		if(sum%4 != 0) cout<<"no\n";
		else 
		{
			L=sum/4;
			for(int i=0; i<4; ++i) for(int j=0; j<(1 << n); ++j) dp[i][j]=-1;
			if(check(0,0,0)) cout<<"yes\n";
			else cout<<"no\n";	
		}
	}
	return 0;
}


// dfs approach, faster than dp -_-

/*#include <iostream>
#include <algorithm>
using namespace std;

int t,n,L,a[25];
bool vis[25];

int dfs(int k, int pos, int sum)
{
	if(k == 3) return 1; // if 3 edges are formed then it must be a square!
	for(int i=pos; i>=0; --i) if(!vis[i])
	{
		vis[i]=true;
		if(sum+a[i] < L)
		{
			if(dfs(k, i, sum+a[i])) return 1;	// nice trick to speed up: avoid revisit old symmetric state!!!
		} 
		else if(sum+a[i] == L) 
		{
			if(dfs(k+1, n-1, 0)) return 1;
		}
		vis[i]=false;
	}
	return 0;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sum=0;
		for(int i=0; i<n; ++i) cin>>a[i], sum+=a[i];
		if(sum%4 != 0) cout<<"no\n";
		else
		{
			L=sum/4;
			for(int i=0; i<n; ++i) vis[i]=false;
			sort(a, a+n);	// kinda speed up a little bit
			if(dfs(0, n-1, 0)) cout<<"yes\n";
			else cout<<"no\n";
		}
	}
	return 0;
}*/
