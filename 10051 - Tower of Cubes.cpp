#include<iostream>
using namespace std;

const int bot[]={1,0,3,2,5,4};
const string side[]={"front","back","left","right","top","bottom"};

int n,a[505][10],best[505][10];
pair<int,int> path[505][10], last;

void print_path(pair<int,int> p)
{
	if(p.first==-1 && p.second==-1) return;
	print_path(path[p.first][p.second]);
	cout<<p.first+1<<" "<<side[p.second]<<endl;
}

int main()
{
	int tc=0;
	while(cin>>n && n)
	{
		for(int i=0; i<n; ++i) for(int j=0; j<6; ++j) cin>>a[i][j], best[i][j]=1, path[i][j]={-1,-1};
		for(int i=1; i<n; ++i) for(int j=0; j<i; ++j)
		{
			for(int p=0; p<6; ++p) for(int q=0; q<6; ++q)
			{
				if(a[i][p]==a[j][bot[q]] && best[i][p]<best[j][q]+1)
				{
					best[i][p]=best[j][q]+1;
					path[i][p]={j,q};
				}
			}
		}	
		int ans=0;
		for(int i=0; i<n; ++i) for(int j=0; j<6; ++j) if(ans<best[i][j]) ans=best[i][j], last={i,j};
		if(tc) cout<<endl;
		printf("Case #%d\n%d\n",++tc,ans);
		print_path(last);
	}
	return 0;
}