#include <iostream>
using namespace std;

typedef long long ll;

ll n,m,a[55],h;

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a,b);
}

int main()
{
	while(cin>>n>>m && n)
	{
		for(int i=0; i<n; ++i) cin>>a[i];
		while(m--)
		{
			cin>>h;
			ll s1=0, s2=1e9;
			for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
			for(int k=j+1; k<n; ++k)
			for(int l=k+1; l<n; ++l)
			{
				ll d=lcm(a[i], lcm(a[j], lcm(a[k], a[l])));
				if(h%d == 0)
				{
					s1=s2=h;
					i=j=k=l=n;
				}
				else
				{
					ll tmp=h/d;
					s1=max(s1, tmp*d);
					s2=min(s2, (tmp+1)*d);
				}
			}
			cout<<s1<<" "<<s2<<endl;
		}
	}
	return 0;
}


// pre-compute lcm, much faster (0.09 vs 0.55), extra mem

/*#include <iostream>
using namespace std;

typedef long long ll;

ll n,m,a[55],h[15],mn[15],mx[15];

ll gcd(ll a, ll b)
{
	if(a == 0) return b;
	return gcd(b%a, a);
}

ll lcm(ll a, ll b)
{
	return a/gcd(a,b)*b;
}

int main()
{
	while(cin>>n>>m && n)
	{
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<m; ++i) cin>>h[i], mn[i]=1e9, mx[i]=1e9;
	
		for(int i=0; i<n; ++i)
		for(int j=i+1; j<n; ++j)
		for(int k=j+1; k<n; ++k)
		for(int l=k+1; l<n; ++l)
		{
			ll L=lcm(a[i], lcm(a[j], lcm(a[k], a[l])));
			for(int p=0; p<m; ++p)
			{
				ll H=h[p];
				ll lo=H%L;
				ll hi=(L-lo)%L;
				mn[p]=min(mn[p], lo);
				mx[p]=min(mx[p], hi);
			}
		}
		for(int i=0; i<m; ++i) cout<<h[i]-mn[i]<<" "<<h[i]+mx[i]<<endl;
	}
	return 0;
}
*/
