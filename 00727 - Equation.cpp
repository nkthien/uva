#include<iostream>
#include<stack>
using namespace std;

int n;
char line[2];

int main()
{
	scanf("%d\n",&n);
	while(n--)
	{
		stack<char> stk;
		while(gets(line))
		{
			if(line[0]=='\0') break;
			char c=line[0];
			if(c=='(')  stk.push('(');
			else if(c=='+' || c=='-') 
			{
				while(!stk.empty() && (stk.top()=='+' 
								|| stk.top()=='-'
								|| stk.top()=='*'
								|| stk.top()=='/' )) printf("%c",stk.top()), stk.pop();
				stk.push(c);
			}
			else if(c=='*' || c=='/')\
			{
				while(!stk.empty() && (stk.top()=='*' 
								|| stk.top()=='/')) printf("%c",stk.top()), stk.pop();
				stk.push(c);
			}
			else if(c==')') 
			{
				while(!stk.empty() && stk.top()!='(') printf("%c",stk.top()), stk.pop();
				stk.pop();
			}
			else printf("%c",c);
		}
		while(!stk.empty()) printf("%c",stk.top()), stk.pop();
		puts(""); 
		if(n!=0) puts("");
	}
	return 0;
}