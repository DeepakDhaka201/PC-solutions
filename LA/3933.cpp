#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cassert>
#include <queue>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>

#define GI ({int y;scanf("%d",&y);y;})
#define REP(i,N) for(int i = 0;i<(N);i++)
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!= mp.end();it++)
#define pb push_back
#define mkp make_pair
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
using namespace std;
typedef pair<int,int> PII;
typedef vector<short int> VI;
typedef vector<string> VS;
typedef long long int LL;

char Map[128][128];
int col[128][128],R,C;
int dir[6][2] = { {0,-1},{0,1},{-1,1},{1,-1},{1,0},{-1,0} };
#define ok(a,b) ( (a) >= 0 && (b) >= 0 && (a) < R && (b) < C )

void go(int r,int c,int x){
	if( !ok(r,c) || Map[r][c] == '.') return;
	if( col[r][c] && col[r][c] == x ) return;
	int p;
	if( x == 3 || col[r][c] ) x = p = 3;
	else if( x == 2 ) p = 1;
	else p = 2;	
	col[r][c] = x;
	REP(d,6) go( r+dir[d][0] , c + dir[d][1] , p);

}

int main(){
	puts("");
	while((R=GI)+(C=GI)){
		REP(i,R) REP(j,C) col[i][j] = 0;
		REP(i,R) scanf("%s",Map[i]);
		REP(i,R) REP(j,C) if( Map[i][j] == 'I') go(i,j,1);
		REP(i,R) REP(j,C)	if( Map[i][j] != '.' ) {
			int c = col[i][j];
			if( c == 0 ) Map[i][j] = 'F';
			else if( c == 1 ) Map[i][j] = '(';
			else if( c == 2 ) Map[i][j] = ')';
			else Map[i][j] = 'B';
		}
		REP(i,R) printf("%s\n",Map[i]);
	}
	return 0;
}
