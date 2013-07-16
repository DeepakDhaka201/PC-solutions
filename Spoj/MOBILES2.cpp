#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <list>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.size());i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define sz size()
#define pb push_back

typedef long long int LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

int Gr[100001][2], level[100001];
PII Res[100001];

int main(){
	int T = GI;
	FOR(tt,1,T){	
		int N = GI;		
		REP(i,N) REP(j,2){
			Gr[i][j] = GI;
			if( Gr[i][j] > 0 ) --Gr[i][j];
		}		
		int lo = INT_MAX , hi = -INT_MAX;
		
		queue<int> Q;
		Q.push( 0 );
		level[ 0 ] = 0;
		while( Q.sz ){
			int r = Q.front(), l = level[r]; Q.pop();
			REP(i,2){
				const int& n = Gr[r][i];
				if( n == -1 ) lo = min( lo , l + 1 ), hi = max( hi ,l + 1 );
				else level[ n ] = l + 1 , Q.push( n );
			}
		}
		if( hi == lo ) hi++;
		
		int ans = 0;
		if( hi - lo > 1 ) ans = -1;
		else {			
			for(int i = N-1; i >= 0; --i ){
				PII a[2];
				REP(j,2){
					if( Gr[i][j] == -1 ) a[j] = PII( hi == level[i] + 1 , lo == level[i] + 1 );
					else a[j] = Res[ Gr[i][j] ];
				}
				if( a[0].second ){
					if( a[1].first && a[1].second && a[0].first ){
						ans = -1;
						break;
					}
					if( a[1].first ){
						ans++;
						swap(a[0],a[1]);
					}
				}
				Res[i] = PII( a[0].first + a[1].first , a[0].second + a[1].second );
			}		
		}
		printf("%d\n",ans);
	}
	return 0;
}