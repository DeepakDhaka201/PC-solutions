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

#define REP(i,N) for(int i = 0;i<(N);i++)
#define REPV(i,ar) for(int i = 0;i < (ar).sz; ++i )
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define GI ({int t;scanf("%d",&t);t;})
#define sz size()
#define cs c_str()
#define pb push_back
#define INF (1<<30)

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long int LL;

const int MN = 102;
int N,M,Matrix[ MN ][ MN ];
long long int Count[MN][MN], Cost[MN][MN];
vector<PII> Edges[MN];

void bfs( int Source ){
	static int Seen[ MN ], Seenid = 1;	
	++Seenid;
	
	set< PII > Q;
	Q.insert( PII(0,Source) );
	Cost[ Source ][ Source ] = 0;
	Count[ Source ][ Source ] = 1;
	
	while( Q.sz ){
		int vertex = Q.begin()->second, cost = Q.begin()->first;Q.erase( Q.begin() );
		if( Seen[ vertex ] == Seenid ) continue;
		Seen[ vertex ] = Seenid,
		Cost[ Source ][ vertex ] = cost;
		
		EACH(it,Edges[ vertex ]) if( Seen[ it->first ] != Seenid )
			Q.insert( PII( cost + it->second , it->first) );		
	}
	
	vector< PII > order;
	REP(i,N) if( Seen[ i ] == Seenid ) order.pb( PII(Cost[ Source ][ i ],i) );
	sort( order.begin() , order.end() );
	assert( order[0].second == Source );
	
	REPV(i,order) {
		int n = order[i].second;		
		REP(j,i){
			int p = order[j].second;
			if( Matrix[ p ][ n ] && Cost[ Source ][ n ] == Cost[ Source ][ p ] + Matrix[ p ][ n ] ) 
				Count[ Source ][ n ] += Count[ Source ][ p ];
		}
	}	
	
}

int main(){
	int T = GI;
	while( T-- ){
		REP(i,MN) Edges[i].clear();
		memset( Matrix , 0 , sizeof( Matrix ) );
		memset( Cost , 0 , sizeof( Cost ) );
		memset( Count , 0 , sizeof( Count ) );
		
		N = GI,M = GI;
		REP(i,M){
			int a = GI - 1,b = GI - 1,c = GI;
			Edges[ a ].pb( PII(b,c) );
			Edges[ b ].pb( PII(a,c) );
			Matrix[ a ][ b ] = Matrix[ b ][ a ] = c;
		}
		//REP(i,N) REP(j,N) printf(" %d%s",Matrix[i][j], j == N-1?"\n":"");
		REP(i,N) bfs( i );		
		REP(k,N){
			double Imp = 0;
			REP(i,N) REP(j,i) if( i != k && i != j && 
				Cost[i][j] == Cost[i][k] + Cost[k][j] &&
				Cost[i][j] && Cost[i][k] && Cost[k][j] ){
				Imp += Count[ i ][ k ] *1.0 / Count[ i ][ j ]*Count[ k ][ j ] ;
			}
			printf("%.3lf\n",Imp*2);
		}
		
	}
	return 0;
}