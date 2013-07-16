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
int Cap[128][128],Source,Sink;
int Seen[128],Seenid = 1;

int flow(int v ){
	if( v == Sink ) return 1;
	Seen[ v ] = Seenid;	
	EACH(it,Gr[v]){
		int n = (*it);
		if( Seen[ n ] != Seenid && Cap[v][n] > 0 && flow( n ) ){
			Cap[v][n]--;
			Cap[n][v]++;
			return 1;
		}
	}
	return 0;	
}

int main(){
	int T = GI;
	while( T-- ){
		int N = GI,M = GI;
		REP(i,128) Gr[i].clear();
		memset(Cap,0,sizeof(Cap));
		REP(i,M){
			int a = GI-1, b = GI-1;
			Gr[a].pb( b );
			Gr[b].pb( a );
			Cap[a][b] = 1;
		}
		Source = GI - 1,Sink = GI - 1;
		int ans = 0;
		Seenid++;
		while( flow(Source) ){
			Seenid++;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
