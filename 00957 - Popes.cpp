#include<iostream>
#include<algorithm>
using namespace std;

int p,n,a[100100];

int main()
{
	while(cin>>p)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>a[i];
		int ans=0, l=0, r=0;
		for(int i=0; i<n; ++i)
		{
			int test=upper_bound(a,a+n,a[i]+p-1)-a-i;
			if(test>ans)
			{
				ans=test;
				l=a[i], r=a[i+test-1];
			}
		}
		printf("%d %d %d\n",ans,l,r);
	}
	return 0;
}