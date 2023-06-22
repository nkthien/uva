#include<iostream>
using namespace std;

int t,n,dp[10010][15];

void build()
{
	for(int i=1; i<=10000; ++i)
	{
		int num=i;
		while(num!=0)
		{
			int j=num%10;
			dp[i][j]++;
			num/=10;
		}
	}
	for(int i=0; i<10; ++i) for(int j=1; j<=10000; ++j) dp[j][i]+=dp[j-1][i];
}

int main()
{
	build();
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<10; ++i)
		{
			if(i!=0) cout<<" ";
			cout<<dp[n][i];
		}
		cout<<endl;
	}
	return 0;
}