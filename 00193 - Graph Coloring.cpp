#include<iostream>
#include<vector>
using namespace std;

const int BLACK=1;
const int WHITE=0;

int t,n,m,u,v,ans,res[110],color[110];
vector<int> g[110];

void dfs(int u)
{
	if(u==n)
	{
		int cnt=0;
		for(int i=0; i<n; ++i) if(color[i]==BLACK) cnt++;
		if(cnt>ans)
		{
			ans=0;
			for(int i=0; i<n; ++i) if(color[i]==BLACK) res[ans++]=i;
		}
		return;
	}
	bool isOk=true;
	for(int i=0; i<g[u].size(); ++i) if(color[g[u][i]]==BLACK)
	{
		isOk=false;
		break;
	}
	if(isOk)
	{
		color[u]=BLACK;
		dfs(u+1);
	}
	color[u]=WHITE;
	dfs(u+1);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0; i<n; ++i) g[i].clear();
		while(m--)
		{
			cin>>u>>v; u--,v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=0;
		dfs(0);
		cout<<ans<<endl;
		for(int i=0; i<ans; ++i)
		{
			cout<<res[i]+1;
			cout<<(i==ans-1 ? "\n":" ");
		}
	}
	return 0;
}