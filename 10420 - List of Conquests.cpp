#include<iostream>
#include<string>
#include<unordered_set>
#include<map>
#include<sstream>
#include<vector>
using namespace std;

int n;
string line;

int main()
{
	cin>>n;
	cin.get();
	map<string,int> mp;
	unordered_set<string> st;
	while(getline(cin,line))
	{
		stringstream ss(line);
		vector<string> v;
		string word;
		while(getline(ss,word,' ')) v.push_back(word);
		/*string tmp = "";
		int sz=v.size();
		for(int i=1; i<sz-1; ++i) tmp += v[i]+" ";
		tmp += v[sz-1];
		if(st.find(tmp)==st.end()) mp[v[0]]++, st.insert(tmp);*/
		mp[v[0]]++;
	}
	for(auto i : mp) cout<<i.first<<" "<<i.second<<endl;
	return 0;
}