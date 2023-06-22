#include<iostream>
using namespace std;

const int v[]={5,10,20,50,100,200}, INF=1e9;

int a[10],return_dp[10050],pay_dp[10010];

int main()
{
	return_dp[0]=0;
	for(int i=1; i<=10000; ++i) return_dp[i]=INF;
	for(int i=0; i<6; ++i)for(int m=1; m<=10000; ++m) if(m>=v[i]) return_dp[m]=min(return_dp[m],return_dp[m-v[i]]+1); // shopkeeper unlimited coins
	while(1)
	{
		int sum=0,b,c;
		for(int i=0; i<6; ++i) scanf("%d ",a+i), sum+=a[i]*v[i];
		if(sum==0) break;
		scanf("%d.%d\n",&b,&c);
		pay_dp[0]=0;
		for(int i=1; i<=sum; ++i) pay_dp[i]=INF;
		for(int i=0; i<6; ++i) for(int m=sum; m>0; --m) for(int j=1; j<=a[i]; ++j)
		{
			if(m<v[i]*j) break;
			pay_dp[m]=min(pay_dp[m],pay_dp[m-v[i]*j]+j);  // limited coins
		}
		int ans=INF, target=b*100+c;
		for(int i=target; i<=sum; ++i) ans=min(ans,pay_dp[i]+return_dp[i-target]);
		printf("%3d\n",ans);
	}
	return 0;
}