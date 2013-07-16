using namespace std;
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

#define GI ({int i;scanf("%d",&i);i;})
#define pb push_back
#define rev(ar) reverse(ALL(ar))
#define sor(ar) sort(ALL(ar))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define REPV(i,n) for(int i=0;i<n.size();i++)
#define EACH(x,a) for(typeof(a.begin()) x(a.begin()),x!=a.end();i++)
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;
vector<PII> V;
int torem[10001];

int main(){
    int T = GI;
    REP(t,T){
        int N = GI,R = GI;
        V.clear();
        memset(torem,0,sizeof(torem));
        
        REP(i,R){
            int a = GI,b = GI;
            V.pb( PII(a,b) );
        }
                
        REPV(i,V) if(torem[V[i].second] < 2){
            int x = V[i].first,y = V[i].second;
            if( x == 1 ) torem[y]++;
            else {
                torem[x] <?= torem[y];
                torem[y]++;
            }
            //cout << " Getting : " << x << "," << y << endl;
            //cout << " Setting : torem[" << x << "] = " << torem[x] << endl;
            //cout << " Setting : torem[" << y << "] = " << torem[y] << endl;
            //cout << " ============== " << endl;
        }
        int c = 0;
        FOR(i,2,N) c += 2 - torem[i];
        cout << c << endl;
     }
}
