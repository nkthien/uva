#include<iostream>
#include<set>
using namespace std;

long long n,m,b,l,h,sum;

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		multiset<int> st;
		sum=0;
		for(int i=0; i<n; ++i)
		{
			cin>>m;
			for(int j=0; j<m; ++j)
			{
				cin>>b;
				st.insert(b);
			}
			l=*st.begin();
			h=*st.rbegin();
			sum+=h-l;
			st.erase(st.begin());
			st.erase(--st.end());
		}
		cout<<sum<<endl;
	}
	return 0;
}