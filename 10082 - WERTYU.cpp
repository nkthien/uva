#include<iostream>
#include<string>
using namespace std;

const string a="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

string line;

int main()
{
	bool first=true;
	int sz=a.length();
	while(getline(cin,line))
	{
		for(int i=0; i<line.length(); ++i)
		{
			int idx=-1;
			for(int j=0; j<sz; ++j) if(line[i]==a[j])
			{
				idx=j;
				break;
			}
			if(idx==-1)
			{
				cout<<line[i];
				continue;
			}
			cout<<a[idx-1];
		}
		cout<<endl;
	}
	return 0;
}