#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define sz size()
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define GI ({int y;scanf("%d",&y);y;})
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

vector<PII> Gr[20002];
int Visited[20002];
int Edges[1000000],Seen[1000000],Seenid,N,M;
int done[20002],doneid = 1;
vector<PII> Path;

int Pdt = 1;

void go(int u,int par){		
	if(Visited[u]){
		int i = Path.sz - 2,c = 1;
		Edges[Path.back().second] = 1;
		while(i>=0){
			if(Edges[Path[i].second] == 1 ) throw 1;
			Edges[Path[i].second] = 1;			
			done[Path[i].first] = doneid;
			if(Path[i].first == u ) break;
			i--,c++;			
		}
		doneid++;
		Pdt *= (c+1);
		return;
	}
	
	Visited[u] = 1;
	REPV(i,Gr[u]) if(Gr[u][i].first != par){
		Path.pb(Gr[u][i]);
		Seen[Gr[u][i].second] = Seenid;
		if( !(done[u] && done[Gr[u][i].first] && done[u]==done[Gr[u][i].first]) )
			go(Gr[u][i].first,u);		
		Path.pop_back();
	}	
}

int main(){
	while(cin >> N >> M){
		int Ecnt = 0;Pdt = 1;++Seenid;
		memset(Edges,0,sizeof(Edges));
		memset(Visited,0,sizeof(Visited));
		memset(done,0,sizeof(done));
		while(M--){
			int R = GI,st = GI;
			REP(i,R-1){
				int n = GI;
				Gr[st].pb(PII(n,Ecnt));Gr[n].pb(PII(st,Ecnt));
				Edges[Ecnt++] = 0;
				st = n;
			}
		}
		
		int f = 0;
		
		try{
			go(1,-1);			
			FOR(i,1,N) if(!Visited[i]) f = 1;
			REP(i,Ecnt) if( Seen[i] != Seenid) f = 1;
		}catch(...){f = 1;	}
			
		
		if(f) cout << 0 << endl;
		else cout << Pdt << endl;
				
	
	}
}