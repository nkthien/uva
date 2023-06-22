#include<iostream>
using namespace std;

int t,n,a[155][155];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) 
		{
			cin>>a[i][j];
			a[i+n][j]=a[i][j+n]=a[i+n][j+n]=a[i][j];
		}
		int ans=-100*200*200;
		for(int i=0; i<n; ++i)
		{
			int tmp[2*n]={};
			for(int j=i; j<i+n; ++j)
			{
				for(int k=0; k<2*n; ++k) tmp[k]+=a[k][j];
				for(int k=0; k<n; ++k) 
				{
					int sum=0;
					for(int l=k; l<k+n; ++l)
					{
						sum=max(sum,0) + tmp[l];
						ans=max(ans,sum);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


// accumulate sum

/*#include<iostream>
using namespace std;

int t,n,a[155][155];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1; i<=2*n; ++i) for(int j=1; j<=2*n; ++j) 
		{
			if(i<=n && j<=n)
			{
				cin>>a[i][j];
				a[i+n][j]=a[i][j+n]=a[i+n][j+n]=a[i][j];
			}
			a[i][j]+=a[i-1][j];
			a[i][j]+=a[i][j-1];
			a[i][j]-=a[i-1][j-1];
		}
		int ans=-100*200*200;
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
		for(int k=i; k<i+n; ++k) for(int l=j; l<j+n; ++l)
		{
			int sum=a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1];
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}*/