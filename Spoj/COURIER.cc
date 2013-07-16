using namespace std;
#define LET(x,a) __typeof(a) x(a)
#define FOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPV(i,ar) for(int i = 0;i<(signed int ) ar.size();i++)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define sz size()
#define cs c_str()
#define pb push_back
#define ALL(f,x) ({bool _o=1;f if(!(x)) {_o=0;break;}_o;})
#define EXISTS(f,x) (!ALL(f,!(x)))
#define COUNT(f,x) ({int _c=0;f _c+=(x);_c;})
#define sor(ar) sort(ar.begin(),ar.end())
#define GI GETNUM()
#define INF (1<<28)
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#include <iostream>
#include <deque>
#include <cstdio>
#include <set>
#include <sstream>
#include <algorithm>

typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
#define V(x) vector< x >
typedef V(int) VI;
typedef V(VI) VVI;
LL ar[101][101],TOT = 0;
int vis[32];
V(PII) V;
int N,M,B;
LL memo[101][1<<16];

#define ITYPE unsigned int
#define GETCHAR getchar_unlocked
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

ITYPE GETNUM ( void )
{
   int i;

   ITYPE j;

   i = GETCHAR () ;
   while ( ! DIG( i ) ) i = GETCHAR () ;

   j = ( i - '0' ) ;

   i = GETCHAR () ;
   while ( DIG( i ) )
   {
      j = ( ( j << 1 ) + ( j << 3 ) + ( i - '0' ) ) ;
      i = GETCHAR () ;
   }
   return ( j ) ;
} 


void clear(){
	V.clear();
	REP(i,N) REP(j,N) ar[i][j] = (INF);
	REP(i,N) ar[i][i] = 0;
	memset(memo,-1,sizeof(memo));	
}


LL go(int c,int code){
	if( memo[c][code] != -1 ) return memo[c][code];

	LL ret = (INF),f = 0;	
	REPV(i,V) if(!(code & (1<<i))){
		f = 1;
		ret <?= ar[c][V[i].first] + ar[V[i].first][V[i].second] + go(V[i].second,code | (1<<i));
	}
	if(!f) return memo[c][code] = ar[c][B];
	return memo[c][code] = ret;
}

int main(){
	int T = GI;
	while(T--){
		N = GI,M = GI,B = GI-1;
		clear();
		REP(i,M){
			int a = GI-1,b = GI-1,c = GI;
			ar[a][b] <?= c;
			ar[b][a] <?= c;
		}
		int Z = GI;
		REP(i,Z){
			int a = GI-1,b = GI-1,c = GI;TOT += c;
			REP(j,c) V.pb(PII(a,b));
		}
		REP(k,N) REP(i,N) REP(j,N) ar[i][j] <?= ar[i][k] + ar[k][j];
		cout << go(B,0) << endl;
	}
	return 0;
}

