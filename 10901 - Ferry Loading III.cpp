#include<iostream>
#include<queue>
#include<string>
using namespace std;

int t,n,c,m,a,b,res[10010];
string str;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>c>>m;
		queue<pair<int,int>> qu[3];
		for(int i=0; i<m; ++i) 
		{
			cin>>a>>str;
			if(str=="left") b=0;
			else b=1;
			qu[b].push(make_pair(a,i));
		}
		int side=0,time=0;
		while(!qu[0].empty() || !qu[1].empty())
		{
			// calculate start time, complicated if else

			/*if(!qu[side].empty() && !qu[side^1].empty() && qu[side].front().first>time && qu[side^1].front().first>time)
			{
				if(qu[side]>qu[side^1])
				{
					side^=1;
					time=qu[side].front().first+c;
				}
				else time=qu[side].front().first;
			}
			else if(qu[side].empty() && !qu[side^1].empty() && qu[side^1].front().first>time)
			{
				side^=1;
				time=qu[side].front().first+c;
			}
			else if(!qu[side].empty() && qu[side^1].empty() && qu[side].front().first>time)
			{
				time=qu[side].front().first;
			}*/

			int test=1e9;
			if(!qu[side].empty()) test=min(test,qu[side].front().first);
			if(!qu[side^1].empty()) test=min(test,qu[side^1].front().first);
			time=(max(time,test)); // ok gg -_-!

			int tmp=n;
			while(!qu[side].empty() && qu[side].front().first<=time && tmp>0)
			{
				res[qu[side].front().second]=time+c;
				qu[side].pop();
				tmp--;
			}
			side^=1;
			time+=c;
		}
		for(int i=0; i<m; ++i) cout<<res[i]<<endl;
		if(t!=0) cout<<endl;
	}
	return 0;
}