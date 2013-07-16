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

int Cap[256][256],Seen[256],COST[256],Par[256];
int Source,Sink,Seenid;
VI Gr[256];

int find_path(){
	int ret = 0,f = 0;
	Seenid++;
	
	set<PII> Q;
	Q.insert( PII(0,Source) );
	
	while( Q.sz ){
		int cost = -Q->begin().first, v = Q->begin().second;Q.erase(Q.begin());
		if( Seen[v] == Seenid ) continue;Seen[v] = Seenid;
		if( v == Sink ) { f = 1;ret = cost;break;}
		
		REPV(i,Gr[v]){
			int _v = Gr[v][i];			
			if( Seen[_v] != Seenid || COST[_v] < cost + Cap[v][_v] ){
				COST[_v] = cost + Cap[v][_v];
				Par[_v] = v;
				Q.insert(PII(-COST[_v],_v));
			}
		}
	}
	
	if( f ){
		int back = Sink,next = Par[back],low = INF;
		for(;back!=Source;back = next,next = Par[back]) if(next!=Source && back!=Sink) low >?= Cap[next][back];
		
		for(back = Sink,next = Par[back];back!=Source;back = next,next = Par[back]) 
			if(next!=Source && back!=Sink) Cap[next][back] -= low,Cap[back][next] += low;		
	}
	return ret;
}

int main(){
	int T = GI,a,b,l;
	while( T-- ){
		memset(Cap,0,sizeof(Cap));
		REP(i,256) Gr[i].clear();
		int C1 = GI,C2 = GI,;
		Source = 0;
		Sink = C1+C2+1;s
		
		FOR(i,1,C1) Gr[Source].pb(i),Cap[Source][i] = 1;
		FOR(i,1,C2) Gr[C1+i].pb(Sink),Cap[C1+i][Sink] = 1;
		
		while((a=GI) + (b=GI) + (l=GI)) if(l){
			Gr[a].pb(C1+b);Gr[C1+b].pb(a);
			Cap[a][C1+b] = l;
		}
		
		int ret = 0,t;
		while( (t = find_path()) ) ret += t;
		cout << ret << endl;
	}
	return 0;
}
