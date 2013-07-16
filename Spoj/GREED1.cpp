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
int N;
int Source = 0,Sink = 1001,Nodes = 1;
int Dist[1024][1024],Gr[512][512],Cnt[512];


int find_path(){
	int P[1024],Vis[1024],Costs[1024],f = 0;
	REP(i,1024) P[i] = -1,Vis[i] = 0,Costs[i] = INF;
	
	set<PII> Q;
	Q.insert(PII(0,Source));//( Cost,Source )
	P[Source] = -1;
	int back;

	while( Q.sz ){
		int c = Q.begin()->first,v = Q.begin()->second;Q.erase(Q.begin());
		if(Vis[v]) continue;
		if(v!=Source)Vis[v] = true;
		if( v == Sink || (v==Source && P[Source]>-1 && c>0)){
			 back = v;
			 f = c;break;
		}
		//cout << "Inside v = " << v << " c = " << c << endl;
		
		FOR(i,Source,Sink) if(Dist[v][i]< INF){
			int nc = c + Dist[v][i];
			if( Costs[i] > nc ){
				Costs[i] = nc;
				P[i] = v;
				//cout << " Pushing : " << i <<"  wid nc = " << nc << endl;
				Q.insert(PII(nc,i));				
			}	
		}	
	}
	//cout << "f = " << f << endl;
	if(f<=0) return 0;

	if(back == Source){
		int prev = P[back];
		int t = Dist[prev][back];
		Dist[prev][back] = INF;
		Dist[back][prev] = -t;
		back = prev;
	}	
	int nc = 0;
	
	while(f>=0 && back!=Source){
		int prev = P[back];
		int t = Dist[prev][back];
		Dist[prev][back] = INF;
		Dist[back][prev] = -t;
		back = prev;
	}
	return f;
}

int main(){
	int T = GI;
	while( T-- ){
		N = GI;
		REP(i,1024) REP(j,1024){
			 Dist[i][j] = INF;
			 if(i<512 && j<512) Gr[i][j] = INF;
		}
		REP(i,512) Gr[i][i] = 0,Cnt[i] = 0;
		REP(i,N) Cnt[GI]++;
		int E = GI;
		REP(i,E){
			int a = GI,b = GI;
			Gr[a][b] <?= 1;
			Gr[b][a] <?= 1;	
		}
		
		FOR(k,1,N) FOR(i,1,N) FOR(j,1,N) Gr[i][j] <?= Gr[i][k] + Gr[k][j];
		
		FOR(i,1,N) if(!Cnt[i]) Dist[i+500][Sink] = 0;
		
		FOR(i,1,N) if(Cnt[i]>1){
			while(Cnt[i]>1){
				Cnt[i]--;
				//cout << " Mapping : "<< Nodes << " to " << i << endl;
				Dist[Source][Nodes] = 0;
				FOR(j,1,N) if(Dist[j+500][Sink] == 0) Dist[Nodes][j+500] = Gr[i][j];
				Nodes++;
			}
		}

		int t,ret = 0;
		while(true){
			 t=find_path();
			 if(t<=0) break;
			 ret += t;
		}
		cout << ret << endl;
		
	}	
}
