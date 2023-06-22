#include<iostream>
#include<string>
using namespace std;

string str;

int main()
{
	while(getline(cin,str))
	{
		int sz=str.length();
		bool first=true;
		for(int i=0; i<sz; ++i)
		{
			if(str[i]==' ' || i==sz-1)
			{
				int j = i-1;
				if(!first) cout<<" ";
				if(i==sz-1 && str[i]!=' ') cout<<str[i];
				while(j >= 0 && str[j]!=' ')
				{
					cout<<str[j];
					--j;
					first=false;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}