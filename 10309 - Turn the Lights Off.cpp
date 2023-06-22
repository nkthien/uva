#include<iostream>
using namespace std;

string name,line;
bool init[15][15],a[15][15];

void push(int x, int y)
{
	a[x][y]=!a[x][y];
	if(x+1<10) a[x+1][y]=!a[x+1][y];
	if(x-1>=0) a[x-1][y]=!a[x-1][y];
	if(y+1<10) a[x][y+1]=!a[x][y+1];
	if(y-1>=0) a[x][y-1]=!a[x][y-1];
}

int main()
{
	while(1)
	{
		cin>>name;
		if(name=="end") break;
		for(int i=0; i<10; ++i) 
		{
			cin>>line;
			for(int j=0; j<10; ++j) init[i][j]=line[j]=='O' ? true:false;
		}
		int ans=101;
		for(int k=0; k<1024; ++k)
		{
			for(int i=0; i<10; ++i) for(int j=0; j<10; ++j) a[i][j]=init[i][j];
			int cnt=0;
			for(int i=0; i<10; ++i) if(k&(1<<i)) push(0,i), cnt++;
			for(int i=1; i<10; ++i) for(int j=0; j<10; ++j) if(a[i-1][j]) push(i,j), cnt++;
			bool isOk=true;
			for(int i=0; i<10; ++i) if(a[9][i]) isOk=false;
			if(isOk) ans=min(ans,cnt);	
		}
		if(ans==101) ans=-1;
		printf("%s %d\n",name.c_str(),ans);
	}
	return 0;
}