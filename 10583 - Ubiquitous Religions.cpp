#include<iostream>
using namespace std;

int n,m,p[50050],u,v,ans;

int findSet(int u)
{
	return u==p[u] ? u : p[u]=findSet(p[u]);
}

void unionSet(int u, int v)
{
	int up=findSet(u);
	int vp=findSet(v);
	if(up==vp) return;
	ans--;
	p[findSet(u)]=findSet(v);
}

int main()
{
	int tc=1;
	while(1)
	{
		cin>>n>>m;
		if(n==0) break;
		for(int i=0; i<n; ++i) p[i]=i;
		ans=n;
		while(m--)
		{
			cin>>u>>v; u--,v--;
			unionSet(u,v);
		}
		// for(int i=0; i<n; ++i) if(p[i]==i) ans++;  // no need
		printf("Case %d: %d\n",tc++,ans);
	}
	return 0;
}