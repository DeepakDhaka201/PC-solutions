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
vector<int> Gr[128];
int Edges[2048][2];
int Cap[2048],Source,Sink,N,M;
int Seen[128],Seenid = 1;

int flow(int v){
	if( v == Sink ) return 1;
	EACH(it,Gr[v]){
		int e = (*it);
		int from = Edges[ e ][0] ,to = Edges[ e ][1];
		if( Seen[to] != Seenid && Cap[e] > 0 && flow( to ) ){
			Cap[e]--;
			Cap[e^1]++;
			return 1;
		}		
	}
	return 0;
}


int main(){
	int T = GI;
	while( T-- ){
		N = GI,M = GI;
		assert( N <= 100 );
		assert( M <= 1000 );
		memset(Cap,0,sizeof(Cap));
		REP(i,128) Gr[i].clear();
		int ecnt = 0;
		REP(i,M){
			int a = GI-1,b = GI-1;assert( a>= 0 && a <N );assert( b>=0 && b < N );
			Edges[ ecnt ][0] = a; Edges[ ecnt ][1] = b;
			Gr[ a ].pb( ecnt );
			Cap[ecnt] = 1;
			
			ecnt++;
			Edges[ ecnt ][0] = b; Edges[ ecnt ][1] = a;
			Gr[ b ].pb( ecnt );
			Cap[ecnt] = 0;	
			ecnt++;
			assert( ecnt < 2048 );
		}
		Source = GI-1, Sink = GI-1;
		int ans = 0;
		Seenid += 2;
		while( flow(Source) ){
			Seenid++;
			ans++;
		}
		printf("%d\n",ans);
	}
}