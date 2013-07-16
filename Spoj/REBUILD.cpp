#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <sstream>
using namespace std;
#define REP(i,N) for(int i = 0;i < (N); ++i)
#define EACH(it,mp) for( __typeof(mp.begin()) it(mp.begin()); it != mp.end(); ++it)
#define pb push_back
#define sz size()
#define GI ({int t;scanf("%d",&t);t;})
#define mkp make_pair
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define MAXN 10001
VI Gr[MAXN],GT[MAXN];
int seen[MAXN],Seenid = 1;
VI times;

void dfs(int u) { 
        if(seen[u] == Seenid) return; seen[u] = Seenid;
        EACH(x,Gr[u]) dfs(*x);
        times.pb(u);
}

int component[MAXN], ncomps;
VI CompGr[MAXN];
bool isIncoming[MAXN];

void dfs2(int u) { 
        if(seen[u] == Seenid) return;
        seen[u] = Seenid; component[u] = ncomps;
        EACH(x,GT[u]) dfs2(*x);
}
void go(int u){
	if( seen[ u ] == Seenid ) return; seen[u] = Seenid;
	EACH(it,CompGr[u]) go( *it );
}



int main(){
	int N,M;
	while( scanf("%d %d",&N,&M) == 2 ){
		assert( N <= 10000 );
		assert( M <= 100000 );
				
		REP(i,MAXN) Gr[i].clear(),GT[i].clear(),isIncoming[i] = 0,CompGr[i].clear();
		times.clear();
		
		REP(i,M){
			int a = GI-1,b = GI-1;assert( a >= 0 && a < N); assert( b >= 0 && b < N);
			Gr[a].pb( b );
			GT[b].pb( a );
		}
		Seenid++;
		REP(i,N) dfs( i );	
		assert( times.sz == N );
		Seenid++;
		ncomps = 0;
		for(int i = N-1;i >= 0; --i ) if( seen[ times[i] ] != Seenid ) dfs2( times[i] ),ncomps++;
		
		REP(i,N) EACH(it,Gr[i]) if( component[i] != component[ *it ] ){
			CompGr[ component[ i ] ].pb( component[ *it ] );
			isIncoming[ component[ *it ] ] = 1;		
		}
		int f = 0;	
		REP(i,ncomps) if( isIncoming[ i ] == 0 ){		
			f = 1;
			++Seenid;
			go( i );		
			REP(i,ncomps) if( seen[i] != Seenid ) f = 0;
			break;
		}		
		printf("%s\n",f?"Yes":"No");		
	}
}