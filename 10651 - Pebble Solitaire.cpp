#include <iostream>
using namespace std;

int t,dp[1 << 12];
string s;

int play(string str, int mask)
{
	if(dp[mask] != -1) return dp[mask];
	int res=0;
	bool found=false;
	for(int i=0; i<10; ++i)
	{
		string cur=str.substr(i,3);
		if(cur == "-oo")
		{
			int new_mask=mask;
			new_mask|=(1 << i);
			new_mask^=(1 << (i+1));
			new_mask^=(1 << (i+2));
			
			string new_str=str;
			new_str[i]='o';
			new_str[i+1]='-';
			new_str[i+2]='-';
			
			res=max(res, play(new_str, new_mask));
			found=true;
		}
		else if(cur == "oo-")
		{
			int new_mask=mask;
			new_mask|=(1 << (i+2));
			new_mask^=(1 << i);
			new_mask^=(1 << (i+1));
			
			string new_str=str;
			new_str[i]='-';
			new_str[i+1]='-';
			new_str[i+2]='o';
			
			res=max(res, play(new_str, new_mask));
			found=true;
		}
	}
	if(!found) return 0;
	return dp[mask]=res+1;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		for(int i=0; i<(1 << 12); ++i) dp[i]=-1;
		int p=0, k=0;
		for(int i=0; i<12; ++i) if(s[i] == 'o') p+=1, k |= (1 << i);
		cout<<p-play(s,k)<<endl;
	}
	return 0;
}
