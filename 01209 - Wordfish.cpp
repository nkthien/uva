#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string name,ans;
int mx;

void check()
{
	int mn=30;
	string save;
	for(int i=0; i<name.length()-1; ++i)
	{
		int test=abs(name[i]-name[i+1]);
		if(mn>test)
		{
			save=name;
			mn=test;
		}
	}
	if(mn>mx)
	{
		mx=mn;
		ans=save;
	}
}

int main()
{
	while(getline(cin,name))
	{
		mx=0;
		for(int i=0; i<=10; ++i) if(!prev_permutation(name.begin(), name.end())) break;
		for(int i=0; i<=20; ++i) if(next_permutation(name.begin(), name.end())) check();
		cout<<ans<<mx<<endl;
	}
	return 0;
}