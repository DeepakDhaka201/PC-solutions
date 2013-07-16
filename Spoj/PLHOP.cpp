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
#define GI ({int i;scanf("%d",&i);i;})
#define p_b push_back
#define rev(ar) reverse(ALL(ar))
#define sor(ar) sort(ALL(ar))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define REPV(i,n) for(int i=0;i<n.size();i++)
#define EACH(x,a) for(typeof(a.begin()) x(a.begin()),x!=a.end();i++)
#define VI vector<LL>
#define VS vector<string>
#define SI set<int>
#define VN vector<node>
#define ALL(ar) ar.begin(),ar.end()
#define INF (1<<30) 
typedef long long int LL;
using namespace std;
LL K,N;
typedef vector<VI> matrix;
matrix pdts[40];
matrix M;

matrix operator*(matrix a , matrix b){
       matrix ret;
       ret.resize(N);
       REP(i,N) ret[i].resize(N);
       
       REP(i,N) REP(j,N){
         ret[i][j] = LL(1e18);
         REP(k,N) ret[i][j] <?=( a[i][k] + b[k][j] );
       }
       
       return ret;
}

ostream &operator<<(ostream& out,matrix mat){
      out << endl;
      REPV(i,mat){
        REPV(j,mat[i]) cout << mat[i][j] << " ";
        out << endl;
      }
      out << "===== " << endl;     
}

int main(){
    int T = GI;
    
    REP(t,T){
       K = GI,N = GI;
       M.clear();
       
       REP(i,N){
          VI temp;
          REP(j,N) temp.p_b( GI );
          M.p_b(temp);
       }
       
       pdts[0] = M;
       
       LL i,cnt = 0;
       for(i = 1;(1LL<<i)<=K;i++){
           pdts[i] = pdts[i-1]*pdts[i-1];
       }       
       --i;
       cnt = (1<<i);
       M = pdts[i];
       
/*       cout << " Need = " << K << endl;
       cout << " Cnt = " << cnt <<" with i = " << i << " " << (1<<i) << endl;
       cout << " Matrix = " << M << endl;
*/       while(K > cnt && i>0){
          i--;
          if(K >= cnt + (1LL<<i) ){
             M = M*pdts[i];  
             cnt += (1LL<<i);  
//             cout << " Adding : " << (1LL<<i) << endl;
          }
//          cout << " i = " << i << " cnt = " << cnt << endl;
       }
       REP(i,N){ REP(j,N) cout << M[i][j] << " ";cout << endl;}

    }

}



