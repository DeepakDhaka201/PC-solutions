#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define sz size()
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<28)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define VI vector<int> 
#define VS vector<string>
#define GI GETNUM()
typedef long long int LL;
typedef pair<int,int> PII;


#define ITYPE unsigned int
#define GETCHAR getchar_unlocked
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

ITYPE GETNUM ( void )
{
   int i ;

   ITYPE j ;

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






int ar[256][256];
int Sums[256][256],Gmin,rcnt,M,N;

inline void Check(const int Sum,const int add){	
	if( Sum == Gmin) rcnt += add;
	else if( Sum > Gmin ) Gmin = Sum,rcnt = add;	
}
inline int Sumit(int a,int b,int c,int d){
	if(a>c || b>d) return 0;
	return Sums[c][d] - Sums[c][b-1] - Sums[a-1][d] + Sums[a-1][b-1];	
}

int main(){
	int T = GI;
	while(T--){
		M = GI,N = GI;
		FOR(i,1,M) FOR(j,1,N){
			ar[i][j] = ((GI)?1:-1);
			Sums[i][j] = Sums[i-1][j] + Sums[i][j-1] - Sums[i-1][j-1] + ar[i][j];	
		}

		Gmin = -INF,rcnt = 0;		
		FOR(i,1,M) FOR(j,1,N) FOR(k,j,N) Check(Sumit(i,j,i,k),1);
		FOR(i,1,N) FOR(j,1,M) FOR(k,j+1,M) Check(Sumit(j,i,k,i),1);
		
		FOR(a,1,M) FOR(b,a+1,M){
			vector<PII> V;// Min,Cnt
			int sofar = INF,c = 0;
			FOR(i,1,N-1){
				int val = Sumit(a,1,a,i) + Sumit(b,1,b,i) - 
						  Sumit(a,i,b,i);
				if( sofar == val ) c++;
				if( val < sofar ) sofar = val,c = 1;
				V.pb(PII(sofar,c));
			}
			for(int i=N;i>1;i--){				
				#define sum (Sumit(a,1,a,i-1) + Sumit(b,1,b,i-1) + Sumit(a,i,b,i) \
				 		  - V.back().first)
				Check(sum,V.back().second);
				V.pop_back();
			}
		}
		cout << Gmin << " "<< rcnt << endl;
	}	
}




