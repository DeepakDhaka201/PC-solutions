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


#define GI ({int y;scanf("%d",&y);y;})
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
vector<LL> v;

int main(){
    
    int T = GI;
    
    REP(t,T){
      LL n;
      cin >> n;
      int lo = 0;
      int hi = sqrt(n) + 1;
      int flag = 0;
      while( lo<= hi){
          LL temp = LL(lo)*lo + LL(hi)*hi - n;
          if( temp > 0 ) hi--;
          else if( temp == 0 ){ flag = 1;break;}
          else lo++;
      }
      cout<< (flag?"Yes":"No") << endl;
    }
}
