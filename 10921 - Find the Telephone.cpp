#include<iostream>
#include<string>
using namespace std;

string line;

int main()
{
	while(getline(cin,line))
	{
		for(int i=0; i<line.size(); ++i)
		{
			if(line[i]=='A' || line[i]=='B' || line[i]=='C') cout<<2;
			else if(line[i]=='D' || line[i]=='E' || line[i]=='F') cout<<3;
			else if(line[i]=='G' || line[i]=='H' || line[i]=='I') cout<<4;
			else if(line[i]=='J' || line[i]=='K' || line[i]=='L') cout<<5;
			else if(line[i]=='M' || line[i]=='N' || line[i]=='O') cout<<6;
			else if(line[i]=='P' || line[i]=='Q' || line[i]=='R' || line[i]=='S') cout<<7;
			else if(line[i]=='T' || line[i]=='U' || line[i]=='V') cout<<8;
			else if(line[i]=='W' || line[i]=='X' || line[i]=='Y' || line[i]=='Z') cout<<9;
			else cout<<line[i];
		}
		cout<<endl;
	}
	return 0;
}