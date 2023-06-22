#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,lis[35],path[35],last;

struct Box
{
	int id,d[15];
} a[35];

bool operator > (Box &a, Box &b)
{
	for(int i=0; i<m; ++i) if(a.d[i]<=b.d[i]) return false;
	return true;
}

void print_lis()
{
	int cur=last;
	vector<int> res;
	while(cur!=-1)
	{
		res.push_back(a[cur].id);
		cur=path[cur];
	}
	int sz=res.size();
	for(int i=sz-1; i>=0; --i) 
	{
		cout<<res[i];
		if(i!=0) cout<<" ";
		else cout<<endl;
	}
}

int main()
{
	while(cin>>n>>m)
	{
		for(int i=0; i<n; ++i)
		{
			a[i].id=i+1;
			for(int j=0; j<m; ++j) cin>>a[i].d[j];
			sort(a[i].d,a[i].d+m);
		}
		for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j) if(a[i]>a[j]) swap(a[i],a[j]); // bubble sort
		for(int i=0; i<n; ++i) lis[i]=1, path[i]=-1;
		for(int i=1; i<n; ++i) for(int j=0; j<i; ++j)
		{
			if(a[i]>a[j] && lis[i]<lis[j]+1)
			{
				lis[i]=lis[j]+1;
				path[i]=j;
			}
		}
		int ans=0;
		for(int i=0; i<n; ++i) if(lis[i]>ans)
		{
			ans=lis[i];
			last=i;
		}
		cout<<ans<<endl;
		print_lis();
	}
	return 0;
}