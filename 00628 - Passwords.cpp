#include<iostream>
using namespace std;

int n,m,sz;
string word[110],pat,cur[260];

void dfs(int i)
{
	if(i==sz)
	{
		for(int j=0; j<sz; ++j) cout<<cur[j]; cout<<endl;
		return;
	}
	if(pat[i]=='#') for(int j=0; j<n; ++j)
	{
		cur[i]=word[j];
		dfs(i+1);
	}
	else for(int j=0; j<10; ++j)
	{
		cur[i]=to_string(j);
		dfs(i+1);
	}
}

int main()
{
	while(cin>>n)
	{
		for(int i=0; i<n; ++i) cin>>word[i];
		cin>>m;
		cout<<"--\n";
		while(m--) 
		{
			cin>>pat;
			sz=pat.length();
			dfs(0);
		}
	}
	return 0;
}