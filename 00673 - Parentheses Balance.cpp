#include<iostream>
#include<string>
#include<stack>
using namespace std;

int n;
string s;

int main()
{
	cin>>n; cin.get();
	while(n--)
	{
		getline(cin,s); 
		int sz=s.length();
		stack<char> stk;
		bool ok=true;
		for(int i=0; i<sz; ++i)
		{
			if(s[i]=='(') stk.push(')');
			else if(s[i]=='[') stk.push(']');
			else if(s[i]==')' && !stk.empty() && stk.top()==')') stk.pop();
			else if(s[i]==']' && !stk.empty() && stk.top()==']') stk.pop();
			else 
			{
				ok=false;
				break;
			}
		}
		if(!stk.empty()) ok=false;
		if(ok) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}