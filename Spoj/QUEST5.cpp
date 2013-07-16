#include <iostream>
#include <string>
#include <cstdio>
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


int Gr[256][256],C1,C2;
int Source = 0,Sink = 241;

int find_path(){
	int P[256],Vis[256],Costs[256],f = -1;
	REP(i,256) P[i] = -1,Vis[i] = 0,Costs[i] = INF;
	
	set<PII> Q;
	Q.insert(PII(0,Source));
	P[Source] = -1;
	int back;
	
	while( Q.sz ){
		int c = -Q.begin()->first,v = Q.begin()->second;Q.erase(Q.begin());
		if(Vis[v]) continue;
		if(v!=Source) Vis[v] = true;

		if( v == Sink || (v==Source && P[Source]>-1 && c>0)){
			 back = v;
			 f = c;break;
		}

		FOR(i,Source,Sink) if(Gr[v][i]< INF){
			int nc = c + Gr[v][i];
			if( Costs[i] > nc ){
				Costs[i] = nc;
				P[i] = v;
				Q.insert(PII(-nc,i));				
			}	
		}	
	}

	if(f<=0) return 0;
	
	if(back == Source){
		int prev = P[back];
		Gr[back][prev] = -Gr[prev][back];		
		Gr[prev][back] = INF;
		back = prev;
	}	
	int nc = 0;
	
	while(f>=0 && back!=Source){
		int prev = P[back];
		Gr[back][prev] = -Gr[prev][back];
		Gr[prev][back] = INF;
		back = prev;
	}
	return f;
}


void print(){
	FOR(i,0,201){
		int f = 0;
		FOR(j,1,201) if(Gr[i][j]<INF){
			if(!f) cout << endl << endl << " For i = "<< i << endl << "      ";
			cout << j << " ";
		}
	}
}

int main(){
	int T = GI,a,b,c;
	while( T-- ){
		int N = GI;
		REP(i,256) REP(j,256) Gr[i][j] = INF;
				
		REP(i,N){
			int a = GI+1,b = GI+1;
			Gr[Source][a] = 0;
			Gr[b+120][Sink] = 0;
			Gr[a][b+120] = 1;
		}
		
		
		int t,ret = 0;
		while(true){
			 t=find_path();
			 if(t<=0) break;
			 ret += t;
		}
		cout << ret << endl;
		
	}
	return 0;
}


