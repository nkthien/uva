#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int t,n;
string line;

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n; cin.get(); 
		int Min=1e9;
		vector<int> res;
		for(int i=0; i<n; ++i)
		{
			getline(cin,line);
			stringstream ss(line);
			int tmp,cnt=0;
			while(ss>>tmp) cnt++;
			if(cnt<Min)
			{
				res=vector<int>();
				res.push_back(i);
				Min=cnt;
			}
			else if(cnt==Min)
			{
				res.push_back(i);
			}
		}
		vector<int>::iterator it;
		for(it=res.begin(); it!=res.end(); ++it)
		{
			cout<<*it+1;
			if(it!=--res.end()) cout<<" ";
		}
		cout<<endl;

		cin.get();
	}
	return 0;
}