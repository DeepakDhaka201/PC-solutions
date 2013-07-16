#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <list>

#define REP(i,n) for(int i=0;i<n;i++)
#define REPV(i,ar) for(int i=0;i<(ar.size());i++)
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define sor(ar) sort(ar.begin(),ar.end())
#define sz size()
#define INF (1<<29)
#define LINF ((LL) 1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define EACH(it,mp) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define VI vector<int>
#define VS vector<string>
typedef long long int LL;
using namespace std;
typedef pair<int,int> PII;

const int P = 4096;
int V[4][4096];
int A[P*P],B[P*P];
int REQ = 0;

int main(){
	int N = GI;
	REP(i,N) REP(j,4) V[j][i] = GI;
	
	int As = 0,Bs = 0;
	set<PII> S;
	REP(i,N) REP(j,N) A[As++] = V[0][i] + V[1][j];
	REP(i,N) REP(j,N) B[Bs++] = V[2][i] + V[3][j];
	
	sort(A,A+As);
	sort(B,B+Bs);
	int lo = 0,hi = Bs-1;
	LL c = 0;

	while( lo<As && hi>=0 ){
		LL s = A[lo] + B[hi] ;
		if( s > REQ ) hi--;
		else if( s < REQ ) lo++;
		else{
			int _lo = lo,_hi = hi;
			while( _lo < As && A[_lo] == A[lo] ) _lo++;
			while( _hi >=0 && B[_hi] == B[hi] ) _hi--;
			c += (_lo-lo)*1LL*(hi-_hi);
			lo = _lo,hi = _hi;
		}
	}
	cout << c << endl;
	return 0;
}
