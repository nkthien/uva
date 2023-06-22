#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char line[55];

int main()
{
	while(1)
	{
		gets(line);
		if(line[0]=='#') break;
		int sz=strlen(line);
		bool ok=true;
		for(int i=sz-1; i>0; --i)
		{
			if(line[i-1]<line[i])
			{
				int j=i;
				while(j<sz && line[j]>line[i-1]) j++;
				swap(line[i-1],line[j-1]);
				sort(line+i,line+sz);
				ok=false;
				break;
			}
		}
		if(ok) cout<<"No Successor";
		else for(int i=0; i<sz; ++i) cout<<line[i];
		cout<<endl;
	}
	return 0;
}