#include<iostream>
using namespace std;

int t,m,n,a[25][25],dp[25][210];

int dfs(int idx, int cur)
{
	if(cur<0) return -1;
	if(idx==n) return m-cur;
	if(dp[idx][cur]!=-1) return dp[idx][cur];
	int res=-1;
	for(int i=1; i<=a[idx][0]; ++i) res=max(res, dfs(idx+1,cur-a[idx][i]));
	return dp[idx][cur]=res;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=0; i<n; ++i)
		{
			cin>>a[i][0];
			for(int j=1; j<=a[i][0]; ++j) cin>>a[i][j];
		}
		for(int i=0; i<20; ++i) for(int j=0; j<=200; ++j) dp[i][j]=-1;
		int ans=dfs(0,m);
		if(ans<0) cout<<"no solution\n";
		else cout<<ans<<endl;
	}
	return 0;
}


// bottom up sol

/*#include<iostream>
using namespace std;

int t,n,m,a[25][25];
bool canReach[25][210];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=0; i<n; ++i)
		{
			cin>>a[i][0];
			for(int j=1; j<=a[i][0]; ++j) cin>>a[i][j];
		}
		for(int i=0; i<n; ++i) for(int j=0; j<=m; ++j) canReach[i][j]=false;
		for(int i=1; i<=a[0][0]; ++i) if(a[0][i]<=m) canReach[0][m-a[0][i]]=true; // base case
		for(int i=0; i<n-1; ++i) for(int j=0; j<=m; ++j)
		{
			if(canReach[i][j]) for(int k=1; k<=a[i+1][0]; ++k) 
			{
				if(j-a[i+1][k]>=0) canReach[i+1][j-a[i+1][k]]=true;
			}
		}
		int j=0;
		while(j<=m && canReach[n-1][j]==false) j++;
		if(j==m+1) cout<<"no solution\n";
		else cout<<m-j<<endl;
	}
	return 0;
}*/


// funny TLE sol, maybe becuase init too many vectors in loop

/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t,n,M,m;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>M>>n;
		vector<vector<int>> garments(n);
		for(int i=0; i<n; ++i)
		{
			cin>>m;
			while(m--)
			{
				int tmp; cin>>tmp;
				garments[i].push_back(tmp);
			}
		}
		// vector<int> res;
		// res.push_back(0); // base case
		// for(auto gar:garments)
		// {
		// 	vector<int> cur;  // ???
		// 	for(auto r:res) for(auto i:gar) if(r+i<=M) cur.push_back(r+i);
		// 	res=cur;	
		// }
		// auto ans=max_element(res.begin(), res.end());
		// if(ans!=res.end()) cout<<*ans<<endl;
		// else cout<<"no solution\n";

		vector<bool> res(M);  // fix init and assign vector in loop --> accepted
		vector<bool> old(M);
		res[0]=true;  // base case
		for(auto gar:garments)
		{
			for(int i=0; i<=M; ++i) old[i]=res[i], res[i]=0;
			for(int i=0; i<=M; ++i) if(old[i]) for(auto g:gar) if(i+g<=M) res[i+g]=true;
		}
		int ans=0;
		for(int i=M; i>=0 && !ans; --i) if(res[i]) ans=i;
		if(ans) cout<<ans<<endl;
		else cout<<"no solution\n";
	}
	return 0;
}*/