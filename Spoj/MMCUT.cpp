#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <cassert>
#include <queue>
#include <set>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdio>

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.size());i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
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

VI Gr[100002];
int Color[1000002];


bool go(int v,int c){
	if( Color[v] == c ) return true;
	
	Color[v] = c;
	int cc = ((c-1)+1)%2 + 1;
	REPV(i,Gr[v]){
		int next = Gr[v][i];
		if( Color[next] && Color[next] != cc ) return false;
		if( !go( next , cc ) ) return false;
	}
	return true;
}

int main(){
	int N = GI,M = GI;
	VI first;
	
	REP(i,M){
		int a = GI,b = GI;
		if( a == N )swap(a,b);		
		if( b == N ){
			first.pb( a );			
			continue;
		}
		Gr[a].pb( b );
		Gr[b].pb( a );
	}
	int f = 0;
	
	REPV(i,first){
		if( Color[i] && Color[i] != 2 ){ f = 1;break;}
		if( !go( i , 2 ) ){ f = 1;break;}
	}
	REP(i,N) if( ! Color[i] ) if(!go( i , 1 )){ f = 1;break;}
	cout << 1 + f << endl;
	return 0;	
}
