#include<iostream>
#include<algorithm>
using namespace std;

int n,q,x,a[50050];

int main()
{
	cin>>n;
	for(int i=0; i<n; ++i) cin>>a[i];
	cin>>q;
	while(q--)
	{
		cin>>x;
		int ans1=lower_bound(a,a+n,x)-a-1;
		int ans2=upper_bound(a,a+n,x)-a;
		if(ans1==-1) cout<<"X "; 
		else cout<<a[ans1]<<" ";
		if(ans2==n) cout<<"X\n"; 
		else cout<<a[ans2]<<"\n";
	}
	return 0;
}