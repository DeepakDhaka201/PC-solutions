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
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i )
#define LET(x,a) __typeof(a) x(a)
#define sz size()
#define cs c_str()
#define REPV(i,ar) for(int i = 0;i<int((ar).size());i++)
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
const int MN = 50000;
map<char,int> Trie[MN];
char Done[10000];
VI Gr[10000];
int EndFlag[MN], cnt, Nodes = 1;
char s[1024];

// 3 possible , 2 not possible , 1 doing , 0 not yet visited
bool go( int p ){	
	if( !p ) return true;
	if( Done[p] == 3 ) return true;
	else if( Done[p] == 2 || Done[p] == 1 || Gr[p].sz == 0){
		Done[p] = 2;
		return false;
	}	
	Done[p] = 1;
	int ans = 1;
	EACH(it,Gr[p]) ans = ans and go( *it );	
	return (Done[p] = 2 + ans) - 2;
}

int getId( const char *s , bool dbg = 0) {
	if( s[0] == '0' ) return 0;
	int root = 0;	
	for(int i = 0; s[i]; ++i ){
		if( !Trie[root].count(s[i]) ) Trie[root][s[i]] = (++Nodes);				
		root = Trie[root][s[i]];		
	}
	if( !EndFlag[root]  ) EndFlag[root] = ++cnt;
	return EndFlag[root];	
}

int main(){		
	int c = 0;
	while( scanf("%s",s) == 1 ){		
		++c;
		int v = getId( s );			
		do {
			scanf("%s",s);
			Gr[v].pb( getId(s) );
		} while( s[0] != '0' );	
	}	
	int ans = 0;
	Done[0] = 3;	
	REP(i,cnt+1) if( Gr[i].sz ) ans += go( i );
	printf("%d\n",ans);
	return 0;
}

