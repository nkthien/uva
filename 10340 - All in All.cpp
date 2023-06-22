#include<iostream>
using namespace std;

string a,b;

int main()
{
	while(cin>>a>>b)
	{
		int j=0;
		for(int i=0; i<b.length() && j<a.length(); ++i) if(a[j]==b[i]) j++;
		if(j<a.length()) puts("No");
		else puts("Yes");
	}
	return 0;
}