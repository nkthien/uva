#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int t,num;
string val;
string line;

int main()
{
	cin>>t; cin.get();
	while(t--)
	{
		cin.get();
		getline(cin,line);
		stringstream in(line);
		vector<int> idx;
		while(in>>num) idx.push_back(num-1);
		int sz=idx.size();
		int cnt=0;
		vector<string> res(sz);
		getline(cin,line);
		in<<line;
		while(in>>val) res[idx[cnt++]]=val;
		for(int i=0; i<sz; ++i) cout<<res[i]<<endl;
		if(t!=0) cout<<endl;
	}
	return 0;
}