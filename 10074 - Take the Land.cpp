#include<iostream>
using namespace std;

int n,m,a[105][105];

int main()
{
	while(cin>>n>>m && n)
	{
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
		{
			cin>>a[i][j];
			a[i][j]+=a[i-1][j];
			a[i][j]+=a[i][j-1];
			a[i][j]-=a[i-1][j-1];
		}
		int ans=0;
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
		for(int k=i; k<=n; ++k) for(int l=j; l<=m; ++l)
		{
			int sum=a[k][l];
			sum-=a[i-1][l];
			sum-=a[k][j-1];
			sum+=a[i-1][j-1];
			if(sum==0) ans=max(ans, (k-i+1)*(l-j+1));
		}
		cout<<ans<<endl;
	}
	return 0;
}