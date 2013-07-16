#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <math.h>
#include <cstdlib>

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define sz size()
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end());
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
#define GETN(V) for(int i=GI;i>=0;i--) V.pb( GI )
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
int P,I;
int Cost[64][64];
VI Src,Dest;



int main(){
	int T = GI;
	while((P=GI) + (I=GI)){
		Src.clear();Dest.clear();
		REP(i,P) Src.pb( GI );
		REP(i,I) Dest.pb( GI );
		
		REP(i,P) REP(j,I){
			double a;scanf("%lf",&a);
			Cost[i][j] = int(a*100);
		}
	}
	return 0;
}




