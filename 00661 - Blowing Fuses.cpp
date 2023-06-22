#include<iostream>
using namespace std;

int n,m,t,on[22],pw[22],c;

int main()
{
	for(int tc=1;; tc++)
	{
		cin>>n>>m>>t;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>pw[i],on[i]=0;
		int mx=0,sum=0;
		bool ok=true;
		for(int i=0; i<m; ++i)
		{
			cin>>c; c--;
			on[c]^=1;
			if(on[c]) sum+=pw[c];
			else sum-=pw[c];
			mx=max(mx,sum);
			if(sum>t) ok=false;
		}
		printf("Sequence %d\n", tc);
		if(!ok) printf("Fuse was blown.\n");
		else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",mx);
		puts("");
	}
	return 0;
}