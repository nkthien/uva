#include<iostream>
#include<algorithm>
using namespace std;

int t,id,prb,tme,board[110][11];
char code,line[50];

struct Player
{
	int id,scr,pen;
	bool sub,solved[10];

	void init(int _id)
	{
		id=_id;
		scr=pen=0;
		sub=false;
		for(int i=0; i<10; ++i) solved[i]=false;
	}

	void record(int prb, int tme, char code)
	{
		sub=true;
		if(!solved[prb])
		{
			if(code=='C') scr+=1, pen+=board[id][prb]+tme, solved[prb]=true;
			else if(code=='I') board[id][prb]+=20;
		}
	}

	bool operator<(const Player &b)
	{
		if(scr!=b.scr) return scr<b.scr;
		if(pen!=b.pen) return pen>b.pen;
		return id>b.id;
	}
};

int main()
{
	scanf("%d\n",&t);
	while(t--)
	{
		Player a[110];
		for(int i=0; i<=100; ++i) 
    {
      a[i].init(i);
      for(int j=0; j<10; ++j) board[i][j]=0;
    }
		while(gets(line))
		{
			if(line[0]=='\0') break;
			sscanf(line,"%d %d %d %c\n",&id,&prb,&tme,&code);
			a[id].record(prb,tme,code);
		}
		sort(a,a+101);
		for(int i=100; i>=0; --i) if(a[i].sub) printf("%d %d %d\n",a[i].id,a[i].scr,a[i].pen);
		if(t) puts("");
	}
	return 0;
}