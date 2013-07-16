#include <iostream>
#include <cassert>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,N) for(int i = 0;i < (N); ++i )
#define EACH(it,x) for( __typeof(x.begin()) it(x.begin()); it != x.end(); ++it )
#define sz size()
#define pb push_back
#define mkp make_pair
#define EPS (1e-9)
# define M_PI		3.14159265358979323846	
# define M_PI_2		1.57079632679489661923 
typedef pair<int,int> PII;
typedef pair<double,double> PDD;

double get_start( const PII& p ){
	if( p.first == 0 ){
		if( p.second == 0 ) assert( 1 > 2 );
		else if( p.second > 0 ) return -M_PI;
		return 0;
	}
	double ang = atan( abs(p.second) * 1. / abs(p.first) );
	if( p.first > 0 ) {
		if( p.second > 0 ) return -(ang + M_PI_2);
		return -(M_PI_2 - ang);
	}
	else {
		if( p.second > 0 ) return (ang + M_PI_2 );
		return (M_PI_2 - ang );
	}
	return 0;
}

vector<PDD> intersect( vector< PDD > V, PDD P ){
	REP(i,V.sz)	if( fabs(V[i].first - V[i].second) > EPS ){
		if( fabs( V[i].second-M_PI) < EPS ) V.pb( PDD(-M_PI,-M_PI) );
		else if( fabs( V[i].first+M_PI) < EPS ) V.pb( PDD(M_PI,M_PI) );
	}
	vector<PDD> ret;
	for(int i = 0; i < V.sz; ++i ){
		double l = max( V[i].first , P.first );
		double m = min( V[i].second , P.second );
		if( fabs(l-m) < EPS ) ret.pb( make_pair(l,m) );
		else if( l < m ) ret.pb( mkp(l,m) );
	}
	return ret;
}
#define CONV(i) ((i)/M_PI*180)
int main(){
	int N,theta;
	int kaseid = 1;
	while( (N=GI)+(theta=GI) ){
		PII last(0,0);
		int needed = 0, maxy = 0;
		vector< PDD > R;
		R.pb( mkp(-M_PI,+M_PI) );
		
		REP(i,N){
			int a = GI,b = GI;
			if( a < maxy ) needed = 1; maxy = max( maxy , a );
			double lower = get_start( PII(a - last.first , b - last.second) );
			double upper = lower + M_PI;
			if( upper > M_PI ){
				upper = -M_PI + lower; // ( lower , M_PI ) , ( -M_PI , upper )
				vector<PDD> v1 = intersect( R , PDD(lower,M_PI ) );
				vector<PDD> v2 = intersect( R , PDD(-M_PI,upper) );
				R = v1;
				REP(i,v2.sz) R.pb( v2[i] );				
			}
			else {
				R = intersect( R , PDD(lower,upper) );
			}
			last = PII(a,b);
		}
		printf("Case %d: ",kaseid++);
		if( !needed ) puts("Acceptable as proposed");
		else if( !R.sz ) puts("Unacceptable");
		else {
			double ans = INT_MAX;
			REP(i,R.sz){
				if( R[i].first < -EPS && R[i].second > EPS ) ans = 0;
				double c = R[i].first;
				if( fabs(c) < fabs(ans) ) ans = c;
				if( fabs(c-ans) < EPS && c < 0 ) ans = c;
				
				c = R[i].second;
				if( fabs(c) < fabs(ans) ) ans = c;
				if( fabs(c-ans) < EPS && c < 0 ) ans = c;
			}
			if( fabs(ans-M_PI) < EPS ) ans = -M_PI;
			if( fabs(ans) < EPS ) puts("Acceptable as proposed");
			else printf("Acceptable after %s rotation of %.2lf degrees\n",ans<0?"clockwise":"counterclockwise" , fabs(CONV(ans)) );
		}
		puts("");
	}
	return 0;
}

