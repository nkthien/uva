#include<iostream>
#include<map>
#include<algorithm>
#include<string.h>
using namespace std;

int t,n,m;
char tourName[150],teamName[40];

struct Team
{
	char name[40];
	int p,g,w,t,l,scr,ags;
	
	void init()
	{
		p=g=w=t=l=scr=ags=0;
	}

	void record(int a, int b)
	{
		if(a>b) p+=3, w+=1;
		else if(a==b) p+=1, t+=1;
		else l+=1;
		g+=1;
		scr+=a;
		ags+=b;
	}

	bool operator<(const Team &b)
	{
		if(p!=b.p) return p<b.p;
		if(w!=b.w) return w<b.w;
		if((scr-ags)!=(b.scr-b.ags)) return (scr-ags)<(b.scr-b.ags);
		if(scr!=b.scr) return scr<b.scr;
		if(g!=b.g) return g>b.g;
		return strcasecmp(name,b.name) > 0;
	}
};

int main()
{
	scanf("%d\n",&t);
	while(t--)
	{
		map<string,int> mp;
		gets(tourName);
		scanf("%d\n",&n);
		Team a[40];
		for(int i=0; i<n; ++i)
		{
			a[i].init();
			gets(a[i].name);
			mp[a[i].name]=i;
		}
		scanf("%d\n",&m);
		for(int i=0; i<m; ++i)
		{
			char name1[40],name2[40];
			int scr1,scr2;
			scanf("%[^#]#%d@%d#%[^\n]\n",name1,&scr1,&scr2,name2);
			a[mp[name1]].record(scr1,scr2);
			a[mp[name2]].record(scr2,scr1);
		}
		sort(a,a+n);
		puts(tourName);
		int rnk=1;
		for(int i=n-1; i>=0; --i)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				rnk++,
				a[i].name,
				a[i].p,
				a[i].g,
				a[i].w,
				a[i].t,
				a[i].l,
				a[i].scr-a[i].ags,
				a[i].scr,
				a[i].ags);
		}
		if(t!=0) puts("");
	}
	return 0;
}