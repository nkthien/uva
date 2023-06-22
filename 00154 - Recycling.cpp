#include<iostream>
#include<unordered_map>
using namespace std;

int n,a[105][5],cnt[105];
char line[100];

int main()
{
	unordered_map<char,int> col;
	col['r']=0;
	col['o']=1;
	col['y']=2;
	col['g']=3;
	col['b']=4;

	unordered_map<char,int> mat;
	mat['P']=0;
	mat['G']=1;
	mat['A']=2;
	mat['S']=3;
	mat['N']=4;

	while(1)
	{
		gets(line);
		if(line[0]=='#') break;
		if(line[0]=='e') 
		{
			for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
			{
				if(i==j) continue;
				for(int k=0; k<5; ++k) if(a[i][k]!=a[j][k]) cnt[i]++;
			}
			int mn=1e9, ans=0;
			for(int i=0; i<n; ++i) if(mn>cnt[i]) 
			{
				mn=cnt[i];
				ans=i;
			}
			cout<<ans+1<<endl;
			for(int i=0; i<n; ++i) cnt[i]=0; 
			n=0;
			continue;
		}
		for(int i=0; i<5; ++i) a[n][col[line[i*4]]]=mat[line[i*4+2]];
		n++;
	}
	return 0;
}