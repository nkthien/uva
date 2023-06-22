#include<iostream>
#include<map>
#include<iomanip>
using namespace std;

int t;
string line;

int main()
{
	cin>>t;
	cin.get();
	cin.get();	
	while(t--)
	{
		map<string,double> mp;
		double cnt=0;
		while(getline(cin,line) && line!="\0")
		{
			mp[line]++;
			cnt++;
		}
		cout<<fixed<<setprecision(4);
		for(auto i : mp) cout<<i.first<<" "<<i.second*100.0/cnt<<endl;
		if(t) cout<<endl;
	}
	return 0;
}
