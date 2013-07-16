#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <queue>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i=GI;i;i--) V.pb( GI )
#define REP(i,N) for(int i = 0;i<N;i++)
#define sz size()
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<28)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef long long int LL;
typedef vector<VI> VVI;


int main(){
	int T = GI;
	REP(t,T){
		int N = GI,L = GI;
		VVI ar;
		VI V;REP(i,N) V.pb( GI );sor(V);
		int X = (int) sqrt(N);
		
		VI temp;
		for(int i=0;i<V.size();){
			VI temp;
			for(int j=0;j<X && i<V.size();j++,i++) temp.pb(V[i]);
			ar.pb(temp);
		}
		int ret=0;
		
		while( ar.sz ){
			int t = ar[0][0];
			if(ar[0].sz == 1) ar.erase(ar.begin()+0);
			else ar[0].erase(ar[0].begin()+0);
			ret++;
			
			int tof = L-t;
			int loc = -1,loc2 = -1;
			REPV(i,ar) if(ar[i][0] <= tof) loc = i;
			if(loc<0) continue;
			
			REPV(i,ar[loc]) if(ar[loc][i]<=tof) loc2 = i;
			if(loc2<0) continue;

			ar[loc].erase(ar[loc].begin()+loc2);
			if(!ar[loc].sz) ar.erase(ar.begin()+loc);
		}
		if(t) cout << endl;
		cout << ret << endl;
	}
}
