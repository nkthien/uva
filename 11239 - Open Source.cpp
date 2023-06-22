#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

string line;

struct Project
{
	string name;
	int cnt;
};

bool cmpProject(Project &a, Project &b)
{
	return a.cnt==b.cnt ? a.name<b.name : a.cnt>b.cnt;
}

int main()
{
	map<string,set<string>> mp;
	set<string> all;
	set<string> ban;
	string prj;
	vector<Project> arr;
	while(getline(cin,line) && line!="0")
	{
		if(line!="1")
		{
			if(line[0]>='A' && line[0]<='Z')
			{
				prj=line;
				mp.insert({prj,set<string>()});
			}
			else mp[prj].insert(line);
		}
		else
		{
			for(auto i:mp) 
			{
				for(auto j:i.second) if(all.count(j)) ban.insert(j);
				for(auto j:i.second) all.insert(j);
			}
			for(auto i:mp)
			{
				Project tmp;
				tmp.name=i.first;
				tmp.cnt=0;
				for(auto j:i.second) if(!ban.count(j)) tmp.cnt++;
				arr.push_back(tmp);
			}
			sort(arr.begin(), arr.end(), cmpProject);
			for(auto i:arr) cout<<i.name<<" "<<i.cnt<<endl;

			// reset
			arr.clear();
			all=set<string>();
			ban=set<string>();
			mp=map<string,set<string>>();
		}
	}
	return 0;
}


// map student with project name

/*#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

string line;

struct Project
{
	string name;
	int num;
};

bool cmp(Project a, Project b)
{
	return a.num==b.num ? a.name<b.name : a.num>b.num;
}

int main()
{
	while(1)
	{
		string name="";
		map<string,set<string>> pro;
		map<string,string> stu;
		vector<Project> arr;
		while(getline(cin,line))
		{
			if(line=="0") return 0;
			if(line=="1") break;
			if(line[0]>='A' && line[0]<='Z')
			{
				name=line;
				pro.insert(make_pair(name,set<string>()));
			}
			else
			{
				if(!stu.count(line)) pro[name].insert(line), stu[line]=name;
				else if(stu[line]==name);
				else stu[line]="#";
			}
		}
		if(line=="1")
		{
			for(auto i:pro)
			{
				Project tmp;
				tmp.name=i.first;
				tmp.num=0;
				for(auto j:i.second) if(stu[j]!="#") tmp.num++;
				arr.push_back(tmp);	
			}
			sort(arr.begin(), arr.end(), cmp);
			for(auto i:arr) cout<<i.name<<" "<<i.num<<endl;
		}
	}
	return 0;
}*/