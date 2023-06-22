#include<iostream>
using namespace std;

int n,m,a[100100],b[100100],e[100100],ST[400100],u,v;

void buildST(int id, int l, int r)
{
	if(l==r) ST[id]=a[l];
	else
	{
		int m=(l+r)/2;
		buildST(2*id+1,l,m);
		buildST(2*id+2,m+1,r);
		ST[id]=max(ST[2*id+1], ST[2*id+2]);
	}
}

int query(int id, int l, int r)
{
	if(v<l || u>r) return -1;
	if(u<=l && v>=r) return ST[id];
	else
	{
		int m=(l+r)/2;
		return max(query(2*id+1,l,m), query(2*id+2,m+1,r));
	}
}

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		cin>>m;
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<n;)
		{
			int j=i, cnt=0;
			while(j<n && a[j]==a[i]) j++, cnt++;
			for(int k=i; k<j; ++k) a[k]=cnt, b[k]=i, e[k]=j-1;
			i=j;
		}
		buildST(0,0,n-1);
		while(m--)
		{
			cin>>u>>v; u--, v--;
			if(b[u]==b[v]) cout<<v-u+1<<endl;
			else
			{
				int test1=e[u]-u+1;
				int test2=v-b[v]+1;
				u=e[u]+1, v=b[v]-1;
				int test3=query(0,0,n-1);
				cout<<max(max(test1,test2),test3)<<endl;
			}
		}
	}
	return 0;
}



// del hieu sao runtime error :(

/*#include<iostream>
using namespace std;

int n,m,a[100100],b[100100],ST[400100],p,q;

void buildST(int node, int l, int r)
{
	if(l==r) ST[node]=1;
	else if(b[l]==b[r])
	{
		ST[node]=r-l+1;
		int m=(l+r)/2;
		buildST(node*2,l,m);
		buildST(node*2+1,m+1,r);
	}
	else
	{
		int m=b[(l+r)/2];
		if(m==b[r]) m=b[l];
		buildST(node*2,l,m);
		buildST(node*2+1,m+1,r);
		ST[node]=max(ST[node*2],ST[node*2+1]);
	}
}

int query(int node, int l, int r, int ql, int qr)
{
	if(qr<l || ql>r) return 0;
	if(ql<=l && qr>=r) return ST[node];
	if(b[l]==b[r]) return query(node*2,l,(r+l)/2,ql,qr) + query(node*2+1,(r+l)/2+1,r,ql,qr);
	int m=b[(l+r)/2];
	if(m==b[r]) m=b[l];
	return max(query(node*2,l,m,ql,qr), query(node*2+1,m+1,r,ql,qr));
}

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		cin>>m;
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<n;)
		{
			int j=i, cnt=0;
			while(j<n && a[j]==a[i]) j++,cnt++;
			for(int k=i; k<j; ++k) a[k]=cnt, b[k]=j-1;
			i=j;
		}
		buildST(1,0,n-1);
		while(m--) 
		{
			cin>>p>>q; p--,q--;
			cout<<query(1,0,n-1,p,q)<<endl;
		}
	}
	return 0;
}*/