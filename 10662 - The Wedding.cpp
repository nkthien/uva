#include<iostream>
using namespace std;

int nt,nr,nh,pt[25],pr[25],ph[25],tr[25][25],rh[25][25],ht[25][25];

int main()
{
	while(cin>>nt>>nr>>nh)
	{
		for(int i=0; i<nt; ++i)
		{
			cin>>pt[i];
			for(int j=0; j<nr; ++j) cin>>tr[i][j];
		}
		for(int i=0; i<nr; ++i)
		{
			cin>>pr[i];
			for(int j=0; j<nh; ++j) cin>>rh[i][j];
		}
		for(int i=0; i<nh; ++i)
		{
			cin>>ph[i];
			for(int j=0; j<nt; ++j) cin>>ht[i][j];
		}
		int ans=1e9, savei=-1, savej=-1, savek=-1;
		for(int i=0; i<nt; ++i)
		for(int j=0; j<nr; ++j)
		for(int k=0; k<nh; ++k) if(tr[i][j]!=1 && rh[j][k]!=1 && ht[k][i]!=1)
		{
			int test=pt[i]+pr[j]+ph[k];
			if(test<ans)
			{
				ans=test;
				savei=i;
				savej=j;
				savek=k;
			}
		}
		if(ans!=1e9) printf("%d %d %d:%d\n",savei,savej,savek,ans);
		else printf("Don't get married!\n");
	}
	return 0;
}