/*
	ACC	
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<28)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
typedef pair<int,int> PII;

VI Gr[5020];
int Seen[5020],Seenid,Target;
VI L;

int go( int v ){
	L.pb( v );
	if( v == Target ) return 1;
	REPV(i,Gr[v]) if( Seen[ Gr[v][i] ] != Seenid ){
		Seen[ Gr[v][i] ] = Seenid;
		if( go( Gr[v][i] ) ) return 1;
	}
	L.pop_back();
	return 0;
}
int main(){
	int N;
	while((N=GI)){
		REP(i,5020) Gr[i].clear();
		REP(i,N-1){
			int a = GI,b = GI;
			Gr[a].pb( b );
			Gr[b].pb( a );
		}
		int L1 = GI;
		REP(i,L1){
			++Seenid;L.clear();
			int sa = GI,sb = GI;Target = sb;	
			Seen[ sa ] = Seenid;		
			assert(go(sa));
			if(!(L.sz%2)){
				int a = L[L.sz/2-1];
				int b = L[L.sz/2];
				if( a > b ) swap(a,b);
				printf("The fleas jump forever between %d and %d.\n",a,b);	
			}
			else printf("The fleas meet at %d.\n",L[L.sz/2]);
		}
	}
}
