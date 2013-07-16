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
int pos[40001];


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
    
    while(T--){

      int a = GI,b = GI,req = GI;
      int cnt = 0;
      REP(i,40001) pos[i] = 1<<30;
      
      int mA = ( a >? b);
      int mB = ( a <? b);
      bool flag = false;
      
                  
      register int cA = 0,cB = 0;
      cnt = 0;  
      
      while( true ){
         cnt++;
         if( cB == 0 ) cB = mB;
         else if( cA < mA ){
              if( cA + cB >= mA ) cB -= ( mA - cA),cA = mA ;
              else cA += cB,cB = 0;
         }
         else if( cA == mA )  cA = 0;     
         pos[ cA ] <?= cnt;
         pos[ cB ] <?= cnt;             
         if( cA == mA && cB == 0 ) break;
      }
      
      swap(mA,mB);
      
      cA = 0,cB = 0;
      cnt = 0;  
      
      while( true ){
         cnt++;
         if( cB == 0 ) cB = mB;
         else if( cA < mA ){
              if( cA + cB >= mA ) cB -= ( mA - cA),cA = mA ;
              else cA += cB,cB = 0;
         }
         else if( cA == mA )  cA = 0;     
         pos[ cA ] <?= cnt;
         pos[ cB ] <?= cnt;             
         if( cA == mA && cB == 0 ) break;
      }
      
      
      if(pos[ req ] >= 1<<30) printf("-1\n");
      else printf("%d\n",pos[ req ]);

    }
    
}

