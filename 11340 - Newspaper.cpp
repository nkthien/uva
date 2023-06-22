#include<iostream>
using namespace std;

int t,m,n,p;
int v[256],cnt[256];
char c,line[10100];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<256; ++i) cnt[i]=0,v[i]=0;
		for(int i=0; i<n; ++i)
		{
			cin>>c>>p;
			v[c]=p;
		}
		cin>>m; cin.get();
		while(m--)
		{
			gets(line);
			int i=0;
			while(line[i]!='\0') cnt[line[i++]]++;
		}
		int sum=0;
		for(int i=0; i<256; ++i) sum+=cnt[i]*v[i];
		double ans=sum*1.0/100;
		printf("%.2lf$\n",ans);
	}
	return 0;
}