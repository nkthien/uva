#include<iostream>
using namespace std;

int w,h,n,x1,x2,y1,y2;
bool b[505][505];

int main()
{
	while(1)
	{
		cin>>w>>h>>n;
		if(w==0) break;
		for(int i=0; i<w; ++i) for(int j=0; j<h; ++j) b[i][j]=true;
		while(n--)
		{
			cin>>x1>>y1>>x2>>y2; 
			x1--,x2--,y1--,y2--;
			if(x1>x2) swap(x1,x2);
			if(y1>y2) swap(y1,y2);
			for(int i=x1; i<=x2; ++i) for(int j=y1; j<=y2; ++j) b[i][j]=false;
		}
		int cnt=0;
		for(int i=0; i<w; ++i) for(int j=0; j<h; ++j) if(b[i][j]) cnt++;
		if(cnt==0) printf("There is no empty spots.\n");
		else if(cnt==1) printf("There is one empty spot.\n");
		else printf("There are %d empty spots.\n",cnt);
	}
	return 0;
}