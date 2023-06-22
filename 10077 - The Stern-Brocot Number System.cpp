#include<iostream>
using namespace std;

int m,n,cnt,a[100000];

void solve(int l1, int l2, int r1, int r2)
{
	int m1=l1+r1, m2=l2+r2;
	if((double)m1/m2==(double)m/n) return;
	else if((double)m1/m2>(double)m/n) a[cnt++]=0, solve(l1,l2,m1,m2);
	else a[cnt++]=1, solve(m1,m2,r1,r2);
}

int main()
{
	while(1)
	{
		cin>>m>>n;
		if(m==1 && n==1) break;
		cnt=0;
		solve(0,1,1,0);
		for(int i=0; i<cnt; ++i) cout<<(a[i] ? "R":"L"); 
		cout<<endl;
	}
	return 0;
}