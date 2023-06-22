#include<iostream>
#include<queue>
#include<string>
using namespace std;

int t,l,m,a,b;
string str;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>l>>m;
		l*=100;
		queue<int> qu[3];
		for(int i=0; i<m; ++i)
		{
			cin>>a>>str;
			if(str=="left") b=0;
			else b=1;
			qu[b].push(a);
		}
		int cur=0,ans=0;
		while(!qu[0].empty() || !qu[1].empty())
		{
			int tmp=l;
			while(!qu[cur].empty() && qu[cur].front()<=tmp) tmp-=qu[cur].front(), qu[cur].pop();
			ans+=1, cur^=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}