#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

const int INF=1e9,N=100;

int t,n;
double x1[N],y1[N],x2[N],y2[N],r[N];

int main()
{
	cin>>t;
	for(int tc=0; tc<t; ++tc)
	{
		cin>>n;
		vector<double> vx;
		for(int i=0; i<n; ++i)
		{
			cin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>r[i];
			if(x1[i]>x2[i]) swap(x1[i],x2[i]);
			vx.push_back(x1[i]); vx.push_back(x2[i]);
		}
		sort(vx.begin(), vx.end());
		int sz=vx.size();
		vector<double> ansx1,ansx2,ansv;
		for(int i=0; i<sz-1; ++i)
		{
			ansx1.push_back(vx[i]);
			ansx2.push_back(vx[i+1]);
			ansv.push_back(1.0);
		}
		for(int i=0; i<sz-1; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(ansx1[i]>=x1[j] && ansx2[i]<=x2[j]) ansv[i]*=r[j];
			}
		}
		cout<<fixed<<setprecision(3);
		cout<<sz+1<<endl;
		cout<<"-inf "<<ansx1[0]<<" 1.000"<<endl;
		for(int i=0; i<sz-1; ++i)
		{
			cout<<ansx1[i]<<" "<<ansx2[i]<<" "<<ansv[i]<<endl;
		}
		cout<<ansx2[sz-2]<<" +inf 1.000"<<endl;
		if(tc!=t-1) cout<<"\n";
	}
	return 0;
}