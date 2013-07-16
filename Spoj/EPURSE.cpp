#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <math.h>
#include <map>
using namespace std;

#define REP(i,N) for(int i=0;i<(N);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.sz);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b); ++i )
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin()); it != mp.end() ; ++it )
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define LINF (1e18)
#define INF (int(1e9))
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
typedef pair<int,int> PII;

int throws[124];

int main(){
	int W,B,N;
	int T = 0;
	while( (W=GI) + (B=GI) + (N=GI) ){
		VI V;
		REP(i,N) V.pb( GI );
		memset(throws,0,sizeof(throws));
		throws[0] = 0;
		
		int nn = 0;
		REP(s,W) if( s < N ){
			nn++;
			int start = s;
			VI pos;
			while( start < N ) pos.pb( V[start]),start += W;
			
			int nthrows[124] = {};
			
			REP(ii,2){
				REPV(i,pos){
					int s1 = 0,r1 = -INF,r2 = 0;
					for(int j=i;j<pos.sz;j++) r2 += pos[j];
					for(int k=0;k<i;k++) s1 += pos[k],r1 >?= s1;
					REP(l,124) if(throws[l] || !l){
						nthrows[l] >?= throws[l];
						nthrows[l+1] >?= throws[l] + r2;
						nthrows[l+2] >?= throws[l] + r1 + r2;
					}
				}				
				if(pos.sz) reverse(pos.begin(),pos.end());
			}
			REP(j,124) throws[j] = nthrows[j];
		}
		int got = 0,used = 0;
		REP(l,124) if( throws[l] > got ) got = throws[l] , used = l;
		printf("Case#%d: Jack wins $%d out of %d throws.\n",++T,got,used);
	}
}