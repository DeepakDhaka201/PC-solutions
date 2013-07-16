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


#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define rev(ar) reverse(ar.begin(),ar.end())
#define INF (1<<30)
#define sor(ar) sort(ar.begin(),ar.end())
#define VI vector<int> 
#define VS vector<string>
#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i= GI;i;i--) V.pb( GI );
typedef long long int LL;
using namespace std;
typedef pair<int,int> PII;


int doit(const VI& V){
	VI Free;
	vector<PII> Occ;
	
	int cost = 0;
	REPV(Ci,V){
		if(!V[Ci]){
			 if(Occ.size()){
				Occ.back().second--;
				cost += abs(Ci-Occ.back().first);
				if(!Occ.back().second) Occ.pop_back();			
			 }
			 else Free.pb(Ci);			 
		}
		else {
			int t = V[Ci];
			while(t>1 && Free.size()){
				cost +=	abs(Ci-Free.back());
				t--;
				Free.pop_back();			
			}
			if(t>1) Occ.pb(PII(Ci,t-1));
		}
	}
	return cost;
}


int main(){
	int T = GI;
	REP(t,T){
		VI V;
		GETN(V);
		int ret = INF;
		REPV(i,V){
			ret <?= doit(V);
			int t = V[0];
			V.erase(V.begin());
			V.pb(t);
		}
		printf("%d\n",ret);
	}	
}


