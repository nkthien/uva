#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

int n;
string line,word;

int main()
{
	unordered_map<string,string> m;
	m[".-"]='A';
	m["-..."]='B';
	m["-.-."]='C';
	m["-.."]='D';
	m["."]='E';
	m["..-."]='F';
	m["--."]='G';
	m["...."]='H';
	m[".."]='I';
	m[".---"]='J';
	m["-.-"]='K';
	m[".-.."]='L';
	m["--"]='M';
	m["-."]='N';
	m["---"]='O';
	m[".--."]='P';
	m["--.-"]='Q';
	m[".-."]='R';
	m["..."]='S';
	m["-"]='T';
	m["..-"]='U';
	m["...-"]='V';
	m[".--"]='W';
	m["-..-"]='X';
	m["-.--"]='Y';
	m["--.."]='Z';
	m["-----"]='0';
	m[".----"]='1';
	m["..---"]='2';
	m["...--"]='3';
	m["....-"]='4';
	m["....."]='5';
	m["-...."]='6';
	m["--..."]='7';
	m["---.."]='8';
	m["----."]='9';
	m[".-.-.-"]='.';
	m["--..--"]=',';
	m["..--.."]='?';
	m[".----."]='\'';
	m["-.-.--"]='!';
	m["-..-."]='/';
	m["-.--."]='(';
	m["-.--.-"]=')';
	m[".-..."]='&';
	m["---..."]=':';
	m["-.-.-."]=';';
	m["-...-"]='=';
	m[".-.-."]='+';
	m["-....-"]='-';
	m["..--.-"]='_';
	m[".-..-."]='"';
	m[".--.-."]='@';
	int n; cin>>n; cin.get();
	int tc=1;
	while(getline(cin,line))
	{
		if(tc!=1) cout<<endl;
		cout<<"Message #"<<tc++<<endl;
		int i=0,j;
		while(i<line.length())
		{
			if(line[i]==' ')
			{
				cout<<" ";
				i+=1;
				continue;
			}
			j=i+1;
			while(j<line.length() && line[j]!=' ') j++;
			cout<<m[line.substr(i,j-i)];
			i=j+1;
		}
		cout<<endl;
	}
	return 0;
}