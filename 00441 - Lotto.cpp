#include<iostream>
using namespace std;

int n,a[15];

int main()
{
	bool first=true;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>a[i];
		if(!first) puts("");
		first=false;
		int d=n-6;
		for(int i=0; i<=d; ++i)
		for(int j=i+1; j<=d+1; ++j)
		for(int k=j+1; k<=d+2; ++k)
		for(int l=k+1; l<=d+3; ++l)
		for(int m=l+1; m<=d+4; ++m)
		for(int n=m+1; n<=d+5; ++n) printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[n]);
	}
	return 0;
}