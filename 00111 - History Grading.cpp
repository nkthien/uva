#include<iostream>
#include<string.h>
using namespace std;

int n,a[25],best[25],rnk[25];
char line[100];

int main()
{
	while(gets(line))
	{
		if(strlen(line)<3)
		{
			sscanf(line,"%d\n",&n);
			int tmp;
			for(int i=0; i<n; ++i) scanf("%d ",&rnk[i]);
		}
		else
		{
			int j=0;
			for(int i=0; i<n; ++i) 
			{
				int tmp;
				sscanf(line+j++,"%d ",&tmp);
				a[tmp-1]=i;
				while(j<strlen(line) && line[j]!=' ' && line[j]!='\n') j++;
			}
			for(int i=0; i<n; ++i) best[i]=1;
			for(int i=1; i<n; ++i) for(int j=0; j<i; ++j) if(rnk[a[i]]>rnk[a[j]]) best[i]=max(best[i],best[j]+1);
			int ans=0;
			for(int i=0; i<n; ++i) ans=max(ans,best[i]);
			cout<<ans<<endl;
		}
	}
	return 0;
}