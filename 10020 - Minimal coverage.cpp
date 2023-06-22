#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t,M,a,b;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second<b.second;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>M;
		vector<pair<int,int>> v;
		while(1)
		{
			cin>>a>>b;
			if(a==0 && b==0) break;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end(),cmp);
		int sz=v.size(), cur=0, cnt=0;
		vector<pair<int,int>> res;
		while(cur<M)
		{
			bool isOk=false;
			for(int i=sz-1; i>=0; --i) if(v[i].second>cur && v[i].first<=cur)
			{
				isOk=true;
				cnt++;
				cur=v[i].second;
				res.push_back({v[i].first,v[i].second});
				break;
			}
			if(!isOk) break;
		}
		if(cur<M) cout<<"0\n";
		else 
		{
			cout<<cnt<<endl;
			for(auto i:res) printf("%d %d\n",i.first,i.second);
		}
		if(t) cout<<endl;
	}
	return 0;
}