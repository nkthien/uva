#include<iostream>
using namespace std;

const int n=5, v[]={1,5,10,25,50};

unsigned long long res[10000],M;

int main()
{
	res[0]=1;
	for(int i=0; i<n; ++i) for(int m=1; m<=7489; ++m) if(m>=v[i]) res[m]+=res[m-v[i]];
	while(cin>>M) cout<<res[M]<<endl;	
	return 0;
}