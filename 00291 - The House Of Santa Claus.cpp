#include<iostream>
using namespace std;

int a[5][5]={
	{0,1,1,0,1},
	{1,0,1,0,1},
	{1,1,0,1,1},
	{0,0,1,0,1},
	{1,1,1,1,0}
};
int res[10];

void solve(int idx, int cur)
{
	res[idx]=cur+1;
	if(idx==8)
	{
		for(int i=0; i<9; ++i) cout<<res[i]; cout<<endl;
		return;
	}
	for(int i=0; i<5; ++i) if(a[cur][i]==1)
	{
		a[cur][i]=a[i][cur]=0;
		solve(idx+1,i);
		a[cur][i]=a[i][cur]=1;
	}
}

int main()
{
	solve(0,0);
	return 0;
}