// TLE
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
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(__typeof(mp.begin()) it(mp.begin());it!= mp.end();it++)
#define pb push_back
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<30)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef vector<short int> VI;
typedef vector<string> VS;
typedef long long int LL;

map<string, short int > maps[10000];
char words[10002][1024];
VI Gr[1024];
int Next[1024],Memo[1024];
char S[10002];

/* recursion is ok only , return -1 immediately if it sees more than soln , dont confuse wid memset's -1 */
int go(int pos){
    if( !S[pos] ) return 1;
    int& ret = Memo[pos];if( ret != -1 ) return ret;
    ret = 0;
    REPV(i,Gr[pos]){
        int x = go( pos + Gr[pos][i] );if( !x ) continue;
        if( x == -1 || ret ) return -1;
        ret = 1,Next[pos] = Gr[pos][i];		
    }	
    return ret;
}

int HASH;
inline const string getString(int i,int j){	
	string mid = "",l = "";if( j > i ) l += S[j];
	if( j - i >= 2 ) mid = string(S,i+1,j-i-1),sor(mid);	
	return S[i] + mid + l;	
}

inline int get_hash(const string& x){
	int r = 1;
	REPV(i,x) r = r*100 + (x[i]-'a'), r %= 10000;
	return r;
}

int main(){
    int T = GI;
    while( T-- ){
        REP(i,10000) maps[i].clear();
		REP(i,1024) Gr[i].clear();
        memset(Memo,-1,sizeof(Memo));
        scanf("%s",S);		
        int N = GI;
		
        REP(i,N){
			scanf("%s",words+i);string s = words[i];
            if( s.sz > 2 ){
                string mid = string(s,1, s.sz-2);sor(mid);
                s = s[0] + mid + s[s.sz-1];
            }
			int p = get_hash(s);
			int x = ( maps[p].count( s ) ? -1: i+1  );
            maps[p][s] = x;		
			
        }
       
        for(int i = 0;S[i];i++){
            for(int j = i; S[j] && j <= i+100 ;++j){
                const string& x = getString(i,j);
                if( maps[get_hash(x)].count(x) ) Gr[i].pb( x.sz );
            }
        }
		
        int r = go(0);
        if( r == -1 ) puts("ambiguous");
        else if ( !r ) puts("impossible");
        else {
            int pos = 0;
            VI v;
            while( S[pos] ){
				int i = pos,j = i + Next[pos] - 1;
				const string& x = getString(i,j);
				int k = maps[get_hash(x)][ x ];
                if( k == -1 ) break;
				pos += Next[pos],v.pb( k );;
            }
            if( S[pos] ) printf("ambiguous");
            else REPV(i,v) printf("%s%s",i?" ":"",words[v[i]-1]);
			puts("");
        }		
    }	
    return 0;
} 