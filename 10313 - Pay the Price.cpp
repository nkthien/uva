#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

long long n,dp[305][305];
string line;

long long query(int n, int l, int r)
{
	if(r>300) r=300;
	if(l>300) l=300;
	if(n==0) return l==-1 ? 1:0;
  if(l==-1) return dp[n][r];
	return dp[n][r]-dp[n][l];
}

int main()
{
	dp[0][0]=1;
	for(int k=1; k<=300; ++k) for(int i=k; i<=300; ++i) for(int j=1; j<=i; ++j) dp[i][j]+=dp[i-k][j-1];
	for(int i=1; i<=300; ++i) for(int j=1; j<=300; ++j) dp[j][i]+=dp[j][i-1];
	while(getline(cin,line))
	{
		stringstream ss(line);
		vector<int> v;
		while(ss>>n) v.push_back(n);
		if(v.size()==1) cout<<query(v[0],-1,300);
		else if(v.size()==2) cout<<query(v[0],-1,v[1]);
		else if(v.size()==3) cout<<query(v[0],v[1]-1,v[2]);
		cout<<endl;
	}
	return 0;
}