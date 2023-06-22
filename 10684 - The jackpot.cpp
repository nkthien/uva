#include<iostream>
using namespace std;

int n,x;

int main()
{
	while(cin>>n && n)
	{
		int sum=0, ans=-1e9;
		for(int i=0; i<n; ++i) 
		{
			cin>>x;
			sum+=x;
			ans=max(ans,sum);
			if(sum<0) sum=0;
		}
		if(ans>0) printf("The maximum winning streak is %d.\n", ans);
		else printf("Losing streak.\n");
	}
	return 0;
}