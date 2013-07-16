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

#define REP(i,N) for(int i = 0;i<(N);i++)
#define REPV(i,ar) for(int i = 0;i < (ar).sz; ++i )
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define sz size()
#define cs c_str()
#define pb push_back
#define INF (1<<30)

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long int LL;

char str[64];
int N,Rem[32];
vector< pair<int,int> > Fact[32];
int main(){
	FOR(n,2,32){
		int nn = n;
		FOR(f,2,32){		
			int c = 0;
			while( nn%f == 0 ) nn /= f, c++;
			if( c ) Fact[n].pb( make_pair( f , c ) );
		}		
	}
		
	while( true ){
		N = 0;
		char c;	while( (c=getchar()) != '\n' && !feof( stdin ) ) str[N++] = c;
		if( str[0] == '#' ) break;		
		set<int> SS;
		for(int i = 0; str[i]; ++i ) SS.insert( str[i]-'a' );
		vector<int> Chars(SS.begin(),SS.end());
		
		memset( Rem , 0 , sizeof(Rem) );
		int Num = N;
		LL ans = 0,cur = -1;
		REP(i,N) Rem[ str[i]-'a']++;
		
		REP(i,N){
			unsigned int c = str[i] - 'a';
			EACH(it,Chars) if( (*it) < c) if( Rem[ *it ] ){
				LL ncur;
				if( cur == -1 ){
					int Cnts[ 32 ] = {};					
					FOR(n,2,Num) EACH(it,Fact[n]) Cnts[ it->first ] += it->second;
					REP(i,32) FOR(n,1,Rem[i]) EACH(it,Fact[n]) Cnts[ it->first ] -= it->second;
					cur = 1;
					REP(i,32) REP(loop,Cnts[i]) cur *= i;					
					ncur = cur;
				}
				ncur = cur*(Rem[ *it ])/Num;				
				ans += ncur;				
			}
			if( cur != -1 ) cur *= Rem[ c ], cur /= Num;
			Rem[ c ]--;
			Num--;
		}
		printf("%10u\n",ans+1);
	}
	return 0;
}