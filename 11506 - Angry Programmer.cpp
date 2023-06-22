#include <iostream>
#include <queue>
using namespace std;

const int INF=1e9;

int n,m,s,t,c[105][105],f[105][105],trace[105];

bool findpath()
{
	for(int i=1; i<=2*n; ++i) trace[i]=0;
	queue<int> qu;
	qu.push(s);
	trace[s]=-1;	// special value
	while(!qu.empty())
	{
		int u=qu.front(),v;
		qu.pop();
		for(v=1; v<=2*n; ++v) if(!trace[v] && c[u][v] > f[u][v])
		{
			trace[v]=u;
			if(v == t) return true;
			qu.push(v);
		}
	}
	return false;
}

void augment()
{
	int u,v,delta=INF;
	for(v=t; (u=trace[v]) != -1; v=u) delta=min(delta, c[u][v] - f[u][v]);
	for(v=t; (u=trace[v]) != -1; v=u)
	{
		f[u][v] += delta;
		f[v][u] -= delta;
	}
}

int solve()
{
	while(findpath()) augment();
	int res=0;
	for(int i=1; i<=2*n; ++i) if(f[s][i] > 0) res += f[s][i];
	return res;
}

int main()
{
	while(cin>>n>>m && n)
	{
		for(int i=1; i<=2*n; ++i) for(int j=1; j<=2*n; ++j) c[i][j]=f[i][j]=0;
		c[1][n+1]=c[n][2*n]=INF;
		for(int i=0; i<n-2; ++i)
		{
			int a,w;
			cin>>a>>w;
			c[a][a+n]=w;
		}
		while(m--)
		{
			int u,v,w;
			cin>>u>>v>>w;
			c[u+n][v]=w;
			c[v+n][u]=w;
		}
		s=1, t=2*n;
		cout<<solve()<<endl;
	}
	return 0;
}


// normal Ford-Fulkerson: slower than Edmond-Karp

/*#include <iostream>
using namespace std;

const int INF=1e9;

int n,m,res[105][105],vis[105];

int augpath(int so, int si, int mf)
{
	vis[so]=true;
	if(so == si) return mf;
	for(int i=0; i<2*n; ++i) if(!vis[i] && res[so][i] > 0)
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
	while(1)
	{
		for(int i=0; i<2*n; ++i) vis[i]=false;
		int flow=augpath(so,si,INF);
		if(flow == 0) break;
		ret+=flow;
	}
	return ret;
}

int main()
{
	while(cin>>n>>m && n)
	{
		for(int i=0; i<2*n; ++i) for(int j=0; j<2*n; ++j) res[i][j]=0;
		res[0][n]=res[n-1][2*n-1]=INF;
		for(int i=0; i<n-2; ++i)
		{
			int a,c;
			cin>>a>>c;
			a--;
			res[a][a+n]=c;
		}
		while(m--)
		{
			int u,v,c;
			cin>>u>>v>>c;
			u--, v--;
			res[u+n][v]=c;
			res[v+n][u]=c;
		}
		cout<<maxflow(0, 2*n-1)<<endl;
	}
	return 0;
}
*/
