#include<iostream>
using namespace std;

int t,n,x;

int main()
{
	cin>>t;
	int tc=1;
	while(t--)
	{
		cin>>n;
		int sum=0, mx=0, bg=0, ed=0, left=1;
		for(int i=1; i<n; ++i)
		{
			cin>>x;
			sum+=x;
			if(sum<0) sum=0, left=i+1;
			else if(sum>mx || (sum==mx && i-left>ed-bg)) mx=sum, bg=left, ed=i;
		}
		if(mx>0) printf("The nicest part of route %d is between stops %d and %d\n", tc++, bg, ed+1);
		else printf("Route %d has no nice parts\n",tc++);
	}
	return 0;
}


// O(n^2)

/*#include<iostream>
using namespace std;

int t,n,a[20020];

int main()
{
	cin>>t;
	int tc=1;
	while(t--)
	{
		cin>>n;
		for(int i=1; i<n; ++i) 
		{
			cin>>a[i];
			a[i]+=a[i-1];
		}
		int resL=-1, resR=-1, mx=-1e9;
		for(int l=1; l<n; ++l) for(int r=n-1; r>=l; --r)
		{
			int sum=a[r]-a[l-1];
			if(sum>mx) resL=l, resR=r, mx=sum;
			else if(sum==mx && r-l>resR-resL) resL=l, resR=r;
		}
		if(mx<0) printf("Route %d has no nice parts\n",tc++);
		else printf("The nicest part of route %d is between stops %d and %d\n", tc++, resL, resR+1);
	}
	return 0;
}*/