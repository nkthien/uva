#include<iostream>
#include<string>
using namespace std;

int n,a[100100],d[100100];

string diff(int a, int b)
{
	string s1=to_string(a);
	string s2=to_string(b);
	int i=0; 
	while(i<s1.length() && s1[i]==s2[i]) i++;
	return s2.substr(i);
}

int main()
{
	int tc=1;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<n-1; ++i) d[i]=a[i+1]-a[i];
		d[n-1]=0;
		int i=0;
		cout<<"Case "<<tc++<<":\n";
		while(i<n)
		{
			int j=i;
			bool ok=false;
			while(j<n && d[j]==1) j++;
			if(j!=i) ok=true;
			cout<<'0';
			if(ok) cout<<a[i]<<"-"<<diff(a[i],a[j])<<endl;
			else cout<<a[i]<<endl;
			i=j+1;
		}
		cout<<endl;
	}
	return 0;
}