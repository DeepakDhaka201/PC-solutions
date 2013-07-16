#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end());
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,PII> PIII;


struct Pt{
	int x,y,ind;
}p;
char str[250002];
int dx[] = { 0 , 0 , 1 , -1 , 0 },dy[] = { 1 , -1 , 0 , 0 , 0};
vector<Pt> V;	
VI X[500002],Y[500002];

void clear(){
	memset(&p,0,sizeof(p));p.x = p.y = p.ind = 0;
	V.clear();
	REP(i,500002) X[i].clear(),Y[i].clear();
}

bool comp(const int& a,const int& b ){
	assert( V[a].x == V[b].x || V[a].y == V[b].y );
	if( V[a].x == V[b].x ) return V[a].y < V[b].y;
	return V[a].x < V[b].x;
}

void myswap( int& a ,int& b ){
	int t = a;
	a = -b;
	b = -t;
}

int main(){
	int T = GI;
	while( T-- ){
		int N = GI;
		scanf("%s",str+1);
		clear();
		
		
		REP(i,N+1) {
			int r = ( str[i] == 'N' ? 0: str[i] == 'S' ? 1: str[i] == 'E' ? 2: str[i] == 'W' ? 3 : 4 );
			p.x += dx[r],p.y += dy[r];
			V.pb( p );
			X[p.x + 250000].pb( p.ind );
			Y[p.y + 250000].pb( p.ind );
			p.ind++;
		}		
		PIII ret(INF,PII(INF,-INF) );
		char d = '\0';
		
		REP(k,500002) if( X[k].sz ) {
			VI& cc = X[k];
			sort( cc.begin() , cc.end() , comp );
			
			for(int i = 0; i+1 < cc.sz; ++i ){
				int b = cc[i],e = cc[i+1];
				int len = V[e].y - V[b].y;			assert( len > 0 );
				int diff = V[e].ind - V[b].ind;		if( abs(diff) <= 1 ) continue;
				
				PIII nret(len,PII(V[b].ind,-V[e].ind));
				if( diff < 0 ) myswap( nret.second.first , nret.second.second );
				if( nret < ret ){
					ret = nret;d = ( diff > 0 ?'N':'S' );
				}
			}
		}
		
		REP(k,500002) if( Y[k].sz ) {
			VI& cc = Y[k];
			sort( cc.begin() , cc.end() , comp );
			for(int i = 0; i+1 < cc.sz; ++i ){
				int b = cc[i],e = cc[i+1];
				int len = V[e].x - V[b].x;			assert( len > 0 );
				int diff = V[e].ind - V[b].ind;		if( abs(diff) <= 1 ) continue;
				
				PIII nret(len,PII(V[b].ind,-V[e].ind));
				if( diff < 0 ) myswap( nret.second.first , nret.second.second );				
				if( nret < ret ){
					ret = nret;d = ( diff > 0 ?'E':'W' );					
				}
			}
		}
		assert( ret.first != INF );
		printf("%d %d %d %c\n",ret.first,ret.second.first,-ret.second.second,d);		
				
	}
	return 0;
}

