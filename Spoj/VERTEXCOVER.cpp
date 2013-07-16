#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define sz size()
#define REPV(i,ar) for(int i=0;i<ar.size();i++)
#define GI ({int y;scanf("%d",&y);y;})
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define rev(ar) reverse(ar.begin(),ar.end())
#define sor(ar) sort(ar.begin(),ar.end())
typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

VI Gr[100001];
int memo[100001][2];

int go(int par,int v,int sel){
	int& ret = memo[v][sel];
	if( ret != -1 ) return ret;
	ret = sel;
	
	REPV(i,Gr[v]) if( Gr[v][i] != par ){
		int t = go( v , Gr[v][i] , 1 );
		if( sel ) t <?= go ( v , Gr[v][i] , 0 );
		ret += t;
	}	
	return ret;
}
int main(){
	int N = GI,root = -1;
	REP(i,N-1){
		int a = GI,b = GI;
		root = a;
		Gr[a].pb( b );
		Gr[b].pb( a );
	}
	memset(memo,-1,sizeof(memo));
	cout << ( go ( -1, root , 0 ) <? go( -1 , root , 1 ) ) << endl;
	return 0;
}