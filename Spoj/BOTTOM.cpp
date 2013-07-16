#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <list>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <math.h>

using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPV(i,ar) for(int i=0;i<int(ar.size());i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!=mp.end();it++)
#define GI ({int y;scanf("%d",&y);y;})
#define sz size()
#define pb push_back
#define INF (1<<30)
#define LINF (1e18)
#define sor(ar) sort(ar.begin(),ar.end())

typedef long long int LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int MN = 5000 + 10;
VI Gr[MN],GrT[MN];
int V,E,Finish[MN],Seen[MN],Seenid,SocId[MN], SocCnt , ft, A[MN] ;
VI Vlist;

void go( int v ){
	if( Seen[v] == Seenid ) return;
	Seen[v] = Seenid;	
	EACH(it,Gr[v]) go( *it );		
	Finish[ v ] = ++ft;
}

inline bool comp( int a , int b ){ 
	if( Finish[a] == Finish[b] ) return a < b;
	return Finish[a] > Finish[b];	
}

void goT( int v ){	
	if( Seen[v] == Seenid ) return;Seen[v] = Seenid;		
	Vlist.pb( v );SocId[ v ] = SocCnt;
	EACH(it,GrT[v]) goT( *it );
}

int main(){
	while( V=GI ){
		REP(i,V+10) Gr[i].clear(), GrT[i].clear(), SocId[i] = -1;
		E = GI;
		REP(i,E) {
			int a = GI-1, b = GI-1;
			Gr[a].pb( b );
			GrT[b].pb( a );
		}
		
		++Seenid;		
		REP(i,V) if( Seen[i] != Seenid ) go( i );		
		REP(i,V) sort( GrT[i].begin(), GrT[i].end(), comp ), A[i] = i;
			
		++Seenid;
		SocCnt = 1;
		sort(A,A+V,comp);
		VI ans;
		REP(i,V) if( Seen[A[i]] != Seenid ){
			Vlist.clear();
			goT( A[i] );
			int ok = 1;
			EACH(it,Vlist) EACH(n,Gr[*it]) if( SocId[*n] != SocCnt ) ok = 0;
			if( ok ) EACH(it,Vlist) ans.pb( *it );
			SocCnt++;
		}
		
		sort( ans.begin() , ans.end() );
		REPV(i,ans) printf("%d%s",ans[i]+1, i == ans.sz - 1 ? "\n" : " ");		
	}
	return 0;
}