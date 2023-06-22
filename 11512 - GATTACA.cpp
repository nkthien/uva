#include <iostream>
#include <algorithm>
using namespace std;

int t,n,sa[1005],ra[1005],rb[1005],g,lcp[1005];
string s;

bool cmp(int x, int y)
{
	if(ra[x] != ra[y]) return ra[x] < ra[y];
	x += g;
	y += g;
	return (x < n && y < n) ? ra[x] < ra[y] : x > y;
}

void buildSA()
{
	for(int i=0; i<n; ++i) sa[i]=i, ra[i]=s[i];
	for(g=1; g<n; g*=2)
	{
		sort(sa, sa+n, cmp);	// O(n(logn)^2)
		rb[sa[0]]=0;
		for(int i=1; i<n; ++i) rb[sa[i]]=rb[sa[i-1]] + cmp(sa[i-1], sa[i]);
		for(int i=0; i<n; ++i) ra[i]=rb[i];
		if(ra[sa[n-1]] == n-1) break;
	}
}

void buildLCP()
{
	lcp[sa[0]]=0;
	for(int i=1; i<n; ++i) 
	{
		int cnt=0;
		while(s[sa[i] + cnt] == s[sa[i-1] + cnt]) cnt++;
		lcp[sa[i]]=cnt;
	}
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		n=s.size();
		buildSA();
		buildLCP();
		int mx=0, id=-1;
		for(int i=0; i<n; ++i) if(mx < lcp[sa[i]])
		{
			mx=lcp[sa[i]];
			id=i;
		}
		if(mx == 0) cout<<"No repetitions found!\n";
		else
		{
			int cnt=0;
			while(id + cnt < n && lcp[sa[id + cnt]] == mx) cnt++;
			for(int i=0; i<mx; ++i) cout<<s[sa[id] + i];
			cout<<" "<<cnt+1<<endl;
		}
	}
	return 0;
}


// trie O(n^2)

/*#include <stdio.h>
#include <string.h>

int M[128],t,id,to[1000000][4],cnt[1000000],resLen,resCnt;
char s[1000],res[1000],pat[]="ACGT";

void clear(int i)
{
	cnt[i]=0;
	for(int j=0; j<4; ++j) to[i][j]=-1;
}

void add(int i, char* c)
{
	cnt[i]++;
	if(!*c) return;
	int &ni=to[i][M[*c]];
	if(ni == -1) clear(ni = ++id);
	add(ni, c+1);
}

void rec(int i, int depth=0)
{
	s[depth]=0;
	if(resLen < depth && cnt[i] > 1)
	{
		resLen=depth;
		resCnt=cnt[i];
		strcpy(res, s);
	}
	for(int j=0; j<4; ++j) if(to[i][j] != -1)
	{
		s[depth]=pat[j];
		rec(to[i][j], depth+1);
	}
}

int main()
{
	M['A']=0;
	M['C']=1;
	M['G']=2;
	M['T']=3;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", s);
		clear(0), id=0;
		for(int i=0; i<strlen(s); ++i) add(0, s+i);
		resLen=resCnt=0;
		rec(0);
		if(resLen > 0) printf("%s %d\n", res, resCnt);
		else printf("No repetitions found!\n");
	}
	return 0;
}
*/
