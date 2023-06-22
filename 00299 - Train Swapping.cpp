#include<iostream>
using namespace std;

int t,n,a[55];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i) cin>>a[i];
		int cnt=0;
		for(int i=0; i<n-1; ++i) for(int j=n-1; j>i; --j) if(a[j]<a[j-1]) swap(a[j],a[j-1]), cnt++;
		printf("Optimal train swapping takes %d swaps.\n",cnt);
	}
	return 0;
}