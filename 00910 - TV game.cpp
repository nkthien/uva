#include <iostream>
#include <unordered_map>
using namespace std;

int n,k,good[30],dp[30][35],g[30][3];
char src,dst1,dst2,spc;

int main()
{
	while(cin>>n)
	{
		unordered_map<int,int> _map;
		int cnt=0;
		for(int i=0; i<n; ++i)
		{
			cin>>src>>dst1>>dst2>>spc;
			if(!_map.count(src)) _map[src]=cnt++;
			if(!_map.count(dst1)) _map[dst1]=cnt++;
			if(!_map.count(dst2)) _map[dst2]=cnt++;
			
			int u=_map[src];
			int v1=_map[dst1];
			int v2=_map[dst2];
			
			g[u][0]=v1;
			g[u][1]=v2;
			if(spc == 'x') good[u]=1;
			else good[u]=0;
		}
		cin>>k;
		for(int h=0; h<=k; ++h) for(int i=0; i<n; ++i) dp[i][h]=0;
		dp[0][0]=1;
		for(int h=0; h<k; ++h) for(int u=0; u<n; ++u)
		{
			for(int i=0; i<2; ++i)
			{
				int v=g[u][i];
				dp[v][h+1]+=dp[u][h];
			}
		}
		int ans=0;
		for(int i=0; i<n; ++i) if(good[i]) ans+=dp[i][k];
		cout<<ans<<endl;
	}
	return 0;
}
