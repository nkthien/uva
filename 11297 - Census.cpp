#include<iostream>
using namespace std;

int n,q,a[550][550],ST[2050][2050][3];
int x1,x2,y1,y2,x,y,d,mnv,mxv;
char op;

void buildSubST(int idx, int lx, int rx, int idy, int ly, int ry)
{
	if(ly==ry)
	{
		if(lx==rx) ST[idx][idy][0]=ST[idx][idy][1]=a[lx][ly];
		else
		{
			ST[idx][idy][0]=max(ST[2*idx+1][idy][0], ST[2*idx+2][idy][0]);
			ST[idx][idy][1]=min(ST[2*idx+1][idy][1], ST[2*idx+2][idy][1]);
		}
	}
	else
	{
		int my=(ly+ry)/2;
		buildSubST(idx,lx,rx,2*idy+1,ly,my);
		buildSubST(idx,lx,rx,2*idy+2,my+1,ry);
		ST[idx][idy][0]=max(ST[idx][2*idy+1][0], ST[idx][2*idy+2][0]);
		ST[idx][idy][1]=min(ST[idx][2*idy+1][1], ST[idx][2*idy+2][1]);
	}
}

void buildST(int idx, int lx, int rx)
{
	if(lx!=rx)
	{
		int mx=(lx+rx)/2;
		buildST(2*idx+1,lx,mx);
		buildST(2*idx+2,mx+1,rx);
	}
	buildSubST(idx,lx,rx,0,0,n-1);
}

void subQuery(int idx, int idy, int ly, int ry, int uy, int vy)
{
	if(vy<ly || uy>ry) return;
	if(uy<=ly && vy>=ry)
	{
		mxv=max(mxv, ST[idx][idy][0]);
		mnv=min(mnv, ST[idx][idy][1]);
	}
	else
	{
		int my=(ly+ry)/2;
		subQuery(idx,2*idy+1,ly,my,uy,vy);
		subQuery(idx,2*idy+2,my+1,ry,uy,vy);
	}
}

void query(int idx, int lx, int rx, int ux, int vx, int uy, int vy)
{
	if(vx<lx || ux>rx) return;
	if(ux<=lx && vx>=rx) subQuery(idx,0,0,n-1,uy,vy);
	else
	{
		int mx=(lx+rx)/2;
		query(2*idx+1,lx,mx,ux,vx,uy,vy);
		query(2*idx+2,mx+1,rx,ux,vx,uy,vy);
	}
}

void subUpdate(int idx, int lx, int rx, int idy, int ly, int ry, int x, int y, int d)
{
	if(ly==ry)
	{
		if(lx==rx) ST[idx][idy][0]=ST[idx][idy][1]=a[lx][ly]=d;
		else
		{
			ST[idx][idy][0]=max(ST[2*idx+1][idy][0], ST[2*idx+2][idy][0]);
			ST[idx][idy][1]=min(ST[2*idx+1][idy][1], ST[2*idx+2][idy][1]);
		}
	}
	else
	{
		int my=(ly+ry)/2;
		if(y<=my) subUpdate(idx,lx,rx,2*idy+1,ly,my,x,y,d);
		else subUpdate(idx,lx,rx,2*idy+2,my+1,ry,x,y,d);
		ST[idx][idy][0]=max(ST[idx][2*idy+1][0], ST[idx][2*idy+2][0]);
		ST[idx][idy][1]=min(ST[idx][2*idy+1][1], ST[idx][2*idy+2][1]);
	}
}

void update(int idx, int lx, int rx, int x, int y, int d)
{
	if(lx!=rx) 
	{
		int mx=(lx+rx)/2;
		if(x<=mx) update(2*idx+1,lx,mx,x,y,d);
		else update(2*idx+2,mx+1,rx,x,y,d);
	}
	subUpdate(idx,lx,rx,0,0,n-1,x,y,d);
}

int main()
{
	cin>>n;
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin>>a[i][j];
	buildST(0,0,n-1);
	cin>>q;
	while(q--)
	{
		cin>>op;
		if(op=='q') 
		{
			cin>>x1>>y1>>x2>>y2; x1--,x2--,y1--,y2--;
			if(x1>x2) swap(x1,x2);
			if(y1>y2) swap(y1,y2);
			mxv=-1, mnv=1e9;
			query(0,0,n-1,x1,x2,y1,y2);
			printf("%d %d\n",mxv,mnv);
		}
		else
		{
			cin>>x>>y>>d; x--,y--;
			update(0,0,n-1,x,y,d);
		}
	}
	return 0;
}