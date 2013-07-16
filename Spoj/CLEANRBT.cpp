#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cassert>
#include <queue>
#include <set>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>


#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.size());i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define mkp(a,b) make_pair((a),(b))
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,-1,0,1};

int N,M;
int Seen[24][24][1<<11],Seenid;
char Gr[24][24];

#define ok(a,b) ((a)>=0 && (b) >=0 && (a) < M && (b) < N )


int reachable(int sa,int sb){
	queue<PII> Q;
	Q.push(PII(sa,sb));
	int Vis[24][24] = {},ret = 0;
	while( Q.sz ){
		int r = Q.front().first, c = Q.front().second;Q.pop();
		if( Vis[r][c] ) continue;Vis[r][c] = 1;
		if( Gr[r][c] >='0' && Gr[r][c] <='9' ) ret++;
		REP(i,4){
			int nx = r + dx[i],ny = c + dy[i];
			if(ok(nx,ny) && Gr[nx][ny] != 'x' ) Q.push(PII(nx,ny));
		}
	}
	return ret;
}

int main(){
	while( (N=GI) + (M=GI) ){
		++Seenid;
		REP(i,M) scanf("%s",Gr[i]);

		int Total = 0,sa,sb;
		REP(i,M) REP(j,N){
			if( Gr[i][j] == 'o') sa = i,sb = j;
			if( Gr[i][j] == '*' ) Gr[i][j] = '0' + Total,Total++;
		}


		int f = -1;
		set< pair<PII,PII> > Q;				
		if( reachable(sa,sb) != Total ) goto bad_start;
		Q.insert( make_pair(PII(0,0),PII(sa,sb)) );		

		
		while( Q.sz ){
			int c = Q.begin()->first.first, b = Q.begin()->first.second,
				x = Q.begin()->second.first, y = Q.begin()->second.second;
			Q.erase(Q.begin());
			if( b == (1<<Total) - 1 ) { f = c;break;}
			
			if( Seen[x][y][b] == Seenid) continue;Seen[x][y][b] = Seenid;
			
			REP(i,4){
				int nx = x + dx[i],ny = y + dy[i],
					nc = c + 1, nb = b;
				if( !ok(nx,ny) || Gr[nx][ny] == 'x' ) continue;
				if( Gr[nx][ny] >='0' && Gr[nx][ny] <= '9' ) nb |= (1<<(Gr[nx][ny]-'0'));
				Q.insert( make_pair(PII(nc,nb),PII(nx,ny)) );
			}
		}
		
		bad_start:
		printf("%d\n",f);		
	}
	return 0;
}
