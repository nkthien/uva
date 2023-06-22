#include<iostream>
#include<math.h>
using namespace std;

#define sq(x) (x)*(x)

int n,p[110],cnt[110];

struct Ring
{
	double x,y,r;
} a[110];

int findSet(int u)
{
	return u==p[u] ? u : p[u]=findSet(p[u]);
}

void unionSet(int u, int v)
{
	int pu=findSet(u);
	int pv=findSet(v);
	if(pu==pv) return;
	p[pu]=pv;
	cnt[pv]+=cnt[pu];
}

double distance(Ring a, Ring b)
{
	return sqrt(sq(a.x-b.x) + sq(a.y-b.y));
}

int main()
{
	while(1)
	{
		cin>>n;
		if(n==-1) break;
		for(int i=0; i<n; ++i) p[i]=i, cnt[i]=1;
		for(int i=0; i<n; ++i) cin>>a[i].x>>a[i].y>>a[i].r;
		for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j)
		{
			double d=distance(a[i],a[j]);
			double test1=abs(a[i].r-a[j].r);
			double test2=a[i].r+a[j].r;
			if(d>test1 && d<test2) unionSet(i,j);
		}
		int ans=0;
		for(int i=0; i<n; ++i) ans=max(ans,cnt[i]);
		printf("The largest component contains %d ring%s\n",ans,ans!=1 ? "s.":".");
	}
	return 0;
}