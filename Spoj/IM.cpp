#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(_typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<30)
#define sz size()
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;
int N,M,n,Seenid = 1,Reachid = 1;
VI Gr[30016];
int Par[30016],Seen[30016][2],Reach[30016];



bool bfs(){
	++Reachid;
	++Seenid;
	int Src = 2,Sink = 3;
	Par[Src] = -1;
	queue<int> Q;
	Q.push(Src);
	Seen[Src][0] = Seenid;
	int f = 0;
	while( Q.sz ){
		int v = Q.front();Q.pop();
		if( v == Sink ){f = 1;break;}
		
		REPV(i,Gr[v]) if(Seen[Gr[v][i]][0] != Seenid ){
			int n = Gr[v][i];
			Par[n] = v;
			Seen[n][0] = Seenid;
			Q.push(n);
		}
	}
	if(!f) return 0;
	
	int back = Sink;
	while( Par[back] > -1 ){
		int prev = Par[back];
		Reach[back] = Reachid;
		Gr[prev].erase(find(Gr[prev].begin(),Gr[prev].end(),back));
		back = prev;
	}
	return f;
}


bool next(){
	++Seenid;
	int Src = 2,Sink = 1;
	queue<int> Q;
	Q.push(Src);
	Seen[Src][0] = Seen[Src][1] = Seenid;
	Par[Src] = -1;
	
	int f = 0;
	while( Q.sz ){
		int v = Q.front();Q.pop();
		if(v == Sink){f = 1;break;}
		
		REPV(i,Gr[v]){
			int n = Gr[v][i],vis = 0;
			if(Reach[n] == Reachid && Reach[v] == Reachid) vis = 1;
			if(Reach[v] && Reach[n]!=Reachid && Reach[Par[v]]!=Reachid) continue;			
			if(Seen[n][vis] == Seenid) continue;
			Par[n] = v;
			Seen[n][vis] = Seenid;
			Q.push(n);
		}
	}
	return f;
}


int main(){
	int T = GI;
	while(T--){
		N = GI,M = GI;
		REP(i,N+1) Gr[i].clear();
		REP(i,M){
			int a = GI,b = GI;
			if(a>N || b>N) continue;
			Gr[a].pb(b);
			Gr[b].pb(a);
		}
		if(bfs() && next()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


