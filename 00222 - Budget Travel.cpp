#include<iostream>
#include<math.h>
using namespace std;

int n;
double dis,cap,mpg,len,icost,station[60],price[60],ans;

void dfs(double cur, double cost)
{
	if(cur>=dis)
	{
		ans=min(ans,cost);
		return;
	}
	bool isOk=false;
	for(int i=0; i<n; ++i)
	{
		if(station[i]>cur) break;
		if(cur-station[i]>=len) continue;
		if(cur-station[i]<=len/2)
		{
			isOk=true;
			double newCost=cost+200+round((len-(cur-station[i]))/len * cap*price[i]);
			double newDis=station[i]+len;
			dfs(newDis,newCost);
		}
	}
	if(!isOk) for(int i=0; i<n; ++i)
	{
		if(station[i]>cur) break;
		if(cur-station[i]>=len) continue;
		double newCost=cost+200+round((len-(cur-station[i]))/len * cap*price[i]);
		double newDis=station[i]+len;
		dfs(newDis,newCost);
	}
}

int main()
{
	int tc=1;
	while(1)
	{
		cin>>dis;
		if(dis==-1) break;
		cin>>cap>>mpg>>icost>>n;
		for(int i=0; i<n; ++i) cin>>station[i]>>price[i];
		ans=1e9;
		len=cap*mpg;
		dfs(cap*mpg,icost*100);
		printf("Data Set #%d\nminimum cost = $%.2f\n",tc++,ans/100);
	}
	return 0;
}