#include<iostream>
#include<algorithm>
using namespace std;

int n,m,a[20020],b[20020];

int main()
{
	while(1)
	{
		cin>>n>>m;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<m; ++i) cin>>b[i];
		sort(a,a+n);
		sort(b,b+m);
		int ans=0, j=0;
		bool isOk=true;
		for(int i=0; i<n && isOk; ++i)
		{
			j=lower_bound(b+j,b+m,a[i])-b;
			if(j==m) isOk=false;
			else ans+=b[j++];
		}
		if(isOk) cout<<ans<<endl;
		else cout<<"Loowater is doomed!\n";
	}
	return 0;
}