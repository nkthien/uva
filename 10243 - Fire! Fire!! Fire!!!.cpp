#include <iostream>
#include <vector>
using namespace std;

int n,m,dp[1006][2];
vector<int> g[1006];

void dfs(int u, int par)
{
	dp[u][0]=0;
	dp[u][1]=1;
	for(auto v : g[u]) if(v != par)
	{
		dfs(v,u);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][0], dp[v][1]);
	}
}

int main()
{
	while(cin>>n && n)
	{
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<n; ++i)
		{
			cin>>m;
			while(m--)
			{
				int tmp;
				cin>>tmp;
				tmp--;
				g[i].push_back(tmp);
			}
		}
		dfs(0,-1);
		int ans=min(dp[0][0], dp[0][1]);
		if(n == 1) ans=1;
		cout<<ans<<endl;
	}
	return 0;
}


// greedy approach gets AC too!!

/*#include <iostream>
#include <vector>
using namespace std;

int n,m,black[1006];
vector<int> g[1006];

void dfs(int u, int par)
{
	for(auto v : g[u]) if(v != par)
	{
		dfs(v,u);
		if(!black[v]) black[u]=true;	// greedy??
	}
}

int main()
{
	while(cin>>n && n)
	{
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<n; ++i)
		{
			cin>>m;
			while(m--)
			{
				int tmp;
				cin>>tmp;
				tmp--;
				g[i].push_back(tmp);
			}
		}
		for(int i=0; i<n; ++i) black[i]=false;
		dfs(0,-1);
		int ans=0;
		for(int i=0; i<n; ++i) if(black[i] == true) ans++;
		if(n == 1) ans=1;
		cout<<ans<<endl;
	}
	return 0;
}*/
