#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <sstream>
#include <math.h>
#include <cstdio>


#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define EACH(it,mp) for(typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define mkp(a,b) make_pair((a),(b))
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define sz size()
#define pb push_back
#define GI ({int t;scanf("%d",&t);t;})
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

int pr[] = { 2, 3, 5, 7, 11 , 13 , 17 , 19 },L = 8;
int X[24],B[24];
int A[24][24],AStore[24][24],XStore[24];

VI factorize(int no){
	VI ret;
	REP(j,8) {
		int c = 0,temp = no;
		while( temp%pr[j] == 0 ) temp /= pr[j],c++;
		ret.pb( c );
	}
	return ret;
}

void swapcol(int a,int b){
	REP(i,L) swap(A[i][a],A[i][b]);
	swap(X[a],X[b]);
}

bool make_normal(int r,int N){
	if( A[r][r] ) return true;
	int f = 0;
	FOR(j,r+1,N-1) if( A[r][j] ){
		swapcol(r,j);
		f = 1;
		break;
	}
	return f;
}

bool solve(int L,int N){
	int Factor = 1,r = 0,c = 0;
	int Values[10] = {};
	
	for(;r < L && r < N ;++r ){
		if( !make_normal( r , N) ) continue;		
		REP(j,N) if( j != r && A[r][j] ) {
			int a = A[r][r],b = A[r][j];
			Factor *= a;
			REP(k,L) A[j][k] = A[j][k] * a - b * A[r][k];
		}		
	}
	REP(i,L) if( i < N ){
		if( !A[i][i] && !B[i] ) continue;
		else if( !A[i][i] && B[i] ) return false;		
		Values[ X[i] ] = B[i] * Factor / A[i][i];		
	}
	REP(i,L){
		int ans = 0;
		REP(j,N) ans += A[i][j] * Values[j];
		if( ans != B[i] ) return false;
	}
	return true;
}

int main(){
	int T = GI;
	FOR(tt,1,T){
		int N = GI;VI V;
		REP(i,N) V.pb( GI );
		sort(V.begin(),V.end());
		int lo = V[0];V.erase(V.begin());
		REPV(i,V) {
			VI f = factorize( V[i]/ lo );
			REPV(j,f) AStore[i][j] = f[j];
			XStore[i] = i;
		}
		
		printf("Scenario #%d:\n",tt);
		int M = GI;
		
		REP(i,M){
			memcpy(X,XStore,sizeof(X));memcpy(A,AStore,sizeof(A));
			int a = GI,b = GI;
			VI af = factorize( a ),bf = factorize( b );
			REPV(i,af) B[i] = af[i] - bf[i];
			
			if( solve(L,N-1) ) printf("Gear ratio %d:%d can be realized.\n",a,b);
			else printf("Gear ratio %d:%d cannot be realized.\n",a,b);				
		}		
		puts("");
	}
	return 0;
}
