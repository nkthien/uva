#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#define sq(x) (x)*(x)

int t,n,k,x[105],y[105],p[105];
string c[105];
vector<pair<int,double>> g[105];
bool vis[105];

double distance(int a, int b)
{
	return sqrt(sq(x[a]-x[b]) + sq(y[a]-y[b]));
}

bool dfs(int u, int value)
{
	vis[u]=true;
	for(int i=0; i<g[u].size(); ++i)
	{
		int v=g[u][i].first;
		double w=g[u][i].second;
		if(w>value) continue;
		if(p[v]==-1 || (!vis[p[v]] && dfs(p[v],value)))
		{
			p[u]=v;
			p[v]=u;
			return true;
		}
	}
	return false;
}

int match(int value)
{
	for(int i=0; i<n; ++i) p[i]=-1;
	int cnt=0;
	for(int i=0; i<n; ++i) if(p[i]==-1)
	{
		for(int j=0; j<n; ++j) vis[j]=false;
		if(dfs(i,value)) cnt++;
	}
	return cnt;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int blue=0, red=0;
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<n; ++i)
		{
			cin>>x[i]>>y[i]>>c[i];
			if(c[i]=="blue") blue++;
			else red++;
		}
		if(min(blue,red)<k)
		{
			cout<<"Impossible\n";
			continue;
		}
		int lo=1e9, hi=0;
		for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j) if(c[i]!=c[j])
		{
			double d=distance(i,j);
			lo=min(lo,(int)d);
			hi=max(hi,(int)d);
			g[i].push_back({j,d});
			g[j].push_back({i,d});
		}
		lo-=1, hi+=1;
		while(lo<=hi)
		{
			int m=(lo+hi)/2;
			if(match(m)<k) lo=m+1;
			else hi=m-1;
		}
		cout<<lo<<endl;
	}
	return 0;
}