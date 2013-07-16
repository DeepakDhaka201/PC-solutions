#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>


#define GI GETNUM()
#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define rev(ar) reverse(ar.begin(),ar.end())
#define p_b push_back
#define mset(ar,i) memset(ar,i,sizeof(ar))
#define VI vector<int> 
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define ALL(ar) ar.begin(),ar.end()
typedef long long int LL;
using namespace std;

typedef pair<int,int> PII;

int ar[101][101];
int gg[101][101];

#define ok(a,b) ((a)>=0 && (b)>=0 && (a)<N && (b)<M)
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
REP(kk,T){    
    int N = GI,M = GI;
    REP(i,N) REP(j,M) ar[i][j] = GI;
    queue<PII> Q;
    
    REP(i,N) REP(j,M){
             Q.push(PII(i,j));
             gg[i][j] = (1<<30);             
    }
    
    
    while( ! Q.empty() ){
       int r = Q.front().first,c = Q.front().second;
       Q.pop();
       int temp = (1<<30);
       
       FOR(i,-1,1) FOR(j,-1,1) if( !i || !j && !(i==0 && j==0)){
                   if(ok(r+i,c+j)) temp <?= gg[r+i][c+j];
                   else temp = 0;
       }
       temp >?= ar[r][c];
       if(temp >= gg[r][c] ) continue;       
       gg[r][c] = temp;
       
       FOR(i,-1,1) FOR(j,-1,1) if( !i || !j && !(i==0 && j==0) && ok(r+i,c+j))
          Q.push(PII(r+i,c+j));           
    }
    
    int ret = 0;
    REP(i,N) REP(j,M) ret += ( gg[i][j] - ar[i][j] );
    cout << ret << endl;
}

}
