#include<iostream>
#include<sstream>
using namespace std;

int t,n,parent[1000100],a,b;
string line,op;

void initSet()
{
	for(int i=0; i<n; ++i) parent[i]=i;
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
}

bool isSame(int u, int v)
{
	int up=findSet(u);
	int vp=findSet(v);
	if(up==vp) return true;
	return false;
}

int main()
{
	cin>>t;
	cin.get(), cin.get();
	while(t--)
	{
		cin>>n; cin.get();
		initSet();
		int res1=0, res2=0;
		while(getline(cin,line))
		{
			if(line.length()==0) break;
			stringstream ss(line);
			ss>>op>>a>>b; a--,b--;
			if(op=="c") unionSet(a,b);
			else if(isSame(a,b)) res1++; else res2++;
		}
		printf("%d,%d\n",res1,res2);
		if(t!=0) puts("");
	}
}