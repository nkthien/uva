#include<iostream>
using namespace std;

#define cube(x) (x)*(x)*(x)

unsigned long long n,v[25],dp[10010];

int main()
{
	for(int i=0; i<21; ++i) v[i]=cube(i+1);
	dp[0]=1;
	for(int i=0; i<21; ++i) for(int m=1; m<10000; ++m) if(m>=v[i]) dp[m]+=dp[m-v[i]];
	while(cin>>n) cout<<dp[n]<<endl;
	return 0;
}