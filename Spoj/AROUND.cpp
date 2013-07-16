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

const int MN = 5001;
int F[MN],Angles[MN][3],Angcnt[MN];
int COST[MN][3];
VI Gr[MN];


int main(){
	int T = GI;
	while( T-- ){
		int N = GI, M = GI;
		REP(i,N) Gr[i].clear(), F[i] = GI, Angcnt[i] = 0;
		REP(i,M) {
			int a = GI-1, b = GI-1;
			Gr[a].pb( b );
			Gr[b].pb( a );
		}

		queue<int> Q;
		Q.push( 0 );
		Q.push( F[0] );
		COST[0][Angcnt[0]] = 0;
		Angcnt[0] = 1;
		int ans = -1;
		while( Q.sz ){
			int f = Q.front();Q.pop();
			int ang = Q.front();Q.pop();			
			if( f == 0 && Angcnt[0] == 2 ){ ans = COST[f][1];break;}
			
			EACH(it,Gr[f]){
				int diff = F[*it] - F[f], ok = 1;
				if (diff > 180) diff -= 360;
				else if (diff < -180) diff += 360;
				const int& nang = ang + diff;
				REP(i,Angcnt[*it]) if( Angles[*it][i] == nang ) ok = 0;
				if( !ok || Angcnt[*it] == 2 ) continue;
				Angles[*it][Angcnt[*it]] = nang;
				COST[*it][Angcnt[*it]++] = COST[f][Angcnt[f]-1] + 1;
				Q.push( *it );
				Q.push( ang + diff );				
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}