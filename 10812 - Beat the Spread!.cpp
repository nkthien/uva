#include<iostream>
using namespace std;

int t,a,b;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int sum=a+b;
		int ansa=sum/2;
		int ansb=a-sum/2;
		if(ansa<0 || ansb<0 || ansa-ansb!=b) cout<<"impossible\n";
		else cout<<sum/2<<" "<<a-sum/2<<endl;
	}
	return 0;
}