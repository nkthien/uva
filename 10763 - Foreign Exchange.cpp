#include<iostream>
#include<bitset>
using namespace std;

int n,a,b;

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		bitset<1000000> bit;
		while(n--)
		{
			cin>>a>>b;
			bit.flip(a);
			bit.flip(b);
		}
		if(bit.any()) puts("NO");
		else puts("YES");
	}
	return 0;
}


// greedy way

/*#include<stdio.h>
#include<algorithm>

int n,a[500500],b[500500];

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		for(int i=0; i<n; ++i) scanf("%d %d",a+i,b+i);
		std::sort(a,a+n);
		std::sort(b,b+n);
		while(--n) if(a[n]!=b[n]) break;
		if(n!=0) puts("NO");
		else puts("YES");
	}
	return 0;
}*/