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

int main(){
       int T = GI;
       while( T-- ){
               int H = GI,L = GI,ret = 0;
               REP(i,H){
                       set<PII> S;
                       int shift = 0;
                       REP(j,L){
                               int x = GI;
                               if( x != -1 ) S.insert( PII(x,j) ), ret += 20*i;
                       }
                       int a = 0;
                       EACH(it,S){
                               int p = it->second + shift + 200*L; p %= L;
                               a += min(p,L-p);
                               if( p > ( L-p ) ) shift += -p;
                               else shift += (L-p);
                       }
                       ret += 5*a;
               }
               cout << ret << endl;
       }
       return 0;
}