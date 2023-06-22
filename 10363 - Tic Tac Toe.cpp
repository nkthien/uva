#include<iostream>
using namespace std;

int t,b[5][5];
char c;
bool ok;
 
bool checkVictory(int type)
{
	int cnt=0;
	for(int i=0; i<3; ++i) if(b[i][0]==type && b[i][0]==b[i][1] && b[i][0]==b[i][2]) cnt++;
	for(int i=0; i<3; ++i) if(b[0][i]==type && b[0][i]==b[1][i] && b[0][i]==b[2][i]) cnt++;
	if(b[1][1]==type && b[0][0]==b[1][1] && b[0][0]==b[2][2]) cnt++;
	if(b[1][1]==type && b[0][2]==b[1][1] && b[0][2]==b[2][0]) cnt++;
	return cnt==1;
}

int main()
{
	cin>>t;
	while(t--)
	{
		int cntX=0,cntO=0;
		for(int i=0; i<3; ++i) for(int j=0; j<3; ++j)
		{
			cin>>c;
			// X is 1, O is 2
			if(c=='X') b[i][j]=1, cntX++; 
			else if(c=='O') b[i][j]=2, cntO++;
			else b[i][j]=0;
		}
		ok=true;
		if(cntO>cntX || cntX-cntO>=2) ok=false;
		if(checkVictory(1) && cntX-cntO != 1) ok=false;
		if(checkVictory(2) && cntX-cntO != 0) ok=false;
		if(ok) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}