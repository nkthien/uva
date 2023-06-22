#include<iostream>
#include<bitset>
using namespace std;

int num;

int main()
{
	while(cin>>num)
	{
		cout<<num<<" converts to ";
		bitset<32> bnum(num);
		bitset<32> bres(0);
		int j=31;
		for(int i=7; i>=0; --i) bres[j--]=bnum[i];
		for(int i=15; i>=8; --i) bres[j--]=bnum[i];
		for(int i=23; i>=16; --i) bres[j--]=bnum[i];
		for(int i=31; i>=24; --i) bres[j--]=bnum[i];
		int res=(int)(bres.to_ulong());
		cout<<res<<endl;
	}
	return 0;
}