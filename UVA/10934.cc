/*
	WA :(
	
*/
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
#define EACH(it,mp) for(__typeof(mp.begin()) it=mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define rev(ar) reverse(ar.begin(),ar.end())
#define GI ({int t;scanf("%d",&t);t;})
#define INF (1<<28)
#define LINF (1e18)
#define GETN(V) for(int i=GI;i;i--) V.pb(GI)
typedef vector<int> VI;
typedef vector<string> VS;
typedef unsigned long long int LL;
typedef pair<int,int> PII;


LL ex = -1;
LL NCR[124][124];

LL go(int D,int E){
	LL& ret = NCR[D][E];
	if( D < E ) return ret = 0;
	if( D == E || !E) return ret = 1;
	if( ret != -1 ) return ret;
	return ret = go(D-1,E-1) + go(D-1,E);
}

int main(){
	int E;LL N;
	while(cin >> E >> N ){	
		if( !E ) break;
		ex = N;
		int ans = -1;
		memset(NCR,-1,sizeof(NCR));				
		FOR(D,1,63){
			LL ret = 0;
			FOR(i,0,E) ret += go( D , i );
			if( ret >= N ){ans = D;break;}
		}
		if( ans != -1 ) cout << ans << endl;
		else cout << "More than 63 trials needed." << endl;
	}
	
}
