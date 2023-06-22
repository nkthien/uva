#include<iostream>
#include<vector>
using namespace std;

int n,m,a[100000],ans,mn;
vector<int> tmp,res;

void dfs(int i)
{
	if(i==m)
	{
		int sum=0;
		for(int i=0; i<tmp.size(); ++i) sum+=tmp[i];
		int test=n-sum;
		if(test>=0 && test<mn)
		{
			mn=test;
			ans=sum;
			res=tmp;
		}
		return;
	}
	tmp.push_back(a[i]);
	dfs(i+1);
	tmp.pop_back();
	dfs(i+1);
}

int main()
{
	while(cin>>n>>m)
	{
		for(int i=0; i<m; ++i) cin>>a[i];
		mn=1e9;
		dfs(0);
		for(int i=0; i<res.size(); ++i) cout<<res[i]<<" ";
		printf("sum:%d\n",ans);
	}
	return 0;
}