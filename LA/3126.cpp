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

#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,N) for(int i = 0;i<N;i++)
#define sz size()
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<28)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

struct node{
	int t;PII start,end;
	node(int x,int a,int b,int c,int d):t(x),start(a,b),end(c,d){}
};
inline int gett(){int a,b;scanf("%d:%d",&a,&b);return a*60+b;}
bool operator<(const node& a,const node& b){ return a.t < b.t;}

VI Gr[512];
int Vis[512];

int perform(vector<node>& V){
	int DP[512] = {},next[512];
	int maxx = -INF,st = -1;
	for(int i=V.sz-1;i>=0;i--) if(!Vis[i]){
		int c = 0;
		REPV(j,Gr[i]) if(!Vis[Gr[i][j]] && c < DP[Gr[i][j]])	c = DP[Gr[i][j]],next[i] = Gr[i][j];
		DP[i] = c+1;
		if(maxx < DP[i] ) maxx = DP[i],st = i;
	}	
	if( st > -1 ){
		int n = st;
		REP(i,DP[st])	Vis[n] = 1,n = next[n];
	}
	return (st != -1);
}

int main(){
	int T = GI;
	while( T-- ){
		vector<node> V;
		int M = GI;
		REP(i,512) Gr[i].clear(),Vis[i] = 0;
		
		REP(i,M){
			int x = gett(),a = GI,b = GI,c = GI,d = GI;
			V.pb(node(x,a,b,c,d));
		}
		sor(V);
		REPV(i,V) REPV(j,V) if(i!=j){
			int a = V[i].end.first,b = V[i].end.second;
			int r = V[j].start.first,c = V[j].start.second;
			int reach = V[i].t + abs(a-V[i].start.first) + abs(b-V[i].start.second) + 
						abs(r-a) + abs(c-b);
			if( reach < V[j].t ) Gr[i].pb(j);
		}
		int ret = 0;
		while(perform(V)) ret++;
		cout << ret << endl;
	}
	return 0;
}


