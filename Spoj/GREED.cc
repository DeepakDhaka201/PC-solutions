#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
#include <map>
#include <sstream>
using namespace std;

#define REP(i,N) for(int i=0;i<N;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(_typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<28)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
#define sz size()
#define pb push_back
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
typedef pair<int,int> PII;
int Dist[512][512],Cnt[512];
#define LOOP FOR(i,1,N) FOR(j,1,N)

int main(){
	int T = GI;
	REP(t,T){
		int N = GI,E;
		LOOP Dist[i][j] = INF;
		FOR(i,1,N) Cnt[i] = 0,Dist[i][i] = 0;
		
		REP(i,N) Cnt[GI]++;
		
		E = GI;
		REP(i,E){
			int a = GI,b = GI;
			Dist[a][b] <?= 1;	
			Dist[b][a] <?= 1;
		}
		FOR(k,1,N) LOOP Dist[i][j] <?= Dist[i][k] + Dist[k][j];		
		
		int ret = 0;
		FOR(i,1,N) if(!Cnt[i]){
			int from = -1,best = INF;
			FOR(j,1,N) if(Cnt[j]>1){
				 if(Dist[j][i]< best || (from>=1 && Dist[j][i]==best && Cnt[from]<Cnt[j])){
				 	 best = Dist[j][i];
				 	 from = j;
				 }
			}
			assert(from!=-1);
			ret += best;
			Cnt[from]--;
			Cnt[i]++;
		}
		cout << ret << endl;
	}
}

