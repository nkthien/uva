#include<iostream>
using namespace std;

int t,n,tm,m,s,a[2000];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>tm>>m;
		for(int i=0; i<m; ++i) cin>>a[i];
		int j=m%n,ans,cnt;
		if(j!=0) ans=a[j-1]+2*tm, cnt=1;
		else ans=0, cnt=0;
		while(j+n<=m)
		{
			j+=n;
			cnt+=1;
			ans=max(ans,a[j-1]);
			ans+=2*tm;
		}
		ans-=tm;
		printf("%d %d\n",ans,cnt);
	}

	return 0;
}