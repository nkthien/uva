#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int t;
long long n, fac[22];
string str;

int main()
{
	fac[0]=fac[1]=1; 
	for(int i=2; i<20; ++i) fac[i]=fac[i-1]*i;
	cin>>t;
	for(int tc=0; tc<t; ++tc)
	{
		cin>>str>>n;
		sort(str.begin(), str.end());
		int sz=str.length();
		while(sz!=0)
		{
			long long fc=fac[sz-1];
			long long idx=n/fc;
			cout<<str[idx];
			str.erase(idx,1);
			n%=fc;
			sz-=1;
		}
		cout<<endl;
	}
	return 0;
}