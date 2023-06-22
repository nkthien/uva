#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>
using namespace std;

int h,m,s,cur,now;
char tmp;
string line;
double ans,spd;

int main()
{
	while(getline(cin,line))
	{
		stringstream ss(line);
		string word;
		vector<string> v;
		while(getline(ss,word,' ')) v.push_back(word);
		h=(v[0][0]-'0')*10 + (v[0][1]-'0');
		m=(v[0][3]-'0')*10 + (v[0][4]-'0');
		s=(v[0][6]-'0')*10 + (v[0][7]-'0');
		now=h*3600 + 60*m + s;
		cout<<fixed<<setprecision(2);
		if(v.size() > 1)
		{
			ans += (now-cur)*spd;
			spd=stoi(v[1]);
			spd=(spd/3600);
			cur=now;
		}
		else
		{
			ans += (now-cur)*spd;
			cout<<setw(2)<<setfill('0')<<h<<":";
			cout<<setw(2)<<setfill('0')<<m<<":";
			cout<<setw(2)<<setfill('0')<<s<<" ";
			cout<<ans<<" km"<<endl;
			cur=now;
		}
	}
	return 0;
}


// much shorter version using sscanf

/*#include<iostream>
using namespace std;

int h,m,s,now,prv;
char line[100],str[100];
double spd,ans;

int main()
{
	while(gets(line))
	{
		sscanf(line,"%d:%d:%d",&h,&m,&s);
		now=h*3600 + m*60 + s;
		ans+=(now-prv)*spd;
		if(line[8]==' ')
		{
			sscanf(line+8,"%lf",&spd);
			spd/=3600.0;
		}
		else printf("%s %.2f km\n",line,ans);
		prv=now;
	}
	return 0;
}*/