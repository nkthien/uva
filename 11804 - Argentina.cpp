#include<iostream>
#include<algorithm>
using namespace std;

int t;

struct Player
{
	string name;
	int atk,def;
} a[15];

bool cmp(Player a, Player b)
{
	if(a.atk==b.atk && a.def==b.def) return a.name<b.name;
	else if(a.atk==b.atk) return a.def<b.def;
	else return a.atk>b.atk;
}

bool nm(Player a, Player b)
{
	return a.name<b.name;
}

int main()
{
	cin>>t;
	for(int tc=1; tc<=t; ++tc)
	{
		for(int i=0; i<10; ++i) cin>>a[i].name>>a[i].atk>>a[i].def;
		sort(a,a+10,cmp);
		sort(a,a+5,nm);
		sort(a+5,a+10,nm);
		
		printf("Case %d:\n(%s",tc,a[0].name.c_str());
		for(int i=1; i<5; ++i) printf(", %s",a[i].name.c_str()); printf(")\n");
		printf("(%s",a[5].name.c_str());
		for(int i=6; i<10; ++i) printf(", %s",a[i].name.c_str()); printf(")\n");
	}
	return 0;
}
