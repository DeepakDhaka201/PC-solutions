// Once i saw prasanna's code , it was hard to unremember :P
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

int M[512][512],Seen[512][512],Seenid = 1;
int Max[512][512];
bool comp(PII a,PII b){
       return make_pair(M[a.first][a.second],PII(a.first,a.second)) >
              make_pair(M[b.first][b.second],PII(b.first,b.second));
}
#define ok(a,b) ((a)>=0 && (b)>=0 && (a)<H && (b)<W)
int main(){
       int T = GI;
       while( T-- ){
               int H = GI,W = GI,D = GI;
               vector<PII> V;
               REP(i,H) REP(j,W){
                       M[i][j] = GI;
                       Max[i][j] = M[i][j];
                       V.pb(PII(i,j));
               }
               sort(V.begin(),V.end(),comp);

               ++Seenid;
               REP(i,V.sz){
                       int a = V[i].first, b = V[i].second;
                       if( Seen[a][b] == Seenid ) continue;
                       int tall = 0;

                       vector<PII> v;
                       queue<PII> Q;
                       Q.push( PII(a,b) );
                       //cout <<"  Pushing a = " << a <<" b = " << b << endl;
                       while( Q.sz ){
                               int r = Q.front().first,
                                   c = Q.front().second;Q.pop();
                               tall >?= Max[r][c];
                               if( Seen[r][c] == Seenid ) continue;Seen[r][c] = Seenid;

                               v.pb( PII(r,c) );
                               FOR(i,-1,1) FOR(j,-1,1) if( (!i||!j) && !(!i && !j) ){
                                       int nx = r + i, ny = c + j;
                                       if( !ok(nx,ny) || M[nx][ny] <= (M[a][b]-D)  ) continue;
                                       Q.push( PII(nx,ny) );
                               }
                       }
                       EACH(it,v) Max[it->first][it->second] >?= tall;

               }
               int r = 0;
               REP(i,H) REP(j,W){
			        r += ( Max[i][j] <= M[i][j] );
               }
               printf("%d\n",r);
       }
       return 0;
}