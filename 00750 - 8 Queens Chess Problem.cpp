#include<iostream>
#include<algorithm>
using namespace std;

int t,x,y,b[100][10];
int a[]={0,1,2,3,4,5,6,7,8};

bool check()
{
	for(int i=1; i<=8; ++i) for(int j=1; j<=8; ++j)
	{
		if(i!=j && abs(i-j)==abs(a[i]-a[j])) return false;
	}
	return true;
}

int main()
{
	int n=0;
	do
	{
		if(check())
		{
			for(int i=1; i<=8; ++i) b[n][i]=a[i];
			n++;
		}
	} while(next_permutation(a+1,a+9));
	
	cin>>t;
	while(t--)
	{
		cin>>x>>y;
		int cnt=1;
		cout<<"SOLN       COLUMN\n";
		cout<<" #      1 2 3 4 5 6 7 8\n\n";
		for(int i=0; i<n; ++i) if(b[i][y]==x)
		{
			printf("%2d      ",cnt++);
			for(int j=1; j<=8; ++j)
			{
				cout<<b[i][j];
				if(j!=8) cout<<" ";
			}
			cout<<endl;	
		}
		if(t) puts("");
	}
	return 0;
}