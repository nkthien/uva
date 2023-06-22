#include<iostream>
#include<string>
using namespace std;

const int v[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
const string r[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

int num;
char line[1000];

int main()
{
	while(gets(line))
	{
		if(line[0]>='0' && line[0]<='9')
		{
			sscanf(line,"%d",&num);
			for(int i=12; i>=0; --i) while(num-v[i]>=0)
			{
				num-=v[i];
				cout<<r[i];
			}
			cout<<endl;
		}
		else
		{
			int sum=0;
			for(int i=0; line[i]!='\0'; ++i)
			{
				if(line[i]=='I' && line[i+1]=='V') sum+=4,i+=1;
				else if(line[i]=='X' && line[i+1]=='L') sum+=40,i+=1;
				else if(line[i]=='I' && line[i+1]=='X') sum+=9,i+=1;
				else if(line[i]=='X' && line[i+1]=='C') sum+=90,i+=1;
				else if(line[i]=='C' && line[i+1]=='D') sum+=400,i+=1;
				else if(line[i]=='C' && line[i+1]=='M') sum+=900,i+=1;
				else for(int j=0; j<13; ++j) if(string(1,line[i])==r[j]) sum+=v[j];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}