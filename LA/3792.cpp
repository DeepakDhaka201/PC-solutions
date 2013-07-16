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
#define REP(i,N) for(int i = 0;i<(N);i++)
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;

int Seen[256],Seenid = 1;
int Cap[256][256],Gr[256][256],Grcnts[256];
int X[256],Y[256],NS[256],MS[256],Sink;
double D;

inline void add(int v,int x){ Gr[v][Grcnts[v]++] = x;};
#define set(a,b,c) Cap[a][b] = c,Cap[b][a] = 0
#define sq(x) ((x)*(x))

int augment(int c,int f){
	if( c == Sink ) return f;
	Seen[c] = Seenid;
	int rf = 0;
	for(int k=0,n=Gr[c][k];k<Grcnts[c];k++,n=Gr[c][k]) 
		if( Seen[n] != Seenid && Cap[c][n] > 0 && (rf=augment(n,min(f,Cap[c][n]))) ){
			Cap[c][n] -= rf;
			Cap[n][c] += rf;
			return rf;
		}
	return rf;
}

int main(){
	int T = GI;
	while( T-- ){
		int N = GI;cin >> D;
		memset(Cap,0,sizeof(Cap));
		memset(Grcnts,0,sizeof(Grcnts));
		
		int src = 0,PP = 0;
		FOR(i,1,N){
			scanf("%d %d %d %d",X+i,Y+i,NS+i,MS+i);PP += NS[i];
			add( src , 2*i );
			add( 2*i , 2*i+1 );
			add( 2*i+1 , 2*i );
		}
		FOR(i,1,N) FOR(j,1,N) if( i != j )	if( sq(X[i]-X[j]) + sq(Y[i]-Y[j]) <= D*D ){ 
			add( 2*i+1 , 2*j ),add( 2*j , 2*i+1 ),
			Cap[ 2*i+1 ][ 2*j ] = INF;
		}

		int st = 0;
		FOR(i,1,N){
			FOR(j,1,N){
				for(int k=0;k<Grcnts[2*j];k++) Cap[ 2*j ][ Gr[2*j][k] ] = 0;
				Cap[ src ][ 2*j ] = NS[j];Cap[ 2*j ][ src ] = 0;
				Cap[ 2*j ][ 2*j+1 ] = MS[j];Cap[ 2*j+1 ][ 2*j ] = 0;
			}		
			int tot = 0,r = 0;
			Sink = 2*i;
			do ++Seenid,tot += r; while (r=augment(src,INF));
			if( tot == PP ) printf("%s%d",st?" ":"",i-1),st = 1;			
		}
		printf("%s\n",st?"":"-1");
	}
	return 0;
}
