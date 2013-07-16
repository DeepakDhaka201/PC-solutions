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
typedef long long int LL;
typedef pair<int,int> PII;
int Ar[256][256];
int Sum[256][256];

inline int getSum(int a,int b,int c,int d){
	return Sum[c][d] - Sum[c][b-1] - Sum[a-1][d] + Sum[a-1][b-1];
}

int main(){
	int T = 1;
	while( T-- ){
		int N = GI,M = GI;
		FOR(i,1,N) FOR(j,1,M){
			Ar[i][j] = GI;
			Sum[i][j] = Sum[i-1][j] + Sum[i][j-1] - Sum[i-1][j-1] + Ar[i][j];
		}
		int A = GI,B = GI;
		set<PII>::iterator i1,i2;
		
		LL ret = 0;
		FOR(i,1,N) FOR(j,i,N){
			set<PII> S;
			S.insert(PII(0,0));
			VI V;
			int cnt = 0;
			cout << i <<" "<< j << endl;
			FOR(k,1,M){
				int x = getSum(i,1,j,k);
				cout << x << endl;
				int lo = x - B,hi = x - A;
				i1 = S.lower_bound( PII(lo,-INF));
				i2 = S.upper_bound(PII(hi,INF));
				i2--;
				if( i1 != S.end() && !(i2->first > hi) && !(i1->first < lo) ){
					cnt += (i2- i1)+1;
				}
				S.insert(PII(x,k));
			}
			cout <<" cnt = " << cnt << endl;
			ret += cnt;
			//exit(0);
		}
		cout << ret << endl;
	}
}
