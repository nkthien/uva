#include<iostream>
using namespace std;

int n,px,py,x,y;

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		cin>>px>>py;
		for(int i=0; i<n; ++i)
		{
			cin>>x>>y;
			int test1=x-px, test2=y-py;
			if(test1==0 || test2==0) cout<<"divisa\n";
			else if(test1>0 && test2>0) cout<<"NE\n";
			else if(test1>0 && test2<0) cout<<"SE\n";
			else if(test1<0 && test2>0) cout<<"NO\n";
			else if(test1<0 && test2<0) cout<<"SO\n";
		}
	}
	return 0;
}