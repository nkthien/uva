#include<iostream>
#include<algorithm>
using namespace std;

int n,a[2000200];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while(1)
	{
		cin>>n;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>a[i];
		sort(a,a+n);
		for(int i=0; i<n; ++i)
		{
			 cout<<a[i];
			 if(i!=n-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}