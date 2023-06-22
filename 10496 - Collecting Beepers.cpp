#include<iostream>
#include<algorithm>
using namespace std;

int t,j,sx,sy,n,x[15],y[15],a[15];

int distance(int x1, int y1, int x2, int y2)
{
	return abs(x1-x2)+abs(y1-y2);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>j>>j>>sx>>sy>>n;
		for(int i=0; i<n; ++i) cin>>x[i]>>y[i];
		for(int i=0; i<n; ++i) a[i]=i;
		int ans=1e9;
		do 
		{
			int dis=distance(sx,sy,x[a[0]],y[a[0]]) + distance(sx,sy,x[a[n-1]],y[a[n-1]]);
			for(int i=0; i<n-1; ++i) dis+=distance(x[a[i]],y[a[i]],x[a[i+1]],y[a[i+1]]);
			ans=min(ans,dis);	
		} while(next_permutation(a,a+n));
		printf("The shortest path has length %d\n",ans);
	}
	return 0;
}