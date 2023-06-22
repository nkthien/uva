#include<iostream>
using namespace std;

int n;

bool check(int u, int v)
{
	bool vis[11];
	for(int i=0; i<10; ++i) vis[i]=false;
	if(u<10000) vis[0]=true;
	while(u!=0)
	{
		if(vis[u%10]) return false;
		else vis[u%10]=true;
		u/=10;
	}
	while(v!=0)
	{
		if(vis[v%10]) return false;
		else vis[v%10]=true;
		v/=10;
	}
	return true;
}

int main()
{
	bool first=true;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		bool isOk=false;
		if(!first) puts("");
		else first=false;
		for(int i=1234; i<50000; ++i)
		{
			int j=i*n;
			if(j>=12345 && j<=98765 && check(i,j)) 
			{
				printf("%05d / %05d = %d\n",j,i,n);
				isOk=true;
			}
		}
		if(!isOk) printf("There are no solutions for %d.\n",n);
	}
}