#include<iostream>
using namespace std;

int t,n,a[30][30];
string line;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>line;
		n=line.length();
		for(int i=0; i<n; ++i)
		{
			if(line[i]=='0') a[0][i]=0;
			else a[0][i]=1;
		} 
		for(int i=1; i<n; ++i) 
		{
			cin>>line;
			for(int j=0; j<n; ++j)
			{
				if(line[j]=='0') a[i][j]=0;
				else a[i][j]=1;
			}
		}
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
		{
			if(i>0) a[i][j]+=a[i-1][j];
			if(j>0) a[i][j]+=a[i][j-1];
			if(i>0 && j>0) a[i][j]-=a[i-1][j-1];
		}
		int ans=0;
		for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
		for(int k=i; k<n; ++k) for(int l=j; l<n; ++l)
		{
			int sum=a[k][l];
			if(i>0) sum-=a[i-1][l];
			if(j>0) sum-=a[k][j-1];
			if(i>0 && j>0) sum+=a[i-1][j-1];
			int area=(k-i+1)*(l-j+1);
			if(area==sum) ans=max(ans, sum);
		}
		cout<<ans<<endl;
		if(t) cout<<endl;
	}
	return 0;
}