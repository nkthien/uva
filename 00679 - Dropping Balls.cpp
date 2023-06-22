#include<iostream>
using namespace std;

int t,j,d,i,a[25];

void solve(int idx, int num)
{
	if(idx==-1) return;
	if(num&1) a[idx]=0, solve(idx-1,num/2+1);
	else a[idx]=1, solve(idx-1,num/2);
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>d>>i;
		a[d-1]=1;
		solve(d-2,i%(1<<(d-1)));
		int ans=0;
		for(int i=d-1; i>=0; --i) if(a[i]) ans+=1<<i;
		cout<<ans<<endl;	
	}
	cin>>j;
	return 0;
}


// children node number is answer -_-!

/*#include<iostream>
using namespace std;

int t,j,d,k;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>d>>k;
		int ans=1;
		for(int i=1; i<d; ++i)
		{
			if(k&1) ans=2*ans;
			else ans=2*ans+1;
			k=(k+1)/2;
		}
		cout<<ans<<endl;
	}
	cin>>j;
	return 0;
}*/