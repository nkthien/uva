#include<iostream>
using namespace std;

int n,a[500500];
long long ans;

long long merge(int l, int m, int r)
{
	long long cnt=0;
	int n1=m-l+1;
	int n2=r-m;
	int a1[n1], a2[n2];
	for(int i=0; i<n1; ++i) a1[i]=a[l+i];
	for(int i=0; i<n2; ++i) a2[i]=a[m+i+1];
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(a1[i]<=a2[j]) a[k++]=a1[i++];
		else a[k++]=a2[j++], cnt+=n1-i;
	}
	while(i!=n1) a[k++]=a1[i++];
	while(j!=n2) a[k++]=a2[j++];
	return cnt;
}

void mergeSort(int l, int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergeSort(l,m);
		mergeSort(m+1,r);
		ans+=merge(l,m,r);
	}
	return;
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
		cout<<ans<<endl;
	}
	return 0;
}