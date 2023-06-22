#include <iostream>
#include <vector>
using namespace std;

int n,m,s,t,k,dp[105][205];
vector<int> g[105];

int main()
{
	while(cin>>n>>m && n)
	{
		for(int i=0; i<n; ++i) g[i].clear();
		while(m--)
		{
			int u,v; 
			cin>>u>>v;
			u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cin>>s>>t>>k;
		s--, t--;
		for(int h=0; h<=k; ++h) for(int i=0; i<n; ++i) dp[i][h]=0;
		dp[s][0]=1;
		for(int h=0; h<k; ++h) for(int u=0; u<n; ++u)
		{
			for(unsigned int i=0; i<g[u].size(); ++i)
			{
				int v=g[u][i];
				dp[v][h+1]|=dp[u][h];
			}
		}
		if(dp[t][k]) cout<<"Yes, Teobaldo can travel.\n";
		else cout<<"No, Teobaldo can not travel.\n";
	}
	return 0;
}
