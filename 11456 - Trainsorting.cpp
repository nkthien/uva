#include<iostream>
using namespace std;

int t,n,a[2020],lis[2020],lds[2020];

void make_lis()
{
	for(int i=0; i<n; ++i) lis[i]=1;
	for(int i=n-2; i>=0; --i) for(int j=i+1; j<n; ++j) if(a[i]<a[j]) lis[i]=max(lis[i],lis[j]+1);
}

void make_lds()
{
	for(int i=0; i<n; ++i) lds[i]=1;
	for(int i=n-2; i>=0; --i) for(int j=i+1; j<n; ++j) if(a[i]>a[j]) lds[i]=max(lds[i],lds[j]+1);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>a[i];
		make_lis();	  // lis[i]: longest sequence from i to n
		make_lds();
		int ans=0;
		for(int i=0; i<n; ++i) ans=max(ans,lis[i]+lds[i]-1);
		cout<<ans<<endl;	
	}
	return 0;
}


// combine into 1 array then find LIS... COOL!

/*#include<iostream>
using namespace std;

int t,n,a[4040],best[4040];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i)
		{
			cin>>a[i+n];
			a[n-i-1]=a[i+n];
		}
		n<<=1;
		for(int i=0; i<n; ++i) best[i]=1;
		for(int i=1; i<n; ++i) for(int j=0; j<i; ++j) if(a[i]>a[j]) best[i]=max(best[i],best[j]+1);
		int ans=0;
		for(int i=0; i<n; ++i) ans=max(ans,best[i]);
		cout<<ans<<endl;
	}
	return 0;
}*/
