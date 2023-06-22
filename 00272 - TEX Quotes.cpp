#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char line[1000];
	bool open=true;
	while(gets(line))
	{
		int sz=strlen(line);
		for(int i=0; i<sz; ++i)
		{
			if(line[i]=='"')
			{
				if(open) printf("``");
				else printf("''");
				open^=1;
			}
			else printf("%c",line[i]);
		}
		puts("");
	}
	return 0;
}