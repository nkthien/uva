#include<iostream>
#include<sstream>
using namespace std;

const int N=201;

int n,p[220];
string str1[220],str2[220];
char code[N];

int find(int u){ return u==p[u] ? u : p[u]=find(p[u]); }

bool join(int u, int v) 
{ 
	int pu=find(u);
	int pv=find(v);
	if(pu==pv) return true;

	char su=code[pu];
	char sv=code[pv];
	char suv;

	if(su!='#' && sv!='#' && su!=sv) return false;
	else if(su!='#') suv=su;
	else suv=sv;

	p[pu]=pv;
	code[pv]=suv;
	return true;
}

bool isLetter(string s)
{
	if(s[0]>='A' && s[0]<='D') return true;
	return false;
}

int main()
{
	bool first=true;
	while(cin>>n)
	{
		for(int i=0; i<N; ++i) p[i]=i, code[i]='#';
		for(int i=0; i<n; ++i) cin>>str1[i];
		for(int i=0; i<n; ++i) cin>>str2[i];
		bool isOk=true;
		for(int i=0; i<n; ++i)
		{
			if(isLetter(str1[i]) && isLetter(str2[i]))
			{
				if(str1[i]!=str2[i]) isOk=false;
			}
			else if(isLetter(str1[i]) && !isLetter(str2[i]))
			{
				int num;
				stringstream ss(str2[i]);
				ss>>num;

				int pnum=find(num);
				if(code[pnum]!='#' && code[pnum]!=str1[i][0]) isOk=false;
				else code[pnum]=str1[i][0];
			}
			else if(!isLetter(str1[i]) && isLetter(str2[i]))
			{
				int num;
				stringstream ss(str1[i]);
				ss>>num;

				int pnum=find(num);
				if(code[pnum]!='#' && code[pnum]!=str2[i][0]) isOk=false;
				else code[pnum]=str2[i][0];
			}
			else
			{
				int x,y;
				stringstream ss(str1[i]);
				ss>>x;
				ss=stringstream(str2[i]);
				ss>>y;
				if(!join(x,y)) isOk=false;
			}
		}
		if(!first) cout<<endl;
		else first=false;
		if(isOk) 
		{
			cout<<"YES"<<endl;
			for(int i=1; i<N; ++i) 
			{
				int pi=find(i);
				if(code[pi]!='#') printf("%d %c\n",i,code[pi]);
			}
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}