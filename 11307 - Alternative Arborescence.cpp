#include <iostream>
#include <vector>
using namespace std;

const int INF=1e9;

int n,dp[10005][10];
vector<int> g[10005];
string line;

void dfs(int u, int par)
{
	for(int i=1; i<=6; ++i) dp[u][i]=i;
	for(auto v : g[u]) if(v != par)
	{
		dfs(v,u);
		for(int i=1; i<=6; ++i)
		{
			int tmp=INF;
			for(int j=1; j<=6; ++j) if(i != j) tmp=min(tmp, dp[v][j]);
			dp[u][i] += tmp;
		}
	}
}

int main()
{
	while(cin>>n && n)
	{
		cin.get();
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<n; ++i)
		{
			getline(cin, line);
			int sz=line.size(), j=0, u=0;
			while(j < sz && line[j] >= '0' && line[j] <='9') u*=10, u+=line[j]-'0', j++;
			j+=2;
			while(j < sz)
			{
				int v=0;
				while(j < sz && line[j] >='0' && line[j] <= '9') v*=10, v+=line[j]-'0', j++;
				j+=1;
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		dfs(0,-1);
		int ans=INF;
		for(int i=1; i<=6; ++i) ans=min(ans, dp[0][i]);
		cout<<ans<<endl;
	}
	return 0;
}
