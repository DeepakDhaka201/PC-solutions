/*
	ACC
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<28)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
typedef pair<int,int> PII;

char Map[64][64];
bool Seen[64][64][1<<11];
map<PII,int> Id;
#define ok(a,b) ((a)>=0 && (b)>=0 && (a)<N && (b)<M)

struct State{
	int x,y,code;
	State(int a,int b,int c){
		x = a,y = b,code = c;
	}
};
bool operator<(const State& a,const State& b ){
	if( a.x == b.x ){
		if( a.y == b.y ) return a.code < b.code;
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main(){
	int N,M;
	while((N=GI) + (M=GI)){
		memset(Seen,0,sizeof(Seen));
		memset(Map,0,sizeof(Map));
		Id.clear();		
		
		
		REP(i,N) scanf("%s",Map[i]);
		int Treasures = 0,poss = 1,sa = -1,sb = -1;
		REP(i,N) REP(j,M){
			if( Map[i][j] == '!' ) Id[PII(i,j)] = ++Treasures;
			if( Map[i][j] == '*' ) FOR(dx,-1,1) FOR(dy,-1,1) if( ok(i+dx,j+dy) ) {
				char& c = Map[i+dx][j+dy];
				if( c == '!' || c == '@') poss = 0;
				if( c != '*' ) c = '~';
			}
			if( Map[i][j] == '@' ) sa = i,sb = j;
		}
		if( !poss ){
			printf("-1\n");
			continue;
		}
		set< pair<int,State> > S;
		S.insert( make_pair( 0 , State(sa,sb,0) ) );
		int Mcost = -1;
		
		while( S.sz ){
			int cost = S.begin()->first;State s = S.begin()->second;S.erase(S.begin());
			if( Seen[s.x][s.y][s.code] ) continue;
			Seen[s.x][s.y][s.code] = 1;
			
			if( s.code == ((1<<Treasures)-1) && s.x == sa && s.y == sb ){
				Mcost = cost;
				break;
			}
			FOR(dx,-1,1) FOR(dy,-1,1) if( !(dx*dy) && !(!dx && !dy) ) if( ok(s.x+dx,s.y+dy) ){
				int a = s.x + dx, b = s.y + dy,ncode = s.code;
				if( !(Map[a][b] == '.' || Map[a][b] == '!' || Map[a][b]== '@') ) continue;
				if( Map[a][b] == '!' )	ncode |= (1<<(Id[PII(a,b)]-1));
				S.insert( make_pair(cost+1,State(a,b,ncode)) );
			}		
		}
		printf("%d\n",Mcost);
	}
	return 0;
}
