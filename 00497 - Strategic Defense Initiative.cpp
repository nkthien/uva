#include<iostream>
using namespace std;

int t,n,a[100100],best[100100],path[100100],last;
char line[100];

void print_path(int i)
{
	if(i==-1) return;
	print_path(path[i]);
	cout<<a[i]<<endl;
}

int main()
{
	scanf("%d ",&t);
	while(t--)
	{
		n=0;
		while(gets(line) && line[0]!='\0') sscanf(line,"%d",&a[n++]);
		for(int i=0; i<n; ++i) best[i]=1, path[i]=-1;
		for(int i=1; i<n; ++i) for(int j=0; j<i; ++j) if(a[i]>a[j] && best[i]<best[j]+1) best[i]=best[j]+1, path[i]=j;
		int ans=0;
		for(int i=0; i<n; ++i) if(ans<best[i]) ans=best[i], last=i;
		printf("Max hits: %d\n",ans);
		print_path(last);	
		if(t) cout<<endl;
	}
	return 0;
}