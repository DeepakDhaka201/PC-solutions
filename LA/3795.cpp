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

int Seen[1024][1024],Seenid = 1;
int D[1024][1024][2];
int dx[] = { -1 , 0 , 1 , 0 };
int dy[] = { 0 , -1, 0 , 1 };
#define ok(a,b) ((a)>=0 && (b)>=0 && (a)<X && (b)<Y)
int main(){
	int T = GI;
	while( T-- ){
		int N = GI,X = GI,Y = GI;
		int sa = GI,sb = GI,ea = GI,eb = GI;
		queue<int> Q;
		
		++Seenid;
		REP(i,N){
			int a = GI,b = GI;
			D[a][b][0] = 0;
			Q.push( a );Q.push( b );
			Seen[a][b] = Seenid;
		}
		
		while( Q.sz ){
			int r = Q.front();Q.pop();
			int c = Q.front();Q.pop();
			
			REP(i,4){
				int nx = r + dx[i], ny = c + dy[i];
				if( !ok(nx,ny) || Seen[nx][ny] == Seenid ) continue;
				Seen[nx][ny] = Seenid;
				D[nx][ny][0] = D[r][c][0] + 1;
				Q.push( nx );Q.push( ny );
			}					
		}

		double lo = -1,hi = (D[sa][sb][0] <? D[ea][eb][0]);
		int len = -1;
		while( (hi-lo) > 1e-1 ){
			double m = (hi+lo)/2;

			++Seenid;
			while( Q.sz ) Q.pop();
			Q.push( sa );Q.push( sb );
			Seen[sa][sb] = Seenid;
			D[sa][sb][1] = 0;
			int f = 0;
			while( Q.sz ){
				int r = Q.front();Q.pop();
				int c = Q.front();Q.pop();
				if( r == ea && c == eb ){ f = 1;break;}
				REP(i,4){
					int nx = r + dx[i],ny = c + dy[i];
					if( !ok(nx,ny) || Seen[nx][ny] == Seenid || D[nx][ny][0] < m ) continue;
					Seen[nx][ny] = Seenid;					
					D[nx][ny][1] = D[r][c][1] + 1;
					Q.push( nx );Q.push( ny );
				}		
			}
			if( f ) lo = m;
			else hi = m;
			len = D[ea][eb][1];
		}
		printf("%d %d\n",int(hi),len);		
	}
	return 0;
}
