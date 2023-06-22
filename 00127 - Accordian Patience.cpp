#include<iostream>
#include<stack>
#include<string>
using namespace std;

int n;
string card;

bool same(string a, string b)
{
	return (a[0]==b[0] || a[1]==b[1]);
}

bool makeMove(stack<string> pile[])
{
	for(int i=1; i<52; ++i) if(!pile[i].empty())
	{
		if(i>=3)
		{
			int cnt=0;
			int j=i-1;
			while(j>=0 && cnt!=3)
			{
				if(!pile[j].empty()) cnt++;
				if(cnt!=3) j--;
			}
			if(j>=0 && cnt==3 && same(pile[i].top(),pile[j].top()))
			{
				pile[j].push(pile[i].top()), pile[i].pop();
				if(pile[i].empty()) n--;
				return true;
			}
		}
		if(i>=1)
		{
			int j=i-1;
			while(j>=0 && pile[j].empty()) j--;
			if(j>=0 && same(pile[i].top(),pile[j].top()))
			{
				pile[j].push(pile[i].top()), pile[i].pop();
				if(pile[i].empty()) n--;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	while(1)
	{
		cin>>card;
		if(card=="#") break;
		stack<string> pile[55];
		pile[0].push(card);
		n=1;
		for(int i=1; i<52; ++i)
		{
			cin>>card;
			pile[i].push(card);
			n++;
			while(makeMove(pile));
		}
		cout<<n<<" pile"<<(n==1?"":"s")<<" remaining:"; 
		for(int i=0; i<52; ++i) if(!pile[i].empty()) cout<<" "<<pile[i].size(); cout<<endl;
	}
	return 0;
}