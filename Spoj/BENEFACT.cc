#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end());
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
#define GETN(V) for(int i=GI;i>=0;i--) V.pb( GI )
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

vector<PII> Gr[50001];
int Seen[50001],Seenid;

PII getLong(int Start){
	set<PII> S;
	S.insert(PII(0,Start));
	Seenid++;
	
	int _cost = -INF,_v = -1;	
	while( S.sz ){		
		int cost = S.begin()->first,v = S.begin()->second;S.erase(S.begin());		
		if( Seen[v] == Seenid ) continue;Seen[v] = Seenid;		
		if( _cost < cost ) _cost = cost, _v = v;		
			
		REPV(i,Gr[v]) S.insert(PII(cost + Gr[v][i].second,Gr[v][i].first));
	}
	
	return PII(_cost,_v);
}

int main(){
	int T = GI;
	while( T-- ){
		int N = GI;
		REP(i,N+1) Gr[i].clear();
		REP(i,N-1){
			int a = GI,b = GI,l = GI;
			Gr[a].pb(PII(b,l));
			Gr[b].pb(PII(a,l));
		}
		
		PII p = getLong(1);		
		PII r = getLong(p.second);		
		cout << r.first << endl;
	}
	return 0;
}
