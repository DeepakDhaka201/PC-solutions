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
#define GI ({int t;scanf("%d",&t);t;})
#define sz size()
#define cs c_str()
#define pb push_back
#define INF (1<<30)

using namespace std;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<int> VI;
typedef long long int LL;
#define EPS (1e-9)
const int MN = 2200,fM = 20;
int facts[fM] = { 41,467,334,500,169,724,478,358,962,464,705,145,281,827,961,491,995,942,827,436 };
const int MOD = 100000;

struct Node {
	PDD p;
	int cnt;
}g;
vector<Node> HashTable[MOD];
int X[MN],Y[MN];

int get_hash( const PDD& p ){
	static char temp[1024];
	sprintf(temp,"%.4lf%.4lf",p.first,p.second);
	long long int ret = 0;
	for(int i = 0; temp[i]; ++i ) if( temp[i] >= '0' && temp[i] <= '9' ) {
		ret = (ret*facts[i%fM] + (temp[i] - '0' ))%MOD;
	}
	return ret;
}


PDD get_Xcut( int i , int j ){
	if( X[i] - X[j] == 0 ) return PDD(X[i],INT_MAX);
	else if( Y[i] - Y[j] == 0 ) return PDD((INT_MAX)*1.*Y[i],0);
	PDD ret;
	ret.second = ( Y[i] - Y[j] ) * 1. / ( X[i] - X[j] );
	ret.first = X[i] - Y[i] / ret.second;
	return ret;

}

int main(){
	int T = GI,N;
	while( T-- ){
		N = GI;
		REP(i,N) X[i] = GI, Y[i] = GI;
		vector<int> seen;
		
		int ret = 1;
		REP(i,N) REP(j,i) {
			PDD a = get_Xcut( i , j );			
			int h = get_hash( a ) , done = 0;			
			seen.pb( h );
			EACH(it,HashTable[h]) 
				if( fabs(it->p.first - a.first) < EPS && fabs(it->p.second - a.second ) < EPS ){
					done = 1;					
					it->cnt++;
					ret = max( ret , it->cnt );
					break;
			}
			if( !done ){
				g.p = a,g.cnt = 1;
				HashTable[h].pb( g );
			}
		}
		ret *= 2;
		int print = -1;
		for(int i = 1;i <= N; ++i ) if( i*(i-1) == ret ) {
			print = i - 1;
			break;
		}
		printf("%d\n",print);		
		assert( print >= 1 );
		if( T ) EACH(it,seen) HashTable[ *it ].clear();
	}
	return 0;
}