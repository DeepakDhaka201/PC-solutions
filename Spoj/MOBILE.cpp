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
#define INF (1<<30)
#define LINF (1e18)
#define sor(ar) sort(ar.begin(),ar.end())

typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

int Ht[100000];

int main(){
	int N;
	while( N = GI ){
		int bad = 0;
		REP(i,N) Ht[i] = INT_MAX;
		vector< VI > Mat(N);
		REP(i,N){
			REP(j,N) Mat[i].pb( GI );		
			Mat[i].pb(INT_MAX);
		}
		REP(i,N){
			for(int j = N-1; j >= i; --j ){
				if( i == j && (Mat[i][j] || Mat[j][i] ) ){ bad = 1;goto end;}
				assert( i != j || (!Mat[i][j] && !Mat[j][i]) );
				if( Mat[i][j] != Mat[j][i] || Mat[i][j] > Mat[i][j+1] || Mat[i][j] > Ht[j] ){
					bad = 1;
					goto end;
				}
				Ht[j] = Mat[i][j];
			}
		}
		end:
		printf("%s\n",(bad?"false":"true"));
	}
	return 0;
}