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
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();i!=mp.end();i++)
#define rev(ar) reverse(ar.begin(),ar.end())
#define p_b push_back
#define mset(ar,i) memset(ar,i,sizeof(ar))
#define VI vector<int> 
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define ALL(ar) ar.begin(),ar.end()
#define mkp(a,b) make_pair((a),(b))
typedef long long int LL;
using namespace std;

struct node{
 int x,y,z;
 node(int a,int b,int c):x(a),y(b),z(c){}
};

bool operator<(const node& a,const node& b){
  if(a.x == b.x) return a.y > b.y;
  return a.x < b.x;
}

vector<node> v;


#define ITYPE unsigned int
#define GETCHAR getchar_unlocked
#define DIG( a ) ( ( ( a ) >= '0' ) && ( ( a ) <= '9' ) )

ITYPE GETNUM ( void )
{
   int
      i;

   ITYPE
      j ;

   i = GETCHAR () ;
   while ( ! DIG( i ) ) i = GETCHAR ();
     

   j = ( i - '0' ) ;

   i = GETCHAR () ;
   while ( DIG( i ) )
   {
      j = ( ( j << 1 ) + ( j << 3 ) + ( i - '0' ) ) ;
      i = GETCHAR () ;
   }
   return ( j ) ;
} 






#define MAX_VAL 1e6
int main(){
   int T = GI,a,b,c;   
   
   REP(t,T){

     int N = GI;
     vector<int> ZC;
     v.clear();
     
     REP(i,N){
         a = GI,b = GI,c = GI;
         v.p_b(node(a,b,c));
         ZC.p_b(c);
     }
         
     ZC.p_b(int(MAX_VAL));     
     sor(ZC);
     sor(v);
     
     LL ret = 0;
     int bx = -1,by = -1,bz = -1;
     
     REPV(zc,ZC){
        int maxZ = ZC[zc];
        int maxY = int(MAX_VAL);
               
        REPV(i,v) if(v[i].z< maxZ){
                  LL temp = maxY*1LL*v[i].x*maxZ;
                  if( temp > ret ){ 
                                    ret = temp;
                                    bx = v[i].x;
                                    by = maxY;
                                    bz = maxZ;
                  } 
                  maxY <?= v[i].y;
        }

        LL temp = (maxY*1LL*int(MAX_VAL)*maxZ);
        if( temp > ret ){
             ret = temp;
             bx = int(MAX_VAL),
             by = maxY,
             bz = maxZ;
        }
     }
     printf("%d %d %d\n",bx,by,bz);
   }    
}
