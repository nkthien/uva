#include<iostream>
using namespace std;

int t,n,parent[30];
string line;

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

int main()
{
	cin>>t; cin.get(); cin.get();
	while(t--)
	{
		getline(cin,line);
		if(line.length()==1) n=line[0]-'A'+1;
		initSet();
		while(getline(cin,line))
		{
			if(line[0]=='\0') break;
			else unionSet(line[0]-'A', line[1]-'A');
		}
		int cnt=0;
		for(int i=0; i<n; ++i) if(parent[i]==i) cnt++;
		cout<<cnt<<endl;
		if(t!=0) cout<<endl;
	}
	return 0;
}