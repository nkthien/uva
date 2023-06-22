#include<iostream>
using namespace std;

int n;

int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int numDigits(int num)
{
	int cnt=0;
	while(num)
	{
		cnt++;
		num/=10;
	}
	return cnt;
}

int main()
{
	int tc=1;
	while(1)
	{
		cin>>n;
		if(n==0) break;
		int sum=0;
		bool neg=false;
		for(int i=0; i<n; ++i)
		{
			int tmp; cin>>tmp;
			sum+=tmp;
		}

		if(sum<0) neg=true, sum*=-1;

		int a=sum/n;
		int b=sum%n;

		cout<<"Case "<<tc++<<":\n";
		if(b==0) 
		{
			if(neg) cout<<"- ";
			cout<<a<<endl;
		}
		else
		{
			int g=gcd(b,n);
			b/=g;
			n/=g;
			int lena=numDigits(a);
			int lenn=numDigits(n);
			int lenb=lenn-numDigits(b);
			if(neg) lena+=2;

			for(int i=0; i<lena+lenb; ++i) cout<<" "; cout<<b<<endl;
			if(neg) cout<<"- "; if(a) cout<<a; for(int i=0; i<lenn; ++i) cout<<"-"; cout<<endl;
			for(int i=0; i<lena; ++i) cout<<" "; cout<<n<<endl;
		}		
	}
	return 0;
}