#include<iostream>
using namespace std;

int t,r,m,x,y,v,mat[1050][1050];

void fill(int x, int y, int v)
{
	int a=x-r, b=x+r;
	int c=y-r, d=y+r;
	if(a<0) a=0; if(b>=1025) b=1024;
	if(c<0) c=0; if(d>=1025) d=1024;
	for(int i=a; i<=b; ++i) for(int j=c; j<=d; ++j) mat[i][j]+=v;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>r>>m;
		for(int i=0; i<1025; ++i) for(int j=0; j<1025; ++j) mat[i][j]=0;
		while(m--)
		{
			cin>>x>>y>>v;
			fill(x,y,v);
		}	
		int mx=0, resx=0, resy=0;
		for(int i=0; i<1025; ++i) for(int j=0; j<1025; ++j) 
		{
			if(mx<mat[i][j]) mx=mat[i][j], resx=i, resy=j;
		}
		printf("%d %d %d\n",resx,resy,mx);
	}
	return 0;
}