#include<iostream>
using namespace std;

int n,mx,cnt;
string b[5];
bool rook[5][5];

bool save(int x, int y)
{
	for(int i=x+1; i<n; ++i) if(rook[i][y]==true) return false; else if(b[i][y]=='X') break;
	for(int i=x-1; i>=0; --i) if(rook[i][y]==true) return false; else if(b[i][y]=='X') break;
	for(int i=y+1; i<n; ++i) if(rook[x][i]==true) return false; else if(b[x][i]=='X') break;
	for(int i=y-1; i>=0; --i) if(rook[x][i]==true) return false; else if(b[x][i]=='X') break;
	return true;
}

void dfs(int i)
{
	for(; i<n; ++i) for(int j=0; j<n; ++j) if(!rook[i][j])
	{
		if(b[i][j]=='.' && save(i,j)) 
		{
			cnt++;
			rook[i][j]=true;
			dfs(i);
			cnt--;
			rook[i][j]=false;
		}
	}
	if(i==n) mx=max(mx,cnt);
}

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>b[i];
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) rook[i][j]=false;
		mx=0, cnt=0;
		dfs(0);
		cout<<mx<<endl;
	}
	return 0;
}