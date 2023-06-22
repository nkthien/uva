#include<iostream>
#include<unordered_map>
using namespace std;

int t,n,all[200100],parent[200100];
string a,b;

void initSet()
{
	for(int i=0; i<200000; ++i) parent[i]=i, all[i]=1;
}

int findSet(int u)
{
	if(u!=parent[u]) parent[u]=findSet(parent[u]);
	return parent[u];
}

void unionSet(int u, int v)
{
	int up=findSet(u);
	int vp=findSet(v);
	if(up==vp) return;
	parent[vp]=up;
	all[up]+=all[vp];
}

int main()
{
	cin>>t;
	while(t--)
	{
		int cnt=0;
		unordered_map<string,int> mp;
		initSet();
		cin>>n;
		while(n--)
		{
			cin>>a>>b;
			if(mp.count(a)==0) mp[a]=cnt++;
			if(mp.count(b)==0) mp[b]=cnt++;
			unionSet(mp[a],mp[b]);
			cout<<all[findSet(mp[a])]<<endl;
		}
	}
	return 0;
}