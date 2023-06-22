#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int t,N,M,L;
char line[100];

struct Agency
{
	int A,B,total;
	char name[20];
} a[100100];

int cmp(const void *f, const void *s)
{
	Agency *a=(Agency*) f;
	Agency *b=(Agency*) s;
	if(a->total!=b->total) return a->total-b->total;
	else return strcmp(a->name,b->name);
}

int main()
{
	int tc=1;
	cin>>t;
	while(t--)
	{
		cin>>N>>M>>L;
		cin.get();
		for(int i=0; i<L; ++i)
		{
			gets(line);
			sscanf(line,"%[^:]:%d,%d\n",a[i].name,&a[i].A,&a[i].B);
			int cur=N, sum=0;
			while(cur!=M)
			{
				int newCur=cur/2;
				if(newCur>=M && a[i].B<=newCur*a[i].A)
				{
					sum+=a[i].B;
					cur/=2;
				}
				else
				{
					sum+=a[i].A;
					cur-=1;
				}
			}
			a[i].total=sum;
		}
		qsort(a,L,sizeof(a[0]),cmp);
		printf("Case %d\n",tc++);
		for(int i=0; i<L; ++i) printf("%s %d\n",a[i].name,a[i].total);
	}
	return 0;
}