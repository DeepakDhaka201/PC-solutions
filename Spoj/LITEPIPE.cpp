#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i=GI;i;i--) V.pb( GI )
#define REP(i,N) for(int i = 0;i<N;i++)
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef long long int LL;
vector< PDD > V;
typedef pair<PDD,PDD> line;
#define X1 first.first
#define Y1 first.second 
#define X2 second.first
#define Y2 second.second
#define AS(x,y) assert(fabs(x-y)>1e-9)

ostream& operator<<(ostream& o,line a){
	o << a.X1 << " , " << a.Y1 << " to " << a.X2 <<" "<< a.Y2 << endl;
	return o;	
}

PDD inter(const line A,const line B){
	double a = A.X1,b = A.Y1,c = A.X2,d = A.Y2;
	double m = B.X1,n = B.Y1,p = B.X2,q = B.Y2;
	AS(a,c);
	if(fabs(m-p)<1e-9){
		double x = m;
		double y = b + (x-a)*(b-d)*1./(a-c);
		return PDD(x,y);
	}
	double s1 = (b-d)*1./(a-c);
	double s2 = (n-q)*1./(m-p);
	if(fabs(s1-s2)<1e-9) assert(1>2);
	double x = (b-n+m*s2-a*s1)*1./(s2-s1);
	double y = b + (x-a)*(b-d)*1./(a-c);
	return PDD(x,y);
}

double Max(line x){
	
	REPV(i,V){
		line t(V[i],PDD(V[i].first,V[i].second - 1.));
		PDD pt = inter(x,t);
		assert(fabs(pt.first-V[i].first)<1e-9);
		double y1 = V[i].second,y2 = V[i].second-1;
		if( pt.second+1e-6 < y2){
			if(!i) return 0;
			PDD p1 = inter(x,line(PDD(V[i-1].first,V[i-1].second-1.0),PDD(V[i].first,V[i].second-1.0)));
			return p1.first;
		}
		else if(pt.second-1e-6>y1){
			if(!i) return 0;
			PDD p1 = inter(x,line(V[i-1],V[i]));
			return p1.first;
		}
	}
	return V.back().first;
}


int main(){
	int N;

	while(N = GI){
		V.clear();
		REP(i,N){
			double a,b;
			cin >> a >> b;	
			V.pb(PDD(a,b));
		}
		double ret = -1;
		REP(i,N) REP(j,N) if(j>i){
			ret >?= Max(line(V[i],V[j]));
			ret >?= Max(line(V[i],PDD(V[j].first,V[j].second-1.0)));
			ret >?= Max(line(PDD(V[i].first,V[i].second-1.0),V[j]));
			ret >?= Max(line(PDD(V[i].first,V[i].second-1.0),PDD(V[j].first,V[j].second-1.0)));
		}		
		printf("%.2lf\n",ret);
	
	}
}

