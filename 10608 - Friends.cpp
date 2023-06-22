#include<iostream>
using namespace std;

int t,n,m,p[30030],cnt[30030],u,v;

void initSet()
{
	for(int i=0; i<n; ++i) p[i]=i, cnt[i]=1;
}

int findSet(int u)
{
	return u==p[u] ? u : p[u]=findSet(p[u]);
}

void unionSet(int u, int v)
{
	int up=findSet(u);
	int vp=findSet(v);
	if(up==vp) return;
	cnt[vp]+=cnt[up];
	p[up]=vp;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		initSet();
		while(m--)
		{
			cin>>u>>v; u--,v--;
			unionSet(u,v);
		}
		int mx=0;
		for(int i=0; i<n; ++i) mx=max(mx,cnt[i]);
		cout<<mx<<endl;
	}
	return 0;
}