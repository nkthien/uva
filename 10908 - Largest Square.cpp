#include <iostream>
using namespace std;

int t,n,m,q,r,c;
string a[105];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		cout<<n<<" "<<m<<" "<<q<<endl;
		for(int i=0; i<n; ++i) cin>>a[i];
		while(q--)
		{
			cin>>r>>c;
			int ans=1;
			bool ok=true;
			for(int k=0; k<n || k<m; ++k)
			{
				for(int i=r-k; i<=r+k && ok; ++i) for(int j=c-k; j<=c+k && ok; ++j)
				{
					if(i<0 || i>=n || j<0 || j>=m || a[i][j] != a[r][c]) ok=false;
				}
				if(!ok)
				{
					ans=2*k-1;
					break;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}


// O(n^2) sol

/*#include <iostream>
using namespace std;

int t,n,m,q,r,c,ver[105][105],hor[105][105];
string a[105];

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>q;
		cout<<n<<" "<<m<<" "<<q<<endl;
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
		{
			if(j != 0 && a[i][j] == a[i][j-1]) hor[i][j]=hor[i][j-1] + 1;
			else hor[i][j]=1;
		}
		for(int i=0; i<m; ++i) for(int j=0; j<n; ++j)
		{
			if(j != 0 && a[j][i] == a[j-1][i]) ver[j][i]=ver[j-1][i] + 1;
			else ver[j][i]=1;
		}
		while(q--)
		{
			cin>>r>>c;
			int ans=1;
			for(int k=1; k<n || k<m; ++k)
			{
				if(r-k < 0 || r+k >=n || c-k < 0 || c+k >= m) break; 
				if(a[r+k][c-k] != a[r][c] || ver[r+k][c-k] < ans+2) break;
				if(a[r+k][c+k] != a[r][c] || ver[r+k][c+k] < ans+2) break;
				if(a[r-k][c+k] != a[r][c] || hor[r-k][c+k] < ans+2) break;
				if(a[r+k][c+k] != a[r][c] || hor[r+k][c+k] < ans+2) break;
				ans+=2;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}*/
