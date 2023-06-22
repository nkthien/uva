#include <iostream>
using namespace std;

const int INF=1000;

int n,m,s,t,res[105][105],vis[105];

int augpath(int so, int si, int mf)
{
	vis[so]=true;
	if(so == si) return mf;
	for(int i=0; i<n; ++i) if(!vis[i] && res[so][i] > 0)
	{
		int flow=augpath(i,si,min(mf, res[so][i]));
		if(flow > 0)
		{
			res[so][i] -= flow;
			res[i][so] += flow;
			return flow;
		}
	}
	return 0;
}

int maxflow(int so, int si)
{
	int ret=0;
	while(true)
	{
		for(int i=0; i<n; ++i) vis[i]=false;
		int flow=augpath(so,si,INF);
		if(flow == 0) return ret;
		ret+=flow;
	}
}

int main()
{
	int tc=1;
	while(cin>>n && n)
	{
		cin>>s>>t>>m;
		s--, t--;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) res[i][j]=0;
		while(m--)
		{
			int u,v,c;
			cin>>u>>v>>c;
			u--, v--;
			res[u][v]+=c;
			res[v][u]=res[u][v];
		}
		printf("Network %d\n", tc++);
		printf("The bandwidth is %d.\n\n", maxflow(s,t));
	}
	return 0;
}
