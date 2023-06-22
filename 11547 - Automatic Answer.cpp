#include<iostream>
using namespace std;

int n,num;

int main()
{
	cin>>n;
	for(int i=0; i<n; ++i)
	{
		cin>>num;
		int res=(num*315+36962)/10 % 10;
		cout<<(res<0 ? res*-1:res)<<endl;
	}
	return 0;
}