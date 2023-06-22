#include<iostream>
using namespace std;

int n,x,y,op,p[20020];

int find(int u) { return u==p[u] ? u : p[u]=find(p[u]); }
void join(int u, int v) { p[find(u)]=find(v); }

int enermyId(int id)
{
	return id+n;
}

bool isFriend(int u, int v)
{
	return find(u)==find(v) || find(enermyId(u))==find(enermyId(v));
}

bool isEnermy(int u, int v)
{
	return find(u)==find(enermyId(v)) || find(v)==find(enermyId(u));
}

void setFriend(int u, int v)
{
	join(u,v);
	join(enermyId(u),enermyId(v));
}

void setEnermy(int u, int v)
{
	join(u,enermyId(v));
	join(v,enermyId(u));
}

int main()
{
	cin>>n;
	for(int i=0; i<2*n; ++i) p[i]=i;
	while(1)
	{
		cin>>op>>x>>y;
		if(op==0) break;
		if(op==1)
		{
			if(isEnermy(x,y)) puts("-1");
			else setFriend(x,y);
		}
		else if(op==2)
		{
			if(isFriend(x,y)) puts("-1");
			else setEnermy(x,y);
		}
		else if(op==3)
		{
			if(isFriend(x,y)) puts("1");
			else puts("0");
		}
		else if(op==4)
		{
			if(isEnermy(x,y)) puts("1");
			else puts("0");
		}
	}
	return 0;
}