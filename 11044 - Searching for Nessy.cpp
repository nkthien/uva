#include<iostream>
using namespace std;

int t,m,n;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>n; m-=2,n-=2;
		int cnt1=m/3;
		if(m%3!=0) cnt1++;
		int cnt2=n/3;
		if(n%3!=0) cnt2++;
		cout<<cnt1*cnt2<<endl;
	}
	return 0;
}
