#include<iostream>
using namespace std;

int num,a[100100],best[100100];

int main()
{
	int tc=0;
	while(1)
	{
		cin>>num;
		if(num==-1) break;
		int cnt=0;
		a[cnt++]=num;
		while(1)
		{
			cin>>num;
			if(num==-1) break;
			a[cnt++]=num;
		}
		for(int i=0; i<cnt; ++i) best[i]=1;
		for(int i=1; i<cnt; ++i) for(int j=0; j<i; ++j) if(a[i]<=a[j]) best[i]=max(best[i],best[j]+1);
		int ans=0;
		for(int i=0; i<cnt; ++i) ans=max(ans,best[i]);
		if(tc) puts("");
		printf("Test #%d:\n  maximum possible interceptions: %d\n",++tc,ans);
	}
	return 0;
}


// binary way, still ac but could be wrong! 

/*5 3 3 3 2 1
4 4 4 4 4 4 4
-1
-1*/

/*#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int num,len,lis[100100],best[100100];

int main()
{
	int tc=0;
	while(1)
	{
		cin>>num;
		if(num==-1) break;
		len=0;
		lis[len++]=num;
		unordered_map<int,int> cnt;
		while(1)
		{
			cin>>num;
			if(num==-1) break;
			if(num>lis[0]) lis[0]=num;
			else if(num<=lis[len-1]) lis[len++]=num;
			else
			{
				int pos=lower_bound(lis,lis+len,num,greater<int>())-lis;
				lis[pos]=num;
			}
		}
		if(tc) puts("");
		printf("Test #%d:\n  maximum possible interceptions: %d\n",++tc,len);
	}
	return 0;
}*/