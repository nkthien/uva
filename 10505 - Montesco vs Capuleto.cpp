#include<iostream>
using namespace std;

int t,n,ne,e,p[405],vis[405];

int find(int u) { return u==p[u] ? u : p[u]=find(p[u]); }
void join(int u, int v) { p[find(u)]=find(v); }

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<2*n; ++i) p[i]=i, vis[i]=0;
		for(int i=0; i<n; ++i)
		{
			cin>>ne;
			while(ne--)
			{
				cin>>e; e--;
				if(e>=n) continue;
				join(i,e+n);
				join(e,i+n);
			}
		}
		int ans=0;
		for(int i=0; i<2*n; ++i) p[i]=find(i);
		for(int i=0; i<n; ++i)
		{
			int root=p[i];
			if(!vis[root])
			{
				int test1=0, test2=0;
				for(int j=0; j<n; ++j) if(!vis[j] && p[j]==root && p[j+n]!=root)
				{
					test1++;
					vis[j]=1;
					vis[j+n]=1;
				}
				for(int j=n; j<2*n; ++j) if(!vis[j] && p[j]==root && p[j-n]!=root)
				{
					test2++;
					vis[j]=1;
					vis[j-n]=1;
				}
				ans+=test1>test2 ? test1:test2;
				vis[root]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}