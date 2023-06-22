#include<iostream>
using namespace std;

int n,m,a[100100],ST[400400],u,v;
char op;

void buildST(int id, int l, int r)
{
	if(l==r) ST[id]=a[l];
	else
	{
		int m=(l+r)/2;
		buildST(2*id+1,l,m);
		buildST(2*id+2,m+1,r);
		ST[id]=ST[2*id+1] * ST[2*id+2];
	}
}

void update(int id, int l, int r, int u, int v)
{
	if(u<l || u>r) return;
	if(l==r) ST[id]=a[u]=v;
	else
	{
		int m=(l+r)/2;
		if(u<=m) update(2*id+1,l,m,u,v);
		else update(2*id+2,m+1,r,u,v);
		ST[id]=ST[2*id+1] * ST[2*id+2];
	}
}

int query(int id, int l, int r, int u, int v)
{
	if(v<l || u>r) return 1;
	if(u<=l && v>=r) return ST[id];
	else
	{
		int m=(l+r)/2;
		return query(2*id+1,l,m,u,v) * query(2*id+2,m+1,r,u,v);
	}
}

int main()
{
	while(cin>>n>>m)
	{
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<n; ++i) a[i]=(a[i]==0 ? 0 : a[i]>0 ? 1 : -1);
		buildST(0,0,n-1);
		while(m--)
		{
			cin>>op>>u>>v;
			if(op=='C') 
			{
				v=(v==0 ? 0 : v>0 ? 1 : -1);
				update(0,0,n-1,u-1,v);
			}
			else
			{
				int test=query(0,0,n-1,u-1,v-1);
				if(test<0) cout<<"-";
				else if(test>0) cout<<"+";
				else cout<<"0";
			}
		}
		cout<<endl;
	}
	return 0;
}