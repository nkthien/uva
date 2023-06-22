#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

int n,a[200];
unordered_map<string,char> m;

int w(char c)
{
	if(c=='-') return 10;
	else return c-'0';
}

string solve()
{
	if(n%6!=5 && (n+1)/6<5) return "bad code";
	int mx=0, mn=1e9;
	for(int i=0; i<n; ++i) mx=max(mx,a[i]), mn=min(mn,a[i]);
	double t=(mx+mn)/2.0;
	mx=0, mn=1e9;
	for(int i=0; i<n; ++i)
	{
		int tmp=a[i];
		if(a[i]<t) tmp*=2;
		mx=max(mx,tmp);
		mn=min(mn,tmp);
	}
	if(mx*95 > mn*105) return "bad code";
	if(!(a[0]<t && a[1]<t)) reverse(a,a+n);
	string code="";
	for(int i=0; i<n; i+=6)
	{
		string tmp="00000";
		if(i!=0 && a[i-1]>=t) return "bad code"; 
		for(int j=0; j<5; ++j) if(a[i+j]>t) tmp[j]='1';
		if(m.count(tmp)==0) return "bad code";
		else code+=m[tmp];
	}
	int sz=code.length();
	if(code[0]!='*' || code[sz-1]!='*') return "bad code";
	for(int i=1; i<sz-1; ++i) if(code[i]=='*') return "bad code";

	int c=w(code[sz-3]);
	int calc=0;
	for(int i=1; i<sz-3; ++i) calc = (calc+((sz-4-i)%10+1)*w(code[i]))%11;
	if(c!=calc) return "bad C";
	
	int k=w(code[sz-2]);
	int calk=0;
	for(int i=1; i<sz-2; ++i) calk = (calk+((sz-4-i+1)%9+1)*w(code[i]))%11;
	if(k!=calk) return "bad K";	
	
	string ans="";
	for(int i=1; i<sz-3; ++i) ans+=code[i];
	return ans;
}

int main()
{
	m["00001"]='0';
	m["10001"]='1';
	m["01001"]='2';
	m["11000"]='3';
	m["00101"]='4';
	m["10100"]='5';
	m["01100"]='6';
	m["00011"]='7';
	m["10010"]='8';
	m["10000"]='9';
	m["00100"]='-';
	m["00110"]='*';

	int tc=1;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>a[i];
		cout<<"Case "<<tc++<<": "<<solve()<<endl;
	}
	return 0;
}