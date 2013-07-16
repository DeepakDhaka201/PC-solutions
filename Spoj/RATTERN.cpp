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
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.size());i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define GI ({int y;scanf("%d",&y);y;})
#define sz size()
#define pb push_back
#define mkp make_pair
#define INF (1<<30)
#define LINF (1e18)
#define sor(ar) sort(ar.begin(),ar.end())

typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int Bits[9][2] = {
{-1,-1}, // (1)

{0,-1}, // (12),(21)
{7,-1}, //(12),(21)

{7,15}, // (123), (321) 
{0,1}, // (123), (321)

{7,8}, // (321)
{0,7}, // (231)
{0,8}, // (123)
{6,7}, // (132)

}, NF = 9;

PII D[18];

vector< pair<int,string> > Forms[NF];
int Map[8][8],N,M,K,NP[] = { -1, 1 , 2 , 3 , 3 };
int canPlace[8][8][10];
char Paints[10];
int Memo[1<<16][8][8];

int go( int bit, int r , int c ){	
	if( r == N ) return ((bit==(1<<16)-1) ? 0 : INT_MAX/4);
	else if( c == M ) return go( bit , r+1 , 0 );
	int& ans = Memo[bit][r][c];
	if( ans != -1 ) return ans;	
	
	ans = INT_MAX/4;
	REP(k,NF) if( canPlace[r][c][k] < INT_MAX){		
		int nb = bit, ok = 1;
		for( int b = 0; Bits[k][b] != -1 && b < 2; ++b ) {
			if( nb & (1<<Bits[k][b]) ) { ok = 0;break;}
			nb |= (1<<Bits[k][b]);
		}
		if( !ok || (nb & (1<<15)) == 0 ) continue;
		// optimizations
		if( r > 0 && (nb&(1<<8)) == 0 && (nb&1) == 1 ) continue;		
		if( r == M-1 && (nb&(1<<7)) == 0 ) continue;		
		ans <?= canPlace[r][c][k] + go( ((nb^(1<<15))<<1) | 1 , r , c+1 );
	}
	int ok = 1;
	if( (bit & (1<<15)) == 0 ) ok = 0;
	if( r > 0 && (bit&(1<<8)) == 0 && (bit&1) == 1 ) ok = 0;	
	if( ok ){
		int nb = ((bit^(1<<15)) << 1 );
		if( Map[r][c] != 2 ) ans <?= 0 + go( nb , r , c+1 );	
		else ans <?= go( nb^1 , r , c+1 );
	}
	return ans;
}


int main(){
	int T = GI;
	D[0] = PII(0,-1);
	D[1] = PII(0,-2);
	D[6] = PII(-1,1);
	D[7] = PII(-1,0);
	D[8] = PII(-1,-1);
	D[15] = PII(-2,0);
	
	while( T-- ){
		REP(i,8) REP(j,8) REP(k,NF) canPlace[i][j][k] = INT_MAX;
		REP(k,NF) Forms[k].clear();
		memset( Memo , -1 , sizeof(Memo) );
		
		N = GI,M = GI,K = GI;
		REP(i,8) REP(j,8) Map[i][j] = 2;
		REP(i,N) REP(j,M) Map[i][j] = GI;
		
		N = 8, M = 8;
		REP(i,K){
			int F = GI,C = GI,xx = 0, Np = NP[F];
			REP(j,Np) xx += sprintf(Paints+xx,"%d",GI);
			string S(Paints);			
			if( F == 1 ) Forms[0].pb( mkp(C,S) );
			else if( F == 2 || F == 3){				
				int st = ( F == 2 ? 1 : 3 );				
				Forms[st].pb(  mkp(C,S) );
				Forms[st+1].pb(  mkp(C,S) );
				reverse(S.begin(),S.end());				
				Forms[st].pb(  mkp(C,S) );
				Forms[st+1].pb(  mkp(C,S) );
			} else {				
				string s1 = ""; s1 += S[2]; s1 += S[1], s1 += S[0];
				string s2 = ""; s2 += S[1]; s2 += S[2] , s2 += S[0];
				string s3 = ""; s3 +=  S[0]; s3 += S[1] , s3 += S[2];
				string s4 = ""; s4 += S[0]; s4 += S[2] , s4 += S[1];				
				Forms[5].pb(  mkp(C,s1) );
				Forms[6].pb(  mkp(C,s2) );
				Forms[7].pb(  mkp(C,s3) );
				Forms[8].pb(  mkp(C,s4) );
			}
		}
		#define ok(a,b) ((a) >= 0 && (a) < N && (b) >= 0 && (b) < M )
		REP(i,N) REP(j,M) if( Map[i][j] != 2 ) {			
			int Pattern[16], r = i, c = j;
			PII cords[16];
			REP(k,16){				
				if( --c < 0 ) --r, c = M-1;				
				Pattern[k] = ( ok(r,c) ? Map[r][c] : 2 );
				cords[k] = PII(r,c);
			}
			
			REP(k,NF) EACH(it,Forms[k]) {				
				if( j == 0 && ( k == 5 || k == 6 || k == 7 || k == 1 || k == 4 ) ) continue;
				if( j == 1 && ( k == 4 ) ) continue;
				if( j == M-1 && ( k == 8 ) ) continue;
				const string& s = it->second;				
				int ok = 1;						
				if( Map[i][j] != s[0] - '0' ) ok = 0;
				else {
					for(int b = 0; Bits[k][b] != -1 && ok && b < 2; ++b ){						
						if( Pattern[Bits[k][b]] != s[b+1] - '0' ) ok = 0;			
					}
				}
				if( ok ) canPlace[i][j][k] <?= it->first;				
			}
		}
		int ans = go((1<<16)-1,0,0);
		printf("%d\n",ans >= INT_MAX/4 ? -1: ans );	
	}
	return 0;
}