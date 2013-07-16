#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <math.h>
#include <map>
using namespace std;

#define REP(i,N) for(int i=0;i<(N);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.sz);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b); ++i )
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin()); it != mp.end() ; ++it )
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

VI Gr[100002];
VI Times;

int go(int v){
	int time = 0;
	int S[2][2] = { 0 , 0 , 0 , 0 };
	REPV(i,Gr[v]){
		int pos = Gr[v][i];
		int ct = go( Gr[v][i] );
		bool g = Times[pos] > Times[v];
		if( S[g][0] < ct && S[g][1] < ct ) S[g][1] = S[g][0],S[g][0] = ct;
		else if ( S[g][1] < ct ) S[g][1] = ct;
	}
	int ret = S[0][0] + S[0][1];
	ret >?= S[1][0] + S[0][0];
	return ret + Times[v];	
}

int main(){
	int N;
	while( N=GI ){
		Times.clear();
		REP(i,100002) Gr[i].clear();
		REP(i,N) Times.pb( GI );
		VI roots;
		REP(i,N) {
			int a = GI;
			if( a == -1 ) roots.pb( i );
			else Gr[a].pb( i );				
		}
		int tot = 0;
		REPV(i,roots) tot += go( roots[i] );
		printf("%d\n",tot);
	}
}