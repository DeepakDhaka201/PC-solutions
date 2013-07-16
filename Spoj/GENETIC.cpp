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
#define REP(i,N) for(int i = 0;i<(N);i++)
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
#define FOR(i,a,b) for(int i =(a);i<(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long int LL;
typedef pair<int,double> PID;

char S[5002];
const char *code = "NOP";

int go(int p){
	if( p == 5001 ) return 1;
	int f;
	REP(i,3){
		S[p] = code[i],f = 1;
		for(int chars=1;p-2*chars+1 >= 0;chars++){
			int b = 1;
			REP(i,chars) if( S[p-chars+1+i] != S[p-2*chars+1+i] ){ b = 0;break;}
			if( b ) f = 0;
		}
		if( f && go(p+1) ) return 1;
	}
	return 0;
}

int main(){
	int N;
	go(0);	
	while((N=GI)){
		REP(i,N) putc(S[i],stdout);
		puts("");
	}
	return 0;
}