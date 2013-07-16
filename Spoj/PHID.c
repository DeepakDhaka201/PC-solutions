#include <stdio.h>
#include <stdlib.h>

#define GI GETNUM()
#define p_b push_back
#define rev(ar) reverse(ALL(ar))
#define sor(ar) sort(ALL(ar))
#define REP(i,n) for(i=0;i<n;i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define REPV(i,n) for(int i=0;i<n.size();i++)
#define EACH(x,a) for(typeof(a.begin()) x(a.begin()),x!=a.end();i++)
#define VI vector<int>
#define VS vector<string>
#define SI set<int>
#define VN vector<node>
#define ALL(ar) ar.begin(),ar.end()

typedef long long int LL;

int W,H,N;
int memo[601][601];
int V[201][2];
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
 
int compar(const void *a, const void *b){
    return *((int*)a) - *((int *)b);
}


int main(){
    int T = GI,t,i,j,a,b,r,c;
    REP(t,T){
       W = GI;H = GI;N = GI;

       REP(i,N){
          V[i][0] = GI;
          V[i][1] = GI;
       }
       qsort(V,N,2*sizeof(int),compar);
       
       REP(a,W+1) REP(b,H+1){
             memo[a][b] = a*b;
             int i = 0;             
             while(i<N && V[i][0]<=a){
                     r = V[i][0];c = V[i++][1];
                     if(c<=b){
                         if( memo[a-r][c] + memo[a][b-c] < memo[a][b]) memo[a][b] = memo[a-r][c] + memo[a][b-c];
                         if( memo[r][b-c] + memo[a-r][b] < memo[a][b]) memo[a][b] = memo[r][b-c] + memo[a-r][b];
                         if(!memo[a][b]) break;
                     }
             }
       }
       printf("%d\n",memo[W][H]);
    }
    return 0;
}
