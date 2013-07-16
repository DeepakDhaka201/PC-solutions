#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
#define REP(i,N) for(int i=0;i<(N);i++)
#define REPV(i,a) for(int i=0;i<a.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define sz size()
#define INF (1<<28)
#define LINF ((int) 1e18)
#define GI ({int t;scanf("%d",&t);t;})
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
typedef long long int LL;
typedef pair<int,int> PII;

int Source,Sink;
int Gr[512][512],Dist[512][512];
int Cnt[512],Par[512];
void print(int N);



int find_path(int N){
	bool Vis[512];int P[512],Costs[512];
	REP(i,512) Vis[i] = 0,P[i] = -1,Costs[i] = INF;
	set<PII> Q;//(cost,Vertex);
	Q.insert(PII(0,Source));
	P[Source] = -1;
	int f = 0;
	//print(N);
	
	while( Q.sz ){
		int c = Q.begin()->first,v = Q.begin()->second;Q.erase(Q.begin());
		if( v == Sink ){ f = c;break;}
		if(Vis[v]) continue;Vis[v] = true;
		
		FOR(i,0,N+1) if(!Vis[i] && Gr[v][i]<INF){
			int nc = c + Gr[v][i];
			if( Costs[i] > nc ){
				Costs[i] = nc;
				P[i] = v;
				Q.insert(PII(nc,i));	
			}
		}		
	}
	int back = Sink;
	while(P[back]>-1){
		int prev = P[back];
		int t = Gr[prev][back];
		Gr[prev][back] = INF;
		Gr[back][prev] = -t;
		back = prev;
	}
	//print(N);
	return f;
}


void print(int N){
		cout << " --------------- "<< endl;
		FOR(i,0,N+1){
			FOR(j,0,N+1) Gr[i][j]==INF?cout<<"- ":cout<<Gr[i][j]<<" ";
			cout << endl;	
		}	
}

int main(){
	int T = GI;
	while( T-- ){		
		int N = GI;
		Source = 0,Sink = 512;
		FOR(i,0,N+1) FOR(j,0,N+1) Dist[i][j] = INF,Gr[i][j] = INF;
		FOR(i,1,N) Dist[i][i] = 0,Cnt[i] = 0;		
		REP(i,N) Cnt[GI]++;
		int E = GI;
		REP(i,E){ 
				int a = GI,b = GI;
				Dist[a][b] <?= 1;
				Dist[b][a] <?= 1;
		}
		
		FOR(k,1,N) FOR(i,1,N) FOR(j,1,N) Dist[i][j] <?= Dist[i][k] + Dist[k][j];
		
		FOR(i,1,N){
			if(Cnt[i]>1){ Gr[Source][i] = 0;cout << " Attaching : "<< i << endl;}
			else if(!Cnt[i]) Gr[i][Sink] = 0,cout << " Sinking : "<< i << endl;
		}		
		FOR(i,1,N) FOR(j,1,N) if(!Gr[Source][i] && !Gr[j][Sink]) Gr[i][j] = Gr[j][i] = Dist[i][j];
		
		int t = 0,ret = 0;
		while((t = find_path(N))) ret += t;
		cout << ret << endl;
	}
}
