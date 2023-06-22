#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

#define sq(x) (x)*(x)

int t,s,n,p[550],a[550],x,y;
vector<pair<int,int>> coor;
vector<pair<double,pair<int,int>>> edge;
vector<double> dis;

int findSet(int u) { return u==p[u] ? u : p[u]=findSet(p[u]); }
void unionSet(int u, int v) { p[findSet(u)]=findSet(v); }

void init()
{
	coor.clear();
	edge.clear();
	dis.clear();
	for(int i=0; i<n; ++i) p[i]=i;
}

void kruskal()
{
	sort(edge.begin(), edge.end());
	int i=0;
	while(dis.size()!=n-1)
	{
		int up=findSet(edge[i].second.first);
		int vp=findSet(edge[i].second.second);
		if(up!=vp)
		{
			dis.push_back(edge[i].first);
			unionSet(up,vp);
		}
		i++;
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s>>n;
		init();
		for(int i=0; i<n; ++i)
		{
			cin>>x>>y;
			coor.push_back({x,y});
		}
		for(int i=0; i<n; ++i)
		{
			for(int j=i+1; j<n; ++j)
			{
				double d=sqrt(sq(coor[i].first-coor[j].first) + sq(coor[i].second-coor[j].second));
				edge.push_back({d,{i,j}});
			}
		}
		kruskal();
		// sort(dis.begin(), dis.end()); // no need to sort, already in increasing order
		printf("%.2f\n",dis[n-1-s]);
	}
	return 0;
}


// binary search way

/*#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

#define sq(x) (x)*(x)

const double eps=1e-6;

int t,s,n,pr[550],x[550],y[550];

int find(int u) { return u==pr[u] ? u : u=find(pr[u]); }
void join(int u, int v) { pr[find(u)]=find(v); }

struct Edge
{
	int u,v;
	double w;
};
vector<Edge> edges;

bool cmp(Edge a, Edge b)
{
	return a.w<b.w;
}

double distance(int a, int b)
{
	return sqrt(sq(x[a]-x[b]) + sq(y[a]-y[b]));
}

int kruskal(double d)
{
	for(int i=0; i<n; ++i) pr[i]=i;
	for(Edge e:edges)
	{
		if(e.w>d) break;
		int pu=find(e.u);
		int pv=find(e.v);
		if(pu!=pv) join(e.u,e.v);
	}
	int cnt=0;
	for(int i=0; i<n; ++i) if(find(i)==i) cnt++;
	return cnt;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s>>n;
		for(int i=0; i<n; ++i) cin>>x[i]>>y[i];
		for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j)
		{
			double d=distance(i,j);
			edges.push_back(Edge{i,j,d});
			edges.push_back(Edge{j,i,d});
		}
		sort(edges.begin(),edges.end(),cmp);
		double lo=0, hi=1e6, m;
		while(lo+eps<hi)
		{
			m=(lo+hi)/2;
			if(kruskal(m)>s) lo=m;
			else hi=m;
		}
		printf("%.2f\n",m);
		edges.clear();
	}
	return 0;
}*/