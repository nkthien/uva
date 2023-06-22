#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int t,n,m;
string s;

int cal(string s)
{
	int cnt=0;
	for(int i=0; i<n-1; ++i) for(int j=i+1; j<n; ++j) if(s[j]<s[i]) cnt++;
	return cnt;
}

bool cmp(pair<int,string> a, pair<int,string> b)
{
	return a.first<b.first;
}

int main()
{
	cin>>t;
	while(t--)
	{
		pair<int,string> p[110];
		cin>>n>>m;
		for(int i=0; i<m; ++i) 
		{
			cin>>s;
			p[i]={cal(s),s};
		}
		stable_sort(p,p+m,cmp);
		for(int i=0; i<m; ++i) cout<<p[i].second<<endl;
		if(t) puts("");
	}
	return 0;
}