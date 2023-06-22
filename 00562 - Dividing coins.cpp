#include<iostream>
using namespace std;

int t,n,a[105],dp[50005];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sum=0;
		for(int i=0; i<n; ++i) cin>>a[i], sum+=a[i];
		int M=sum/2;
		for(int i=0; i<=M; ++i) dp[i]=0;
		for(int i=0; i<n; ++i) for(int j=M; j>=0; --j) if(j>=a[i]) dp[j]=max(dp[j], dp[j-a[i]]+a[i]);
		int ans=sum-2*dp[M];
		cout<<ans<<endl;
	}
	return 0;
}