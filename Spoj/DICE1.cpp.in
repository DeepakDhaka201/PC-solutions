#include <iostream>
#include <cstdio>
#include <set>
#include <cassert>
#include <queue>
#include <vector>
using namespace std;
#define sz size()
#define GI ({int t;scanf("%d",&t);t;})
#define REP(i,N) for(int i = 0;i < (N); ++i)
#define FOR(i,a,b) for(int i = (a);i < (b); ++i)
#define LINF (LL(1e18))
#define INF (1<<30)
#define mkp make_pair
typedef long long int LL;
typedef pair<int,int> PII;

const int Dir[4][2] = { {1,0} , {-1,0} , {0,-1} , {0,1} };
int Rotate[6][6][4][2];
#define ok(x,y) ( (x)>=0 && (x)<FIXED && (y)>=0 && (y)<4)
struct State {
	int top,front,col;
	State(){}
	void turn(int d,int f = 0){
		col += Dir[d][1];		
		int ntop = Rotate[top][front][d][0];
		front = Rotate[top][front][d][1],top = ntop;
	}
	int enc(){ return (top*6 + front)*4+col; }
	State(int x){ 
		col = x%4; x /= 4;
		front = x%6; x /= 6;
		top = x;		
	}
}global;
const int FIXED = 12;
int Matrix[144][144],Unit[144][144],Cost[144][FIXED];
LL Mul[128][144][144];
int Inp[6];

void moveRight(int& t,int& f,int& l){
	int ol = l,ot = t,of = f;
	l = 5-ot,t = ol;
	Rotate[ot][of][0][0] = t , Rotate[ot][of][0][1] = f;
	Rotate[t][f][1][0] = ot , Rotate[t][f][1][1] = of;
}
void moveDown(int& t,int& f,int& l){
	int of = f,ot = t,ol = l;
	f = ot,t = 5-of;
	Rotate[ot][of][2][0] = t, Rotate[ot][of][2][1] = f;
	Rotate[t][f][3][0] = ot, Rotate[t][f][3][1] = of;
}

void buildRotate(int x){	
	int vis[6][6][6] = {},s = 0;
	memset(Rotate,-1,sizeof(Rotate));
	queue< pair<int,PII> > Q;
	Q.push( make_pair(0,PII(1,x) ) );
	while( Q.sz ){
		int t = Q.front().first, f = Q.front().second.first, l = Q.front().second.second;Q.pop();
		if( vis[t][f][l] ) continue;vis[t][f][l]++;
		int ot = t,of = f,ol = l;
		moveRight(t,f,l);Q.push( make_pair(t,PII(f,l)) );
		t = ot,f = of,l = ol;
		moveDown(t,f,l);Q.push( make_pair(t,PII(f,l)) );
		s++;
	}
	
}
#define isok(x,a,b) ((x)>=a && (x)<b)

void buildMatrix(){	
	REP(i,144) REP(j,144) Matrix[i][j] = Unit[i][j] = INF;
	
	REP(i,6) REP(j,6) REP(c,4) if( i != j && i+j != 5 ){
		global.top = i,global.front = j,global.col = c;
		int ge = global.enc();
		
		set< pair<int,PII> > S;
		S.insert( mkp(0,PII(ge,FIXED/2) ) );
		
		REP(i,144) REP(j,FIXED) Cost[i][j] = INF;Cost[ge][FIXED/2] = 0;
		int ncnt = 0,scnt = 0;
		int req = global.top == 0 && global.front == 1 && global.col == 0;
		while( S.sz ){
			int cost = S.begin()->first, e = S.begin()->second.first, x = S.begin()->second.second;
			S.erase(S.begin());
			
			State st(e);
			if( x == FIXED/2 + 1) Matrix[ge][e] <?= cost,ncnt++;			
			if( x == FIXED/2 ) Unit[ge][e] <?= cost,scnt++;			
			REP(d,4){
				State nst(e);nst.turn( d );
				int nx = x+Dir[d][0],ne = nst.enc();				
				if( isok(nx,0,FIXED) && isok(nst.col,0,4) && isok(nst.top,0,6) && isok(nst.front,0,6) 
					&& Cost[ne][nx] == INF){					
					Cost[ne][nx] = cost + Inp[nst.top];					
					S.insert( mkp(Cost[ne][nx],PII(ne,nx)) );
				}			
			}		
		}		
	}
	
}

void go(int put,int N){	
	if( !N ) REP(i,144) REP(j,144) Mul[put][i][j] = Unit[i][j];		
	if( N&1 ){
		go(put+1,N-1);
		REP(i,144) REP(j,144) REP(k,144) Mul[put][i][j] <?= Mul[put+1][i][k] + LL(Matrix[k][j]);
	}
	else if( N ){
		go(put+1,N/2);
		REP(i,144) REP(j,144) REP(k,144) Mul[put][i][j] <?= Mul[put+1][i][k] + Mul[put+1][k][j];
	}
	return;
}

int main(){
	int T = GI;	
	while( T-- ){
		REP(i,6) Inp[i] = GI;
		int x1 = GI,y1 = GI-1,x2 = GI,y2 = GI-1;
		buildRotate( x2 > x1 ? 2: 3);
		buildMatrix();		
		REP(k,128) REP(i,144) REP(j,144) Mul[k][i][j] = LINF;		
		go(0,abs(x2-x1));
		
		LL ans = LINF;		
		REP(i,144) REP(j,144) {			
			State s(i),s1(j);
			if( s.col == y1 && s.top == 0 && s.front == 1 && s1.col == y2 )	ans <?= Mul[0][i][j];
		}
		cout << ans << endl;
	}
	return 0;
}