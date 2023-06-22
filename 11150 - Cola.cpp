#include<iostream>
using namespace std;

int n,mx;

int main()
{
	while(cin>>n)
	{
		mx=0;
		for(int i=0; i<3; ++i)
		{
			int sum=n+i,cal=n,rm=0;
			while(sum>=3)
			{
				rm=sum%3;
				cal+=sum/3;
				sum/=3;
				sum+=rm;
			}
			if(sum<i) cal=0;
			mx=max(mx,cal);
		}
		cout<<mx<<endl;
	}
	return 0;
}


// much shorter code, if remain 2 bottles then ans+1;

/*#include<iostream>
using namespace std;

int n;

int main()
{
	while(scanf("%d",&n)==1)
	{
		int sum=n;
		while(n>=3)
		{
			sum+=n/3;
			n=n/3 + n%3;
		}
		if(n==2) sum++;
		printf("%d\n",sum);
	}
	return 0;
}*/