#include<iostream>
#include<algorithm>
using namespace std;

int n,a[10010],lis[10010],lds[10010],tmp[10010];

// normal O(N^2) get way TLE.....again -__-!

/*void construct(int *best)
{
	for(int i=0; i<n; ++i) best[i]=1;
	for(int i=1; i<n; ++i) for(int j=0; j<i; ++j) if(a[i]>a[j]) best[i]=max(best[i],best[j]+1);	
}*/

void construct(int *best)
{
	int len=0;
	for(int i=0; i<n; ++i) 
	{
		int pos=lower_bound(tmp,tmp+len,a[i])-tmp;
		best[i]=pos+1;
		tmp[pos]=a[i];
		if(pos==len) len++;
	}
}

int main()
{
	while(cin>>n)
	{
		for(int i=0; i<n; ++i) cin>>a[i];
		construct(lis);
		reverse(a,a+n);
		construct(lds);
		reverse(lds,lds+n);
		int ans=0;
		for(int i=0; i<n; ++i) ans=max(ans,2*min(lis[i],lds[i])-1);
		cout<<ans<<endl;
	}
	return 0;
}