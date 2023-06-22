#include<iostream>
using namespace std;

int t,n,m;
string ans;

void dfs(int idx, int cnt)
{
	if(cnt>m) return;
	if(m-cnt>n-idx) return;
	if(idx==n)
	{
		cout<<ans<<endl;
		return;
	}
	ans[idx]='0';
	dfs(idx+1,cnt);
	ans[idx]='1';
	dfs(idx+1,cnt+1);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ans=string(n,'0');
		dfs(0,0);
		if(t) puts("");
	}
	return 0;
}