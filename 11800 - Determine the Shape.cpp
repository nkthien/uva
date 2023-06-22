#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

#define sq(a) ((a)*(a))

struct Point
{
	double x,y;
	bool operator< (const Point &b) const 
	{
		return x==b.x ? y<b.y ? 1:0 : x<b.x;
	}
};

int t;
Point p[5];

double distance(const Point &a, const Point &b)
{
	return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}

double dx(const Point &a, const Point &b)
{
	return b.x-a.x;
}

double dy(const Point &a, const Point &b)
{
	return b.y-a.y;
}

bool checkParallel(const Point &a, const Point &b, const Point &c, const Point &d)
{
	return (dx(a,b)*dy(c,d) - dx(c,d)*dy(a,b)) == 0;
}

bool oppositeSide(const Point &a, const Point &b, const Point &c, const Point &d)
{
	return ( ((a.y-b.y)*(c.x-a.x) + (b.x-a.x)*(c.y-a.y)) * ((a.y-b.y)*(d.x-a.x) + (b.x-a.x)*(d.y-a.y)) ) < 0;
}

int main()
{
	cin>>t;
	for(int tc=0; tc<t; ++tc)
	{
		for(int i=0; i<4; ++i) cin>>p[i].x>>p[i].y;
		sort(p,p+4);
		if(!oppositeSide(p[0],p[3],p[1],p[2])) swap(p[2],p[3]);
		double d1=distance(p[0],p[1]);
		double d2=distance(p[1],p[3]);
		double d3=distance(p[3],p[2]);
		double d4=distance(p[2],p[0]);
		double d5=distance(p[0],p[3]); // d5 d6 is dist of diagonal
		double d6=distance(p[1],p[2]);		
		cout<<"Case "<<tc+1<<": ";
		if(d1==d3 && d2==d4)
		{
			if(d1==d2)
			{
				if(d5==d6) cout<<"Square\n";
				else cout<<"Rhombus\n";
			}
			else
			{
				if(d5==d6) cout<<"Rectangle\n";
				else cout<<"Parallelogram\n";
			}
		}
		else
		{
			if(checkParallel(p[0],p[1],p[2],p[3]) || checkParallel(p[0],p[2],p[1],p[3])) cout<<"Trapezium\n";
			else cout<<"Ordinary Quadrilateral\n";
		}
	}
	return 0;
}