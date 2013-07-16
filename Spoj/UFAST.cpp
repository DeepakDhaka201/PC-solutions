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

using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
#define VI vector<int> 
#define VS vector<string>
typedef long long int LL;

#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i= GI;i;i--) V.pb( GI );
int dp[101][1001];
int dp2[101][1001];

int main(){
	int T = GI;
	while(T--){
		int N = GI,D = GI;
		VI V;
		REP(i,N) V.pb( GI );	
		sor(V);
		
		REPV(i,V) FOR(j,0,1000){			
			dp[i][j] = INF;dp2[i][j] = INF;
			int cost = abs(j-V[i]);
			if(i){
				FOR(k,((j-D) >? 0),j){
					dp[i][j] <?= dp[i-1][k] + cost;
					dp2[i][j] <?= ( dp2[i-1][k] >? cost );
				}						
			}
			else {
				dp[i][j] = cost;
				dp2[i][j] = cost;
			}
		}
   		
		int a1 = INF,a2 = INF;
		FOR(j,0,1000) a1 <?= dp[N-1][j],a2 <?= dp2[N-1][j];
		cout << a2 << " "<< a1 << endl;
	}

}






