#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <sstream>
using namespace std;
#define REP(i,N) for(int i = 0;i < (N); ++i)
#define EACH(it,mp) for( __typeof(mp.begin()) it(mp.begin()); it != mp.end(); ++it)
#define pb push_back
#define sz size()
#define GI ({int t;scanf("%d",&t);t;})
#define mkp make_pair
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
typedef pair<int,int> PII;

char Map[1024][1024];
bool Seen[1024][1024][4];
int Dir[8][2] = { {-1,0},{0,1},{1,0},{0,-1} };

int main(){
	int N = GI,M = GI;
	REP(i,N) scanf("%s",Map[i]);
	int sx = GI,sy = GI,dx = GI,dy = GI;
	int f2 = GI,f1 = GI;
	assert( Map[sx][sy] != '1' );
	priority_queue< pair<int, pair<int,PII> > > Q;
	Q.push( mkp( 0 , mkp( 2 , PII(sx,sy) ) ) );
	
	int f = -1;
	#define ok(a,b) ((a)>=0 && (a)<N && (b)>=0 && (b)<M && Map[(a)][(b)] != '1')
	
	while( Q.sz ){
		int cost = -Q.top().first, 
			d = Q.top().second.first,
			x = Q.top().second.second.first,
			y = Q.top().second.second.second;
			Q.pop();
		
		if( x == dx && y == dy ) {
			f = cost;
			break;
		}
		if( Seen[x][y][d] ) continue;Seen[x][y][d] = 1;
		for(int i = 0;i < 4; ++i )
			Q.push( mkp( -(cost + f2), mkp( i , PII(x,y) ) ) );
			
		int nx = x + Dir[d][0],ny = y + Dir[d][1];
		if( ok(nx,ny) )
			Q.push( mkp( -(cost + f1) , mkp( d , PII(nx,ny) ) ) );
	}	
	printf("%d\n",f);
	return 0;
}