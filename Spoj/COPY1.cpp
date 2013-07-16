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
vector<int> v;
#define get_sum(i,j) (sums[j] - sums[i])
int S;
double last;

bool pos( double min_val){
     int cnt = 0;
     LL sum = 0;
//     cout << " min_val = " << min_val << endl;
     REPV(i,v){
               sum += v[i];
//               cout <<" sum = " << sum <<" :" << v[i] << endl;
               if( sum > min_val ){
//                 cout <<" Cutting at : " << v[i] << endl;
                 cnt++;
                 if( cnt > S - 1 ) return false;
                 sum = 0;
                 i--;    
               }
     }
     
//     cout << " F SUM = " << sum << endl;
     if( sum > min_val ) return false;
     last = min_val;
     return true;
}


string to_s(int no){
       char buff[100];
       sprintf(buff,"%d",no);
       return string(buff);       
}

int main(){
    int T = GI;
    while( T -- ){
     LL N = GI,sum = 0;S = GI;
     int minx = 1<<30,maxx = -10;     
     v.clear();
     
     REP(i,N){ int t; v.p_b( t = GI );minx <?= t;sum+=t;}
     
     double lo = 0,hi = sum;

     while( (hi - lo) > 1e-1 ){
           double mid = ( lo + hi )/2;
           if( pos(mid) ) hi = mid;
           else lo = mid;
     }

//     cout << " hi = "<< hi << " lo = " << lo << endl;
     
     string ret = "";
     
     double min_val = last;
     string sret = "";
     sum = 0;
     rev(v);
     
     REPV(i,v){
         sum += v[i];
         if( sum > min_val ){
           sret = " /" + sret;
           i--;
           sum = 0;
         }
         else{
              sret = (i==v.size()-1?"":" ") + to_s(v[i]) + sret; 
         }
//         cout << sret << endl;
     }
     printf("%s\n",sret.c_str());

   }
     
}
