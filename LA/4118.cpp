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

int X,Y,Z;
int Seen[32][32][32];
int final[4],start[4];

void get(){
	REP(i,3) scanf("%d",final+i);
	string s; cin >> s;
	final[3] = ( s[1] == 'x' ? 1 : s[1] == 'y' ? 2 : 3 );
	if( s[0] == '-') final[3] *= -1;
}

bool check( int *a, int *b ){
	for(int i = 0;i < 4; ++i) if( final[ i ] != start[ i ] ) return false;
	return true;
}

bool markit( int mulfactor , int p , int l , int f, int v = 0){
	int ok = 1;
	for(int i = 1; i <= l; ++i ) {
		start[ p ] += i*mulfactor;
		if( !f ){
			if( Seen[ start[0] ][ start[1] ][ start[2] ] ) return false;
		}
		else {
			Seen[ start[0] ][ start[1] ][ start[2] ] = v;
		}
		start[ p ] -= i;
	}
}

int fans;
void go( int step ){
	if( step == 7 ) return;
	if( check( start , final ) ){
		fans <?= step;
		return;
	}
	cout <<" step = " << step << endl;
	int d = start[ 3 ], p = abs( d ) - 1;
	int sides[] = { 2 , 3 };
	#define SIGN(x) ( (x) > 0 ? +1 : (x) < 0 ? -1: ({assert(1>2),1;}) )
	
	REP(ss,2){
		int l = sides[ ss ];
		if( !markit( SIGN(d) , p , l , 0 ) ) continue;
		markit( SIGN(d) , p , l , 1 , 1);
		
		start[ p ] += l;
		int ol = sides[ !ss ], t[]  = { 1 , -1 };
		for(int dir = 0; dir < 3; ++dir ) if( dir != p ) REP(tt,2) {
			if( !markit( t[tt] , dir , ol , 0 ) ) continue;
			markit( t[tt] , dir , ol , 1 , 1 );
			start[ dir ] += ol;
			start[ 3 ] = (dir+1)*t[tt];
			go( step + 1 );
			start[ 3 ] = d;
			start[ dir ] -= ol;	
			markit( t[tt], dir , ol , 1 , 0 );
		}
		start[ p ] -= l;
		markit( SIGN(d) , l , 1 , 0 );
	}
	
}

int main(){
	int testcase = 1;
	while( X=GI ){
		cout <<" here " << endl;
		Y = GI;
		Z = GI;
		get();
		REP(i,4) start[ i ] = final[ i ];
		int d = start[ 3 ], p = abs( d ) - 1;
		start[ p ] += -1*SIGN( d );
		get();
		cout <<" here " << endl;
		memset(Seen,0,sizeof(Seen));
		fans = 7;		
		go( 0 );
		printf("Case %d: ",testcase++);
		if( fans == 7 ) puts("Impossible");
		else printf("%d\n",fans);
	}
	return 0;
}


