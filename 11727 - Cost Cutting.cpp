#include<iostream>
using namespace std;

int t,a,b,c;

int main()
{
	cin>>t;
	for(int tc=0; tc<t; ++tc)
	{
		cin>>a>>b>>c;
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		printf("Case %d: %d\n",tc+1,b);
	}
	return 0;
}