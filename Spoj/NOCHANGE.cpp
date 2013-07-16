#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cassert>
#include <queue>
#include <set>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.size());i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define mkp(a,b) make_pair((a),(b))
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;


int DP[200000][5];
VI V;

int main(){
	int N = GI,K = GI;
	REP(j,K) V.pb( GI );
	REP(i,N+1) REP(j,5) DP[i][j] = INF;
	
	DP[0][0] = 1;
	rev( V );
	
	REP(j,K){
		int x = V[j];
		if( j ){
			FOR(c,0,N) if( DP[c][j-1] < INF ){
				int l = DP[c][j-1]-1;
				if( c+l*x <= N+1 ) DP[c+l*x][j] <?= l+1;
			}
		}
		FOR(c,0,N) DP[c+x][j] <?= DP[c][j] + 1;
	}
	
	if( DP[N][K-1] < INF ) printf("YES\n");
	else printf("NO\n");
	return 0;
}
