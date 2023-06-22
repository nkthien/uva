#include<iostream>
using namespace std;

int n,a[20];
bool vis[20],isPrime[35];

void dfs(int idx)
{
	if(idx==n)
	{
		for(int i=0; i<n; ++i) printf("%d%c",a[i],i==n-1 ? '\n':' ');
		return;
	}
	for(int i=2; i<=n; ++i) if(!vis[i])
	{
		if(!isPrime[a[idx-1]+i]) continue;
		if(idx==n-1 && !isPrime[a[0]+i]) continue; 
		a[idx]=i;
		vis[i]=true;
		dfs(idx+1);
		vis[i]=false;
	}
}

int main()
{	
	for(int i=2; i<=32; ++i) isPrime[i]=true;
	for(int i=2; i<=5; ++i)
	{
		if(!isPrime[i]) continue;
		for(int j=i+i; j<=32; j+=i) isPrime[j]=false;
	}
	int tc=0;
	while(cin>>n)
	{
		if(tc) puts("");
		printf("Case %d:\n",++tc);
		a[0]=1;
		dfs(1);
	}
	return 0;
}