#include<iostream>
using namespace std;

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int t,n,m,a[110][110],ans;
string name;

void dfs(int x, int y, int cnt)
{
	bool isOk=true;
	for(int i=0; i<4; ++i)
	{
		int newx=x+dx[i], newy=y+dy[i];
		if(newx>=0 && newx<n && newy>=0 && newy<m && a[newx][newy]<a[x][y])
		{
			dfs(newx,newy,cnt+1);
			isOk=false;
		}
	}
	if(isOk)
	{
		ans=max(ans,cnt);
		return;
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>name>>n>>m;
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>a[i][j];
		ans=0;
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) dfs(i,j,1);
		printf("%s: %d\n",name.c_str(),ans);
	}
	return 0;
}


// memoize sol

/*#include<iostream>
using namespace std;

#define tx x+dx[i]
#define ty y+dy[i]

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int t,n,m,a[110][110],dp[110][110];
int cnt;
string name;

int dfs(int x, int y)
{
	if(dp[x][y]) return dp[x][y];
	int mx=0;
	for(int i=0; i<4; ++i) if(tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]<a[x][y]) mx=max(mx,dfs(tx,ty));
	dp[x][y]=mx+1;
	return mx+1;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>name>>n>>m;
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>a[i][j], dp[i][j]=0;
		int ans=0;
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) ans=max(ans,dfs(i,j));
		printf("%s: %d\n",name.c_str(),ans);	
	}
	return 0;
}*/