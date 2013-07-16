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
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;

int W,H,N;
int memo[601][601];
vector< PII > V;
#define INF (1<<30)

#define ITYPE unsigned int
#define GETCHAR getchar
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


int main(){
    int T = GI;
    V.resize(201);
    
    REP(t,T){
       W = GI,H = GI,N = GI;
       vector<PII>::iterator it = V.begin();
        
       REP(i,N){
         it->first = GI;
         it->second = GI;
         it++;
       }
       sort(V.begin(),it);
       
       REP(a,W+1) REP(b,H+1){
             memo[a][b] = a*b;
             int i = 0;             
             while(i<N && V[i].first<=a){
                     if(V[i].first<=a && V[i].second<=b){
                         memo[a][b] <?= memo[a-V[i].first][V[i].second] + memo[a][b-V[i].second];
                         memo[a][b] <?= memo[V[i].first][b-V[i].second] + memo[a-V[i].first][b];                  
                     }
                     i++;
             }
       }
       printf("%d\n",memo[W][H]);
    }
    
}
