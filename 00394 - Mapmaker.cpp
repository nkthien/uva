#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

const int N = 100;

int n,m;
int C[N][11],l[N][11],r[N][11];
int B[N],sz[N],d[N];
int idx[11];
string name;

int main()
{
	cin>>n>>m;
	unordered_map<string,int> mp;
	for(int i=0; i<n; ++i)
	{
		cin>>name>>B[i]>>sz[i]>>d[i];
		mp[name]=i;
		for(int j=1; j<=d[i]; ++j) cin>>l[i][j]>>r[i][j];
		C[i][d[i]]=sz[i];
		for(int j=d[i]-1; j>0; --j) C[i][j] = (r[i][j+1] - l[i][j+1] + 1)*C[i][j+1];
	}
	for(int i=0; i<m; ++i)
	{
		cin>>name;
		int cur=mp[name];
		for(int j=1; j<=d[cur]; ++j) cin>>idx[j];
		int ans=B[cur];
		cout<<name<<"[";
		for(int j=1; j<=d[cur]; ++j) 
		{
			cout<<idx[j];
			if(j!=d[cur]) cout<<", ";
			ans -= (l[cur][j] - idx[j])*C[cur][j];
		}
		cout<<"] = "<<ans<<endl;;
	}

	return 0;
}