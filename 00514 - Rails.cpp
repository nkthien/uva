#include<iostream>
#include<stack>
using namespace std;

int n,a[1010],tmp;

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		while(1)
		{
			cin>>tmp;
			if(tmp==0) break;
			a[0]=tmp;
			for(int i=1; i<n; ++i) cin>>a[i];
			stack<int> stk;
			int cur=1;
			bool ok=true;
			for(int i=0; i<n; ++i)
			{
				while(cur<=a[i]) stk.push(cur++);
				if(!stk.empty() && a[i]==stk.top()) 
				{
					stk.pop();
					continue;
				}
				else 
				{
					ok=false;
					break;
				}
			}
			if(ok) cout<<"Yes\n";
			else cout<<"No\n";
		}
		cout<<endl;
	}
	return 0;
}
