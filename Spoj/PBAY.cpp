#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i=GI;i;i--) V.pb( GI )
#define REP(i,N) for(int i = 0;i<N;i++)
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef long long int LL;

void solve();

int main(){
	int T = GI;
	REP(t,T){
		int N = GI;
		int R = N-1;
		LL ret = 1;
		VI V;
		while(R) V.pb(R%2),R/=2;
		rev(V);
		REPV(i,V){
			ret = (ret*ret)%10007;			
			if(V[i]) ret = (ret*(N+1))%10007;
		}
		cout << ret << endl;
	}
}
