#include<iostream>
#include<unordered_map>
using namespace std;

const int N=35,INF=1e9;

int m,p,q,dis[35][35];

int main()
{
	int tc=1;
	while(1)
	{
		cin>>m;
		if(m==0) break;
		unordered_map<int,int> mp;
		int n=0;
		for(int i=0; i<30; ++i) for(int j=0; j<30; ++j) dis[i][j]=INF;
		for(int i=0; i<30; ++i) dis[i][i]=0;
		for(int i=0; i<m; ++i)
		{
			cin>>p>>q;
			if(mp.count(p)==0) mp[p]=n++;
			if(mp.count(q)==0) mp[q]=n++;
			if(p!=q) dis[mp[p]][mp[q]]=dis[mp[q]][mp[p]]=1;
		}
		for(int k=0; k<n; k++) 
			for(int i=0; i<n; ++i)
				for(int j=0; j<n; ++j)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		while(1)
		{
			cin>>p>>q;
			if(p==0 && q==0) break;
			if(mp.count(p)==0) mp[p]=n++;
			int ans=0;
			for(int i=0; i<n; ++i) if(dis[mp[p]][i]>q) ans++;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc++,ans,p,q);
		}
	}
	return 0;
}


// queue way, much slower
/*
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

int n,p,q;

int main()
{
	int tc=1;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		unordered_map<int,vector<int>> graph;
		for(int i=0; i<n; ++i)
		{
			cin>>p>>q;
			graph[p].push_back(q);
			graph[q].push_back(p);
		}
		while(1)
		{
			cin>>p>>q;
			if(p==0 && q==0) break;
			unordered_map<int,int> dis;
			dis[p]=0;
			queue<int> qu;
			qu.push(p);
			while(!qu.empty())
			{
				int u=qu.front();
				qu.pop();
				for(int i=0; i<graph[u].size(); ++i)
				{
					int v=graph[u][i];
					if(dis.count(v)==0)
					{
						qu.push(v);
						dis[v]=dis[u]+1;
					}
				}
			}
			int ans=0;
			for(auto i : graph) if(dis.count(i.first)==0 || dis[i.first]>q) ans++;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc++,ans,p,q);
		}
	}
	return 0;
}
*/
