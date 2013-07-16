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
const int MN =50000*2 + 1;

int Outgoing[2][MN],N1,N2,D;
VI GrT[MN]; 

int main(){
	while( (N1=GI) + (N2=GI) + (D=GI) ){
		REP(i,N1+N2) GrT[i].clear(), Outgoing[0][i] = Outgoing[1][i] = 0;
		
		REP(i,D){
			int a = GI-1, b = GI-1;
			Outgoing[0][a]++;
			Outgoing[1][a]++;			
			GrT[b].pb( a );
		}
		
		int ans = INT_MAX;
		REP(s,2){
			int changes = 1, cd = s, installed = 0;
			queue<int> Q[2];
			REP(i,N1+N2) if( Outgoing[s][i] == 0 ) Q[i>=N1].push( i );
			while( Q[0].sz || Q[1].sz ){
				while( Q[cd].sz ){
					const int& v = Q[cd].front();Q[cd].pop();					
					EACH(it,GrT[v]) if( --Outgoing[s][*it] == 0 ) Q[(*it)>=N1].push( *it );
				}				
				cd ^= 1;				
				changes++;
			}
			ans = min( ans , changes );			
		}
		printf("%d\n",ans);
	}
	return 0;
}