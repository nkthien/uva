#include<iostream>
using namespace std;

int n,num,a[100100],lis[100100],path[100100],len;

int lower_bound(int l, int r, int v)
{
	if(l>r) return l;
	int m=(l+r)/2;
	if(a[lis[m]]>=v) return lower_bound(l,m-1,v);
	else return lower_bound(m+1,r,v); 
}

int LIS()
{
	len=0;
	lis[len++]=0;
	for(int i=0; i<n; ++i) path[i]=-1;
	for(int i=1; i<n; ++i)
	{
		if(a[i]<=a[lis[0]]) lis[0]=i;
		else if(a[i]>a[lis[len-1]]) path[i]=lis[len-1], lis[len++]=i;
		else
		{
			int pos=lower_bound(0,len,a[i]);
			path[i]=lis[pos-1];
			lis[pos]=i;
		}
	}
	return len;
}

void print_path(int i)
{
	if(i==-1) return;
	print_path(path[i]);
	cout<<a[i]<<endl;
}

int main()
{
	n=0;
	while(cin>>num) a[n++]=num;
	cout<<LIS()<<endl;
	cout<<"-"<<endl;
	print_path(lis[len-1]);
	return 0;
}


// normal O(N^2) way TLE -__-

/*#include<iostream>
using namespace std;

int n,num,a[100100],best[100100],path[100100],last;

int LIS()
{
	for(int i=0; i<n; ++i) best[i]=1, path[i]=-1;
	for(int i=1; i<n; ++i) for(int j=0; j<i; ++j) 
	{
		if(a[i]>a[j] && best[i]<best[j]+1) best[i]=best[j]+1, path[i]=j;
	}
	int ans=0;
	for(int i=0; i<n; ++i) if(ans<=best[i]) ans=best[i], last=i;
	return ans;
}

void print_path(int i)
{
	if(i==-1) return;
	print_path(path[i]);
	cout<<a[i]<<endl;
}

int main()
{
	n=0;
	while(cin>>num) a[n++]=num;
	cout<<LIS()<<endl;
	cout<<"-"<<endl;
	print_path(last);
	return 0;
}*/