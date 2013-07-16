#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>


#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define VI vector<int> 
#define GI GETNUM()
#define VS vector<string>
typedef long long int LL;
using namespace std;

struct n{
	int a,b;
};
n ar[10011];
inline bool operator<(const n& a,const n& b){return a.a < b.a;}


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
	REP(t,T){
		int N = GI;
		REP(i,N){
			ar[i].a = GI;
			ar[i].b = GI;			
		}
		sort(ar,ar+N);
		
		int ret = 0;
		int up = -200;
		REP(i,N){
			up <?= ar[i].b;
			if(	ar[i].a > up) ret++,up = ar[i].b;
		}
		cout << ret << endl;
	}
}


