#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string name;
unordered_map<char,char> mp;

bool check(int j)
{
	if(mp[name[j]]==0 || mp[name[j]]==mp[name[j-1]]) return false;
	return true;
}

int main()
{
	mp['A']=0;
	mp['E']=0;
	mp['I']=0;
	mp['O']=0;
	mp['U']=0;
	mp['Y']=0;
	mp['W']=0;
	mp['H']=0;
	mp['P']=1;
	mp['B']=1;
	mp['F']=1;
	mp['V']=1;
	mp['C']=2;
	mp['S']=2;
	mp['K']=2;
	mp['G']=2;
	mp['J']=2;
	mp['Q']=2;
	mp['X']=2;
	mp['Z']=2;
	mp['D']=3;
	mp['T']=3;
	mp['L']=4;
	mp['M']=5;
	mp['N']=5;
	mp['R']=6;

	cout<<string(9,' ')<<"NAME"<<string(21,' ')<<"SOUNDEX CODE\n";
	while(getline(cin,name))
	{
		int sz=name.length();
		cout<<string(9,' ');
		cout<<name;
		cout<<string(25-sz,' ');
		string ans = "0000";
		ans[0]=name[0];
		int i=1,j=1;
		while(i<=4)
		{
			while(j<=sz && !check(j)) j++;
			if(j>=sz) break;
			ans[i++]=mp[name[j++]]+'0';
		}
		cout<<ans<<endl;
	}
	cout<<string(19,' ')<<"END OF OUTPUT\n";
	return 0;
}