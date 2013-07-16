#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define sz size()
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i= GI;i;i--) V.pb( GI );
#define VI vector<int> 
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;


double get_dot(PDD a,PDD b){return a.first*b.first + a.second*b.second;}
inline PDD operator-(const PDD& a,const PDD& b){return PDD(a.first-b.first,a.second-b.second);}
int Gr[64][64];
vector< PDD > BTS;
vector< PDD > City;

inline double hypot1(double a,double b){return sqrt(a*a+b*b);}

int find_closest(PDD P){
	double Dist = INF,t;int ind;
	REPV(i,BTS){
		t = hypot1(BTS[i].first-P.first,BTS[i].second-P.second);
		if(t < Dist )  Dist = t,ind = i;
	}
	return ind;
}


int cnt(int s,int d){
	int ret = 0;	
	int a = find_closest(City[s]);
	int b = find_closest(City[d]);
	ret += (a==b?1:2);
	
	PDD vect = City[d] - City[s],t;
	double dist = hypot1(vect.first,vect.second);
	REPV(i,BTS) if(i!=a && i!=b){
		PDD t = BTS[i] - City[s];
		if(get_dot(vect,t)>1e-9 && get_dot(vect,t)+1e-9 < dist) ret++;
	}
	return ret;	
}


int main(){
	int B,R,C,Q;
	int cn = 1;
	
	while((B=GI) + (C=GI) + (R=GI) + (Q=GI)){
		REP(i,51) REP(j,51) Gr[i][j] = INF;
		REP(i,51) Gr[i][i] = 1;
		
		BTS.clear();City.clear();
		REP(i,B){
			double a,b;scanf("%lf %lf",&a,&b);
			BTS.pb(PDD(a,b));
		}
		REP(i,C){
			double a,b;scanf("%lf %lf",&a,&b);
			City.pb(PDD(a,b));
		}		
		REP(i,R){
			int a = GI-1,b = GI-1;
			Gr[a][b] = cnt(a,b);
		}	
		
		REP(k,C) REP(i,C) REP(j,C) Gr[i][j] <?= (Gr[i][k] + Gr[k][j] - 1 );
		
		printf("Case %d:\n",cn); 
		REP(i,Q){
			int a = GI-1,b = GI-1;
			if(	Gr[a][b] < INF ) cout << Gr[a][b] << endl;
			else cout << "Impossible" <<endl;
		}
		cn++;
	}
	
		
	
}
