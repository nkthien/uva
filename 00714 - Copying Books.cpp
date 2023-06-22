#include<iostream>
using namespace std;

typedef long long ll;

int t,n,k,a[550],s[550];

int divide(ll m)
{
	int cnt=1, i=0;
	ll sum=0;
	while(i<n)
	{
		if(sum+a[i]<=m) sum+=a[i++];
		else cnt++, sum=0;
		if(cnt>k) return k+1;
	}
	return cnt;
}

ll findMax(ll l, ll r)
{
	if(l>r) return l;
	ll m=(l+r)/2;
	if(divide(m)>k) return findMax(m+1,r);
	else return findMax(l,m-1);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll sum=0;
		for(int i=0; i<n; ++i) cin>>a[i], sum+=a[i], s[i]=0;
		ll mx=findMax(1,sum);
		int j=n-1;
		for(int i=k-1; i>0; --i)
		{
			sum=0;
			while(j>=i)
			{
				if(sum+a[j]<=mx) sum+=a[j--];
				if(i==j+1 || sum+a[j]>mx)
				{
					s[j+1]=1;
					break;
				}
			}
		}
		for(int i=0; i<n; ++i) 
		{
			if(s[i]) cout<<"/ ";
			cout<<a[i];
			if(i!=n-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}