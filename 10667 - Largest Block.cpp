#include<iostream>
using namespace std;

int t,n,m,a[105][105],x1,x2,y1,y2;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) a[i][j]=0;
		while(m--)
		{
			cin>>x1>>y1>>x2>>y2; x1--, x2--, y1--, y2--;
			for(int i=x1; i<=x2; ++i) for(int j=y1; j<=y2; ++j) a[i][j]=1;
		}
		int ans=0;
		for(int i=0; i<n; ++i) 
		{
			int tmp[n]={};
			for(int j=i; j<n; ++j) 
			{
				int cnt=0, longest=0;
				for(int k=0; k<n; ++k)
				{
					tmp[k]+=a[k][j];
					if(tmp[k]==0) cnt++, longest=max(longest, cnt);
					else cnt=0;
				}
				ans=max(ans, longest*(j-i+1));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}