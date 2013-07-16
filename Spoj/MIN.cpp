#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define p_b push_back
#define VI vector<LL>
#define VS vector<string>
#define GI ({int t;scanf("%d",&t);t;})
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define INF (1<<30)
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
vector<PII> V;
vector<string> gr;
int N,M,D;
int wts[7][7];

#define ok(i,j) (i>=0 && j>=0 && i<N && j<M && !vis[i][j] && gr[i][j]!='#')

void expand(int id){
     PII p = V[id];
     queue<PIII> Q;
     int vis[61][61];
     memset(vis,0,sizeof(vis));
     Q.push(make_pair(1,p));
     
     while(!Q.empty()){
         int r = Q.front().second.first,c = Q.front().second.second;
         int wt = Q.front().first;
         Q.pop();
         if(vis[r][c]) continue;vis[r][c] = wt;
         
         REPV(i,V) if(V[i] == PII(r,c) ) wts[id][i] <?= (wt-1);
        
         FOR(i,-1,1) FOR(j,-1,1) if(!i || !j) if(ok(r+i,c+j)) Q.push( make_pair(wt+1,PII(r+i,c+j)) );
     }     
}



int main(){
    N = GI,M = GI,D = GI;
    REP(i,7) REP(j,7) wts[i][j] = INF;
    REP(i,N){
       string temp;
       cin >> temp;
       gr.p_b(temp);
    }
    V.p_b(PII(0,0));
    REPV(i,gr) REPV(j,gr[i]) if(gr[i][j] == 'o') V.p_b(PII(i,j));
    
    VI temp;
    REPV(i,V) expand(i);
    FOR(j,1,V.size()-1) temp.p_b(j);
    int ret = INF;
    
    do{
       int cost = wts[0][temp[0]];
       if( cost == INF ) continue;
       REP(i,D-1){
                   cost += wts[temp[i]][temp[i+1]];
                   if(wts[temp[i]][temp[i+1]] == INF ){
                     cost = INF;
                     break;                           
                   }
       }
       ret <?= cost;           
    }while( next_permutation(temp.begin(),temp.end()) );

    if(ret == INF) cout << -1 << endl;
    else cout << ret << endl;
}
