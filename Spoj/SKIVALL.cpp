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
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()

#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

int A[64][64],NN;
short int DP[61][61][61][61], prev[61][61][61][61];
PII Ar[ 60*60 + 1 ];
int dx[] = { 0 , -1 , 0 , 1 };
int dy[] = { 1 , 0 , -1 , 0 };

bool comp( const PII& a , const PII& b ){
	return A[a.first][a.second] < A[b.first][b.second];
}

int main(){
	int M = GI,N = GI,ret = 1;
	PII back[2];
	REP(i,M) REP(j,N){
		A[i][j] = GI;
		Ar[NN++] = PII(i,j);
	}
	sort( Ar, Ar+NN	, comp );
	#define REF(x,a,b) x[a.first][a.second][b.first][b.second]
	#define ok(a) ( a.first >=0 && a.first< M && a.second >= 0 && a.second < N )
	#define HT(a) A[a.first][a.second]
	
	REP(i,NN) REP(j,NN){
		PII ar[] = { Ar[i], Ar[j] };		
		short int& ans = REF(DP,ar[0],ar[1]), ch, val[] = { 0 , 0 }, &p = REF(prev,ar[0],ar[1]);
		ans = 1, p = -1;
		if( i != j ) {
			ans = -10000;
			if( HT(ar[0]) > HT(ar[1]) ) val[0] = 1;
			else if( HT(ar[0]) == HT(ar[1]) ) val[0] = val[1] = 1;
			else val[1] = 1;
			REP(ch,2) if( val[ch] ){
				int Ht = HT(ar[ch]), lo = -INT_MAX;
				REP(d,4){
					ar[ch].first += dx[d], ar[ch].second += dy[d];
					if( ok(ar[ch]) && HT(ar[ch]) < Ht ){
						const int& nans = REF(DP,ar[0],ar[1]) + 1;					
						if( nans > ans ) ans = nans, p = ch*4 + d;				
					}
					ar[ch].first -= dx[d], ar[ch].second -= dy[d];	
				}
			}
		}
		if( ans > ret ) ret = ans, back[0] = ar[0], back[1] = ar[1];		
	}
	
	vector<PII> V[2];
	REP(i,2) V[i].pb( back[i] );
	
	while( true ){				
		int p = REF(prev,back[0],back[1]);
		if( p == -1 ) break;
		int ch = p/4, d = p%4;		
		back[ch].first += dx[d], back[ch].second += dy[d];
		V[ch].pb( back[ch] );		
	}
	reverse(V[1].begin(),V[1].end());
	V[0].pop_back();
	printf("%d\n",ret);
	REP(i,2) EACH(it,V[i]) printf("%d %d\n",it->first + 1, it->second + 1);
	return 0;
}

