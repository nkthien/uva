#include<iostream>
using namespace std;

int t,n,m,q,f,a[1000100],ST[4000100],u,v;
char op,lazy[4000100];
string pat;

void buildST(int id, int l, int r)
{
	if(l==r) ST[id]=a[l];
	else
	{
		int m=(l+r)/2;
		buildST(2*id+1,l,m);
		buildST(2*id+2,m+1,r);
		ST[id]=ST[2*id+1] + ST[2*id+2];
	}
}

void update(int id, int l, int r)
{
	if(l>r) return;
	if(lazy[id]!='0')
	{
		if(lazy[id]=='F') ST[id]=r-l+1;
		else if(lazy[id]=='E') ST[id]=0;
		else ST[id]=r-l+1-ST[id];
		
		if(l!=r)
		{
			if(lazy[2*id+1]=='F' && lazy[id]=='I') lazy[2*id+1]='E';
			else if(lazy[2*id+1]=='E' && lazy[id]=='I') lazy[2*id+1]='F';
			else if(lazy[2*id+1]=='I' && lazy[id]=='I') lazy[2*id+1]='0';
			else lazy[2*id+1]=lazy[id];

			if(lazy[2*id+2]=='F' && lazy[id]=='I') lazy[2*id+2]='E';
			else if(lazy[2*id+2]=='E' && lazy[id]=='I') lazy[2*id+2]='F';
			else if(lazy[2*id+2]=='I' && lazy[id]=='I') lazy[2*id+2]='0';
			else lazy[2*id+2]=lazy[id];
		}
		lazy[id]='0';
	}
	if(v<l || u>r) return;
	if(u<=l && v>=r)
	{
		if(op=='F') ST[id]=r-l+1;
		else if(op=='E') ST[id]=0;
		else ST[id]=r-l+1-ST[id];

		if(l!=r)
		{
			if(lazy[2*id+1]=='F' && op=='I') lazy[2*id+1]='E';
			else if(lazy[2*id+1]=='E' && op=='I') lazy[2*id+1]='F';
			else if(lazy[2*id+1]=='I' && op=='I') lazy[2*id+1]='0';
			else lazy[2*id+1]=op;

			if(lazy[2*id+2]=='F' && op=='I') lazy[2*id+2]='E';
			else if(lazy[2*id+2]=='E' && op=='I') lazy[2*id+2]='F';
			else if(lazy[2*id+2]=='I' && op=='I') lazy[2*id+2]='0';
			else lazy[2*id+2]=op;
		}
	}
	else
	{
		int m=(l+r)/2;
		update(2*id+1,l,m);
		update(2*id+2,m+1,r);
		ST[id]=ST[2*id+1] + ST[2*id+2];
	}
}

int query(int id, int l, int r)
{
	if(l>r) return 0;
	if(lazy[id]!='0')
	{
		if(lazy[id]=='F') ST[id]=r-l+1;
		else if(lazy[id]=='E') ST[id]=0;
		else ST[id]=r-l+1-ST[id];
		
		if(l!=r)
		{
			if(lazy[2*id+1]=='F' && lazy[id]=='I') lazy[2*id+1]='E';
			else if(lazy[2*id+1]=='E' && lazy[id]=='I') lazy[2*id+1]='F';
			else if(lazy[2*id+1]=='I' && lazy[id]=='I') lazy[2*id+1]='0';
			else lazy[2*id+1]=lazy[id];

			if(lazy[2*id+2]=='F' && lazy[id]=='I') lazy[2*id+2]='E';
			else if(lazy[2*id+2]=='E' && lazy[id]=='I') lazy[2*id+2]='F';
			else if(lazy[2*id+2]=='I' && lazy[id]=='I') lazy[2*id+2]='0';
			else lazy[2*id+2]=lazy[id];
		}
		lazy[id]='0';
	}
	if(v<l || u>r) return 0;
	if(u<=l && v>=r) return ST[id];
	int m=(l+r)/2;
	return query(2*id+1,l,m) + query(2*id+2,m+1,r);
}

int main()
{
	cin>>t;
	int tc=1;
	while(t--)
	{
		n=0;
		cin>>m;
		while(m--)
		{
			cin>>f>>pat;
			int len=pat.length(), c=0;
			f*=len;
			while(f--) a[n++]=pat[c++%len]-'0';
		}
		for(int i=0; i<4*n; ++i) ST[i]=0, lazy[i]='0';
		buildST(0,0,n-1);
		cin>>q;
		int qn=1;
		printf("Case %d:\n", tc++);
		while(q--)
		{
			cin>>op>>u>>v;
			if(op=='S') printf("Q%d: %d\n", qn++, query(0,0,n-1));
			else update(0,0,n-1);
		}
	}
	return 0;
}