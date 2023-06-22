#include<iostream>
#include<string>
using namespace std;

int n,p,r,mxCmp;
double prc,mnPrc;
string line,name,ans;

int main()
{
	int tc=1;
	while(1)
	{
		cin>>n>>p; cin.get();
		if(n==0) break;
		if(tc!=1) cout<<endl;
		for(int i=0; i<n; ++i) getline(cin,line);
		mxCmp=0, mnPrc=1e9;
		for(int i=0; i<p; ++i)
		{
			getline(cin,name);
			int cmp=0;
			cin>>prc>>r; cin.get();
			for(int i=0; i<r; ++i) getline(cin,line);
			if(mxCmp<r)
			{
				mxCmp=r;
				ans=name;
				mnPrc=prc;
			}
			else if(mxCmp==r && prc<mnPrc)
			{
				mnPrc=prc;
				ans=name;
			}
		}
		printf("RFP #%d\n%s\n", tc++,ans.c_str());
	}
	return 0;
}