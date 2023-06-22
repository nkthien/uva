#include<iostream>
using namespace std;

const int INF=1e9;

int n,a[100100];
long long ans;

long long merge(int l, int m, int r)
{
	int n1=m-l+2;
	int n2=r-m+1;
	int a1[n1], a2[n2];
	for(int i=0; i<n1-1; ++i) a1[i]=a[l+i];
	for(int i=0; i<n2-1; ++i) a2[i]=a[m+1+i];
	a1[n1-1]=INF, a2[n2-1]=INF;
	int i=0,j=0,k=l,sz=r-l+1;
	long long cnt=0,subans=0;
	while(l<=r)
	{
		if(a1[i]<=a2[j]) a[l++]=a1[i++], subans+=cnt;
		else a[l++]=a2[j++], cnt++;
	}
	return subans;
}

void mergeSort(int l, int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergeSort(l,m);
		mergeSort(m+1,r);
		ans+=merge(l,m,r);
		return;
	}
}

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>a[i];
		ans=0;
		mergeSort(0,n-1);
		if(ans%2) cout<<"Marcelo\n";
		else cout<<"Carlos\n";
	}
	return 0;
}