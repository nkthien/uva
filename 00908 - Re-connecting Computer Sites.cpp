#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int INF=1e9;

int n,u,v,w,k,m;
string line;
vector<pair<int,int>> graph[1000100];
int d[1000100];

int mst(int s)
{
	int sum=0;
	for(int i=0; i<n; ++i) d[i]=INF;
	d[s]=0;
	priority_queue<pair<int,int>> qu;
	qu.push({0,s});
	while(qu.size())
	{
		int u=qu.top().second, du=-qu.top().first;
		qu.pop();
		if(du!=d[u]) continue;
		sum+=du; d[u]=0;
		for(int i=0; i<graph[u].size(); ++i)
		{
			int v=graph[u][i].first, w=graph[u][i].second;
			if(d[v]>w)
			{
				d[v]=w;
				qu.push({-w,v});
			}
		}
	}
	return sum;
}

int main()
{
	while(1)
	{
		cin>>n;
		for(int i=0; i<n; ++i) graph[i].clear();
		int res1=0;
		for(int i=0; i<n-1; ++i)
		{
			cin>>u>>v>>w;
			res1+=w;
		}
		cin>>k;
		for(int i=0; i<k; ++i)
		{
			cin>>u>>v>>w; u--,v--;
			graph[u].push_back({v,w});
			graph[v].push_back({u,w});
		}
		cin>>m;
		for(int i=0; i<m; ++i)
		{
			cin>>u>>v>>w; u--,v--;
			graph[u].push_back({v,w});
			graph[v].push_back({u,w});
		}
		int res2=mst(0);
		cout<<res1<<endl<<res2<<endl;
		cin.get();
		if(getline(cin,line)) cout<<endl;
		else break;
	}
	return 0;
}