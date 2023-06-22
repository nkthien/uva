#include<iostream>
using namespace std;

int n,a[105][105];

int main()
{
	while(cin>>n)
	{
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin>>a[i][j];
		int ans=-127*100*100;
		for(int i=0; i<n; ++i)
		{
			int tmp[n]={};
			for(int j=i; j<n; ++j)
			{
				int sum=0;
				for(int k=0; k<n; ++k) 
				{
					tmp[k]+=a[k][j];
					sum=max(sum,0)+tmp[k];    // kadane algorithm
					ans=max(ans,sum);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


// O(n^4)

/*#include<iostream>
using namespace std;

int n,a[105][105];

int main()
{
	while(cin>>n)
	{
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
		{
			cin>>a[i][j];
			if(i>0) a[i][j]+=a[i-1][j];
			if(j>0) a[i][j]+=a[i][j-1];
			if(i>0 && j>0) a[i][j]-=a[i-1][j-1];
		}
		int ans=-127*100*100;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
		for(int k=i; k<n; ++k) for(int l=j; l<n; ++l)
		{
			int subRect=a[k][l];
			if(i>0) subRect-=a[i-1][l];
			if(j>0) subRect-=a[k][j-1];
			if(i>0 && j>0) subRect+=a[i-1][j-1];
			ans=max(ans, subRect);
		}
		cout<<ans<<endl;
	}
	return 0;
}*/