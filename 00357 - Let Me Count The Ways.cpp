#include<iostream>
using namespace std;

const int n=5, v[]={1,5,10,25,50};

unsigned long long res[30030],M;

int main()
{
	res[0]=1;
	for(int i=0; i<n; ++i) for(int m=1; m<=30000; ++m) if(m>=v[i]) res[m]+=res[m-v[i]];
	while(cin>>M)
	{
		if(res[M]==1) printf("There is only 1 way to produce %lld cents change.\n",M);
		else printf("There are %lld ways to produce %lld cents change.\n",res[M],M);
	}	
	return 0;
}