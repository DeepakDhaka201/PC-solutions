#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>
#include <cassert>
#include <sstream>
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

int memo[21][21][361],sign[21],sum[21];
VI nos;

int go(int s,int e,int k){
	int& ret = memo[s][e][k];
	ret = INF;
	if( ret != -1 ) return ret;	
	if( sum[e]-sum[s]+nos[s] < abs(k) ) return ret;

	for(int i=s+1;i<e;i++){
		if( sign[i] < 0 ){
			sign[i] = 1;
			
		}
	}
}

int main(){
	int T = GI;
	char str[64];
	while( T--){
		memset(memo,-1,sizeof(memo));nos.clear();
		scanf("%s",str);
		for(int i=0;str[i];i+=2){
			int s = str[i] == '+'?1:-1;
			int no = str[i+1]-'0';
			sign[i/2] = s;
			nos.pb( no*s );
			sum[i/2] = (i?sum[i/2-1]:0) + no;
		}
		
		
		
	}
	return 0;
}



