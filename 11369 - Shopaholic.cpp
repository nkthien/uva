#include<iostream>
#include<algorithm>
using namespace std;

int t,n,a[20020];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>a[i];
		sort(a,a+n,greater<int>());
		int ans=0, j=1;
		for(int j=1; 3*j-1<n; ++j) ans+=a[3*j-1];
		cout<<ans<<endl;
	}
	return 0;
}