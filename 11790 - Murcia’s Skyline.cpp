#include<iostream>
using namespace std;

int t,n,h[10010],w[10010],lis[10010],lds[10010];

int main()
{
	int tc=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>h[i];
		for(int i=0; i<n; ++i) cin>>w[i];
		for(int i=0; i<n; ++i) lis[i]=lds[i]=w[i];
		for(int i=1; i<n; ++i) for(int j=0; j<i; ++j) if(h[i]>h[j]) lis[i]=max(lis[i],lis[j]+w[i]);
		for(int i=1; i<n; ++i) for(int j=0; j<i; ++j) if(h[i]<h[j]) lds[i]=max(lds[i],lds[j]+w[i]);
		int best_lis=0, best_lds=0;
		for(int i=0; i<n; ++i) best_lis=max(best_lis,lis[i]), best_lds=max(best_lds,lds[i]);
		if(best_lis>=best_lds) printf("Case %d. Increasing (%d). Decreasing (%d).\n",tc++,best_lis,best_lds);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n",tc++,best_lds,best_lis);
	}
	return 0;
}