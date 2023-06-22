#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF=601; // 601 is enough

int n,nh,m,a[10005][10005],dis[10005],vis[10005];
vector<int> hotel;
vector<pair<int,int> > g[10005];

void dijkstra(int s)
{
	priority_queue<pair<int,int> > pq;
	pq.push({0,s});
	for(int i=0; i<n; ++i) dis[i]=INF;
	dis[s]=0;
	while(pq.size())
	{
		int u=pq.top().second;
		int du=-pq.top().first;
		pq.pop();

		if(du != dis[u]) continue;

		for(auto e : g[u])
		{
			int v=e.first, uv=e.second;
			if(dis[v] > du+uv)
			{
				dis[v]=du+uv;
				pq.push({-dis[v],v});
			}
		}
	}
}


int main()
{
	while(cin>>n && n)
	{
		hotel.clear();
		for(int i=0; i<n; ++i) g[i].clear();
		cin>>nh;
		hotel.push_back(0);
		hotel.push_back(n-1);
		for(int i=0; i<nh; ++i)
		{
			int tmp;
			cin>>tmp;
			tmp--;
			hotel.push_back(tmp);
		}
		cin>>m;
		while(m--)
		{
			int u,v,w;
			cin>>u>>v>>w;
			u--, v--;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}

		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) a[i][j]=0;
		for(auto h : hotel)
		{
			a[h][h]=0;
			dijkstra(h);
			for(int i=0; i<n; ++i) if(i != h && dis[i] <= 600) a[h][i]=1;
		}

		int ans=-1;
		queue<int> qu;
		qu.push(0);
		for(int i=0; i<n; ++i) vis[i]=0;
		vis[0]=1;
		while(qu.size()) // bfs
		{
			int u=qu.front();
			qu.pop();
			if(u == n-1)
			{
				ans=vis[u]-2; // start and end don't have hotels
				break;
			}	
			for(int v=0; v<n; ++v) if(a[u][v] && !vis[v] && v != u)
			{
				vis[v]=vis[u]+1;
				qu.push(v);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
