#include<iostream>
using namespace std;

const int d[]={-1,0,1}, v[]={20,30,60}, INF=1e9;

int t,n,w[15][1005],dp[15][1005];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n; n/=100;
		for(int h=9; h>=0; --h) for(int i=0; i<n; ++i) cin>>w[h][i];
		for(int i=0; i<=n; ++i) for(int h=0; h<10; ++h)
		{
			if(i==0)
			{
				if(h!=0) dp[h][i]=INF;
				continue;
			}
			int cost=INF;
			for(int j=0; j<3; ++j)
			{
				int k=h+d[j];
				if(k<0 || k>9) continue;
				cost=min(cost, dp[k][i-1] + v[j] - w[k][i-1]);
			}
			dp[h][i]=cost;
		}
		cout<<dp[0][n]<<endl<<endl;
	}
	return 0;
}