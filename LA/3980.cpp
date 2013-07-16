#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <queue>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,N) for(int i = 0;i<(N);i++)
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
#define M_PI 3.14159265358979323846
int Hts[2501];
LL Area;
inline double hypot1(const double& a,const double& b){
	return sqrt( a*a + b*b );
}

inline pair<int,double> TriArea(const PII& A,const PII& B,const PII& C){
	#define X1 (B.first - A.first)
	#define Y1 (B.second - A.second)
	#define X2 (C.first - A.first)
	#define Y2 (C.second - A.second)
	return make_pair( 
		(X1*LL(Y2) - LL(Y1)*X2),
		fabs( acos( (X1*LL(X2) + LL(Y1)*Y2)/(hypot1(X1,Y1)*hypot1(X2,Y2)) ) )
	);
}

bool is_inside(PII P,const vector<PII>& C ){
	Area = 0;
	double ang = 0;	
	for( int i = 0;i < C.sz; ++i){
		pair<LL,double> add = TriArea(P,C[i],C[(i+1)%C.sz]);
		Area += add.first;
		if( add.first > 0 ) add.second = -add.second;
		ang += add.second;		
	}	
	if( Area < 0 ) Area = -Area;	
	return fabs(ang) > 1;
}

int main(){
	int T = GI;
	
	while( T-- ){
		int N = GI;
		vector< pair<LL,int> > A,B;		
		REP(i,N){
			vector<PII> Curves;
			int H = GI,R = GI;			
			REP(j,R){
				int a = GI,b = GI;
				Curves.pb( PII(a,b) );
			}
			
			int b = is_inside(PII(100000,0),Curves),
				a = is_inside(PII(0,0),Curves);
			if( a*b || (!a && !b) ) continue;
			
			pair<LL,int> P = make_pair( Area , H );			
			if ( a ) A.pb( P );
			else B.pb( P );			
		}
		int h = 0,d = 0;
		sor(A);sor(B);
		for(int i = B.sz-1;i >= 0; --i ) A.pb( B[i] );		
		for(int i = 0,dif;i < int(A.sz-1); ++i ){
			dif = A[i+1].second - A[i].second;
			if( dif < 0 ) d += -dif;else h += dif;			
		}		
		printf("%d %d\n",h,d);		
	}
	return 0;
}