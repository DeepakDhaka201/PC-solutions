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
#define GI ({int t;scanf("%d",&t);t;})
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
typedef long long int LL;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int prev[8001];
int curr[8001];
int cnts[8002];
bool marked[8001];

int main(){
    int T = GI;
    REP(t,T){
        int R = GI;
        vector<PIII> V;

        REP(i,R){
           int a = GI,b = GI,c = GI;                
           V.p_b( PIII(c,PII(b,a)) );
        }
        sor(V);

        memset(prev,-1,sizeof(prev));
        memset(curr,-1,sizeof(curr));
        memset(cnts,0,sizeof(cnts));
        
        REPV(i,V){
           int hi = V[i].second.first,lo = V[i].second.second;
           assert(hi>=lo);
           
           VI temp;
           FOR(l,lo,hi) if(curr[l]>=0 && !marked[curr[l]]){
                         marked[curr[l]] = 1;
                         cnts[i] += ;
           }
           
           memset(marked,0,sizeof(marked));
        }
        
        
        
    }    
    
}
