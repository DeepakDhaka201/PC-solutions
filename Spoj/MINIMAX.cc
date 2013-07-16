#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
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
#define INF (1<<30)
#define LINF ((LL) 1e18)
#define rev(ar) reverse(ar.begin(),ar.end());
#define GI ({int t;scanf("%d",&t);t;})
#define GETN(V) for(int i=GI;i>=0;i--) V.pb( GI )
using namespace std;
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

VI Buck[256];
int MIN[256],nB;

int calc(int a,int b){
	int sa = a/nB,sb = b/nB;
	int ret = INF;	
	if ( sa == sb )	for(int i = (a%nB);i<= (b%nB);i++) ret <?= Buck[sa][i];	
	else{
		for(int i = (a%nB);i<nB;i++) ret <?= Buck[sa][i];
		for(int x = sa+1;x< sb;x++) ret <?= MIN[x];
		for(int i = 0;i <= b%nB;i++) ret <?= Buck[sb][i];
	}
	return ret; 
}

int solve(){
	int L = GI,N = GI;
	nB = sqrt(L) + 1;
	vector<PII> V;
	REP(k,nB+1) Buck[k].clear(),Buck[k].resize(nB);	
	REP(i,N){
		int a = GI-1,b = GI-1;
		if( V.sz && PII(a,b) == V.back() ) continue;
		V.pb( PII(a,b) );		
	}
	
	REP(i,L){
		if( i == 0 ) Buck[0].pb(0),MIN[0] = 0;
		else Buck[i/nB][i%nB] = INF,MIN[i/nB] = INF;		
	}	
	
	REPV(i,V){
		int x = calc(V[i].first,V[i].second );
		int b = V[i].second/nB,o = V[i].second%nB;
		MIN[b] <?= (x+1);
		Buck[b][o] <?= (x+1);
	}
	L--;
	cout << Buck[L/nB][L%nB] << endl;
	return 0;
}

int main(){
	int T = GI;
	while( T-- ) solve();
	return 0;
}
