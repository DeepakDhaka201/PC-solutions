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
#define VI vector<int>
#define VS vector<string>
#define SI set<int>
#define VN vector<node>
#define ALL(ar) ar.begin(),ar.end()
typedef long long int LL;
using namespace std;
bool primes[int(1e6)+1],vis[1002];
int N,M,D;
int to_print[1002];


bool is_prime(int n){
     if(n==1 || n==2) return true;

     for(int i = 2;i*i<=n;i++) if(n%i == 0 ) return false;
     return true;   
}

void gen_primes(){
     FOR(i,1,int(1e6)) primes[i] = is_prime(i);
}

bool go(int pos){
    if(pos == M-N+1) return true;
    
    FOR(v,N,M) if(!vis[v]){
         int s = v,ok = 1;
         FOR(j,1,D-1) if(pos>=j){
                 s += to_print[pos-j];
                 if( primes[s] ){ ok = 0;break;}
         }
         
         if(ok){
            to_print[pos] = v;
            vis[v] = true;
            if(go(pos+1)) return true;
            vis[v] = false;
         }
         
     }
     return false;
}





int main(){
    gen_primes();
    while(1){
         N = GI,M = GI,D = GI;
         memset(vis,0,sizeof(vis));
         if(!N) break;
         bool flag = false;
         
         FOR(i,N,M){
           vis[i] = 1;
           to_print[0] = i;
           if(go(1)){ flag = true;break;}
           vis[i] = 0;
         }
         
         if(flag) FOR(i,N,M){
             if(i-N) printf(",");
             printf("%d",to_print[i-N]);
             vis[ to_print[i-N] ] = 0;
         }
         else printf("No anti-prime sequence exists.");
         
         printf("\n");

    }
    
}
