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
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i )
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
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

int A[1024][3],Seen[1024];
double Dist[1024][1024];
double Q[1024];

PII getEndPoint( const int& i ){ 
	return PII(A[i][0] + (  A[i][2] > 0 ? A[i][2] : 0 ), A[i][1] + ( A[i][2] < 0 ? -A[i][2] : 0 ) );
}

bool isOnline( int i , const PII& p ){
	PII ret = getEndPoint( i );
	return p.first >= A[i][0] && p.first <= ret.first &&
			p.second >= A[i][1] && p.second <= ret.second;
}
double dist( const PII& a, const PII& b ){
	return hypot( a.first - b.first , a.second - b.second );
}

double getClose( int i , int j ){
	set<int> X,Y;
	PII e1 = getEndPoint( i ), e2 = getEndPoint( j );
	X.insert( A[i][0] );Y.insert( A[i][1] );
	X.insert( A[j][0] );Y.insert( A[j][1] );
	X.insert( e1.first );Y.insert( e1.second );
	X.insert( e2.first );Y.insert( e2.second );	
	double ans = INT_MAX;
	EACH(it,X) EACH(it1,Y){
		PII p = PII(*it,*it1);		
		int ok = 0;
		if( isOnline(i,p) ) ans <?= dist(p,e2), ans <?= dist(p,PII(A[j][0],A[j][1])), ok++;
		if( isOnline(j,p) ) ans <?= dist(p,e1), ans <?= dist(p,PII(A[i][0],A[i][1])), ok++;
		if( ok == 2 ) return 0;
	}
	return ans;
}


int main(){
	int N;
	while( N = GI ){
		REP(i,N) REP(j,3) A[i][j] = GI, Q[i] = INT_MAX;
		REP(i,N) REP(j,i) Dist[i][j] = Dist[j][i] = getClose( i , j );
		
		REP(i,N) Q[i] = INT_MAX, Seen[i] = 0;
		int start = 0,next;
		Q[ start ] = 0;
		while( start != 1 ){
			Seen[ start ]  = 1;
			double smallest = INT_MAX;
			REP(i,N) if( Seen[i] == 0 ) {
				Q[i] <?= max( Q[start],Dist[ start ][ i ]);
				if( Q[i] < smallest ) smallest = Q[i], next = i; 
			}
			start = next;			
		}
		printf("%.2lf\n",Q[start]);
	}
	return 0;
}

