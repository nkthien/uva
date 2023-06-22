#include<iostream>
using namespace std;

int n;
long long a[100100];

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		for(int i=0; i<n; ++i) cin>>a[i];
		long long sum=0;
		for(int i=0; i<n; ++i)
		{
			if(a[i]==0) continue;
			for(int j=i+1; j<n && a[i]; ++j) if(a[i]*a[j]<0)
			{
				sum+=(j-i)*min(abs(a[i]),abs(a[j]));
				if((a[i]+a[j])*a[i]>0) a[i]+=a[j], a[j]=0;
				else a[j]+=a[i], a[i]=0;
			}
		}
		cout<<sum<<endl;
	}
}


// much simpler way -_-!

/*#include<iostream>
using namespace std;

int n;
long long a,b,ans;

int main()
{
	while(1)
	{
		cin>>n;
		if(n==0) break;
		cin>>a;
		ans=abs(a);
		for(int i=0; i<n-1; ++i) 
		{
			cin>>b;
			ans+=abs(a+b);
			a+=b;
		}
		cout<<ans<<endl;	
	}
	return 0;
}*/