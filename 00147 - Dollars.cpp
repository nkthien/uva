#include<iostream>
#include<iomanip>
using namespace std;

const int n=11;
const int v[]={5,10,20,50,100,200,500,1000,2000,5000,10000};

unsigned long long res[30030],M;
double d;

int main()
{
	cout<<fixed<<setprecision(2);
	res[0]=1;
	for(int i=0; i<n; ++i) for(int m=5; m<=30000; m+=5) if(m>=v[i]) res[m]+=res[m-v[i]];
	while(1)
	{
		cin>>d;
		if(d==0) break;
		M=d*100+0.5;
		cout<<setw(6)<<d<<setw(17)<<res[M]<<endl;
	}
	return 0;
}