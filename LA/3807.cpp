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

PII Holes[8];
PII Start[8];
int MHoles[4][4],N,M,W;
bool canMove[4][4][4][4];
const int dx[] = { 0 , -1 , 0 , 1 },
		  dy[] = { -1 , 0 , 1 , 0 };
map<int,bool> Seen;		  
#define ok(a,b) ((a)>=0 && (b)>=0 && (a)<N && (b)<N)

#define DO		int id = Board[i][j]-1;\
				int a = i,b = j,brk = 0;\
				while( true ){\
					int na = a + dx[d],nb = b + dy[d];\
					if( !ok(na,nb) || !canMove[a][b][na][nb] || nBoard[na][nb] ) break;\
					\
					a = na,b = nb;\
					if( MHoles[a][b] ){\
						if( MHoles[a][b] == id+1 ){\
							nMatched |= (1<<id),brk = 1;\
							break;\
						}\
						if( (nMatched & (1<<(MHoles[a][b]-1))) == 0 ) \
							return 0;\
					}					\
				}\
				if(!brk ) nBoard[a][b] = id+1;\


struct State {
	int Matched,Board[4][4];
	State():Matched(0){memset(Board,0,sizeof(Board));}
	State(int bit):Matched(0){
		memset(Board,0,sizeof(Board));
		REP(i,M){
			int e = (bit&15);			
			if( MHoles[e/4][e%4] == i+1 ) Matched |= (1<<i);
			else Board[e/4][e%4] = i+1;
			bit >>= 4;
		}
	}
	int encode(){
		int ret = 0;
		REP(i,N) REP(j,N) if( Board[i][j] ) ret |= ( ((i<<2)+j) << ( 4*(Board[i][j] - 1) ) );
		REP(i,M) if( Matched & (1<<i) ) ret |=  ( ((Holes[i].first<<2) + Holes[i].second)<<(4*i) );
		return ret;
	}	
	bool turn(int d){
		int nMatched = Matched,nBoard[4][4] = {};
		if( d <=1 ){
			REP(i,N) REP(j,N) if( Board[i][j] ){DO}			
		}
		else {
			for(int i=N-1;i>=0;i--) for(int j=N-1;j>=0;j--) if(Board[i][j]){DO}
		}		
		REP(i,4) REP(j,4) Board[i][j] = nBoard[i][j];
		Matched = nMatched;		
		return 1;
	}
};


int main(){
	int tt = 0;
	while((N=GI)+(M=GI)+(W=GI)){tt++;
		assert( M <= 8 );
		Seen.clear();
		memset(MHoles,0,sizeof(MHoles));		
		REP(i,N) REP(j,N) REP(x,N) REP(y,N) canMove[i][j][x][y] = 1;
		
		REP(i,M) Start[i].first = GI,Start[i].second = GI;
		REP(i,M){
			Holes[i].first = GI,Holes[i].second = GI;
			MHoles[Holes[i].first][Holes[i].second] = i+1;
		}
		REP(i,W){
			int a = GI,b = GI,x = GI,y = GI;
			canMove[a][b][x][y] = canMove[x][y][a][b] = 0;
		}
		State s;		
		REP(i,M){
			int a = Start[i].first,b = Start[i].second;
			if( MHoles[a][b] == i+1 ) s.Matched |= (1<<i);			
			else s.Board[a][b] = i+1;
		}
		
		queue<PII> Q;
		int S = s.encode(),f = -1;
		Q.push( PII(S,0) ),Seen[S] = 1;
		
		while( Q.sz ){
			State s(Q.front().first);
			int cost = Q.front().second;Q.pop();
			if( s.Matched == (1<<M)-1 ){f = cost;break;}
			REP(i,4){
				State ns = s;
				if( !ns.turn(i) ) continue;
				int next = ns.encode();
				if( !Seen.count(next) ) Q.push( PII(next,cost+1) ),Seen[next] = 1;				
			}
		}
		if( f == -1 ) printf("Case %d: impossible\n\n",tt);
		else printf("Case %d: %d moves\n\n",tt,f);
	}
	return 0;
}
