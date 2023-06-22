#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int t,n,m,b,c,k;
string cake,name,type;

struct Flavor
{
	string name;
	int cost;
};

bool cmp(Flavor a, Flavor b)
{
	return a.cost==b.cost ? a.name<b.name : a.cost<b.cost;
}

int main()
{
	cin>>t; cin.get();
	while(t--)
	{
		vector<Flavor> res;
		map<string,int> mp;
		getline(cin,cake);
		transform(cake.begin(), cake.end(), cake.begin(), ::toupper);
		cin>>m>>n>>b;
		for(int i=0; i<m; ++i)
		{
			cin>>name>>c;
			mp[name]=c;
		}
		cin.get();
		for(int i=0; i<n; ++i)
		{
			int sum=0;
			getline(cin,type);
			cin>>k;
			for(int j=0; j<k; ++j)
			{
				cin>>name>>c;
				sum+=mp[name]*c;
			}
			if(sum<=b) 
			{
				Flavor tmp;
				tmp.name=type;
				tmp.cost=sum;
				res.push_back(tmp);
			}
			cin.get();
		}
		sort(res.begin(), res.end(), cmp);
		cout<<cake<<endl;
		if(res.size()) for(auto i:res) cout<<i.name<<endl;
		else cout<<"Too expensive!\n";
		cout<<endl;
	}
	return 0;
}