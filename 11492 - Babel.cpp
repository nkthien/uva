#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int n,cnt;
string start,dest,a,b,c;
vector<pair<int, pair<string,bool>>> graph[5050];

int dijkstra(int s, int t)
{
	priority_queue<pair<pair<int,char>, int>> pq;
	pq.push({{0,'#'}, s});
	while(pq.size())
	{
		int u=pq.top().second;
		int du=-pq.top().first.first;
		int lu=pq.top().first.second;
		pq.pop();
		if(u==t) return du;
		for(int i=0; i<graph[u].size(); ++i)
		{
			int v=graph[u][i].first;
			int uv=graph[u][i].second.first.length();
			char lv=graph[u][i].second.first[0];
			bool vis=graph[u][i].second.second;
			if(!vis && lu!=lv)
			{
				pq.push({{-(du+uv),lv}, v});
				graph[u][i].second.second=true;
			}
		}
	}
	return -1;
}

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		unordered_map<string,int> mp;
		cnt=0;
		cin>>start>>dest;
		for(int i=0; i<n; ++i)
		{
			cin>>a>>b>>c;
			if(mp.count(a)==0) mp[a]=cnt++;
			if(mp.count(b)==0) mp[b]=cnt++;
			int u=mp[a], v=mp[b];
			graph[u].push_back({v,{c,false}});
			graph[v].push_back({u,{c,false}});
		}
		if(mp.count(start)==0 || mp.count(dest)==0) cout<<"impossivel\n";
		else
		{
			int s=mp[start], t=mp[dest];
			int res=dijkstra(s,t);
			if(res==-1) cout<<"impossivel\n";
			else cout<<res<<endl;
		}
		for(int i=0; i<cnt; ++i) graph[i].clear();
	}
	return 0;
}