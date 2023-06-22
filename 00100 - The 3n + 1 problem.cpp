#include<iostream>
using namespace std;

int l,r;

int findNumCycle(int i)
{
	if(i==1) return 1;
	if(i&1) return 1+findNumCycle(3*i+1);
	else return 1+findNumCycle(i/2);
}

int main()
{
	while(scanf("%d%d",&l,&r) != -1)
	{
		printf("%d %d ",l,r);
		if(l > r) swap(l,r);
		int mx=0;
		for(int i=l; i<=r; ++i) mx=max(mx,findNumCycle(i));
		printf("%d\n",mx);
	}
	return 0;
}