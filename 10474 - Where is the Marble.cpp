#include<iostream>
#include<algorithm>
using namespace std;

int n,q,x,a[10010];

int main()
{
	int tc=1;
	while(1)
	{
		cin>>n>>q;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>a[i];
		sort(a,a+n);
		printf("CASE# %d:\n",tc++);
		while(q--)
		{
			cin>>x;
			int ans=lower_bound(a,a+n,x)-a;
			if(ans<n && a[ans]==x) printf("%d found at %d\n",x,ans+1);
			else printf("%d not found\n",x);
		}
	}
	return 0;
}