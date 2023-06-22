#include<iostream>
#include<set>
#include<unordered_map>
#include<sstream>
using namespace std;

string line;
set<int> st[12];
unordered_map<string,int> mp;
bool ok[12];

const int dx[7]={0,2,4,5,7,9,11};
const string keys[12]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

int main()
{
	mp["C"]=0;
	mp["C#"]=1;
	mp["D"]=2;
	mp["D#"]=3;
	mp["E"]=4;
	mp["F"]=5;
	mp["F#"]=6;
	mp["G"]=7;
	mp["G#"]=8;
	mp["A"]=9;
	mp["A#"]=10;
	mp["B"]=11;
	for(int i=0; i<12; ++i) for(int j=0; j<7; ++j) st[i].insert((i+dx[j]) % 12);
	while(getline(cin,line))
	{
		if(line=="END") break;
		for(int i=0; i<12; ++i) ok[i]=true;
		stringstream ss(line);
		string word;
		while(getline(ss,word,' ')) for(int i=0; i<12; ++i) if(st[i].find(mp[word])==st[i].end()) ok[i]=false;
		bool first=true;
		for(int i=0; i<12; ++i) if(ok[i]) 
		{
			if(!first) cout<<" ";
			else first=false;
			cout<<keys[i];
		}
		puts("");
	}
	return 0;
}