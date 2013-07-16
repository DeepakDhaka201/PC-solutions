#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <list>
//defines	
#define GI GETNUM()
#define p_b push_back
#define rev(ar) reverse(ALL(ar))
#define sor(ar) sort(ALL(ar))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define REPV(i,n) for(int i=0;i<n.size();i++)
#define EACH(x,a) for(typeof(a.begin()) x(a.begin()),x!=a.end();i++)
#define VI vector<int>
#define VS vector<string>
#define SI set<int>
#define VN vector<node>
#define ALL(ar) ar.begin(),ar.end()

#define ITYPE unsigned int
#define GETCHAR getchar_unlocked
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

ITYPE GETNUM ( void )
{
   int
      i ;

   ITYPE
      j ;

   i = GETCHAR () ;
   while ( ! DIG( i ) )
      i = GETCHAR () ;

   j = ( i - '0' ) ;

   i = GETCHAR () ;
   while ( DIG( i ) )
   {
      j = ( ( j << 1 ) + ( j << 3 ) + ( i - '0' ) ) ;
      i = GETCHAR () ;
   }
   return ( j ) ;
} 



typedef long long int LL;
using namespace std;

bool ar[21][21];
LL dp[(1<<20)+1];
int N;


int main(){
    int T = GI;

    REP(tt,T){
       N = GI;LL ans = 0;
       REP(i,N) REP(j,N) ar[i][j] = GI;     
       int LAST = (1<<N);
       dp[0] = 1;
       
       FOR(i,1,LAST-1){
           int cnt = 0;
           REP(j,N) if(i & (1<<j))cnt++;cnt--;
           dp[i] = 0;
           REP(j,N)if(i & (1<<j) && ar[cnt][j]) dp[i] += dp[i & ~(1<<j)];
       }
       printf("%lld\n",dp[LAST-1]);
    }
    
}
