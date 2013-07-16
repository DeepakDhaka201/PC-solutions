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
#define LINF (1e18)
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

int start[32];
int target[32];

LL go(int disc,int pos){
	LL ret = 0,vis[3] = {};
	vis[ pos ] = vis[ start[disc] ] = 1;
	LL rem = -1;
	REP(i,3) if( !vis[i] ) rem = i;
	for(int i=disc-1;i>=0;i--) ret += go( i , rem );
	LL add = start[disc] != pos;
	start[disc] = pos;
	return ret + ( add );
}

int main(){
	int N;
	while( N = GI ){
		REP(i,N) start[i] = GI-1;
		REP(i,N) target[i] = GI-1;
		LL c = 0;
		for(int i=N-1;i>=0;i--) if( start[i] != target[i] ){
			c += go( i , target[i] );
			//REP(i,N) cout <<" -> " << start[i] << endl;
			//cout <<" c = " << c << endl;
		}
		cout << c << endl;
	}
}