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
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

int Seen[100000][10], Seenid, MOD, x;
char s[1000000];

void go( int n ){
	REP(i,10) if( Seen[n][i] != Seenid ){
		Seen[n][i] = Seenid;
		int nn = (n*10 + i )%MOD;
		go( nn );
		s[--x] = '0' + i;
	}
}
int main(){
	int N;
	while( N = GI ){
		MOD = 1;REP(i,N-1) MOD *= 10;
		REP(i,N-1) putchar('0');
		++Seenid;
		x = 1000000 - 2;
		go(0);
		printf("%s",s+x);		
		puts("");
  }
  return 0;
}
