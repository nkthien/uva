#include<iostream>
using namespace std;

int t,hs[3],hf[3],ms[3],mf[3];

int main()
{
	cin>>t;
	for(int tc=0; tc<t; ++tc)
	{
		scanf("%d:%d %d:%d\n",&hs[0],&ms[0],&hf[0],&mf[0]);
		scanf("%d:%d %d:%d\n",&hs[1],&ms[1],&hf[1],&mf[1]);
		if(hs[0]>hs[1] || (hs[0]==hs[1] && ms[0]>ms[1])) 
		{
			swap(hs[0],hs[1]);
			swap(ms[0],ms[1]);
			swap(hf[0],hf[1]);
			swap(mf[0],mf[1]);
		}
		bool ok=true;
		printf("Case %d: ",tc+1);
		if(hf[0]>hs[1] || (hf[0]==hs[1] && mf[0]>=ms[1])) ok=false;
		if(ok) cout<<"Hits Meeting\n";
		else cout<<"Mrs Meeting\n";
	}
	return 0; 
}